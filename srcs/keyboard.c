/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 02:54:49 by amuriel           #+#    #+#             */
/*   Updated: 2021/03/30 14:22:45 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_movement(t_engine *engine, int x, int y)
{
	if (engine->world_map[x][y] != '1' && engine->world_map[x][y] != '2')
		return (1);
	return (0);
}

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

int		ft_keycode_used(int keycode, t_engine *engine)
{
	if (keycode == W)
		engine->keycode_w = 1;
	if (keycode == S)
		engine->keycode_s = 1;
	if (keycode == A)
		engine->keycode_a = 1;
	if (keycode == D)
		engine->keycode_d = 1;
	if (keycode == KEY_LEFT)
		engine->keycode_left = 1;
	if (keycode == KEY_RIGHT)
		engine->keycode_right = 1;
	return (0);
}

int		ft_exit(t_engine *engine)
{
	ft_free_array(&engine->world_map);
	mlx_destroy_window(engine->data.mlx, engine->data.win);
	exit(-1);
}

int		ft_keycode_unused(int keycode, t_engine *engine)
{
	if (keycode == W)
		engine->keycode_w = 0;
	if (keycode == S)
		engine->keycode_s = 0;
	if (keycode == A)
		engine->keycode_a = 0;
	if (keycode == D)
		engine->keycode_d = 0;
	if (keycode == KEY_LEFT)
		engine->keycode_left = 0;
	if (keycode == KEY_RIGHT)
		engine->keycode_right = 0;
	if (keycode == ESC)
	{
		ft_free_array(&engine->world_map);
		mlx_destroy_window(engine->data.mlx, engine->data.win);
		exit(-1);
	}
	return (0);
}
