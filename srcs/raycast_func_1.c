/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_func_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:58:18 by amuriel           #+#    #+#             */
/*   Updated: 2021/04/01 16:00:38 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
		if (engine->world_map[engine->map_x][engine->map_y] == '1')
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
	double camera_x;

	camera_x = 2 * engine->x / (double)(engine->scr_width) - 1;
	engine->ray_dir_x = engine->dir_x + engine->plane_x * camera_x;
	engine->ray_dir_y = engine->dir_y + engine->plane_y * camera_x;
	engine->map_x = (int)(engine->pos_x);
	engine->map_y = (int)(engine->pos_y);
	engine->delta_dist_x = fabs(1 / engine->ray_dir_x);
	engine->delta_dist_y = fabs(1 / engine->ray_dir_y);
}

void	ft_all_calculation(t_engine *engine)
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
			if (engine->y < engine->draw_start)
				my_mlx_pixel_put(&engine->data, engine->x, engine->y,
				ft_get_rgb_color_ceiling(engine));
			if (engine->y >= engine->draw_start &&
			engine->y <= engine->draw_end)
				ft_print_wall(engine);
			if (engine->y > engine->draw_end && engine->y < engine->scr_height)
				my_mlx_pixel_put(&engine->data, engine->x, engine->y,
				ft_get_rgb_color_floor(engine));
			engine->y++;
		}
		engine->z_buff[engine->x] = engine->perp_wall_dist;
		engine->x++;
	}
	ft_main_sprites(engine);
	return (0);
}
