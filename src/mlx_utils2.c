/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:41:50 by avillar           #+#    #+#             */
/*   Updated: 2022/03/01 16:10:00 by avillar          ###   ########.fr       */
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
	int		i;
	int		j;
	void	*img1;
	int		imgWidth;
	int		imgHeight;

	i = 0;
	img1 = mlx_xpm_file_to_image(&data->mlx_ptr, "../floor_2.xpm", &imgWidth, &imgHeight);
	while (i < WIN_H)
	{
		j = 0;
		while (j < WIN_L)
		{
			mlx_put_image_to_window(&data->mlx_ptr, &data->win_ptr, &img1, i, j++);
		}
		++i;
	}
	return (0);
}

int		render(t_mlx *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_background(data);
	render_rect(&data->img, (t_rect){WIN_L - 100, WIN_H - 100,
		100, 100, GREEN});
	render_rect(&data->img, (t_rect){0, 0, 500, 300, RED});

	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}