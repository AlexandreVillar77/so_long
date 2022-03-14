/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:41:50 by avillar           #+#    #+#             */
/*   Updated: 2022/03/14 13:27:47 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_lgt + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int	render_rect(t_img *img, t_rect rect)
{
	int		i;
	int		j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
		{
			img_pix_put(img, j++, i, rect.color);
		}
		++i;
	}
	return (0);
}

int	render_background(t_mlx *data)
{
	t_rect	rect;

	init_rect(&rect);
	if (make_img(FLOOR, data, &rect) == 1)
	{
		ft_printf("Error\nerror while creating the floor.");
		return (1);
	}
	while (rect.y < data->win_h)
	{
		rect.x = 0;
		while (rect.x < data->win_l)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img.mlx_img, rect.x, rect.y);
			rect.x += rect.height;
		}
		rect.y += rect.width;
	}
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	return (0);
}

int	render_owall(t_mlx *data)
{
	t_rect	rect;
	int		i;
	int		t;

	i = 0;
	t = 0;
	init_rect(&rect);
	if (make_img(WALL, data, &rect) == 1)
		return (rtnerr("wall"));
	while (data->map->map[i++])
	{
		if (data->map->map[i] == '1')
		{
			rect.x = t % data->map->l;
			rect.y = i / (data->map->l + 1);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img.mlx_img, rect.x * rect.width, rect.y * rect.width);
		}
		if (data->map->map[i] != '\n')
			t++;
	}
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	return (0);
}

int	render(t_mlx *data)
{
	if (data->win_ptr == NULL)
		return (1);
	if (data->img.mapdone == 0)
	{
		if (render_background(data) == 1 || render_owall(data) == 1
			|| render_exit(data) == 1)
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->img.mapdone = 1;
	}
	else if (data->map->p.move == 1)
	{
		if (render_collec(data) == 1 || render_player(data) == 1)
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->map->p.move = 0;
	}
	else if (check_end(data) == 1)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}
