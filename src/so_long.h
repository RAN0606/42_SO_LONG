/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:24:12 by rliu              #+#    #+#             */
/*   Updated: 2022/03/11 12:38:51 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>

/**************Macros************************/

# if defined (__APPLE__) && (__MACH__)
#  define KEY_ESC 53
#  define KEY_W_UP 13
#  define KEY_A_LEFT 0
#  define KEY_S_DOWN 1
#  define key_D_RIGHT 2
# else
#  define KEY_ESC 65307
#  define KEY_W_UP 119
#  define KEY_A_LEFT 97
#  define KEY_S_DOWN 115
#  define key_D_RIGHT 100
# endif

tpyedef struct s_play
{
    void    *mlx_self;
    void    *mlx_win;

} t_play;
