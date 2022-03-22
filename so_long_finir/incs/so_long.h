/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:24:12 by rliu              #+#    #+#             */
/*   Updated: 2022/03/22 19:43:32 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"	
# include "fcntl.h"	//for open;

/**************Macros************************/

# if defined (__APPLE__) && (__MACH__)
#  define KEY_ESC 53
#  define KEY_W_UP 13
#  define KEY_A_LEFT 0
#  define KEY_S_DOWN 1
#  define KEY_D_RIGHT 2
# else
#  define KEY_ESC 65307
#  define KEY_W_UP 119
#  define KEY_A_LEFT 97
#  define KEY_S_DOWN 115
#  define KEY_D_RIGHT 100
# endif

typedef struct s_map
{
	char *maplist;
	char **maparray;
	int	mapcol;
	int	mapline;
	int	p_x;
	int	p_y;
	int	p_direct;
	int	collect_nb;
}t_map;


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
	t_img	player_up;
	t_img	player_down;
	t_img	player_left;
	t_img	player_right;
} t_img_set;

typedef struct s_play
{
    void    *mlx_self;
    void    *mlx_win;
    t_img_set	imgs;
    t_map	*map;
}t_play;

/*struct	mapcharacters
{
	int wall;
	int collect;
	int start;
	int exit;
	int place;
}mapcharacter;*/

/***********************check_map****************************/
int ft_checkmap_shape(t_map *map, int fd);
void	ft_checkmap_character_count(char c, t_map *map, int y, int x);	
int ft_checkmap_character_size(t_map *map);
void    ft_map_exit(char *message, t_map *map);
int	ft_checkmap(t_map *map, char *map_path);

#endif
