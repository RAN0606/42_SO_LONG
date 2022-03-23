/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:32:14 by rliu              #+#    #+#             */
/*   Updated: 2022/03/23 17:55:03 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	ft_map_exit(char *message, t_map *map)
{
	int	i;

	i = 0;
	ft_putstr_fd(message, 1);
	if (map->maplist)
		free(map->maplist);
	if (map->maparray)
	{
		while (i < map->mapline)
		{
			free(*(map->maparray + i));
			i++;
		}
		free(map->maparray);
	}
	free(map);
	exit (1);
}

void	ft_display_exit(char *message, t_play *play)
{
	ft_destroy_image(play);
	mlx_destroy_window(play->mlx_self, play->mlx_win);
	mlx_destroy_display(play->mlx_self);
	free(play->mlx_self);
	ft_map_exit(message, play->map);
}

void	ft_init_display(t_play *play, t_map *map)
{
	int	screen_l;
	int	screen_h;

	play->mlx_self = mlx_init();
	mlx_get_screen_size(play->mlx_self, &screen_l, &screen_h);
	if (map->mapcol * 48 > screen_l || map->mapline * 48 > screen_h)
	{
		free(play->mlx_self);
		ft_map_exit("Error\nMapsize is too big for this screen!", map);
	}
	play->mlx_win = mlx_new_window(play->mlx_self,
			map->mapcol * 48, map->mapline * 48, "./so_long");
	play->imgs = ft_init_imgs(play->mlx_self);
}

int	main(int argc, char **argv)
{
	t_play	play;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nInvalide args number!", 1);
		exit(1);
	}
	if (!ft_checkmap_mapname(argv[1]))
	{
		ft_putstr_fd("Error\nInvalide file type!", 1);
		exit(1);
	}
	play.map = ft_calloc(1, sizeof(t_map));
	ft_checkmap(play.map, argv[1]);
	ft_init_display(&play, play.map);
	ft_putimgs(play, *(play.map));
	mlx_key_hook(play.mlx_win, ft_keyhook, &play);
	mlx_hook(play.mlx_win, RED_CROSS, 1L << 2, ft_redcross, &play);
	mlx_loop(play.mlx_self);
}
