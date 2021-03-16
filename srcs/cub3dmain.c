/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3dmain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:31:29 by amuriel           #+#    #+#             */
/*   Updated: 2021/03/16 18:26:17 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char		worldMap[mapWidth][mapHeight] =
		{
				{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
				{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '0', '0', '0', '0', '0', '2', '2', '2', '2', '2', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '0', '0', '0', '0', '0', '2', '2', '2', '2', '2', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '0', '0', '0', '0', '0', '1', '0', '2', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '0', '0', '0', '0', '0', '1', '0', '2', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '0', '0', '0', '0', '0', '1', '0', '2', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '0', '0', '0', '0', '0', '0', '0', '2', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '0', '0', '0', '0', '0', '0', '0', '2', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '0', '0', '0', '0', '0', '0', '0', '2', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '0', '0', '0', '0', '0', '0', '0', '2', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '0', '0', '0', '0', '0', '0', '0', '2', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
				{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
		};

void 	ft_init_texture(t_engine *engine)
{
	int		width = TEX_WIDTH;
	int 	height = TEX_HEIGHT;

	engine->texNorth = NO;
	engine->texSouth = SO;
	engine->texWest = WE;
	engine->texEast = EA;
	engine->texSprite = SP;


	engine->dataNO.img = mlx_xpm_file_to_image(engine->data.mlx,
										engine->texNorth, &width, &height);
	engine->dataNO.addr = mlx_get_data_addr(engine->dataNO.img,
										 &engine->dataNO.bitsPerPixel,
										 &engine->dataNO.sizeLine,
										 &engine->dataNO.endian);

	engine->dataSO.img = mlx_xpm_file_to_image(engine->data.mlx,
										engine->texSouth, &width, &height);
	engine->dataSO.addr = mlx_get_data_addr(engine->dataSO.img,
										&engine->dataSO.bitsPerPixel,
										&engine->dataSO.sizeLine,
										&engine->dataSO.endian);

	engine->dataWE.img = mlx_xpm_file_to_image(engine->data.mlx,
										engine->texWest, &width, &height);
	engine->dataWE.addr = mlx_get_data_addr(engine->dataWE.img,
										&engine->dataWE.bitsPerPixel,
										&engine->dataWE.sizeLine,
										&engine->dataWE.endian);

	engine->dataEA.img = mlx_xpm_file_to_image(engine->data.mlx,
										engine->texEast, &width, &height);
	engine->dataEA.addr = mlx_get_data_addr(engine->dataEA.img,
										&engine->dataEA.bitsPerPixel,
										&engine->dataEA.sizeLine,
										&engine->dataEA.endian);

	engine->dataSPR.img = mlx_xpm_file_to_image(engine->data.mlx,
										engine->texSprite, &width, &height);
	engine->dataSPR.addr = mlx_get_data_addr(engine->dataSPR.img,
										&engine->dataSPR.bitsPerPixel,
										&engine->dataSPR.sizeLine,
										&engine->dataSPR.endian);

}

int		init_engine(t_engine *engine)
{
	engine->data.mlx = NULL;
	engine->data.win = NULL;
	engine->scrHeight = SCR_HEIGHT;
	engine->scrWidth = SCR_WIDTH;

	engine->posX = 20;
	engine->posY = 10;
	engine->dirX = -1;
	engine->dirY = 0;
	engine->planeX = 0;
	engine->planeY = 0.66;
	engine->keycodeA = 0;
	engine->keycodeD = 0;
	engine->keycodeS = 0;
	engine->keycodeW = 0;
	engine->keycodeLeft = 0;
	engine->keycodeRight = 0;
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dest;

	dest = data->addr + (y * data->sizeLine + x * (data->bitsPerPixel / 8));
	*(unsigned int*)dest = color;
}

unsigned	int	get_pixel(t_data *data, int x, int y)
{
	unsigned int	color;
	char			*dst;

	dst = data->addr + (y * data->sizeLine+ x * (data->bitsPerPixel / 8));
	color = *(unsigned int*)dst;
	return (color);
}

void	ft_ray_walldist_calculation2(t_engine *engine)
{
	engine->lineHeight = (int) (engine->scrHeight / engine->perpWallDist);
	engine->drawStart = -engine->lineHeight / 2 + engine->scrHeight / 2;
	if (engine->drawStart < 0)
		engine->drawStart = 0;
	engine->drawEnd = engine->lineHeight / 2 + engine->scrHeight / 2;
	if (engine->drawEnd >= engine->scrHeight)
		engine->drawEnd = engine->scrHeight - 1;
	if (engine->side == 0)
		engine->wallX = engine->posY + engine->perpWallDist * engine->rayDirY;
	else
		engine->wallX = engine->posX + engine->perpWallDist * engine->rayDirX;
	engine->wallX -= floor(engine->wallX);
	engine->textureX = (int) (engine->wallX * (double) (TEX_WIDTH));
	if (engine->side == 0 && engine->rayDirX > 0)
		engine->textureX = TEX_WIDTH - engine->textureX - 1;
	if (engine->side == 1 && engine->rayDirY < 0)
		engine->textureX = TEX_WIDTH - engine->textureX - 1;
	engine->step = (1.0 * TEX_HEIGHT) / engine->lineHeight;
	engine->texPos = (engine->drawStart - engine->scrHeight / 2 +
									engine->lineHeight / 2) * engine->step;
}

void	ft_ray_walldist_calculation(t_engine *engine)
{
	if (engine->side == 0)
		engine->perpWallDist = (engine->mapX - engine->posX +
								(1 - engine->stepX) / 2) / engine->rayDirX;
	else
		engine->perpWallDist = (engine->mapY - engine->posY +
								(1 - engine->stepY) / 2) / engine->rayDirY;
}

void	ft_ray_hit(t_engine *engine)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if (engine->sideDistX < engine->sideDistY)
		{
			engine->sideDistX += engine->deltaDistX;
			engine->mapX += engine->stepX;
			engine->side = 0;
		}
		else
		{
			engine->sideDistY += engine->deltaDistY;
			engine->mapY += engine->stepY;
			engine->side = 1;
		}
		if (worldMap[engine->mapX][engine->mapY] == '1') // > 0
			hit = 1;
		}
}

void	ft_ray_position(t_engine *engine)
{
	if (engine->rayDirX < 0)
	{
		engine->stepX = -1;
		engine->sideDistX = (engine->posX - engine->mapX) *
													engine->deltaDistX;
	}
	else
	{
		engine->stepX = 1;
		engine->sideDistX = (engine->mapX + 1.0 - engine->posX) *
													engine->deltaDistX;
	}
	if (engine->rayDirY < 0)
	{
		engine->stepY = -1;
		engine->sideDistY = (engine->posY - engine->mapY) *
													engine->deltaDistY;
	}
	else
	{
		engine->stepY = 1;
		engine->sideDistY = (engine->mapY + 1.0 - engine->posY) *
													engine->deltaDistY;
	}
}

void	ft_camera_calculation(t_engine *engine)
{
	double cameraX;

	cameraX = 2 * engine->x / (double) (engine->scrWidth) - 1;
	engine->rayDirX = engine->dirX + engine->planeX * cameraX;
	engine->rayDirY = engine->dirY + engine->planeY * cameraX;
	engine->mapX = (int) (engine->posX);
	engine->mapY = (int) (engine->posY);
	engine->deltaDistX = fabs(1 / engine->rayDirX);
	engine->deltaDistY = fabs(1 / engine->rayDirY);
//		engine->deltaDistX = sqrt(1 + pow(engine->rayDirY, 2) / pow(engine->rayDirX, 2));
//		engine->deltaDistY = sqrt(1 + pow(engine->rayDirX, 2) / pow(engine->rayDirY, 2));
}

int		ft_raycast(t_engine *engine)
{
	engine->strSpr = ft_get_sprites(engine);
	engine->x = 0;

	while (engine->x < engine->scrWidth)
	{
		ft_camera_calculation(engine);
		ft_ray_position(engine);
		ft_ray_hit(engine);
		ft_ray_walldist_calculation(engine);
		ft_ray_walldist_calculation2(engine);
		engine->y = 0;
		while (engine->y < engine->scrHeight)
		{
			//потолок
			if (engine->y < engine->drawStart)
				my_mlx_pixel_put(&engine->data, engine->x, engine->y,
						ft_get_rgb_color_ceiling(engine));
			//cтены
			if (engine->y >= engine->drawStart && engine->y <= engine->drawEnd)
			{
				engine->textureY = (int) engine->texPos & (TEX_HEIGHT - 1);
				engine->texPos += engine->step;
				if (engine->side == 0)
				{
					if (engine->stepX > 0)
						my_mlx_pixel_put(&engine->data, engine->x, engine->y,
										 get_pixel(&engine->dataSO, engine->textureX, engine->textureY));
					else
						my_mlx_pixel_put(&engine->data, engine->x, engine->y,
										 get_pixel(&engine->dataNO, engine->textureX, engine->textureY));
				}
				else
				{
					if (engine->stepY > 0)
						my_mlx_pixel_put(&engine->data, engine->x, engine->y,
										 get_pixel(&engine->dataEA, engine->textureX, engine->textureY));
					else
						my_mlx_pixel_put(&engine->data, engine->x, engine->y,
										 get_pixel(&engine->dataWE, engine->textureX, engine->textureY));
				}
			}
			//пол
			if (engine->y > engine->drawEnd && engine->y < engine->scrHeight)
				my_mlx_pixel_put(&engine->data, engine->x, engine->y,
								 ft_get_rgb_color_floor(engine));
			engine->y++;
		}
		engine->x++;
		engine->zBuff[engine->x] = engine->perpWallDist;
	}
	ft_main_sprites(engine);
	mlx_put_image_to_window(engine->data.mlx, engine->data.win,
							engine->data.img, 0, 0);
	return (0);
}

int 	ft_restart(t_engine *engine)
{
	ft_keycode_handle(engine);
	engine->zBuff = malloc(sizeof(double) * engine->scrWidth);
	ft_raycast(engine);
	free(engine->zBuff);
	return (0);
}

int 	main(void)
{

	t_engine *engine;
	engine = malloc(sizeof(t_engine));

	if (init_engine(engine) != 0)
		return (-1);
	if (ft_init_color_rgb(engine) != 0)
		return (-1);
	engine->data.mlx = mlx_init();
	engine->data.win = mlx_new_window(engine->data.mlx,
										engine->scrWidth,
										engine->scrHeight, "Cub3D");
	ft_init_texture(engine);
	engine->data.img = mlx_new_image(engine->data.mlx,
										engine->scrWidth, engine->scrHeight);
	engine->data.addr = mlx_get_data_addr(engine->data.img,
										&engine->data.bitsPerPixel,
										&engine->data.sizeLine,
										&engine->data.endian);

	mlx_hook(engine->data.win, 2, (1L << 0), ft_keycode_used, engine);
	mlx_hook(engine->data.win, 3, (1L << 1), ft_keycode_unused, engine);
	mlx_hook(engine->data.win, 33, (1L << 0), ft_exit, engine);
	mlx_loop_hook(engine->data.mlx, ft_restart, engine);
	mlx_loop(engine->data.mlx);
	free(engine);
}
