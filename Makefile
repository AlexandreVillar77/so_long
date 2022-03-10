# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avillar <avillar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/06 11:34:20 by avillar           #+#    #+#              #
#    Updated: 2022/03/10 12:41:10 by avillar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

SRCS		=	so_long.c		\
				map.c			\
				utils.c			\
				map2.c			\
				mlx_utils.c		\
				mlx_utils2.c	\
				utils2.c		\
				mlx_utils3.c	\
				handle_move.c	\


SRC	=	test.c

CFLAG = -Wall -Wextra -Werror

FSAN = -g3
CFLAG := $(FSAN)

MAC = -Lmlx_mac -lmlx -framework OpenGL -framework AppKit

LINUX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

OBJS	= $(addprefix src/, ${SRCS:.c=.o})

all:	mlx_linux/libmlx_Linux.a printf/libprintf.a ${NAME}

.c.o:
			$(CC)  $(CFLAG) -Imlx -Ift_printf -c -I/includes/includes.h $< -o $@

${NAME}: ${OBJS}
			$(CC) $(OBJS) -Lft_printf -lprintf $(LINUX) -o $(NAME)

mlx_mac :
	make -C mlx_mac

mlx_linux/libmlx_Linux.a :
	make -C mlx_linux

printf/libprintf.a :
	make -C ft_printf

clean:
			rm -f ${OBJS}

fclean:		clean
			make -C mlx_linux clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
