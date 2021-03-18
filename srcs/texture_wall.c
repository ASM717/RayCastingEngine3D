#include "../cub3d.h"
{
	engine->textureY = (int) engine->texPos & (TEX_HEIGHT - 1);
	engine->texPos += engine->step;
	if (engine->side == 0)
	{
		if (engine->stepX > 0)
			my_mlx_pixel_put(&engine->data, engine->x, engine->y,
							 ft_get_pixel(&engine->dataSO, engine->textureX, engine->textureY));
		else
			my_mlx_pixel_put(&engine->data, engine->x, engine->y,
							 ft_get_pixel(&engine->dataNO, engine->textureX, engine->textureY));
	}
	else
	{
		if (engine->stepY > 0)
			my_mlx_pixel_put(&engine->data, engine->x, engine->y,
							 ft_get_pixel(&engine->dataEA, engine->textureX, engine->textureY));
		else
			my_mlx_pixel_put(&engine->data, engine->x, engine->y,
							 ft_get_pixel(&engine->dataWE, engine->textureX, engine->textureY));
	}
}