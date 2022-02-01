/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:52:50 by avillar           #+#    #+#             */
/*   Updated: 2022/01/12 16:01:32 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"


int main()
{
    
    void    *mlx;
    void    *mlx_win;
    
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 900, 600, "Hello World");
    mlx_loop(mlx);
}