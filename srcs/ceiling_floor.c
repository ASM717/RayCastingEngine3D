/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_floor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:25:32 by amuriel           #+#    #+#             */
/*   Updated: 2021/03/30 14:24:02 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_get_rgb_color_ceiling(t_engine *engine)
{
	engine->rgb_ceiling.rgb_color =
	(256 * 256 * engine->rgb_ceiling.col_r) +
	(256 * engine->rgb_ceiling.col_g) + engine->rgb_ceiling.col_b;
	return (engine->rgb_ceiling.rgb_color);
}

int		ft_get_rgb_color_floor(t_engine *engine)
{
	engine->rgb_floor.rgb_color =
	(256 * 256 * engine->rgb_floor.col_r) +
	(256 * engine->rgb_floor.col_g) + engine->rgb_floor.col_b;
	return (engine->rgb_floor.rgb_color);
}
