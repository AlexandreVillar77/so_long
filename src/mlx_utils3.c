/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:16:30 by avillar           #+#    #+#             */
/*   Updated: 2022/03/14 13:29:18 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int	render_player(t_mlx *data)
{
	t_rect	rect;

	init_rect(&rect);
	if (make_img(PLAYER, data, &rect) == 1)
	{
		ft_printf("Error\nerror while creating the character.");
		return (1);
	}
	if (data->map->map[data->map->p.index] == 'C')
	{
		data->map->map[data->map->p.index] = '0';
		data->map->p.collected++;
	}
	ft_printf("move = %d\n", data->map->p.count);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img,
		data->map->p.xpos * rect.width, data->map->p.ypos * rect.width);
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	return (0);
}

int	render_collec(t_mlx *data)
{
	t_rect	rect;
	int		i;
	int		t;

	i = 0;
	t = 0;
	init_rect(&rect);
	if (make_img(COLLEC, data, &rect) == 1)
		return (rtnerr("Collectibles"));
	while (data->map->map[i++])
	{
		if (data->map->map[i] == 'C')
		{
			rect.x = t % data->map->l;
			rect.y = t / data->map->l;
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img.mlx_img, rect.x * rect.width, rect.y * rect.width);
		}
		if (data->map->map[i] != '\n')
			t++;
	}
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	return (0);
}

int	render_exit(t_mlx *data)
{
	t_rect	rect;
	int		i;
	int		t;

	t = 0;
	i = 0;
	init_rect(&rect);
	if (make_img(EXIT, data, &rect) == 1)
		return (1);
	while (data->map->map[i] && data->map->map[i] != 'E')
	{
		if (data->map->map[i] != '\n')
			t++;
		i++;
	}
	rect.x = t % data->map->l;
	rect.y = t / data->map->l;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img,
		rect.x * rect.width, rect.y * rect.width);
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	return (0);
}

int	check_end(t_mlx *data)
{
	if (data->map->p.collected == data->map->c_nb
		&& (data->map->map[data->map->p.index] == 'E'))
	{
		ft_printf("You successfully finish the game GGWP!");
		return (1);
	}
	return (0);
}

int	rtnerr(char *str)
{
	ft_printf("Error\nerror while making %s.", str);
	return (1);
}
