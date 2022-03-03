/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:41:50 by avillar           #+#    #+#             */
/*   Updated: 2022/03/03 16:05:51 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

/*int		encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16, green << 8, blue);
}*/

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char *pixel;
	
	pixel = img->addr + (y * img->line_lgt + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int		render_rect(t_img *img, t_rect rect)
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

int		render_background(t_mlx *data)
{
	t_rect	rect;

	init_rect(&rect);
	if (make_img("../floor.xpm", data, &rect) == 1)
		return (1);
	while (rect.y < WIN_H)
	{
		rect.x = 0;
		while (rect.x < WIN_L)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, rect.x, rect.y);
			rect.x += rect.height;
		}
		rect.y += rect.width;
	}
	return (0);
}

int		render_wall(t_mlx *data)
{
	t_rect	rect;

	init_rect(&rect);
	if (make_img("../wall.xpm", data, &rect) == 1)
		return (1);
	while (rect.x < WIN_L)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, rect.x, rect.y);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, rect.x, (WIN_H - rect.height));
		rect.x += rect.width;
	}
	while (rect.y < WIN_H)
	{
		rect.y += WIN_H;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, rect.x, rect.y);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, rect.y);
	}
	return (0);
}

int		render(t_mlx *data)
{
	if (data->win_ptr == NULL)
		return (1);
	if (render_background(data) == 1)
	{
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
			return (1);
	}
	render_wall(data);
	/*render_rect(&data->img, (t_rect){WIN_L - 100, WIN_H - 100,
		100, 100, GREEN});
	render_rect(&data->img, (t_rect){0, 0, 500, 300, RED});
*/
	return (0);
}