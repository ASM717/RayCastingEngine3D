/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:57:45 by amuriel           #+#    #+#             */
/*   Updated: 2021/03/16 17:24:06 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include "minilibx-linux/mlx.h"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdint.h>

# include <stdio.h>

# define ESC			65307
# define W				119
# define S				115
# define A				97
# define D				100
# define KEY_LEFT		65361
# define KEY_RIGHT		65363

# define MAP_WIDTH		24
# define MAP_HEIGHT		24

# define SCR_WIDTH		640
# define SCR_HEIGHT		480

# define TEX_WIDTH		64
# define TEX_HEIGHT		64

# define MOVESPEED		0.2
# define ROTSPEED		0.05

# define NO "textures/marbface.xpm"
# define SO "textures/mountains.xpm"
# define WE "textures/metal.xpm"
# define EA "textures/brick.xpm"
# define SP "textures/barrel.xpm"

char					worldMap[MAP_WIDTH][MAP_HEIGHT];

typedef struct			s_data
{
	void				*img;
	void				*mlx;
	void				*win;
	char				*addr;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
}						t_data;

typedef struct			s_rgb
{
	int 				col_r;
	int 				col_g;
	int 				col_b;
	unsigned int 		rgb_color;
}						t_rgb;

typedef struct			s_headshot
{
	int 				fd;
	int 				bmp_plane;
	int 				scr_size;
	int 				bmp_size;
	int 				bmp_off_bits;
	int 				zero;
	int 				color_table;
	int 				range;
	int 				col;
}						t_headshot;

typedef struct			s_sprite
{
	double				x_str;
	double				y_str;
}						t_sprite;

typedef struct			s_pm
{
	int 				fd;
	char 				*line;
}						t_pm;

typedef struct			s_engine
{
	t_data				data;
	t_data				data_no;
	t_data				data_so;
	t_data				data_we;
	t_data				data_ea;
	t_data				data_spr;
	t_sprite			*str_spr;
	t_rgb				rgb_floor;
	t_rgb				rgb_ceiling;
	t_headshot			shot;
	t_pm				pm;
	int 				screen_flag;
	int 				scr_height;
	int 				scr_width;

	int 				x;
	int 				y;
	double				pos_x;
	double				pos_y;
	double				dir_x;
	double				dir_y;
	double				plane_x;
	double				plane_y;
	double				ray_dir_x;
	double				ray_dir_y;
	int					map_x;
	int					map_y;
	double				side_dist_x;
	double				side_dist_y;
	double				delta_dist_x;
	double				delta_dist_y;
	int					step_x;
	int					step_y;
	int					side;
	int					draw_start;
	int					draw_end;
	double				perp_wall_dist;
	int 				line_height;

	int 				keycode_w;
	int 				keycode_s;
	int 				keycode_a;
	int 				keycode_d;
	int					keycode_left;
	int					keycode_right;
	double				old_dir_x;
	double				old_plane_x;
	double				wall_x;
	int 				texture_x;
	int					texture_y;
	double				step;
	double				tex_pos;
	char 				*tex_north;
	char 				*tex_south;
	char 				*tex_west;
	char 				*tex_east;
	char 				*tex_sprite;
	double				*zBuff;
	int 				sprite_num;
	int 				*sprite_order;
	double				*sprite_dist;
	double				sprite_x;
	double				sprite_y;
	double				inv_det;
	double				transform_x;
	double 				transform_y;
	int 				sprite_scr_x;
	int 				sprite_h;
	int 				draw_start_y;
	int 				draw_end_y;
	int 				sprite_w;
	int 				draw_start_x;
	int					draw_end_x;
	int					stripe;
	int					spr_text_x;
	int 				spr_text_y;
	int 				tmp_spr_y;
	int					tmp_spr_d;
	int 				spr_col;
	int 				s;
}						t_engine;

int		check_movement(int x, int y);
void	ft_keycode_movement(t_engine *engine);
int		ft_keycode_used(int keycode, t_engine *engine);
int		ft_keycode_unused(int keycode, t_engine *engine);
int		ft_exit(t_engine *engine);

unsigned	int	ft_get_pixel(t_data *data, int x, int y);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void 	ft_print_wall(t_engine *engine);
void 	ft_main_sprites(t_engine *engine);
void	ft_sort_swap(t_engine *engine);
t_sprite			*ft_get_sprites(t_engine *engine);
int		ft_number_sprites();

int 	ft_init_color_rgb(t_engine *engine);
int 	ft_get_rgb_color_ceiling(t_engine *engine);
int 	ft_get_rgb_color_floor(t_engine *engine);



void		ft_screenshot_make(t_engine *engine);

#endif
