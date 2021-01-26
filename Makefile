# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amuriel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 16:58:05 by amuriel           #+#    #+#              #
#    Updated: 2021/01/26 17:51:16 by amuriel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D

CC			= gcc
AR			= ar rc
RM			= rm -f

_SRCS		= main.c
SRCS		= $(addprefix srcs/, $(_SRCS))

OBJS		= $(SRCS:.c=.o)

CFLAGS		= -Wall -Wextra -Werror

%.o: %.c
			$(CC) $(CFLAGS) -Iincludes -Ilibft -Imlx -c $< -o $@

$(NAME):	$(OBJS)
			make -C libft
			make -C minilibx_opengl
			mv minilibx_opengl/libmlx.a libmlx.a
			$(CC) -Llibft -lft -L. -lmlx -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

all:		$(NAME)


run : $(NAME)
	./$(NAME) cub3d.cub

norm :
	@norminette *.c *.h ./libft/*.c ./libft/*.h

screen : $(NAME)
	./$(NAME) cub3d.cub --save
	open screen.bmp

.PHONY: all bonus clean fclean re norm run screen
