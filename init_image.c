/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:32:14 by rliu              #+#    #+#             */
/*   Updated: 2022/03/22 18:41:26 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img ft_init_imgs_spirit(void *mlx, char *path)
{		
	t_img	img;
	 
	img.ptr = mlx_xpm_file_to_image(mlx, path, &(img.w), &(img.h));
	return (img);	
}

t_img_set ft_init_imgs(void *mlx)
{
	t_img_set imgs;

	imgs.wall = ft_init_imgs_spirit(mlx,"img_48/tree_green.xpm");
	imgs.terrain = ft_init_imgs_spirit(mlx,"img_48/floor_green.xpm");
	imgs.collect = ft_init_imgs_spirit(mlx,"img_48/collect_1_green.xpm");
	imgs.exit = ft_init_imgs_spirit(mlx,"img_48/exit_green.xpm");
	imgs.start = ft_init_imgs_spirit(mlx,"img_48/start.xpm");
	imgs.player_up = ft_init_imgs_spirit(mlx,"cat_48/background/up_2.xpm");
	imgs.player_down = ft_init_imgs_spirit(mlx,"cat_48/background/down_2.xpm");
	imgs.player_left = ft_init_imgs_spirit(mlx,"cat_48/background/left_2.xpm");
	imgs.player_right = ft_init_imgs_spirit(mlx,"cat_48/background/right_2.xpm");
	return (imgs);

}

void ft_putimg(t_play play, t_map map, int line, int col)
{

	if (map.maparray[line][col] == '1')
		mlx_put_image_to_window(play.mlx_self, play.mlx_win, play.imgs.wall.ptr, col*48, line*48);
	if (map.maparray[line][col] == 'P')
	{
		if (map.p_direct == KEY_W_UP)
			mlx_put_image_to_window(play.mlx_self, play.mlx_win, play.imgs.player_up.ptr, col*48, line*48);
		else if (map.p_direct == KEY_D_RIGHT)
			mlx_put_image_to_window(play.mlx_self, play.mlx_win, play.imgs.player_right.ptr, col*48, line*48);
		else if (map.p_direct == KEY_A_LEFT)
			mlx_put_image_to_window(play.mlx_self, play.mlx_win, play.imgs.player_left.ptr, col*48, line*48);
		else
			mlx_put_image_to_window(play.mlx_self, play.mlx_win, play.imgs.player_down.ptr, col*48, line*48);
	}
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

			mlx_put_image_to_window(play.mlx_self, play.mlx_win, play.imgs.terrain.ptr, col*48, line*48);
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

int	ft_mov(int x, int y, t_play *play, int keycode)
{
	char	c;
	static int	i;

	play->map->p_direct = keycode;
	c= play->map->maparray[play->map->p_y + y][play->map->p_x + x];
	if (c == 'E' && play->map->collect_nb == 0)
	{
		i++;
		ft_putstr_fd("\rMovement total: ",1);
		ft_putnbr_fd(i,1);
	       	ft_map_exit("\nWIN!", play->map);
	}
	else if (c != '1' && c != 'E')
	{
		i++;
		ft_putstr_fd("\rMovement total: ",1);
		ft_putnbr_fd(i, 1);
		if (c == 'C')
			play->map->collect_nb -=1;
		play->map->maparray[play->map->p_y][play->map->p_x] = '0';
		play->map->p_y += y;
		play->map->p_x += x;
		play->map->maparray[play->map->p_y][play->map->p_x] = 'P';
	}
	ft_putimgs(*play,*(play->map));
	return (0);
}

int	ft_keyhook(int keycode, t_play *play)
{
	
	if (keycode == KEY_S_DOWN)
		ft_mov(0, 1, play,keycode);
	else if (keycode == KEY_D_RIGHT)
		ft_mov(1, 0, play,keycode);	
	else if (keycode == KEY_W_UP)
		ft_mov(0, -1, play,keycode);
	else if (keycode == KEY_A_LEFT)
		ft_mov(-1, 0, play,keycode);
	return (0);
}


int	main(int argc, char **argv)
{
	t_play	play;
	
	play.map = ft_calloc(1, sizeof(t_map));	
	ft_checkmap(play.map,argv[1]);
	ft_init_display(&play,play.map);
	ft_putimgs(play,*(play.map));
	mlx_key_hook(play.mlx_win,ft_keyhook, &play);
	mlx_loop(play.mlx_self);
}
