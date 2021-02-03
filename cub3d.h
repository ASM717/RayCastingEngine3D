/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:57:45 by amuriel           #+#    #+#             */
/*   Updated: 2021/02/03 15:14:24 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "srcs/gnl/get_next_line.h"
//# include "minilibx-linux/mlx.h"
# include "minilibx/mlx.h"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_screen
{
	int			width;
	int			height;
}				t_screen;

typedef struct 	s_side
{
	char 		*north;
	char		*south;
	char		*west;
	char		*east;
}				t_side;

typedef struct	s_map
{

}				t_map;

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

typedef struct	s_engine
{
	t_screen 	screen;
	t_side		side;
	t_keyb		keyb;
}				t_engine;

#endif
