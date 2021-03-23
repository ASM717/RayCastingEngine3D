/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 02:55:14 by amuriel           #+#    #+#             */
/*   Updated: 2021/03/22 02:55:15 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void 	ft_print_wall(t_engine *engine)
{
	engine->texture_y = (int) engine->tex_pos & (TEX_HEIGHT - 1);
	engine->tex_pos += engine->step;
	if (engine->side == 0)
	{
		if (engine->step_x > 0)
			my_mlx_pixel_put(&engine->data, engine->x, engine->y,
							 ft_get_pixel(&engine->data_so, engine->texture_x, engine->texture_y));
		else
			my_mlx_pixel_put(&engine->data, engine->x, engine->y,
							 ft_get_pixel(&engine->data_no, engine->texture_x, engine->texture_y));
	}
	else
	{
		if (engine->step_y > 0)
			my_mlx_pixel_put(&engine->data, engine->x, engine->y,
							 ft_get_pixel(&engine->data_ea, engine->texture_x, engine->texture_y));
		else
			my_mlx_pixel_put(&engine->data, engine->x, engine->y,
							 ft_get_pixel(&engine->data_we, engine->texture_x, engine->texture_y));
	}
}
