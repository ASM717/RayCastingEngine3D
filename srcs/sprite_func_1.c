/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_func_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:19:12 by amuriel           #+#    #+#             */
/*   Updated: 2021/04/01 16:20:10 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_swap_sprites(t_engine *engine)
{
	int i;
	int var;

	i = 0;
	while (i < engine->sprite_num - 1)
	{
		if (engine->sprite_dist[i] < engine->sprite_dist[i + 1])
		{
			engine->tmp_dist = engine->sprite_dist[i];
			engine->sprite_dist[i] = engine->sprite_dist[i + 1];
			engine->sprite_dist[i + 1] = engine->tmp_dist;
			var = engine->sprite_order[i];
			engine->sprite_order[i] = engine->sprite_order[i + 1];
			engine->sprite_order[i + 1] = var;
			i = -1;
		}
		i++;
	}
}

void	ft_sort_swap(t_engine *engine)
{
	int i;

	i = 0;
	engine->sprite_dist = (double *)malloc(sizeof(double) *
			engine->sprite_num);
	while (i < engine->sprite_num)
	{
		engine->sprite_order[i] = i;
		engine->sprite_dist[i] = ((engine->pos_x - engine->str_spr[i].x_str)
		* (engine->pos_x - engine->str_spr[i].x_str)
		+ (engine->pos_y - engine->str_spr[i].y_str)
		* (engine->pos_y - engine->str_spr[i].y_str));
		i++;
	}
	ft_swap_sprites(engine);
}

void	ft_sprite_calculation3(t_engine *engine)
{
	if (engine->transform_y > 0 && engine->stripe > 0 && engine->stripe <
	engine->scr_width && engine->transform_y < engine->z_buff[engine->stripe])
	{
		engine->tmp_spr_y = engine->draw_start_y;
		while (engine->tmp_spr_y < engine->draw_end_y)
		{
			engine->tmp_spr_d = (engine->tmp_spr_y) * 256 - engine->scr_height *
			128 + engine->sprite_h * 128;
			engine->spr_text_y = ((engine->tmp_spr_d * TEX_HEIGHT) /
			engine->sprite_h) / 256;
			engine->spr_col = ft_get_pixel(&engine->data_spr,
			engine->spr_text_x, engine->spr_text_y);
			if (engine->spr_col != 0)
				my_mlx_pixel_put(&engine->data, engine->stripe,
				engine->tmp_spr_y, engine->spr_col);
			engine->tmp_spr_y++;
		}
	}
}

void	ft_sprite_calculation2(t_engine *engine)
{
	engine->sprite_h = abs((int)(engine->scr_height / (engine->transform_y)));
	engine->draw_start_y = -engine->sprite_h / 2 + engine->scr_height / 2;
	if (engine->draw_start_y < 0)
		engine->draw_start_y = 0;
	engine->draw_end_y = engine->sprite_h / 2 + engine->scr_height / 2;
	if (engine->draw_end_y >= engine->scr_height)
		engine->draw_end_y = engine->scr_height - 1;
	engine->sprite_w = abs((int)(engine->scr_height / (engine->transform_y)));
	engine->draw_start_x = -engine->sprite_w / 2 + engine->sprite_scr_x;
	if (engine->draw_start_x < 0)
		engine->draw_start_x = 0;
	engine->draw_end_x = engine->sprite_w / 2 + engine->sprite_scr_x;
	if (engine->draw_end_x >= engine->scr_width)
		engine->draw_end_x = engine->scr_width - 1;
}

void	ft_sprite_calculation1(t_engine *engine)
{
	engine->sprite_x = engine->str_spr[engine->sprite_order[engine->s]].x_str -
			engine->pos_x;
	engine->sprite_y = engine->str_spr[engine->sprite_order[engine->s]].y_str -
			engine->pos_y;
	engine->inv_det = 1.0 / (engine->plane_x * engine->dir_y -
			engine->dir_x * engine->plane_y);
	engine->transform_x = engine->inv_det * (engine->dir_y * engine->sprite_x -
			engine->dir_x * engine->sprite_y);
	engine->transform_y = engine->inv_det * (-engine->plane_y *
			engine->sprite_x + engine->plane_x * engine->sprite_y);
	engine->sprite_scr_x = (int)((engine->scr_width / 2)
			* (1 + engine->transform_x / engine->transform_y));
}
