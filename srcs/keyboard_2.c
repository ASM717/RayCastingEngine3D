/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:12:22 by amuriel           #+#    #+#             */
/*   Updated: 2021/04/01 16:15:07 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init_keycode(t_engine *engine)
{
	engine->keycode_a = 0;
	engine->keycode_d = 0;
	engine->keycode_s = 0;
	engine->keycode_w = 0;
	engine->keycode_left = 0;
	engine->keycode_right = 0;
}

int		ft_exit(t_engine *engine)
{
	ft_free_array(&engine->world_map);
	mlx_destroy_window(engine->data.mlx, engine->data.win);
	exit(-1);
}

int		check_movement(t_engine *engine, int x, int y)
{
	if (engine->world_map[x][y] != '1' && engine->world_map[x][y] != '2')
		return (1);
	return (0);
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
