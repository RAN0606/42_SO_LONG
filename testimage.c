#include "mlx.h"
#include "so_long.h"

typedef struct s_map
{
	char	*maplist;
	int		**map_array;
	int		map_line;
	int		map_col;
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
		(*play).x = (*play).x - (*play).img_width
	mlx_put_image_to_window((*play).mlx_self, (*play).mlx_win, (*play).img, (*play).x, (*play).y);
	return (0);
}

t_map	ft_checkmap_size(t_map map,:wq char *map_path)
{
	int		fd;
	char	*temp;

	map.mapline =0;
	map.mapcol = 0;
	map.maplist = ft_strdup("");
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("File erro: fd does not exist!");
		exit (1);
	}
	while (fd)
	{
		temp = get_next_line(fd);
		if (map.mapline == 0)
		{
			if (temp)
		map.mapline += 1;
		
		

	}
}


int	main(void)
{
	t_play	play;
	t_map	map;
	char	relative_path[] = "./cat.xpm";


	play.x = 0;
	play.y = 0;
	play.mlx_self = mlx_init();
	play.mlx_win = mlx_new_window(play.mlx_self, 1920, 1080, "Hello world!");
	play.img = mlx_xpm_file_to_image(play.mlx_self, relative_path, &(play.img_width), &(play.img_height));
	mlx_put_image_to_window(play.mlx_self, play.mlx_win, play.img, play.x, play.y);
	mlx_key_hook(play.mlx_win, ft_keyhook, &play);	
//	mlx_mouse_get_pos(mlx, mlx_win, &img_width, &img_height);
	mlx_loop(play.mlx_self);
}
