/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:16:59 by avillar           #+#    #+#             */
/*   Updated: 2022/02/24 15:50:24 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int	handle_input(int keysim, t_mlx *data)
{
	if (keysim == ECHAP)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->mlx_ptr);
		free(data->map);
		ft_printf("succesfully exited\n");
		exit(0);
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

void	mloop(t_mlx	*data)
{
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WIN_L, WIN_H);
	mlx_key_hook(data->win_ptr, &handle_input, data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	free(data->map);
}
