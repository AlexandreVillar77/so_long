/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:16:59 by avillar           #+#    #+#             */
/*   Updated: 2022/03/17 18:17:23 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

//on gere l'action a executer en fonction de la touche presser

int	handle_input(int keysim, t_mlx *data)
{
	if (keysim == ECHAP)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		ft_printf("Successfully exited");
		mlx_loop_end(data->mlx_ptr);
	}
	if (keysim == W)
		return (w_move(data));
	else if (keysim == D)
		return (d_move(data));
	else if (keysim == A)
		return (a_move(data));
	else if (keysim == S)
		return (s_move(data));
	return (0);
}

//ici on cree la structure de notre mlx

int	create_mlx(t_mlx *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		a_free(data);
		ft_printf("Error\nMLX error");
		return (1);
	}
	data->win_ptr = (mlx_new_window(data->mlx_ptr, data->win_l,
				data->win_h, G_NAME));
	if (data->win_ptr == NULL)
	{
		a_free(data);
		ft_printf("Error\nMLX error");
		return (1);
	}
	data->img.mapdone = 0;
	init_player(data);
	return (0);
}

// la fonction qui nous permet de passer nos fichiers xpm en image

int	make_img(char *xpm, t_mlx *data, t_rect *rect)
{
	int		width;
	int		height;

	width = 0;
	height = 0;
	data->img.mlx_img = (mlx_xpm_file_to_image(data->mlx_ptr,
				xpm, &width, &height));
	if (data->img.mlx_img == NULL)
	{
		if (data->win_ptr)
		{
			mlx_clear_window(data->mlx_ptr, data->win_ptr);
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		}
		return (1);
	}
	rect->height = height;
	rect->width = width;
	return (0);
}

// creation de la structure rect qui contiens les donnes 
// permettant de bien positionner nos image dans la window

void	init_rect(t_rect *rect)
{
	rect->x = 0;
	rect->y = 0;
	rect->width = 0;
	rect->height = 0;
	rect->color = 0;
}

// la fonciton qui execute la mlx_loop

void	mloop(t_mlx	*data)
{
	mlx_hook(data->win_ptr, 17, 0, &prog_leaver, data);
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_key_hook(data->win_ptr, &handle_input, data);
	if (data->win_ptr && data->mlx_ptr)
		mlx_loop(data->mlx_ptr);
	mlx_destroy_display(data->mlx_ptr);
}
