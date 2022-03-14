/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:31:13 by avillar           #+#    #+#             */
/*   Updated: 2022/03/14 14:53:40 by avillar          ###   ########.fr       */
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

char	*make_str(char *s)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}

int	check_map_name(char *map)
{
	int		i;
	int		t;
	char	*str;

	i = 0;
	t = 0;
	str = make_str(".ber\0");
	while (map[i])
		i++;
	map = map + (i - 4);
	while (map[t] && str[t])
	{
		if (map[t] != str[t])
			return (1);
		t++;
	}
	return (0);
}
