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
	if (engine->keycodeW == 1)
	{
		if (check_movement((int)(engine->posX + engine->dirX * MOVESPEED),(int)(engine->posY)))
			engine->posX += engine->dirX * MOVESPEED;
		if (check_movement((int)(engine->posX), (int)(engine->posY + engine->dirY * MOVESPEED)))
			engine->posY += engine->dirY * MOVESPEED;
	}
	if (engine->keycodeS == 1)
	{
		if (check_movement((int)(engine->posX - engine->dirX * MOVESPEED), (int)(engine->posY)))
			engine->posX -= engine->dirX * MOVESPEED;
		if (check_movement((int)(engine->posX), (int)(engine->posY - engine->dirY * MOVESPEED)))
			engine->posY -= engine->dirY * MOVESPEED;
	}
	if (engine->keycodeLeft == 1)
	{
		oldDirX = engine->dirX;
		engine->dirX = (engine->dirX * cos(ROTSPEED)) - (engine->dirY * sin(ROTSPEED));
		engine->dirY = (oldDirX * sin(ROTSPEED)) + (engine->dirY * cos(ROTSPEED));
		oldPlaneX = engine->planeX;
		engine->planeX = (engine->planeX * cos(ROTSPEED)) - (engine->planeY * sin(ROTSPEED));
		engine->planeY = (oldPlaneX * sin(ROTSPEED)) + (engine->planeY * cos(ROTSPEED));
	}
	if (engine->keycodeRight == 1)
	{
		oldDirX = engine->dirX;
		engine->dirX = engine->dirX * cos(-ROTSPEED) - (engine->dirY * sin(-ROTSPEED));
		engine->dirY = (oldDirX * sin(-ROTSPEED)) + (engine->dirY * cos(-ROTSPEED));
		oldPlaneX = engine->planeX;
		engine->planeX = (engine->planeX * cos(-ROTSPEED)) - (engine->planeY * sin(-ROTSPEED));
		engine->planeY = (oldPlaneX * sin(-ROTSPEED)) + (engine->planeY * cos(-ROTSPEED));
	}
	if (engine->keycodeA == 1)
	{
		// if (check_movement((int)(engine->posY - engine->planeY * MOVESPEED), (int)(engine->posX)))
		// 	engine->posY -= engine->planeY * MOVESPEED;
		// if (check_movement((int)(engine->posY), (int)(engine->posX - engine->planeX)))
		// 	engine->posX -= engine->planeX * MOVESPEED;

		if (check_movement((int)(engine->posX), (int)(engine->posY + engine->dirX * MOVESPEED)))
			engine->posY += engine->dirX * MOVESPEED;
		if (check_movement((int)(engine->posX - engine->dirY * MOVESPEED), (int)(engine->posY)))
			engine->posX -= engine->dirY * MOVESPEED;
	}
	if (engine->keycodeD == 1)
	{
		// if (check_movement((int)(engine->posY + engine->planeY * MOVESPEED), (int)(engine->posX)))
		// 	engine->posY += engine->planeY * MOVESPEED;
		// if (check_movement((int)(engine->posY), (int)(engine->posX + engine->planeX * MOVESPEED)))
		// 	engine->posX += engine->planeX * MOVESPEED;

		if (check_movement((int)(engine->posX), (int)(engine->posY - engine->dirX * MOVESPEED)))
			engine->posY -= engine->dirX * MOVESPEED;
		if (check_movement((int)(engine->posX + engine->dirY * MOVESPEED), (int)(engine->posY)))
			engine->posX += engine->dirY * MOVESPEED;
	}
}

int		ft_keycode_used(int keycode, t_engine *engine)
{
	if (keycode == W)
		engine->keycodeW = 1;
	if (keycode == S)
		engine->keycodeS = 1;
	if (keycode == A)
		engine->keycodeA = 1;
	if (keycode == D)
		engine->keycodeD = 1;
	if (keycode == KEY_LEFT)
		engine->keycodeLeft = 1;
	if (keycode == KEY_RIGHT)
		engine->keycodeRight = 1;
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
		engine->keycodeW = 0;
	if (keycode == S)
		engine->keycodeS = 0;
	if (keycode == A)
		engine->keycodeA = 0;
	if (keycode == D)
		engine->keycodeD = 0;
	if (keycode == KEY_LEFT)
		engine->keycodeLeft = 0;
	if (keycode == KEY_RIGHT)
		engine->keycodeRight = 0;

	if (keycode == ESC)
	{
		mlx_destroy_window(engine->data.mlx, engine->data.win);
		exit(1);
	}
	return (0);
}
