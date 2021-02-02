# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amuriel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 16:58:05 by amuriel           #+#    #+#              #
#    Updated: 2021/02/02 11:52:24 by amuriel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = cub3D

SRC		    = parser.c \
                gnl/get_next_line.c gnl/get_next_line_utils.c
SRCS		= $(addprefix srcs/, $(SRC))

OBJS		= $(SRCS:.c=.o)

INC         = -I ./ -I ./libft

FLAGS       = -Wall -Wextra -Werror -g

LIBFT       = -L libft -lft

MLXLINUX    = -I minilibx -L minilibx-linux -lmlx
SYS         = -lXext -lX11 -lbsd -lm
# MLX         = -lmlx -framework OpenGL -framework AppKit
all:$(NAME)

$(NAME):
	@make -C ./libft
	@make -C ./minilibx-linux
# @make -C ./lmx
	gcc ${FLAGS} ${SRCS} ${LIBFT} ${MLXLINUX} ${SYS} -o ${NAME}
	gcc ${FLAGS} ${SRCS} ${LIBFT} ${MLX} -o ${NAME}
clean:
	@/bin/rm -f $(OBJ)
	@make clean -C ./libft

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f cub3D.bmp
	@make fclean -C ./libft
	@make clean -C ./mlx
	@make clean -C ./minilibx-linux

re: fclean all

norm :
	@norminette *.c *.h ./libft/*.c ./libft/*.h

screen : $(NAME)
	./$(NAME) cub3d.cub --save
	open screen.bmp

.PHONY: all clean fclean re norm run screen
