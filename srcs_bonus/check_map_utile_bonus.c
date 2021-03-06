/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utile_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:11:50 by rliu              #+#    #+#             */
/*   Updated: 2022/03/24 11:25:12 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../incs/so_long_bonus.h"

struct s_mapcharacters
{
	int	wall;
	int	collect;
	int	start;
	int	exit;
	int	place;
}mapcharacter;

size_t	ft_strlen_non(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\n' && str[len])
		len++;
	return (len);
}

void	ft_free_temp_exit(char *temp, t_map *map)
{
	if (!ft_strlen_non(temp))
	{
		free (temp);
		ft_map_exit("Error\nEmpty line", map);
	}
	if (map->mapcol != ft_strlen_non(temp))
	{
		free(temp);
		ft_map_exit("Error\nMap size should be rectangle", map);
	}
}

int	ft_checkmap_shape(t_map *map, int fd)
{
	char	*temp;

	temp = 0;
	map->maplist = ft_strdup("");
	while (fd)
	{
		temp = get_next_line(fd);
		if (!temp)
		{
			if (map->mapcol * map->mapline >= 15)
				return (1);
			ft_map_exit("Error\nMap size should be at least >=15", map);
		}
		else if (map->mapcol == 0)
			map->mapcol = ft_strlen_non(temp);
		else
			ft_free_temp_exit(temp, map);
		map->maplist = ft_strjoin_free(map->maplist, temp);
		map->mapline += 1;
	}
	return (0);
}

void	ft_checkmap_character_count(char c, t_map *map, int y, int x)
{	
	if (c == '1')
		mapcharacter.wall++;
	else if (c == 'P')
	{
		mapcharacter.start++;
		map->p_x = x;
		map->p_y = y;
	}
	else if (c == 'E')
		mapcharacter.exit++;
	else if (c == 'C')
		mapcharacter.collect++;
	else if (c == '0')
		mapcharacter.place++;
	else
		ft_map_exit("Error\nInvalide character", map);
}

int	ft_checkmap_character_size(t_map *map)
{
	if (mapcharacter.start < 1)
		ft_map_exit("Error\nAt least one depart!", map);
	if (mapcharacter.start > 1)
		ft_map_exit("Error\nAt most one depart!", map);
	if (mapcharacter.exit < 1)
		ft_map_exit("Error\nAt least one exit!", map);
	if (mapcharacter.collect < 1)
		ft_map_exit("Error\nAt least one collect!", map);
	map->collect_nb = mapcharacter.collect;
	return (1);
}
