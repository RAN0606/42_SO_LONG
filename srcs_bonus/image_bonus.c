/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:32:14 by rliu              #+#    #+#             */
/*   Updated: 2022/03/24 11:25:51 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../incs/so_long_bonus.h"

t_img	ft_init_imgs_spirit(void *mlx, char *path)
{		
	t_img	img;

	img.ptr = mlx_xpm_file_to_image(mlx, path, &(img.w), &(img.h));
	return (img);
}

t_img_set	ft_init_imgs(void *mlx)
{
	t_img_set	imgs;

	imgs.wall = ft_init_imgs_spirit(mlx, "img/tree_green.xpm");
	imgs.terrain = ft_init_imgs_spirit(mlx, "img/floor_green.xpm");
	imgs.collect = ft_init_imgs_spirit(mlx, "img/collect_1_green.xpm");
	imgs.exit = ft_init_imgs_spirit(mlx, "img/exit_green.xpm");
	imgs.player_up = ft_init_imgs_spirit(mlx, "img/cat/up_2.xpm");
	imgs.player_down = ft_init_imgs_spirit(mlx, "img/cat/down_2.xpm");
	imgs.player_left = ft_init_imgs_spirit(mlx, "img/cat/left_2.xpm");
	imgs.player_right
		= ft_init_imgs_spirit(mlx, "img/cat/right_2.xpm");
	return (imgs);
}

void	ft_putimg(t_play play, t_map map, int line, int col)
{
	void	*img_ptr;

	if (map.maparray[line][col] == '1')
		img_ptr = play.imgs.wall.ptr;
	if (map.maparray[line][col] == '0')
		img_ptr = play.imgs.terrain.ptr;
	if (map.maparray[line][col] == 'P')
	{
		if (map.p_direct == KEY_W_UP)
			img_ptr = play.imgs.player_up.ptr;
		else if (map.p_direct == KEY_D_RIGHT)
			img_ptr = play.imgs.player_right.ptr;
		else if (map.p_direct == KEY_A_LEFT)
			img_ptr = play.imgs.player_left.ptr;
		else
			img_ptr = play.imgs.player_down.ptr;
	}
	if (map.maparray[line][col] == 'C')
		img_ptr = play.imgs.collect.ptr;
	if (map.maparray[line][col] == 'E')
		img_ptr = play.imgs.exit.ptr;
	mlx_put_image_to_window(play.mlx_self,
		play.mlx_win, img_ptr, col * 48, line * 48);
}

void	ft_putimgs(t_play play, t_map map)
{
	int		line;
	int		col;
	char	*mov_str;

	line = 0;
	while (line < map.mapline)
	{
		col = 0;
		while (col < map.mapcol)
		{
			ft_putimg(play, map, line, col);
			col++;
		}
		line++;
	}
	mov_str = ft_strjoin_free(ft_strdup("TOTAL MOVEMENTS: "),
			ft_itoa(play.map->mov));
	mlx_string_put(play.mlx_self, play.mlx_win, (map.mapcol / 2 - 1) * 48,
		(map.mapline - 1) * 48, 0xFFe0, mov_str);
	free(mov_str);
}

void	ft_destroy_image(t_play *play)
{
	mlx_destroy_image(play->mlx_self, play->imgs.wall.ptr);
	mlx_destroy_image(play->mlx_self, play->imgs.terrain.ptr);
	mlx_destroy_image(play->mlx_self, play->imgs.exit.ptr);
	mlx_destroy_image(play->mlx_self, play->imgs.collect.ptr);
	mlx_destroy_image(play->mlx_self, play->imgs.player_up.ptr);
	mlx_destroy_image(play->mlx_self, play->imgs.player_down.ptr);
	mlx_destroy_image(play->mlx_self, play->imgs.player_left.ptr);
	mlx_destroy_image(play->mlx_self, play->imgs.player_right.ptr);
}
