CC = gcc

NAME = cub3D

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -framework OpenGL -framework AppKit

LIBFT = libft
MLXLIB = minilibx_opengl

LIBS = $(LIBFT)/libft.a $(MLXLIB)/libmlx.a

SRC = main.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

.c.o:
	@$(CC) -I$(INCLUDES) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	@make bonus -C $(LIBFT)
	@$(CC) $(FLAGS) $(MLXFLAGS) $(LIBS) $(OBJS) -o $(NAME)
	@echo "Compile cub3d done!"

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFT)
	@echo "Clean .o files done!"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)
	@echo "Clean libftprintf.a done!"

norme:
	norminette $(LIBFT)
	@echo
	norminette $(INCLUDES)
	@echo
	norminette $(DIR_S)

re: fclean all