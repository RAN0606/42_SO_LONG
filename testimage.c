#include "mlx.h"
#include "so_long.h"

typedef struct s_map
{
	char	*maplist;
	int		**maparray;
	int		mapline;
	int		mapcol;
} t_map;

typedef struct s_play
{
    void    *mlx_self;
    void    *mlx_win;
	void	*img;
	int		img_width;
	int		img_height;
	char	*relative_path;
	int		x;
	int		y;

} t_play;

int	ft_keyhook(int keycode, t_play *play)
{
	if (keycode == KEY_S_DOWN)
		(*play).y = (*play).y + (*play).img_height;
	else if (keycode == KEY_D_RIGHT)
		(*play).x = (*play).x + (*play).img_width;
	else if (keycode == KEY_W_UP)
		(*play).y = (*play).y - (*play).img_height;
	else if (keycode == KEY_A_LEFT)
		(*play).x = (*play).x - (*play).img_width;
	mlx_put_image_to_window((*play).mlx_self, (*play).mlx_win, (*play).img, (*play).x, (*play).y);
	return (0);
}

size_t	ft_strlen_non(char *str)
{
	size_t len;

	len = 0;
	while (str[len] != '\n' && str[len])
		len++;
	return(len);
}

int	ft_checkmap_size(t_map map,char *map_path)
{
	int		fd;
	char	*temp;

	temp = 0;
	map.mapline =0;
	map.mapcol = 0;
	map.maplist = ft_strdup("");
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		printf("File error: fd does not exist!");
		exit (1);
	}
	while (fd)
	{
		temp = get_next_line(fd);
		if (ft_strlen_non(temp))
		{
			if (map.mapcol == 0)
				map.mapcol = ft_strlen_non(temp);
			else if (map.mapcol == ft_strlen_non(temp))
				map.maplist = ft_strjoin(map.maplist, temp);
			else 
				return (0)
			map.mapline += 1;
		}
		if(!temp && map.mapcol != 0)
			return(1);
	}
	return (0);
}

int ft_checkmap_c(t_map map)
{
	int i;
	int j;
	int depart = 0;
	int exit = 0;
	int collect = 0;

	i = 0;
	map.maparray = ft_split(map.maplist);
	if (!map.maparray)
		return (0);
	while (i < map.mapline)
	{
		j = 0;
		while (j < map.mapcol)
	{
			if (map.maparray[i][j] != 'E' && map.maparray[i][j] != '1' 
					&& map.maparray[i][j] != '0' && map.maparray != 'P')
			{
				printf("Error\n the character is not defined");
				return (0);
			}
			else if ((i == 0 || i == map.mapline - 1 || j == 0 || j == map.mapcol - 1) 
				&& map.maparray[i][j] != '1')
			{
				printf("Error\n this place should be the wall");
				return (0);
			}
			else if (map.maparray[i][j] == 'P')
				depart++;
			else if (map.maparray[i][j] == 'E')
				exit++;
			else if (map.maparray[i][j] == 'C')
				collect++;
			j++;
	}
		i++;
	}
	if (!depart || !exit || !collect)
	{
		printf(printf("Error\n at least one item, one exit, and one collect, please check your map!"));
		return (0)
	}
	return (1);
}

void ft_putimg_set()

int	main(void)
{
	t_play	play;
	t_map	map;
	char	relative_path[] = "./cat.xpm";

	play.x = 0;
	play.y = 0;
	play.mlx_self = mlx_init();
	play.mlx_win = mlx_new_window(play.mlx_self, 1920, 1080, "Hello world!");
	play.img_1 = mlx_xpm_file_to_image(play.mlx_self, relative_path, &(play.img_width), &(play.img_height));
	mlx_put_image_to_window(play.mlx_self, play.mlx_win, play.img, play.x, play.y);
	mlx_key_hook(play.mlx_win, ft_keyhook, &play);
//	mlx_mouse_get_pos(mlx, mlx_win, &img_width, &img_height);
	mlx_loop(play.mlx_self);
}
