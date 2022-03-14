/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:18:27 by avillar           #+#    #+#             */
/*   Updated: 2022/03/14 11:22:47 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

t_map	failed_map(void)
{
	t_map	mapres;

	mapres.map = NULL;
	mapres.l = 0;
	mapres.h = 0;
	return (mapres);
}

void	init_map(char *map, t_map *data)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	data->size = ft_strlen(map);
	while (map[i] != '\n' && map[i])
		i++;
	data->l = i;
	while (x < data->size && map[x])
		x += i;
	data->h = x / i - 1;
	data->map = ft_strcpy(map);
	free(map);
}

void	a_free(t_mlx *data)
{
	if (data->mlx_ptr)
		free(data->mlx_ptr);
	if (data->map->map)
		free(data->map->map);
	if (data->map)
		free(data->map);
	if (data)
		free(data);
}

int	so_long(char *mapname)
{
	t_mlx	*data;
	t_map	map;

	init_map(recup_map(mapname), &map);
	if (!map.map || (valid_check(&map) == 1))
		return (1);
	data = malloc(sizeof(t_mlx));
	if (data == NULL)
		return (1);
	copymap(data, &map);
	create_mlx(data);
	if (check_wins(data) == 1)
		return (1);
	if (data->mlx_ptr == NULL)
	{
		a_free(data);
		ft_printf("Error\nerror mlx malloc\n");
		return (1);
	}
	mloop(data);
	a_free(data);
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc < 2 || !(argv[1]))
	{
		ft_putstr("Error\nGive a map name as argument.", 1);
		exit (0);
	}
	so_long(argv[1]);
	ft_printf("\n");
	return (0);
}
