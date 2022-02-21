/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:52:50 by avillar           #+#    #+#             */
/*   Updated: 2022/02/07 15:17:56 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"
#include <x11/keysim.h>

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lgt + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int	handle_no_events(void *data)
{
	return (0);
}

int	handle_input(int keysim, t_mlx *data)
{
	if (keysim == XK_Escape)
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 920, 600, "Hello World");
	img.img = mlx_new_image(mlx, 920, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_lgt, &img.endian);

	mlx_loop(mlx);
}
