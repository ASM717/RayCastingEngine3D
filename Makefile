NAME = cub3D

SRCS = main.c

OSRC = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME) $(OSRC)

$(NAME): $(SRC)
	@make -C libft bonus
	@make -C minilibx_opengl
	@cp libft/libft.a ./
	@cp minilibx_opengl/libmlx.a ./
	@gcc $(FLAGS) ./libft/libft.a ./minilibx_opengl/libmlx.a -framework OpenGl -framework AppKit $(SRCS) -o $(NAME)

bonus: all

%.o: %.c $(HEADER)
	gcc $(FLAGS) -c $< -o $@

clean:
	@make -C libft clean
	@rm -f $(OSRC)

fclean: clean
	@make -C libft fclean
	@make -C mlx clean
	@rm -f libft.a
	@rm -f libmlx.a
	@rm -f $(NAME)

re: fclean all

run : $(NAME)
	./$(NAME) cub3d.cub

norm :
	@norminette *.c *.h ./libft/*.c ./libft/*.h

screen : $(NAME)
	./$(NAME) cub3d.cub --save
	open screen.bmp

.PHONY: all bonus clean fclean re norm run screen