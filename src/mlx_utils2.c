/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:41:50 by avillar           #+#    #+#             */
/*   Updated: 2022/03/03 13:47:12 by avillar          ###   ########.fr       */
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
	int		x;
	int		y;

	int		imgWidth;
	int		imgHeight;

	x = 0;
	y = 0;
		ft_printf("here\n");

	data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "../test.xpm", &imgWidth, &imgHeight);
		ft_printf("here\n");

	if (data->img.mlx_img == NULL)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		return (1);
	}
	data->img.addr = mlx_get_data_addr(&data->img.mlx_img, &data->img.bpp, &data->img.line_lgt, &data->img.endian);
	while (x < WIN_H)
	{
		y = 0;
		while (y < WIN_L)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, y, x);
			y += imgHeight;
		}
		x += imgWidth;
	}
	return (0);
}

int		render(t_mlx *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_background(data);
	/*render_rect(&data->img, (t_rect){WIN_L - 100, WIN_H - 100,
		100, 100, GREEN});
	render_rect(&data->img, (t_rect){0, 0, 500, 300, RED});
*/
	return (0);
}