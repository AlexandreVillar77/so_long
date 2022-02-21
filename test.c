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

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lgt + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int	handle_no_events(void *data)
{
	void *y;
	y = data;
	return (0);
}

int	handle_input(int keysim, t_mlx *data)
{
	(void)data;
	ft_printf("keysim = %d\n", keysim);
	if (keysim == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		//ft_printf("mlx_ptr = %p\n", data->mlx_ptr);
		free(data->mlx_ptr);
	}
	return (0);
}

int	main(void)
{
	t_mlx data;

	data.mlx_ptr = mlx_init();
	/*if (data.mlx_ptr == NULL)
		return (1);*/
	data.win_ptr = mlx_new_window(data.mlx_ptr, 920, 600, "Test");
	/*if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (1);
	}*/
	mlx_loop_hook(data.mlx_ptr, &handle_no_events, &data);
	mlx_key_hook(data.win_ptr, &handle_input, &data);
	mlx_loop(data.mlx_ptr);
	ft_printf("pass\n");
	//mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	//free(data.mlx_ptr);
	/*void	*mlx;
	void	*mlx_win;
	t_img	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 920, 600, "Hello World");
	img.img = mlx_new_image(mlx, 920, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_lgt, &img.endian);
	mlx_key_hook(mlx_win, handle_input, )
	mlx_loop(mlx);*/
}
