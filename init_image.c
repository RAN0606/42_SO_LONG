/* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:32:14 by rliu              #+#    #+#             */
/*   Updated: 2022/03/18 21:09:18 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
typedef struct s_img
{
	void	*ptr;
	int	w; //width of img
	int	h;//height of img
} t_img;

typedef struct s_img_set
{
	t_img	wall;
	t_img	terrain;
	t_img	collect;
	t_img	exit;
	t_img	start;
	t_img	player;
} t_img_set;

typedef struct s_play
{
    void    *mlx_self;
    void    *mlx_win;
    t_img_set	imgs;
    int		x;
    int		y;
} t_play;

t_img ft_init_imgs_spirit(void *mlx, char *path)
{		
	t_img	img;
	 
	img.ptr = mlx_xpm_file_to_image(mlx, path, &(img.w), &(img.h));
	return (img);	
}

t_img_set ft_init_imgs(void *mlx)
{
	t_img_set imgs;

	imgs.wall = ft_init_imgs_spirit(mlx,"img_48/tree.xpm");
	imgs.terrain = ft_init_imgs_spirit(mlx,"img_48/floor_purple.xpm");
	imgs.collect = ft_init_imgs_spirit(mlx,"img_48/collect2.xpm");
	imgs.exit = ft_init_imgs_spirit(mlx,"img_48/exit.xpm");
	imgs.start = ft_init_imgs_spirit(mlx,"img_48/start.xpm");
	imgs.player = ft_init_imgs_spirit(mlx,"cat_48/down_2.xpm");
	return (imgs);

}

void ft_putimg(t_play play, t_map map, int line, int col)
{
	mlx_put_image_to_window(play.mlx_self, play.mlx_win, play.imgs.terrain.ptr, col*48, line*48);
	if (line == 0 || line == map.mapline - 1 || col == 0 || col == map.mapcol - 1)
		mlx_put_image_to_window(play.mlx_self, play.mlx_win, play.imgs.wall.ptr, col*48, line*48);
	if (map.maparray[line][col] == 'P')
		mlx_put_image_to_window(play.mlx_self, play.mlx_win, play.imgs.player.ptr, col*48, line*48);
	if (map.maparray[line][col] == 'C')
		mlx_put_image_to_window(play.mlx_self, play.mlx_win, play.imgs.collect.ptr, col*48, line*48);
	if (map.maparray[line][col] == 'E')
		mlx_put_image_to_window(play.mlx_self, play.mlx_win, play.imgs.exit.ptr, col*48, line*48);


}
void ft_putimgs(t_play play, t_map map)
{
        int line = 0;
        int col = 0;
        while (line < map.mapline)
        {
                col = 0;
                while (col < map.mapcol)
                {
			ft_putimg(play,map,line,col);
                        col++;
                }
                line++;
        }
}

void ft_init_display(t_play *play, t_map *map)
{
	int screen_l;
	int screen_h;

	play->mlx_self = mlx_init();
	mlx_get_screen_size(play->mlx_self, &screen_l, &screen_h);
	if (map->mapcol * 48 > screen_l || map->mapline * 48 > screen_h)
	{
		ft_map_exit("mapsize is too big for this screen!", map);
	}
	play->mlx_win = mlx_new_window(play->mlx_self, map->mapcol * 48, map->mapline * 48, "./so_long");
	play->imgs = ft_init_imgs(play->mlx_self);	
	
}

int	main(int argc, char **argv)
{
	t_play	play;
	t_map	map;
	
	ft_checkmap(&map,argv[1]);
	ft_init_display(&play,&map);
	ft_putimgs(play,map);
	mlx_loop(play.mlx_self);
}
