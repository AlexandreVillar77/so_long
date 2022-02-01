/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:00:43 by avillar           #+#    #+#             */
/*   Updated: 2022/01/18 13:10:58 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

t_map   failed_map()
{
    t_map   mapres;

    mapres.map = NULL;
    mapres.L = 0;
    mapres.H = 0;
    return (mapres);
}

t_map   init_map(char *map)
{
    int     i;
    int     x;
    t_map   mapres;
    i = 0;
    x = 0;

    while(map[i] != '\n')
        i++;
    mapres.L = i;
    while(map[x])
        x+=i;
    mapres.H = x / i - 1;
    mapres.map = malloc(sizeof(char) * ft_strlen(map) + 1);
    if (!mapres.map)
        return (failed_map());
    mapres.map = ft_strcpy(map);
    return (mapres);
}

int so_long(char *mapname)
{
    t_map   map;

    map = init_map(recup_map(mapname));
    printf("retour du check %d \n",valid_check(map));
    printf("ma map = \n%s", map.map);
    return (0);
}

int main(int argc, char **argv)
{
    int     i;

    i = 0;
    if (argc < 2)
    {
        ft_putstr("veuillez renseigner le nom d'une map.\n", 1);
        //exit (0);
    }
    //so_long(argv[1]);
    // test de mlx
    (void)argv;
    void    *mlx;
    void    *mlx_win;
    //			gcc -L/usr/X11/include/../lib -lXext -lX11 -lmlx -o $@ $^
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 900, 600, "Hello World");
    mlx_loop(mlx);
}