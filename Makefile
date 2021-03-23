NAME		= cub3D

SRC		    = cub3dmain.c \
              	keyboard.c \
              	sprite.c \
              	ceiling_floor.c \
              	screenshot_bmp.c \
              	texture_wall.c \
              	parse_cub.c \
              	pm_resolution.c \
              	pm_rgb_color.c \
              	pm_texture.c
SRCS		= $(addprefix srcs/, $(SRC))

OBJS		= $(SRCS:.c=.o)

CC			= gcc

INC			= -I ./ -I ./libft

FLAGS		= -Wall -Wextra -Werror -g

LIBFT		= -L libft -lft

MLX			= -I minilibx -L minilibx-linux -lmlx

SYS			= -lXext -lX11 -lbsd -lm

all:$(NAME)

$(NAME):
	@make -C ./libft
	@make -C ./minilibx-linux
	@$(CC) ${FLAGS} ${SRCS} ${LIBFT} ${MLX} ${SYS} -o ${NAME}
	@echo "\n\033[0;33mCompile cub3D done!"

clean:
	@/bin/rm -f $(OBJ)
	@make clean -C ./libft
	@echo "\n\033[0;33mClean .o files done!"

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f cub3D.bmp
	@make fclean -C ./libft
	@make clean -C ./minilibx-linux
	@echo "\n\033[0;33mScreenshot clean done!"
	@echo "\033[0;33mClean all files done!"

re: fclean all

norm :
	norminette *.c *.h ./libft/*.c ./libft/*.h

screen : $(NAME)
	./$(NAME) cub3d.cub --save
	open screen.bmp

.PHONY: all clean fclean re norm run screen
