/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:11:50 by rliu              #+#    #+#             */
/*   Updated: 2022/03/16 18:49:01 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

size_t	ft_strlen_non(char *str)
{
	size_t len;

	len = 0;
	while (str[len] != '\n' && str[len])
		len++;
	return(len);
}

int ft_checkmap_size(t_map *map, char *map_path)
{
	int		fd;
	char	*temp;

	temp = 0;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		printf("File error: fd does not exist!");
		exit (1);
	}
	while (fd)
	{
		temp = get_next_line(fd);
		if (!temp )
		{
			if (!map->mapcol)
			{
				printf ("empty map or read map fail\n");
				return(0);
			}
			return(1);
		}
//		printf("%s", temp);
//		free(temp);
//		else
//		{
		if (map->mapcol == 0)
		{
			map->mapcol = ft_strlen_non(temp);
			map->maplist = ft_strjoin_free(map->maplist, temp);
		}
		else if (map->mapcol == ft_strlen_non(temp))
			map->maplist = ft_strjoin_free(map->maplist, temp);
		else
		{
				printf("not right size");	
				return(0);
		}
			map->mapline += 1;
//		}
	}
	return (0);
}

int ft_checkmap_c(t_map *map)
{
	int i;
	int j;
	int depart = 0;
	int exit = 0;
	int collect = 0;

	i = 0;
	map->maparray = ft_split(map->maplist,'\n');
	if (!map->maparray)
		return (0);
	while (i < map->mapline)
	{
		j = 0;
		while (j < map->mapcol)
		{
			if (map->maparray[i][j] != 'E' && map->maparray[i][j] != '1' 
					&& map->maparray[i][j] != '0' && map->maparray[i][j] != 'P' && map->maparray[i][j] !='C')
			{
				printf("Error\n the character is not defined");
				return (0);
			}
			else if ((i == 0 || i == map->mapline - 1 || j == 0 || j == map->mapcol - 1) 
				&& map->maparray[i][j] != '1')
			{
				printf("Error\n this place should be the wall");
				return (0);
			}
			else if (map->maparray[i][j] == 'P')
				depart++;
			else if (map->maparray[i][j] == 'E')
				exit++;
			else if (map->maparray[i][j] == 'C')
				collect++;
			j++;
		}
		i++;
	}
	if (!depart || !exit || !collect)
	{
		printf("Error\n at least one item, one exit, and one collect, please check your map!");
		return (0);
	}
	return (1);
}

/*int	main(int argc, char **argv)
{
	t_map	*map;

	map = ft_calloc(1,sizeof(t_map));
	
	map->maplist = ft_strdup("");
	ft_checkmap_size(map, argv[1]);
	ft_checkmap_c(map);
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
	
}*/

