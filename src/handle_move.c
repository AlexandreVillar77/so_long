/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 12:29:46 by avillar           #+#    #+#             */
/*   Updated: 2022/03/17 11:54:41 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

//efface le personnage pour le reafficher a son nouvel emplacement

int	erase_pos(t_mlx *data)
{
	t_rect	rect;

	init_rect(&rect);
	if (data->map->map[data->map->p.index] != 'E' &&
		make_img(FLOOR, data, &rect) == 1)
		return (1);
	if (data->map->map[data->map->p.index] != 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img,
			data->map->p.xpos * rect.width, data->map->p.ypos * rect.width);
	else if (data->map->map[data->map->p.index] == 'E')
		render_exit(data);
	if (data->map->map[data->map->p.index] != 'E')
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	return (0);
}

int	w_move(t_mlx *data)
{
	if (data->map->map[data->map->p.index - (data->map->l + 1)] != '1')
	{
		if (erase_pos(data) == 1)
			return (1);
		data->map->p.move = 1;
		data->map->p.ypos -= 1;
		data->map->p.index -= data->map->l + 1;
		data->map->p.count++;
	}
	return (0);
}

int	d_move(t_mlx *data)
{
	if (data->map->map[data->map->p.index + 1] != '1')
	{
		if (erase_pos(data) == 1)
			return (1);
		data->map->p.move = 1;
		data->map->p.xpos += 1;
		data->map->p.index++;
		data->map->p.count++;
	}
	return (0);
}

int	a_move(t_mlx *data)
{
	if (data->map->map[data->map->p.index - 1] != '1')
	{
		if (erase_pos(data) == 1)
			return (1);
		data->map->p.move = 1;
		data->map->p.xpos -= 1;
		data->map->p.index--;
		data->map->p.count++;
	}
	return (0);
}

int	s_move(t_mlx *data)
{
	if (data->map->map[data->map->p.index + (data->map->l + 1)] != '1')
	{
		if (erase_pos(data) == 1)
			return (1);
		data->map->p.move = 1;
		data->map->p.ypos += 1;
		data->map->p.count++;
		data->map->p.index += data->map->l + 1;
	}
	return (0);
}
