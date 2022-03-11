/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:14:24 by rliu              #+#    #+#             */
/*   Updated: 2022/03/11 14:31:55 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int check_mapname(char *mapname)
{
	size_t	len;
	char	*str;

	str = 0;
	len = 0;
	str = ft_strrcher(mapname, '.');
	if (str)
	{
		len = ft_strrchr(str);
		if (ft_memcmp(str, ".ber", len) == 0)
			return (1);
	}
	else
		write()
	return (0);
}

int check_map()

int	main(int argc, char **argv)
{
	t_play	play_sl;
	
	if (argc == 2 && check_mapname(argv[1]))
	{

		init_map()

	}	


	
	

}
