/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:25:53 by avillar           #+#    #+#             */
/*   Updated: 2022/02/01 14:18:44 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <mlx.h>

//structure pour la map
typedef struct s_map{
	int			h;
	int			l;
	char		*map;
}				t_map;

typedef struct s_img{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_lgt;
	int			endian;
}				t_img;

//fichier utils.c
void	ft_putchar(char c, int fd);
int		ft_strlen(char *str);
void	ft_putstr(char *str, int fd);
char	*ft_strcpy(char *src);
char	*ft_strcat(char *src, char *tmp);
//fonction fichier map.c
char	*checkbuf(char *buf, char *keep);
char	*recup_map(char *map);
int		check_border(t_map map, int x);
int		check_rectangle(t_map map);
int		valid_check(t_map map);
//fihcier map2.c
int		sameL(t_map map);
int		checkchar(t_map map);
int		checkchar2(t_map map);
//fichier so_long.c
t_map	failed_map(void);
t_map	init_map(char *map);
int		so_long(char *mapname);

#endif