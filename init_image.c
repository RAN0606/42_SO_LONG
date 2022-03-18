/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:32:14 by rliu              #+#    #+#             */
/*   Updated: 2022/03/18 15:33:24 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#include "mlx.h"
typedef struct s_img
{
	void	*ptr;
	int		*w; //width of img
	int		*h;//height of img
} t_img;

typedef struct s_img_set
{
	t_img	wall;
	t_img	floor;
	t_img	collcet;
	t_img	exit;
	t_img	start;
	t_img	spirit;
} t_img_set;

typedef struct s_play
{
    void    *mlx_self;
    void    *mlx_win;
	t_img_set	imgs;
	int		x;
	int		y;
} t_play;

void ft_init_image(t_play play)
{	
	char	path[] = "img_48/Purple.xpm";
	play.imgs.wall.ptr = mlx_xpm_file_to_image(play.mlx_self, path, play.imgs.wall.w, play.imgs.wall.h);	
/*	play.imgs.floor.ptr = mlx_xpm_file_to_image(play.mlx_self, relative_path2, &(play.img_width2), &(play.img_height2));	
	play.imgs.collect.ptr = mlx_xpm_file_to_image(play.mlx_self, relative_path2, &(play.img_width2), &(play.img_height2));	
	play.imgs.exit.ptr = mlx_xpm_file_to_image(play.mlx_self, relative_path2, &(play.img_width2), &(play.img_height2));	
	play.imgs.start.ptr = mlx_xpm_file_to_image(play.mlx_self, relative_path2, &(play.img_width2), &(play.img_height2));		
	play.imgs.spirit.ptr = mlx_xpm_file_to_image(play.mlx_self, relative_path2, &(play.img_width2), &(play.img_height2));*/
}

int	main(void)
{
	t_play	play;
//	t_map	map;
//	char	relative_path1[] = "../sprit_cat/down_2.xpm";
//	char	relative_path2[] = "../img/Jump.xpm";

	play.x = 0;
	play.y = 0;
	play.mlx_self = mlx_init();
	ft_init_image(play);
//	play.img1 = mlx_xpm_file_to_image(play.mlx_self, relative_path1, &(play.img_width1), &(play.img_height1));
//	play.img2 = mlx_xpm_file_to_image(play.mlx_self, relative_path2, &(play.img_width2), &(play.img_height2));	
//	win_x = (play.img_width-1) * 9;
//	win_y = (play.img_height-1) * 4;
	play.mlx_win = mlx_new_window(play.mlx_self, 900, 400, "so_long");
	mlx_put_image_to_window(play.mlx_self, play.mlx_win, play.imgs.wall.ptr, 0, 0);	
//	mlx_put_image_to_window(play.mlx_self, play.mlx_win, play.img2, 0, 0);

//	printf("size: %d", mlx_get_screen_size(play.mlx_self, &win_xi, &win_y));
	//mlx_put_image_to_window(play.mlx_self, play.mlx_win, play.img, play.x, play.y);
//	ft_putimg_set(play);
//	mlx_key_hook(play.mlx_win, ft_keyhook, &play);
//	mlx_mouse_get_pos(mlx, mlx_win, &img_width, &img_height);	
	mlx_loop(play.mlx_self);
}
