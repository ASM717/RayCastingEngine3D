/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:28:54 by amuriel           #+#    #+#             */
/*   Updated: 2021/03/15 16:50:59 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

int		ft_number_sprites()
{
	int		count;
	int		x;
	int		y;

	x = 0;
	count = 0;
	while (x < mapWidth)
	{
		y = 0;
		while (y < mapHeight)
		{
			if (worldMap[x][y] == '2')
				count++;
			y++;
		}
		x++;
	}
	return (count);
}

t_sprite	*ft_get_sprites(t_engine *engine)
{
	int			x;
	int			y;
	int			i;
	t_sprite	*str_spr;

	x = 0;
	i = 0;
	engine->sprite_num = ft_number_sprites();
	str_spr = malloc(sizeof(t_sprite) * engine->sprite_num);
	engine->sprite_order = malloc(sizeof(int) * engine->sprite_num);
	while (x < mapWidth)
	{
		y = 0;
		while (y < mapHeight)
		{
			if (worldMap[x][y] == '2')
			{
				str_spr[i].x_str = x + 0.5;
				str_spr[i++].y_str = y + 0.5;
			}
			y++;
		}
		x++;
	}
	return (str_spr);
}

void 	ft_swap_sprites(t_engine *engine)
{
	int i;
	int tmpDist;
	int var;

	i = 0;
	while (i < engine->sprite_num - 1)
	{
		if (engine->sprite_dist[i] < engine->sprite_dist[i + 1])
		{
			tmpDist = engine->sprite_dist[i];
			engine->sprite_dist[i] = engine->sprite_dist[i + 1];
			engine->sprite_dist[i + 1] = tmpDist;
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

void 	ft_sprite_calculation3(t_engine *engine)
{
	if (engine->transform_y > 0 && engine->stripe > 0 && engine->stripe <
	engine->scr_width && engine->transform_y < engine->zBuff[engine->stripe])
	{
		engine->tmp_spr_y= engine->draw_start_y;
		while (engine->tmp_spr_y < engine->draw_end_y)
		{
			engine->tmp_spr_d = (engine->tmp_spr_y) * 256 - engine->scr_height *
					128 + engine->sprite_h * 128;
			engine->spr_text_y = ((engine->tmp_spr_d * TEX_HEIGHT) /
								engine->sprite_h) / 256;
			engine->spr_col = ft_get_pixel(&engine->data_spr, engine->spr_text_x,
								 engine->spr_text_y);
			if (engine->spr_col != 0)
				my_mlx_pixel_put(&engine->data, engine->stripe,
					 engine->tmp_spr_y, engine->spr_col);
			engine->tmp_spr_y++;
		}
	}
}

void 	ft_sprite_calculation2(t_engine *engine)
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

void 	ft_sprite_calculation1(t_engine *engine)
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

void 	ft_main_sprites(t_engine *engine)
{
	engine->s = 0;
	ft_sort_swap(engine);
	while (engine->s < engine->sprite_num)
	{
		ft_sprite_calculation1(engine);
		ft_sprite_calculation2(engine);
		engine->stripe = engine->draw_start_x;
		while (engine->stripe < engine->draw_end_x)
		{
			engine->spr_text_x = (int)(256 * (engine->stripe - (engine->sprite_w /
					2 + engine->sprite_scr_x)) *
							TEX_WIDTH / engine->sprite_w) / 256;
			ft_sprite_calculation3(engine);
			engine->stripe++;
		}
		engine->s++;
	}
	free(engine->sprite_dist);
	free(engine->sprite_order);
	free(engine->str_spr);
}
