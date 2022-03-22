/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:11:50 by rliu              #+#    #+#             */
/*   Updated: 2022/03/22 18:41:24 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"


struct	mapcharacters
{
	int wall;
	int collect;
	int start;
	int exit;
	int place;
}mapcharacter;

void	ft_map_exit(char *message, t_map *map)
{
	ft_putstr_fd(message, 1);
	if (map->maplist)
		free(map->maplist);
	if (map->maparray)
		free(map->maparray);
	free(map);
	exit (1);
}

size_t	ft_strlen_non(char *str)
{
	size_t len;

	len = 0;
	while (str[len] != '\n' && str[len])
		len++;
	return(len);
}

int ft_checkmap_shape(t_map *map, int fd)
{
	char	*temp;

	temp = 0;
	map->maplist = ft_strdup("");
	while (fd)
	{
		temp = get_next_line(fd);
		if (!temp)
		{
			if (map->mapcol*map->mapline >= 15)
				return (1);
			ft_map_exit("Error\nMap size should be at least 4 x 4", map); 
		}
		else if (!ft_strlen_non(temp))
			ft_map_exit("Error\nEmpty line", map);
		else if (map->mapcol == 0)
			map->mapcol = ft_strlen_non(temp);
		else if (map->mapcol != ft_strlen_non(temp))
			ft_map_exit("Error\nMap size should be rectangle", map);
		map->maplist = ft_strjoin_free(map->maplist, temp);
		map->mapline += 1;
	}
	return (0);
}

void	ft_checkmap_character_count(char c, t_map *map, int y, int x)
{	
	if (c == '1')
		mapcharacter.wall++;
	else if (c =='P')
	{
	    mapcharacter.start++;
	    map->p_x = x;
	    map->p_y = y;
	}
	else if (c =='E')
		mapcharacter.exit++;
	else if (c == 'C')	
		mapcharacter.collect++;
	else if (c == '0')
		mapcharacter.place++;
	else
		ft_map_exit("Error\n Invalide character", map);
}

int ft_checkmap_character_size(t_map *map)
{
	if (mapcharacter.start < 1)
		ft_map_exit("Error\nAt least one depart!", map);
	if (mapcharacter.start > 1)
		ft_map_exit("Error\nAt most one depart!", map);
	if (mapcharacter.exit < 1)
		ft_map_exit("Error\nAt least one exit!", map);
	if (mapcharacter.collect < 1)
		ft_map_exit("Error\nAt least one collect!", map);
	return (1);
}

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
		{
			map->collect_nb = mapcharacter.collect;
			return (1);
		}
	}
	return(0);
}

/*int	main(int argc, char **argv)
{
	t_map	*map;

	map = ft_calloc(1,sizeof(t_map));
	if (ft_checkmap(map,argv[1]))
	{
		printf("finalt:%s col:%d line:%d\n", map->maplist, map->mapcol, map->mapline);
		int i=0;
		while(map->maparray[i])
		{
			int j=0;
			while (map->maparray[i][j])
			{
				printf("%c",map->maparray[i][j]);
				j++;
			}
			i++;
			printf("\n");
		}
	}
	
}*/