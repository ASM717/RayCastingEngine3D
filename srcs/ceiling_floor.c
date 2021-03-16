/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_floor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:25:32 by amuriel           #+#    #+#             */
/*   Updated: 2021/03/15 16:31:10 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int 	ft_init_color_rgb(t_engine *engine)
{
	engine->rgbCeiling.colR = 51;
	engine->rgbCeiling.colG = 0;
	engine->rgbCeiling.colB = 0;

	engine->rgbFloor.colR = 51;
	engine->rgbFloor.colG = 51;
	engine->rgbFloor.colB = 26;

	return (0);
}


int 	ft_get_rgb_color_ceiling(t_engine *engine)
{
	engine->rgbCeiling.rgbColor =
			(256 * 256 * engine->rgbCeiling.colR) +
					(256 * engine->rgbCeiling.colG) +
					engine->rgbCeiling.colB;
	return (engine->rgbCeiling.rgbColor);
}

int 	ft_get_rgb_color_floor(t_engine *engine)
{
	engine->rgbFloor.rgbColor =
			(256 * 256 * engine->rgbFloor.colR) +
			(256 * engine->rgbFloor.colG) +
			engine->rgbFloor.colB;
	return (engine->rgbFloor.rgbColor);
}
