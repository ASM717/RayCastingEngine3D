#include "../cub3d.h"

int		check_movement(int x, int y)
{
	if (worldMap[x][y] != '1' && worldMap[x][y] != '2')
		return (1);
	return (0);
}

void	ft_keycode_handle(t_engine *engine)
{
	double oldDirX;
	double oldPlaneX;

	// if (keycode == W || keycode == S || keycode == KEY_LEFT || keycode == KEY_RIGHT
	// 	|| keycode == A || keycode == D)
	// {
	if (engine->keycode_w == 1)
	{
		if (check_movement((int)(engine->pos_x + engine->dir_x * MOVESPEED),(int)(engine->pos_y)))
			engine->pos_x += engine->dir_x * MOVESPEED;
		if (check_movement((int)(engine->pos_x), (int)(engine->pos_y + engine->dir_y * MOVESPEED)))
			engine->pos_y += engine->dir_y * MOVESPEED;
	}
	if (engine->keycode_s == 1)
	{
		if (check_movement((int)(engine->pos_x - engine->dir_x * MOVESPEED), (int)(engine->pos_y)))
			engine->pos_x -= engine->dir_x * MOVESPEED;
		if (check_movement((int)(engine->pos_x), (int)(engine->pos_y - engine->dir_y * MOVESPEED)))
			engine->pos_y -= engine->dir_y * MOVESPEED;
	}
	if (engine->keycode_left == 1)
	{
		oldDirX = engine->dir_x;
		engine->dir_x = (engine->dir_x * cos(ROTSPEED)) - (engine->dir_y * sin(ROTSPEED));
		engine->dir_y = (oldDirX * sin(ROTSPEED)) + (engine->dir_y * cos(ROTSPEED));
		oldPlaneX = engine->plane_x;
		engine->plane_x = (engine->plane_x * cos(ROTSPEED)) - (engine->plane_y * sin(ROTSPEED));
		engine->plane_y = (oldPlaneX * sin(ROTSPEED)) + (engine->plane_y * cos(ROTSPEED));
	}
	if (engine->keycode_right == 1)
	{
		oldDirX = engine->dir_x;
		engine->dir_x = engine->dir_x * cos(-ROTSPEED) - (engine->dir_y * sin(-ROTSPEED));
		engine->dir_y = (oldDirX * sin(-ROTSPEED)) + (engine->dir_y * cos(-ROTSPEED));
		oldPlaneX = engine->plane_x;
		engine->plane_x = (engine->plane_x * cos(-ROTSPEED)) - (engine->plane_y * sin(-ROTSPEED));
		engine->plane_y = (oldPlaneX * sin(-ROTSPEED)) + (engine->plane_y * cos(-ROTSPEED));
	}
	if (engine->keycode_a == 1)
	{
		// if (check_movement((int)(engine->posY - engine->planeY * MOVESPEED), (int)(engine->posX)))
		// 	engine->posY -= engine->planeY * MOVESPEED;
		// if (check_movement((int)(engine->posY), (int)(engine->posX - engine->planeX)))
		// 	engine->posX -= engine->planeX * MOVESPEED;

		if (check_movement((int)(engine->pos_x), (int)(engine->pos_y + engine->dir_x * MOVESPEED)))
			engine->pos_y += engine->dir_x * MOVESPEED;
		if (check_movement((int)(engine->pos_x - engine->dir_y * MOVESPEED), (int)(engine->pos_y)))
			engine->pos_x -= engine->dir_y * MOVESPEED;
	}
	if (engine->keycode_d == 1)
	{
		// if (check_movement((int)(engine->posY + engine->planeY * MOVESPEED), (int)(engine->posX)))
		// 	engine->posY += engine->planeY * MOVESPEED;
		// if (check_movement((int)(engine->posY), (int)(engine->posX + engine->planeX * MOVESPEED)))
		// 	engine->posX += engine->planeX * MOVESPEED;

		if (check_movement((int)(engine->pos_x), (int)(engine->pos_y - engine->dir_x * MOVESPEED)))
			engine->pos_y -= engine->dir_x * MOVESPEED;
		if (check_movement((int)(engine->pos_x + engine->dir_y * MOVESPEED), (int)(engine->pos_y)))
			engine->pos_x += engine->dir_y * MOVESPEED;
	}
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
	engine->data.mlx = engine->data.mlx;
	exit(1);
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
		mlx_destroy_window(engine->data.mlx, engine->data.win);
		exit(1);
	}
	return (0);
}
