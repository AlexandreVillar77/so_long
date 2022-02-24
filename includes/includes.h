/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:25:53 by avillar           #+#    #+#             */
/*   Updated: 2022/02/24 15:55:12 by avillar          ###   ########.fr       */
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
# include <ft_printf.h>
# include "../mlx_mac/mlx.h"

# define G_NAME "first game"
# define WIN_L 920
# define WIN_H 600
# define ECHAP 53
//structure pour la map
typedef struct s_map{
	int			h;
	int			l;
	char		*map;
}				t_map;

typedef struct s_img{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_lgt;
	int			endian;
}				t_img;

typedef struct s_rect{
	int			x;
	int			y;
	int			width;
	int			height;
	int			color;
}				t_rect;

typedef struct s_mlx{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	*map;
	t_img	img;
}	t_mlx;

//fichier utils.c
void	ft_putchar(char c, int fd);
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
int		recup_fd(char *map);
void	copymap(t_mlx *data, t_map *map);

//fichier so_long.c
t_map	failed_map(void);
void	init_map(char *map, t_map *data);
int		so_long(char *mapname);

//fichier mlx_utils.c
int		handle_input(int keysim, t_mlx *data);
void	create_mlx(t_mlx *data);
void	mloop(t_mlx	*data);

void	my_mlx_pixel_put(t_img *data, int x, int y, int color);

#endif
