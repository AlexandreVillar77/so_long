# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avillar <avillar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/06 11:34:20 by avillar           #+#    #+#              #
#    Updated: 2022/02/22 12:27:58 by avillar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

SRCS		=	so_long.c		\
				map.c			\
				utils.c			\
				map2.c			\
				mlx_utils.c		\


SRC	=	test.c

CFLAG = -Wall -Wextra -Werror

OBJS	= $(addprefix src/, ${SRCS:.c=.o})

all:		${NAME}

.c.o:
			$(CC)  $(CFLAG) -g3 -Imlx -Ift_printf -c -I/includes/includes.h $< -o $@

${NAME}:	mlx printf ${OBJS}
			$(CC) $(OBJS) -Lft_printf -lprintf -Lmlx_mac -lmlx -framework OpenGL -framework AppKit -o $(NAME)

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
