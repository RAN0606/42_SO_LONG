/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:24:12 by rliu              #+#    #+#             */
/*   Updated: 2022/03/18 20:44:21 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <unistd.h>
# include <stdio.h>
# include "libft.h"	
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
}t_map;

/*************************************************************/
void    ft_map_exit(char *message, t_map *map);
int	ft_checkmap(t_map *map, char *map_path);

#endif

/*tpyedef struct s_play
{
    void    *mlx_self;
    void    *mlx_win;

} t_play;*/
