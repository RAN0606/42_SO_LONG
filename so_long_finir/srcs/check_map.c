/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:11:50 by rliu              #+#    #+#             */
/*   Updated: 2022/03/22 19:44:04 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../incs/so_long.h"

int ft_checkmap_character(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->mapline)
	{
		j = 0;
		while (j < map->mapcol)
		{
			ft_checkmap_character_count(map->maparray[i][j], map, i,j);
			if ((i == 0 || i == map->mapline - 1 || j == 0 || j == map->mapcol - 1)
					&& map->maparray[i][j] != '1')
				ft_map_exit("Error\n 4 sides of map should be the wall", map);
			j++;
		}
		i++;
	}
	if (ft_checkmap_character_size(map))
		return (1);
	return (0);
}

int ft_checkmap(t_map *map, char *map_path)
{
	int		fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		ft_map_exit("Error\n Invalid file\n", map);
	else if (ft_checkmap_shape(map,fd))
	{
		map->maparray = ft_split(map->maplist,'\n');  // split the mapstring to one array;
		if (!map->maparray)
			ft_map_exit("Error\nMaparray invalid", map); 
		if (ft_checkmap_character(map))
			return (1);
	}
	return(0);
}
