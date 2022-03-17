/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:32:14 by rliu              #+#    #+#             */
/*   Updated: 2022/03/17 19:32:21 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
typedef struct s_img
{
	char	*img_path;
	char	*ptr;
	int		width;
	int		height;
} t_img;

typedef struct s_img_set
{
	t_img	wall;
	t_img	floor;
	t_img	collcet;
	t_img	sprit;
	t_img	exit;
} t_img_set;

typedef struct s_play
{
    void    *mlx_self;
    void    *mlx_win;
	img_set	imgs;
	int		x;
	int		y;

} t_play;
void ft_init_image(s_play play)
{
	imgs.sprit.ptr

	
	
}
