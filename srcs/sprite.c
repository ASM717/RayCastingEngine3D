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
	t_sprite	*strSpr;

	x = 0;
	i = 0;
	engine->spriteNum = ft_number_sprites();
	strSpr = malloc(sizeof(t_sprite) * engine->spriteNum);
	engine->spriteOrder = malloc(sizeof(int) * engine->spriteNum);
	while (x < mapWidth)
	{
		y = 0;
		while (y < mapHeight)
		{
			if (worldMap[x][y] == '2')
			{
				strSpr[i].xStr = x + 0.5;
				strSpr[i++].yStr = y + 0.5;
			}
			y++;
		}
		x++;
	}
	return (strSpr);
}

void 	ft_swap_sprites(t_engine *engine)
{
	int i;
	int tmpDist;
	int var;

	i = 0;
	while (i < engine->spriteNum - 1)
	{
		if (engine->spriteDist[i] < engine->spriteDist[i + 1])
		{
			tmpDist = engine->spriteDist[i];
			engine->spriteDist[i] = engine->spriteDist[i + 1];
			engine->spriteDist[i + 1] = tmpDist;
			var = engine->spriteOrder[i];
			engine->spriteOrder[i] = engine->spriteOrder[i + 1];
			engine->spriteOrder[i + 1] = var;
			i = -1;
		}
		i++;
	}
}

void	ft_sort_swap(t_engine *engine)
{
	int i;

	i = 0;
	engine->spriteDist = (double *)malloc(sizeof(double *) *
			engine->spriteNum);
	while (i < engine->spriteNum)
	{
		engine->spriteOrder[i] = i;
		engine->spriteDist[i] = ((engine->posX - engine->strSpr[i].xStr)
				* (engine->posX - engine->strSpr[i].xStr)
				+ (engine->posY - engine->strSpr[i].yStr)
				* (engine->posY - engine->strSpr[i].yStr));
		i++;
	}
	ft_swap_sprites(engine);
}

void 	ft_sprite_calculation3(t_engine *engine)
{
	if (engine->transformY > 0 && engine->stripe > 0 && engine->stripe <
	engine->scrWidth && engine->transformY < engine->zBuff[engine->stripe])
	{
		engine->tmpSprY= engine->drawStartY;
		while (engine->tmpSprY < engine->drawEndY)
		{
			engine->tmpSprD = (engine->tmpSprY) * 256 - engine->scrHeight *
					128 + engine->spriteH * 128;
			engine->sprTextY = ((engine->tmpSprD * TEX_HEIGHT) /
								engine->spriteH) / 256;
			engine->sprCol = ft_get_pixel(&engine->dataSPR, engine->sprTextX,
								 engine->sprTextY);
			if (engine->sprCol != 0)
				my_mlx_pixel_put(&engine->data, engine->stripe,
					 engine->tmpSprY, engine->sprCol);
			engine->tmpSprY++;
		}
	}
}

void 	ft_sprite_calculation2(t_engine *engine)
{
	engine->spriteH = abs((int)(engine->scrHeight / (engine->transformY)));
	engine->drawStartY = -engine->spriteH / 2 + engine->scrHeight / 2;
	if (engine->drawStartY < 0)
		engine->drawStartY = 0;
	engine->drawEndY = engine->spriteH / 2 + engine->scrHeight / 2;
	if (engine->drawEndY >= engine->scrHeight)
		engine->drawEndY = engine->scrHeight - 1;
	engine->spriteW = abs((int)(engine->scrHeight / (engine->transformY)));
	engine->drawStartX = -engine->spriteW / 2 + engine->spriteScrX;
	if (engine->drawStartX < 0)
		engine->drawStartX = 0;
	engine->drawEndX = engine->spriteW / 2 + engine->spriteScrX;
	if (engine->drawEndX >= engine->scrWidth)
		engine->drawEndX = engine->scrWidth - 1;
}

void 	ft_sprite_calculation1(t_engine *engine)
{
	engine->spriteX = engine->strSpr[engine->spriteOrder[engine->s]].xStr -
			engine->posX;
	engine->spriteY = engine->strSpr[engine->spriteOrder[engine->s]].yStr -
			engine->posY;
	engine->invDet = 1.0 / (engine->planeX * engine->dirY -
			engine->dirX * engine->planeY);
	engine->transformX = engine->invDet * (engine->dirY * engine->spriteX -
			engine->dirX * engine->spriteY);
	engine->transformY = engine->invDet * (-engine->planeY *
			engine->spriteX + engine->planeX * engine->spriteY);
	engine->spriteScrX = (int)((engine->scrWidth / 2)
			* (1 + engine->transformX / engine->transformY));
}

void 	ft_main_sprites(t_engine *engine)
{
	engine->s = 0;
	ft_sort_swap(engine);
	while (engine->s < engine->spriteNum)
	{
		ft_sprite_calculation1(engine);
		ft_sprite_calculation2(engine);
		engine->stripe = engine->drawStartX;
		while (engine->stripe < engine->drawEndX)
		{
			engine->sprTextX = (int)(256 * (engine->stripe - (engine->spriteW /
					2 + engine->spriteScrX)) *
							TEX_WIDTH / engine->spriteW) / 256;
			ft_sprite_calculation3(engine);
			engine->stripe++;
		}
		engine->s++;
	}
	free(engine->spriteDist);
	free(engine->spriteOrder);
	free(engine->strSpr);
}
