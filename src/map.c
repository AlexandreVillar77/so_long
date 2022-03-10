/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:47:09 by avillar           #+#    #+#             */
/*   Updated: 2022/03/10 16:27:28 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

char	*checkbuf(char *buf, char *keep)
{
	char	*tmp;

	if (keep == NULL)
	{
		keep = malloc(sizeof(char));
		if (!keep)
			exit(0);
		keep[0] = '\0';
	}
	tmp = ft_strcpy(keep);
	free(keep);
	keep = ft_strcat(buf, tmp);
	free(tmp);
	return (keep);
}

char	*recup_map(char *map)
{
	int		fd;
	char	*buf;
	char	*mapres;
	int		i;

	fd = recup_fd(map);
	if (fd == 0)
		exit(0);
	buf = malloc(sizeof(char) + 1);
	if (!buf)
		exit(0);
	i = read(fd, buf, 1);
	mapres = NULL;
	while ((i > 0) && buf)
	{
		buf[i] = '\0';
		mapres = checkbuf(buf, mapres);
		i = read(fd, buf, 1);
	}
	close (fd);
	free (buf);
	return (mapres);
}

int	check_border(t_map map, int x)
{
	while (map.map[x] != '\n' && map.map[x])
	{
		if (map.map[x] != '1')
		{
			return (1);
		}
		x++;
	}
	return (0);
}

int	check_rectangle(t_map map)
{
	int	x;

	x = 0;
	if (check_border(map, 0) == 1)
		return (1);
	while (x < map.size && map.map[x])
	{
		if (map.map[x] != '1')
			return (1);
		x = x + map.l - 1;
		if (map.map[x] != '1' && map.map[x])
			return (1);
		x += 2;
	}
	if (check_border(map, (map.l + 1) * (map.h - 1)) == 1)
		return (1);
	return (0);
}

int	valid_check(t_map *map)
{
	if (sameL(*map) == 1)
	{
		ft_printf("Error\nla map n'est pas rectangulaire\n");
		free(map->map);
		return (1);
	}
	if (check_rectangle(*map) == 1)
	{
		ft_printf("Error\nla map n'est pas fermer par des 1 de tout les côté\n");
		free(map->map);
		return (1);
	}
	if (checkchar(*map) == 1)
	{
		ft_printf("Error\nla map n'est pas composer avec les cractères autoriser\n");
		free(map->map);
		return (1);
	}
	if (checkchar2(*map) == 1)
	{
		ft_printf("Error\nla map ne dispose pas du minimum de sortie,");
		ft_printf("collectible et point depart requis\n");
		free(map->map);
		return (1);
	}
	return (0);
}
