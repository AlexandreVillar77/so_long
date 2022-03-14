/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:25:53 by avillar           #+#    #+#             */
/*   Updated: 2022/03/14 15:31:40 by avillar          ###   ########.fr       */
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
# include "../mlx_linux/mlx.h"

# define G_NAME "first game"
# define ECHAP 65307 // 53 MAC / 65307 Linux
# define W 119
# define D 100
# define A 97
# define S 115
# define FLOOR "./library/floor.xpm"
# define WALL "./library/wall.xpm"
# define COLLEC "./library/collec.xpm"
# define PLAYER "./library/player.xpm"
# define EXIT "./library/exit.xpm"
# define RED 0xFF0000
# define GREEN 0xFF00
# define WHITE 0xFFFFFF

//structure pour la map

typedef struct s_player
{
	int			index;
	int			move;
	int			count;
	int			collected;
	int			xpos;
	int			ypos;
	void		*img;
}				t_player;

typedef struct s_map{
	int			h;
	int			l;
	char		*map;
	int			c_nb;
	int			size;
	t_player	p;
}				t_map;

typedef struct s_img{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_lgt;
	int			endian;
	int			mapdone;
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
	int		win_h;
	int		win_l;
	t_map	*map;
	t_img	img;
}	t_mlx;

//fichier utils.c
void	ft_putchar(char c, int fd);
void	ft_putstr(char *str, int fd);
char	*ft_strcpy(char *src);
char	*ft_strcat(char *src, char *tmp);
int		p_num(char *map);
//fonction fichier map.c
char	*checkbuf(char *buf, char *keep);
char	*recup_map(char *map);
int		check_border(t_map map, int x);
int		check_rectangle(t_map map);
int		valid_check(t_map *map);
//fihcier map2.c
int		samel(t_map map);
int		checkchar(t_map map);
int		checkchar2(t_map map);
int		recup_fd(char *map);
void	copymap(t_mlx *data, t_map *map);

//fichier so_long.c
t_map	failed_map(void);
void	init_map(char *map, t_map *data);
void	a_free(t_mlx *data);
int		so_long(char *mapname);

//fichier mlx_utils.c
int		handle_input(int keysim, t_mlx *data);
void	create_mlx(t_mlx *data);
void	mloop(t_mlx	*data);
void	init_rect(t_rect *rect);
int		make_img(char *xpm, t_mlx *data, t_rect *rect);

//fichier mlx_utils2.c
void	img_pix_put(t_img *img, int x, int y, int color);
int		render_rect(t_img *img, t_rect rect);
int		render_background(t_mlx *data);
int		render(t_mlx *data);
int		render_owall(t_mlx *data);

//fichier utils2.c
int		check_wins(t_mlx *data);
int		player_posx(t_mlx *data);
int		p_find(t_mlx *data);
void	init_player(t_mlx *data);
int		count_c(char *map);

//fichier mlx_utils3.c
int		render_player(t_mlx *data);
int		render_collec(t_mlx *data);
int		render_exit(t_mlx *data);
int		check_end(t_mlx *data);
int		rtnerr(char *str);

//fichier handle_move.c
int		erase_pos(t_mlx *data);
int		w_move(t_mlx *data);
int		d_move(t_mlx *data);
int		a_move(t_mlx *data);
int		s_move(t_mlx *data);

//fichier utils3.c
int		player_posy(t_mlx *data);
int		check_map_name(char *map);

#endif
