/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:52:50 by avillar           #+#    #+#             */
/*   Updated: 2022/03/08 12:36:48 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int	handle_no_event(t_mlx *data)
{
	(void)data;
	return (0);
}

int	handle_input(int keysim, t_mlx *data)
{
	ft_printf("keysim = %d\n", keysim);
	if (keysim == ECHAP)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_loop_end(data->mlx_ptr);
		//free(data->mlx_ptr);
		//ft_printf("succesfully exited\n");
		//exit(0);
	}
	return (0);
}

void	create_mlx(t_mlx *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return ;
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_L, WIN_H, G_NAME);
	if (data->win_ptr == NULL)
	{
		free (data->mlx_ptr);
		return ;
	}
}

int		render_background(t_mlx *data)
{
	int		x;
	int		y;
	int		imgWidth;
	int		imgHeight;

	x = 0;
	y = 0;
	data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./floor.xpm", &imgWidth, &imgHeight);
	if (data->img.mlx_img == NULL)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		return (0);
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

void	mloop(t_mlx	*data)
{
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WIN_L, WIN_H);
	mlx_loop_hook(data->mlx_ptr, &render_background, data);
	//mlx_loop_hook(data->mlx_ptr, &handle_no_event, data);
	mlx_key_hook(data->win_ptr, &handle_input, data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	ft_printf("succesfully exited\n");
}

int	main(void)
{
	t_mlx	data;

	create_mlx(&data);
	if (data.mlx_ptr == NULL || data.win_ptr == NULL)
	{
		ft_printf("\nerreur malloc mlx\n");
		return (1);
	}
	mloop(&data);
	return (0);
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
