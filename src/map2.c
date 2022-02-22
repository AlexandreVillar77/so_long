/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:10:51 by avillar           #+#    #+#             */
/*   Updated: 2022/02/02 14:31:53 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int	sameL(t_map map)
{
	int	x;
	int	i;

	x = 0;
	while (x < ft_strlen(map.map))
	{
		i = 0;
		while (map.map[x + i] != '\n' && map.map[x + i] != '\0')
			i++;
		if (i != map.l)
			return (1);
		x = x + map.l + 1;
	}
	return (0);
}

int	checkchar(t_map map)
{
	int	x;
	int	size;

	x = 0;
	size = ft_strlen(map.map);
	while (x < size && map.map[x])
	{
		if (map.map[x] != '1' && map.map[x] != '0' && map.map[x] != '\n'
			&& map.map[x] != 'P' && map.map[x] != 'E' && map.map[x] != 'C')
		{
			printf("x = %d\n", x);
			return (1);
		}
		x++;
	}
	return (0);
}

int	checkchar2(t_map map)
{
	int	x;

	x = 0;
	while (map.map[x++])
		if (map.map[x] == 'E')
			break ;
	if (x >= ft_strlen(map.map))
		return (1);
	x = 0;
	while (map.map[x++])
		if (map.map[x] == 'C')
			break ;
	if (x >= ft_strlen(map.map))
		return (1);
	x = 0;
	while (map.map[x])
	{
		if (map.map[x] == 'P')
			break ;
		x++;
	}
	if (x >= ft_strlen(map.map))
		return (1);
	return (0);
}

int	recup_fd(char *map)
{
	int	fd;

	errno = 0;
	fd = open(map, O_RDWR);
	if (errno > 0)
	{
		close(fd);
		perror("Error ");
		ft_putchar('\n', 1);
		return (0);
	}
	return (fd);
}