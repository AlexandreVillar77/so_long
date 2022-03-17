/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:31:38 by avillar           #+#    #+#             */
/*   Updated: 2022/03/15 15:03:36 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

//la fonction qui check ou en ai la recolte de collectible

int	check_wins(t_mlx *data)
{
	int		l;
	int		h;

	mlx_get_screen_size(data->mlx_ptr, &l, &h);
	if (data->win_l > l || data->win_h > h)
	{
		ft_printf("The map is to big please respect max size of %dx%d",
			l / 64, h / 64);
		a_free(data);
		return (1);
	}
	return (0);
}

// recuperation de l'emplacement du joueur sur la map pour 
//l'afficher dans la window selon les axe x et y

int	player_posx(t_mlx *data)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (data->map->map[i] && data->map->map[i] != 'P')
	{
		if (data->map->map[i] == '\n')
			res--;
		i++;
	}
	res = (i + res) % data->map->l;
	return (res);
}

// permet de trouver l'index au quel se trouve le joueur

int	p_find(t_mlx *data)
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

// on initialise la structure du joueur dans la strucutre mlx

void	init_player(t_mlx *data)
{
	int		width;
	int		height;

	width = 0;
	height = 0;
	data->map->p.index = p_find(data);
	data->map->p.move = 1;
	data->map->p.count = 0;
	data->map->p.xpos = player_posx(data);
	data->map->p.ypos = player_posy(data);
	data->map->p.collected = 0;
	data->map->p.img = NULL;
}

// permet de compter le nombre de collectible sur la map pour savoir
//combien le player doit en recolter

int	count_c(char *map)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (map[i])
	{
		i++;
		if (map[i] == 'C')
			res++;
	}
	return (res);
}
