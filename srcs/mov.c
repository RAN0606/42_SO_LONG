/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:32:14 by rliu              #+#    #+#             */
/*   Updated: 2022/03/23 18:17:03 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../incs/so_long.h"

void	ft_mov_updatemap(int x, int y, t_play *play)
{
	play->map->maparray[play->map->p_y][play->map->p_x] = '0';
	play->map->p_y += y;
	play->map->p_x += x;
	play->map->maparray[play->map->p_y][play->map->p_x] = 'P';
}

int	ft_mov(int x, int y, t_play *play, int keycode)
{
	char		c;
	static int	i;

	play->map->p_direct = keycode;
	c = play->map->maparray[play->map->p_y + y][play->map->p_x + x];
	if (c == 'E' && play->map->collect_nb == 0)
	{
		i++;
		ft_putstr_fd("\rMovement total: ", 1);
		ft_putnbr_fd(i, 1);
		ft_display_exit("\nWIN!", play);
	}
	else if (c != '1' && c != 'E')
	{
		i++;
		ft_putstr_fd("\rMovement total: ", 1);
		ft_putnbr_fd(i, 1);
		if (c == 'C')
			play->map->collect_nb -= 1;
		ft_mov_updatemap(x, y, play);
	}
	ft_putimgs(*play,*(play->map));
	return (0);
}

int	ft_keyhook(int keycode, t_play *play)
{	
	if (keycode == KEY_S_DOWN)
		ft_mov(0, 1, play, keycode);
	else if (keycode == KEY_D_RIGHT)
		ft_mov(1, 0, play, keycode);
	else if (keycode == KEY_W_UP)
		ft_mov(0, -1, play, keycode);
	else if (keycode == KEY_A_LEFT)
		ft_mov(-1, 0, play, keycode);
	else if (keycode == KEY_ESC)
		ft_display_exit("\nESC quit", play);
	return (0);
}

int	ft_redcross(t_play *play)
{
	ft_display_exit("\nCross quit!", play);
	return (0);
}
