/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:30:12 by avillar           #+#    #+#             */
/*   Updated: 2022/01/06 13:14:23 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int sameL(t_map map)
{
    int x;
    int i;
    
    x = 0;
    while (x < ft_strlen(map.map))
    {
        i = 0;
        while (map.map[x + i] != '\n' && map.map[x + i] != '\0')
            i++;
        if (i != map.L)
            return (1);
        x = x + map.L + 1;
    }
    return (0);
}

int checkchar(t_map map)
{
    int x;
    int size;
    
    x = 0;
    size = ft_strlen(map.map);
    while (x < size && map.map[x])
    {
        if (map.map[x] != '1' && map.map[x] != '0' && map.map[x] != '\n'
            && map.map[x] != 'P' && map.map[x] != 'E' && map.map[x] != 'C')
        {
            printf("x = %d\n", x);
            return (1);
        }
        x++;
    }
    return (0);
}

int checkchar2(t_map map)
{
    int x;

    x = 0;
    while (map.map[x++])
        if (map.map[x] == 'E')
            break ;
    if (x >= ft_strlen(map.map))
        return (1);
    x = 0;
    while (map.map[x++])
        if (map.map[x] == 'C')
            break ;
    if (x >= ft_strlen(map.map))
        return (1);
    x = 0;
    while (map.map[x])
    {
        if (map.map[x] == 'P')
            break ;
        x++;
    }
    if (x >= ft_strlen(map.map))
        return (1);
    return (0);
}