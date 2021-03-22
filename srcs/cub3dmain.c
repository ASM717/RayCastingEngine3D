/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3dmain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:31:29 by amuriel           #+#    #+#             */
/*   Updated: 2021/03/16 18:26:17 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char		worldMap[mapWidth][mapHeight] =
		{
				{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
				{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '0', '0', '0', '0', '0', '2', '2', '2', '2', '2', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '0', '0', '0', '0', '0', '2', '2', '2', '2', '2', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '0', '0', '0', '0', '0', '1', '0', '2', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '0', '0', '0', '0', '0', '1', '0', '2', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '0', '0', '0', '0', '0', '1', '0', '2', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '0', '0', '0', '0', '0', '0', '0', '2', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '0', '0', '0', '0', '0', '0', '0', '2', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '0', '0', '0', '0', '0', '0', '0', '2', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '0', '0', '0', '0', '0', '0', '0', '2', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '0', '0', '0', '0', '0', '0', '0', '2', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
		};

//void	ft_init_texture2(t_engine *engine)
//{
//
//}

void 	ft_init_texture(t_engine *engine)
{
	int		width = TEX_WIDTH;
	int 	height = TEX_HEIGHT;

	engine->tex_north = NO;
	engine->tex_south = SO;
	engine->tex_west = WE;
	engine->tex_east = EA;
	engine->tex_sprite = SP;

	engine->data_no.img = mlx_xpm_file_to_image(engine->data.mlx,
										engine->tex_north, &width, &height);
	engine->data_no.addr = mlx_get_data_addr(engine->data_no.img,
										 &engine->data_no.bits_per_pixel,
										 &engine->data_no.size_line,
										 &engine->data_no.endian);
	engine->data_so.img = mlx_xpm_file_to_image(engine->data.mlx,
										engine->tex_south, &width, &height);
	engine->data_so.addr = mlx_get_data_addr(engine->data_so.img,
										&engine->data_so.bits_per_pixel,
										&engine->data_so.size_line,
										&engine->data_so.endian);
	engine->data_we.img = mlx_xpm_file_to_image(engine->data.mlx,
										engine->tex_west, &width, &height);
	engine->data_we.addr = mlx_get_data_addr(engine->data_we.img,
										&engine->data_we.bits_per_pixel,
										&engine->data_we.size_line,
										&engine->data_we.endian);
	engine->data_ea.img = mlx_xpm_file_to_image(engine->data.mlx,
										engine->tex_east, &width, &height);
	engine->data_ea.addr = mlx_get_data_addr(engine->data_ea.img,
										&engine->data_ea.bits_per_pixel,
										&engine->data_ea.size_line,
										&engine->data_ea.endian);
	engine->data_spr.img = mlx_xpm_file_to_image(engine->data.mlx,
										engine->tex_sprite, &width, &height);
	engine->data_spr.addr = mlx_get_data_addr(engine->data_spr.img,
										&engine->data_spr.bits_per_pixel,
										&engine->data_spr.size_line,
										&engine->data_spr.endian);

}

int		init_engine(t_engine *engine)
{
	engine->data.mlx = NULL;
	engine->data.win = NULL;
	engine->scr_height = SCR_HEIGHT;
	engine->scr_width = SCR_WIDTH;

	engine->pos_x = 20;
	engine->pos_y = 12;
	engine->dir_x = -1;
	engine->dir_y = 0;
	engine->plane_x = 0;
	engine->plane_y = 0.66;
	engine->keycode_a = 0;
	engine->keycode_d = 0;
	engine->keycode_s = 0;
	engine->keycode_w = 0;
	engine->keycode_left = 0;
	engine->keycode_right = 0;
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dest;

	dest = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dest = color;
}

unsigned	int	ft_get_pixel(t_data *data, int x, int y)
{
	unsigned int	color;
	char			*dest;

	dest = data->addr + (y * data->size_line+ x * (data->bits_per_pixel / 8));
	color = *(unsigned int*)dest;
	return (color);
}

void	ft_ray_walldist_calculation2(t_engine *engine)
{
	engine->line_height = (int) (engine->scr_height / engine->perp_wall_dist);
	engine->draw_start = -engine->line_height / 2 + engine->scr_height / 2;
	if (engine->draw_start < 0)
		engine->draw_start = 0;
	engine->draw_end = engine->line_height / 2 + engine->scr_height / 2;
	if (engine->draw_end >= engine->scr_height)
		engine->draw_end = engine->scr_height - 1;
	if (engine->side == 0)
		engine->wall_x = engine->pos_y + engine->perp_wall_dist * engine->ray_dir_y;
	else
		engine->wall_x = engine->pos_x + engine->perp_wall_dist * engine->ray_dir_x;
	engine->wall_x -= floor(engine->wall_x);
	engine->texture_x = (int) (engine->wall_x * (double) (TEX_WIDTH));
	if (engine->side == 0 && engine->ray_dir_x > 0)
		engine->texture_x = TEX_WIDTH - engine->texture_x - 1;
	if (engine->side == 1 && engine->ray_dir_y < 0)
		engine->texture_x = TEX_WIDTH - engine->texture_x - 1;
	engine->step = (1.0 * TEX_HEIGHT) / engine->line_height;
	engine->tex_pos = (engine->draw_start - engine->scr_height / 2 +
			engine->line_height / 2) * engine->step;
}

void	ft_ray_walldist_calculation(t_engine *engine)
{
	if (engine->side == 0)
		engine->perp_wall_dist = (engine->map_x - engine->pos_x +
				(1 - engine->step_x) / 2) / engine->ray_dir_x;
	else
		engine->perp_wall_dist = (engine->map_y - engine->pos_y +
				(1 - engine->step_y) / 2) / engine->ray_dir_y;
}

void	ft_ray_hit(t_engine *engine)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if (engine->side_dist_x < engine->side_dist_y)
		{
			engine->side_dist_x += engine->delta_dist_x;
			engine->map_x += engine->step_x;
			engine->side = 0;
		}
		else
		{
			engine->side_dist_y += engine->delta_dist_y;
			engine->map_y += engine->step_y;
			engine->side = 1;
		}
		if (worldMap[engine->map_x][engine->map_y] == '1')
			hit = 1;
		}
}

void	ft_ray_position(t_engine *engine)
{
	if (engine->ray_dir_x < 0)
	{
		engine->step_x = -1;
		engine->side_dist_x = (engine->pos_x - engine->map_x) *
				engine->delta_dist_x;
	}
	else
	{
		engine->step_x = 1;
		engine->side_dist_x = (engine->map_x + 1.0 - engine->pos_x) *
				engine->delta_dist_x;
	}
	if (engine->ray_dir_y < 0)
	{
		engine->step_y = -1;
		engine->side_dist_y = (engine->pos_y - engine->map_y) *
				engine->delta_dist_y;
	}
	else
	{
		engine->step_y = 1;
		engine->side_dist_y = (engine->map_y + 1.0 - engine->pos_y) *
				engine->delta_dist_y;
	}
}

void	ft_camera_calculation(t_engine *engine)
{
	double cameraX;

	cameraX = 2 * engine->x / (double) (engine->scr_width) - 1;
	engine->ray_dir_x = engine->dir_x + engine->plane_x * cameraX;
	engine->ray_dir_y = engine->dir_y + engine->plane_y * cameraX;
	engine->map_x = (int) (engine->pos_x);
	engine->map_y = (int) (engine->pos_y);
	engine->delta_dist_x = fabs(1 / engine->ray_dir_x);
	engine->delta_dist_y = fabs(1 / engine->ray_dir_y);
}

void 	ft_all_calculation(t_engine *engine)
{
	ft_camera_calculation(engine);
	ft_ray_position(engine);
	ft_ray_hit(engine);
	ft_ray_walldist_calculation(engine);
	ft_ray_walldist_calculation2(engine);
}

int		ft_raycast(t_engine *engine)
{
	engine->str_spr = ft_get_sprites(engine);
	engine->x = 0;

	while (engine->x < engine->scr_width)
	{
		ft_all_calculation(engine);
		engine->y = 0;
		while (engine->y < engine->scr_height)
		{
			//потолок
			if (engine->y < engine->draw_start)
				my_mlx_pixel_put(&engine->data, engine->x, engine->y,
					 ft_get_rgb_color_ceiling(engine));
			//cтены
			if (engine->y >= engine->draw_start && engine->y <= engine->draw_end)
				ft_print_wall(engine);
			//пол
			if (engine->y > engine->draw_end && engine->y < engine->scr_height)
				my_mlx_pixel_put(&engine->data, engine->x, engine->y,
					 ft_get_rgb_color_floor(engine));
			engine->y++;
		}
		engine->zBuff[engine->x] = engine->perp_wall_dist;
		engine->x++;
	}
	ft_main_sprites(engine);
	return (0);
}

int 	ft_restart(t_engine *engine)
{
	ft_keycode_movement(engine);
	engine->zBuff = malloc(sizeof(double) * engine->scr_width);
	ft_raycast(engine);
	mlx_put_image_to_window(engine->data.mlx, engine->data.win,
							engine->data.img, 0, 0);
	free(engine->zBuff);
	if (engine->screen_flag == 1)
		ft_screenshot_make(engine);
	return (0);
}

void 	ft_mlx_data_continue(t_engine *engine)
{
	mlx_hook(engine->data.win, 2, (1L << 0),
			 ft_keycode_used, engine);
	mlx_hook(engine->data.win, 3, (1L << 1),
			 ft_keycode_unused, engine);
	mlx_hook(engine->data.win, 33, (1L << 0),
			 ft_exit, engine);
	mlx_loop_hook(engine->data.mlx, ft_restart, engine);
	mlx_loop(engine->data.mlx);
	free(engine);
}

void 	ft_mlx_data_start(t_engine *engine)
{
	engine->data.mlx = mlx_init();
	engine->data.win = mlx_new_window(engine->data.mlx,
									  engine->scr_width,
									  engine->scr_height, "Cub3D");
	ft_init_texture(engine);
	engine->data.img = mlx_new_image(engine->data.mlx,
									 engine->scr_width, engine->scr_height);
	engine->data.addr = mlx_get_data_addr(engine->data.img,
										  &engine->data.bits_per_pixel,
										  &engine->data.size_line,
										  &engine->data.endian);
}

int 	main(int argc, char **argv)
{
	t_engine	*engine;

	engine = malloc(sizeof(t_engine));

	if (init_engine(engine) != 0)
		return (-1);
	if (ft_init_color_rgb(engine) != 0)
		return (-1);
	ft_mlx_data_start(engine);
	if (argc == 1 && argv[0])
	{
		engine->screen_flag = 0;
		ft_mlx_data_continue(engine);
	}
	else if (argc == 2 && argv[1])
	{
		engine->screen_flag = 1;
		ft_mlx_data_continue(engine);
	}
}
