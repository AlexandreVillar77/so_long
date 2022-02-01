# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avillar <avillar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/06 11:34:20 by avillar           #+#    #+#              #
#    Updated: 2022/02/01 11:29:30 by avillar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

SRC		=	so_long.c		\
				map.c			\
				utils.c			\
				map2.c			\
				

SRCS	=	test.c
				

OBJS		= $(addprefix src/, ${SRC:.c=.o})

all:		${NAME}

.c.o:
			$(CC) -Wall -Wextra -Werror -Imlx -c -I/includes/includes.h $< -o $@

${NAME}:	mlx ${OBJS}
			$(CC) $(OBJS) -Lmlx_mac -lmlx -framework OpenGL -framework AppKit -o $(NAME)

mlx :
	make -C mlx_mac

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re