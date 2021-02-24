/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:57:45 by amuriel           #+#    #+#             */
/*   Updated: 2021/02/24 18:32:23 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "srcs/gnl/get_next_line.h"
# include "minilibx-linux/mlx.h"
//# include "mlx/mlx.h"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# define ESC 53
# define W 13
# define S 1
# define A 0
# define D 2
# define Q 12
# define E 14
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define SCALE 16
# define EXIT -1

// typedef struct	s_win //структура для окна
// {
// 	void		*mlx;
// 	void		*win;
// 	void		*img;
// 	void		*addr;
// 	int			line_l;
// 	int			bpp;
// 	int			en;
// }				t_win;

// typedef struct	s_point // структура для точки
// {
// 	int			x;
// 	int			y;
// }				t_point;

// typedef struct	s_plr //структура для игрока и луча
// {
// 	float		x;
// 	float		y;
// 	float		dir;
// 	float		start;
// 	float		end;
// }				t_plr;

// typedef struct	s_all // структура для всего вместе
// {
// 	t_win		*win;
// 	t_plr		*plr;
// 	char		**map;
// }				t_all;

typedef struct	s_screen
{
	int			width;
	int			height;
}				t_screen;

typedef struct	s_side
{
	char 		*north;
	char		*south;
	char		*west;
	char		*east;
}				t_side;

typedef struct	s_keyb
{
	int 		w;
	int 		s;
	int 		a;
	int 		d;
	int 		escape;
	int 		right;
	int 		left;
}				t_keyb;

typedef struct	s_data {
	void 		*mlx;
	void 		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_rgb
{
	int			r;
	int			g;
	int			b;
	int			color;
}				t_rgb;

typedef struct	s_parser
{
	int			flag;
	int			size;
	char		*line;
	t_list		*head;
	int			flag_verif;
}				t_parser;

typedef struct	s_engine
{
	char		**map;
	char		*sprite;
	t_screen	screen;
	t_side		side;
	t_keyb		keyb;
	t_data		data;
	t_rgb		rgb;
	t_rgb		f_rgb;
	t_rgb		c_rgb;
}				t_engine;

int				ft_exist_screensave(char *s);
int				ft_file_exist(char *s);
void			ft_init_all_struct(t_engine *game);
void			ft_err_print(char *s);
int				ft_start_parser(int fd, t_parser *parser, t_engine *game);
void			ft_init_start_parser(t_parser *parser);
int				ft_parser2(t_engine *game);
void			ft_free_array_str(char **s);
char			**ft_build_map(t_parser *parser);
int				ft_map_verification(char **str, t_parser *parser);
int				ft_player_verification(char c, t_parser *parser);
int				ft_str_array_map_len(char **str);
int				ft_indent(int i, int j, char **str);
int				ft_square(char c);

#endif
