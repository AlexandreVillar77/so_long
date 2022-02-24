/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:41:50 by avillar           #+#    #+#             */
/*   Updated: 2022/02/24 16:19:41 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int		encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16, green << 8, blue);
}

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

int		render_background(t_img *img, int color)
{
	int		i;
	int		j;

	i = 0;
	while (i < WIN_H)
	{
		j = 0;
		while (j < WIN_L)
		{
			img_pix_put(img, j++, i,color);
		}
		++i;
	}
	return (0);
}

int		render(t_mlx *data)
{
	if (data->win_ptr == NULL)
		NULL;
	render_background(&data->img, )
}