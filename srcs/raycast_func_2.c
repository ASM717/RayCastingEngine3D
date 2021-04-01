/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_func_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:03:29 by amuriel           #+#    #+#             */
/*   Updated: 2021/04/01 16:50:22 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int					ft_init_engine(t_engine *engine)
{
	engine->data.mlx = NULL;
	engine->data.win = NULL;
	engine->scr_height = -1;
	engine->scr_width = -1;
	engine->tex_north = NULL;
	engine->tex_south = NULL;
	engine->tex_west = NULL;
	engine->tex_east = NULL;
	engine->tex_sprite = NULL;
	engine->rgb_ceiling.col_r = -1;
	engine->rgb_ceiling.col_g = -1;
	engine->rgb_ceiling.col_b = -1;
	engine->rgb_floor.col_r = -1;
	engine->rgb_floor.col_g = -1;
	engine->rgb_floor.col_b = -1;
	engine->rgb_ceiling.rgb_color = -1;
	engine->rgb_floor.rgb_color = -1;
	engine->pos_x = 0;
	engine->pos_y = 0;
	engine->plane_x = 0;
	engine->plane_y = 0;
	engine->dir_x = 0;
	engine->dir_y = 0;
	return (0);
}

void				my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dest;

	dest = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dest = color;
}

unsigned	int		ft_get_pixel(t_data *data, int x, int y)
{
	unsigned int	color;
	char			*dest;

	dest = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
	color = *(unsigned int*)dest;
	return (color);
}

void				ft_ray_walldist_calculation2(t_engine *engine)
{
	engine->line_height = (int)(engine->scr_height / engine->perp_wall_dist);
	engine->draw_start = -engine->line_height / 2 + engine->scr_height / 2;
	if (engine->draw_start < 0)
		engine->draw_start = 0;
	engine->draw_end = engine->line_height / 2 + engine->scr_height / 2;
	if (engine->draw_end >= engine->scr_height)
		engine->draw_end = engine->scr_height - 1;
	if (engine->side == 0)
		engine->wall_x = engine->pos_y +
		engine->perp_wall_dist * engine->ray_dir_y;
	else
		engine->wall_x = engine->pos_x +
		engine->perp_wall_dist * engine->ray_dir_x;
	engine->wall_x -= floor(engine->wall_x);
	engine->texture_x = (int)(engine->wall_x * (double)(TEX_WIDTH));
	if (engine->side == 0 && engine->ray_dir_x > 0)
		engine->texture_x = TEX_WIDTH - engine->texture_x - 1;
	if (engine->side == 1 && engine->ray_dir_y < 0)
		engine->texture_x = TEX_WIDTH - engine->texture_x - 1;
	engine->step = (1.0 * TEX_HEIGHT) / engine->line_height;
	engine->tex_pos = (engine->draw_start - engine->scr_height / 2 +
		engine->line_height / 2) * engine->step;
}

void				ft_ray_walldist_calculation(t_engine *engine)
{
	if (engine->side == 0)
		engine->perp_wall_dist = (engine->map_x - engine->pos_x +
		(1 - engine->step_x) / 2) / engine->ray_dir_x;
	else
		engine->perp_wall_dist = (engine->map_y - engine->pos_y +
		(1 - engine->step_y) / 2) / engine->ray_dir_y;
}
