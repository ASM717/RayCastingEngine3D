/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 02:54:49 by amuriel           #+#    #+#             */
/*   Updated: 2021/04/01 16:41:35 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_keycode_movement_ad(t_engine *engine)
{
	if (engine->keycode_a == 1)
	{
		if (check_movement(engine, (int)(engine->pos_x),
		(int)(engine->pos_y + engine->dir_x * MOVESPEED)))
			engine->pos_y += engine->dir_x * MOVESPEED;
		if (check_movement(engine,
		(int)(engine->pos_x - engine->dir_y * MOVESPEED),
			(int)(engine->pos_y)))
			engine->pos_x -= engine->dir_y * MOVESPEED;
	}
	if (engine->keycode_d == 1)
	{
		if (check_movement(engine, (int)(engine->pos_x),
		(int)(engine->pos_y - engine->dir_x * MOVESPEED)))
			engine->pos_y -= engine->dir_x * MOVESPEED;
		if (check_movement(engine,
		(int)(engine->pos_x + engine->dir_y * MOVESPEED),
			(int)(engine->pos_y)))
			engine->pos_x += engine->dir_y * MOVESPEED;
	}
}

void	ft_keycode_movement_rot_right(t_engine *engine)
{
	if (engine->keycode_right == 1)
	{
		engine->old_dir_x = engine->dir_x;
		engine->dir_x = engine->dir_x * cos(-ROTSPEED) -
			(engine->dir_y * sin(-ROTSPEED));
		engine->dir_y = (engine->old_dir_x * sin(-ROTSPEED)) +
			(engine->dir_y * cos(-ROTSPEED));
		engine->old_plane_x = engine->plane_x;
		engine->plane_x = (engine->plane_x * cos(-ROTSPEED)) -
			(engine->plane_y * sin(-ROTSPEED));
		engine->plane_y = (engine->old_plane_x * sin(-ROTSPEED)) +
			(engine->plane_y * cos(-ROTSPEED));
	}
}

void	ft_keycode_movement_rot_left(t_engine *engine)
{
	if (engine->keycode_left == 1)
	{
		engine->old_dir_x = engine->dir_x;
		engine->dir_x = (engine->dir_x * cos(ROTSPEED)) -
			(engine->dir_y * sin(ROTSPEED));
		engine->dir_y = (engine->old_dir_x * sin(ROTSPEED)) +
			(engine->dir_y * cos(ROTSPEED));
		engine->old_plane_x = engine->plane_x;
		engine->plane_x = (engine->plane_x * cos(ROTSPEED)) -
			(engine->plane_y * sin(ROTSPEED));
		engine->plane_y = (engine->old_plane_x * sin(ROTSPEED)) +
			(engine->plane_y * cos(ROTSPEED));
	}
}

void	ft_keycode_movement_ws(t_engine *engine)
{
	if (engine->keycode_w == 1)
	{
		if (check_movement(engine,
		(int)(engine->pos_x + engine->dir_x * MOVESPEED),
		(int)(engine->pos_y)))
			engine->pos_x += engine->dir_x * MOVESPEED;
		if (check_movement(engine, (int)(engine->pos_x),
		(int)(engine->pos_y + engine->dir_y * MOVESPEED)))
			engine->pos_y += engine->dir_y * MOVESPEED;
	}
	if (engine->keycode_s == 1)
	{
		if (check_movement(engine,
		(int)(engine->pos_x - engine->dir_x * MOVESPEED),
		(int)(engine->pos_y)))
			engine->pos_x -= engine->dir_x * MOVESPEED;
		if (check_movement(engine, (int)(engine->pos_x),
		(int)(engine->pos_y - engine->dir_y * MOVESPEED)))
			engine->pos_y -= engine->dir_y * MOVESPEED;
	}
}

void	ft_keycode_movement(t_engine *engine)
{
	ft_keycode_movement_ws(engine);
	ft_keycode_movement_ad(engine);
	ft_keycode_movement_rot_left(engine);
	ft_keycode_movement_rot_right(engine);
}
