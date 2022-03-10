/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:18:27 by avillar           #+#    #+#             */
/*   Updated: 2022/03/10 13:17:05 by avillar          ###   ########.fr       */
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
	while (map[i] != '\n')
		i++;
	data->l = i;
	while (map[x])
		x += i;
	data->h = x / i - 1;
	data->map = ft_strcpy(map);

	free (map);
}

int	so_long(char *mapname)
{
	t_mlx	*data;
	t_map	map;

	data = malloc(sizeof(t_mlx));
	if (data == NULL)
		return (1);
	init_map(recup_map(mapname), &map);
	if (!map.map)
		return (1);
	copymap(data, &map);
	create_mlx(data);
	if (check_wins(data) == 1)
		return (1);
	if (data->mlx_ptr == NULL || data->win_ptr == NULL)
	{
		ft_printf("\nerreur malloc mlx\n");
		return (1);
	}
	data->img.mapdone = 0;
	mloop(data);
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc < 2 || !(argv[1]))
	{
		ft_putstr("veuillez renseigner le nom d'une map.\n", 1);
		exit (0);
	}
	so_long(argv[1]);
	ft_printf("\n");
	return (0);
}
