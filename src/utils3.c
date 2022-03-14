/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:31:13 by avillar           #+#    #+#             */
/*   Updated: 2022/03/14 15:31:36 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int	player_posy(t_mlx *data)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (data->map->map[i] && data->map->map[i] != 'P')
	{
		if (data->map->map[i] == '\n')
			res--;
		i++;
	}
	res = (i + res) / data->map->l;
	return (res);
}

int	check_map_name(char *map)
{
	int		i;
	int		t;
	char	*str;

	i = 0;
	t = 0;
	str = ft_strcpy(".ber");
	while (map[i])
		i++;
	map = map + (i - 4);
	while (map[t] && str[t])
	{
		if (map[t] != str[t])
		{
			free(str);
			return (1);
		}
		t++;
	}
	free(str);
	return (0);
}
