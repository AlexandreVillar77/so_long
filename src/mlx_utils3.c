/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:16:30 by avillar           #+#    #+#             */
/*   Updated: 2022/03/10 13:19:29 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int		render_player(t_mlx *data)
{
	t_rect	rect;

	init_rect(&rect);

	if (make_img(PLAYER, data, &rect) == 1)
	{
		ft_printf("Erreur lors de la creation du personnage.");
		return (1);
	}
	if (data->map->map[data->map->p.index] == 'C')
	{
		data->map->map[data->map->p.index] = '0';
		data->map->p.collected++;
	}
	ft_printf("move = %d,	map = %c\n", data->map->p.count, data->map->map[data->map->p.index]);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, data->map->p.xpos * rect.width, data->map->p.ypos * rect.width);
	return (0);
}

int		render_collec(t_mlx *data)
{
	t_rect	rect;
	int		i;
	int		t;

	i = 0;
	t = 0;
	init_rect(&rect);
	if (make_img(COLLEC, data, &rect) == 1)
	{
		ft_printf("Erreur lors de la creation de la texture des collectibles.");
		return (1);
	}
	while (data->map->map[i])
	{
		if (data->map->map[i] == 'C')
		{
			rect.x = t  % data->map->l;
			rect.y = i / data->map->l;
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, rect.x * rect.width, rect.y * rect.width);
		}
		if (data->map->map[i] != '\n')
			t++;
		i++;
	}
	return (0);
}

int		render_owall(t_mlx *data)
{
		t_rect	rect;
	int		i;
	int		t;

	i = 0;
	t = 0;
	init_rect(&rect);
	if (make_img(WALL, data, &rect) == 1)
	{
		ft_printf("Erreur lors de la creation de la texture des collectibles.");
		return (1);
	}
	while (data->map->map[i])
	{
		if (data->map->map[i] == '1')
		{
			rect.x = t  % data->map->l;
			rect.y = i / data->map->l;
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, rect.x * rect.width, rect.y * rect.width);
		}
		if (data->map->map[i] != '\n')
			t++;
		i++;
	}
	return (0);
}