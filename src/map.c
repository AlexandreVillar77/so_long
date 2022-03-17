/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:47:09 by avillar           #+#    #+#             */
/*   Updated: 2022/03/15 15:04:46 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

//on ajoute ce que l'on vien de lire dans un string

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

//on recupere tout les contenu du fichier map pour pouvoir
// faire les verif dessus puis l'utiliser pour faire le jeu

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

//une serie de check pour savoir si la map respecte les regles imposer

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
	if (check_rectangle(*map) == 1 || samel(*map) == 1)
	{
		ft_printf("Error\nThe map is not surrounded by 1 or");
		ft_printf(" the map is not a rectangle.");
		free(map->map);
		return (1);
	}
	if (checkchar(*map) == 1)
	{
		ft_printf("Error\nThe map contains unsupported char or ");
		free(map->map);
		return (1);
	}
	if (checkchar2(*map) == 1 || p_num(map->map) == 1)
	{
		ft_printf("Error\nThe map do not contain the minimal number of exit,");
		ft_printf(" starting position, collectible, as to much starting pos,");
		ft_printf(" or/and exit.");
		free(map->map);
		return (1);
	}
	return (0);
}
