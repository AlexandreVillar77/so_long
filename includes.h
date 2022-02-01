/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:01:59 by avillar           #+#    #+#             */
/*   Updated: 2022/01/12 15:03:24 by avillar          ###   ########.fr       */
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
typedef struct      s_map{
        int         H;
        int         L;
        char        *map;
}                   t_map;

//fichier utils.c
void    ft_putchar(char c, int fd);
int     ft_strlen(char *str);
void    ft_putstr(char *str, int fd);
char	*ft_strcpy(char *src);
char	*ft_strcat(char *src, char *tmp);
//fonction fichier map.c
char	*checkbuf(char *buf, char *keep);
char    *recup_map(char *map);
int     check_border(t_map map, int x);
int     check_rectangle(t_map map);
int     valid_check(t_map map);
//fihcier map2.c
int     sameL(t_map map);
int     checkchar(t_map map);
int     checkchar2(t_map map);
//fichier so_long.c
t_map   failed_map();
t_map   init_map(char *map);
int     so_long(char *mapname);

#endif