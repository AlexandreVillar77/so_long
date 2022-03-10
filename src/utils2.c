/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:31:38 by avillar           #+#    #+#             */
/*   Updated: 2022/03/10 13:08:50 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int		check_wins(t_mlx *data)
{
	int		l;
	int		h;

	mlx_get_screen_size(data->mlx_ptr, &l, &h);
	if (data->win_l > l || data->win_h > h)
	{
		ft_printf("La map est trop grande merci de respecter une taille max de %dx%d", l/64, h/64);
		free(data->map);
		free(data->mlx_ptr);
		return (1);
	}
	return (0);
}

int		player_pos(t_mlx *data, char c)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	if (c == 'x')
	{
		while (data->map->map[i] && data->map->map[i] != 'P')
		{
			if (data->map->map[i] == '\n')
				res--;
			i++;
		}
		res += i % data->map->l;

	}
	else if (c == 'y')
	{
		while (data->map->map[i] && data->map->map[i] != 'P')
		{
			res = i / (data->map->l + 1);
			i++;
		}
	}
	return (res);
}

int		p_find(t_mlx *data)
{
	int		i;
	int		res;

	res = 0;
	i = 0;
	while (data->map->map[i] && data->map->map[i] != 'P')
	{
		if (data->map->map[i] != '\n')
			res++;
		i++;
	}
	return (i);
}

void	init_player(t_mlx *data)
{
	int		width;
	int		height;

	width = 0;
	height = 0;
	data->map->p.index = p_find(data);
	data->map->p.move = 1;
	data->map->p.count = 0;
	data->map->p.xpos = player_pos(data, 'x');
	data->map->p.ypos = player_pos(data, 'y');
	data->map->p.collected = 0;
	data->map->p.img = NULL;
}