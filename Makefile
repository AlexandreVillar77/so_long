# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avillar <avillar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/06 11:34:20 by avillar           #+#    #+#              #
#    Updated: 2022/03/01 16:14:51 by avillar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

SRCS		=	so_long.c		\
				map.c			\
				utils.c			\
				map2.c			\
				mlx_utils.c		\
				mlx_utils2.c	\


SRC	=	test.c

CFLAG = -Wall -Wextra -Werror

FSAN = -fsanitize=address -g3

OBJS	= $(addprefix src/, ${SRC:.c=.o})

all:		${NAME}

.c.o:
			$(CC)  $(CFLAG) -Imlx -Ift_printf -c -I/includes/includes.h $< -o $@

${NAME}:	mlx printf ${OBJS}
			$(CC) $(OBJS) $(FSAN) -Lft_printf -lprintf -Lmlx_mac -lmlx -framework OpenGL -framework AppKit -o $(NAME)

mlx :
	make -C mlx_mac

printf :
	make -C ft_printf

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
