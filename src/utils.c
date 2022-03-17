/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:21:21 by avillar           #+#    #+#             */
/*   Updated: 2022/03/15 15:03:45 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

// quelque fonction basique et pratique pour la realisation du programme

void	ft_putchar(char c, int fd)
{
	if (fd == -1)
		fd = 1;
	write(fd, &c, 1);
}

void	ft_putstr(char *str, int fd)
{
	if (fd == -1)
		fd = 1;
	write(fd, str, ft_strlen(str));
}

char	*ft_strcpy(char *src)
{
	int		i;
	char	*dst;

	i = 0;
	dst = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dst)
		return (0);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strcat(char *src, char *tmp)
{
	int		i;
	int		x;
	char	*dst;

	i = 0;
	x = 0;
	dst = malloc(sizeof(char) * (ft_strlen(tmp) + ft_strlen(src) + 1));
	if (!dst)
		exit(0);
	while (tmp[i])
	{
		dst[i] = tmp[i];
		i++;
	}
	while (src[x])
	{
		dst[i] = src[x];
		x++;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

// un petit check si il y a plusieurs emplacement d'apperition du 
//player ou plusieurs sortie pour ne pas accepter ces cas la 

int	p_num(char *map)
{
	int	i;
	int	c;
	int	x;

	x = 0;
	c = 0;
	i = 0;
	while (map[i])
	{
		if (map[i] == 'P')
			c++;
		if (map[i] == 'E')
			x++;
		if (c > 1 || x > 1)
			return (1);
		i++;
	}
	return (0);
}
