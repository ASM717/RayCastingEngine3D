/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:57:45 by amuriel           #+#    #+#             */
/*   Updated: 2021/02/11 14:47:01 by amuriel          ###   ########.fr       */
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

#define SCALE 16 // условный размер каждого квадратика в карте

typedef struct	s_win //структура для окна
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			line_l;
	int			bpp;
	int			en;
}				t_win;

typedef struct	s_point // структура для точки
{
	int			x;
	int			y;
}				  t_point;

typedef struct	s_plr //структура для игрока и луча
{
	float		x;
	float		y;
	float		dir;
	float		start;
	float		end;
}				  t_plr;

typedef struct	s_all // структура для всего вместе
{
	t_win		*win;
	t_plr		*plr;
	char		**map;
}				  t_all;

// typedef struct	s_screen
// {
// 	int			width;
// 	int			height;
// }				t_screen;

// typedef struct 	s_side
// {
// 	char 		*north;
// 	char		*south;
// 	char		*west;
// 	char		*east;
// }				t_side;

// typedef struct	s_keyb
// {
// 	int 		w;
// 	int 		s;
// 	int 		a;
// 	int 		d;
// 	int 		escape;
// 	int 		right;
// 	int 		left;
// }				t_keyb;

// typedef struct  s_data {
// 	void 		*mlx;
// 	void 		*win;
// 	void        *img;
// 	char        *addr;
// 	int         bits_per_pixel;
// 	int         line_length;
// 	int         endian;
// }               t_data;

// typedef struct	s_engine
// {
// 	t_screen 	screen;
// 	t_side		side;
// 	t_keyb		keyb;
// 	t_data		data;
// }				t_engine;

#endif
