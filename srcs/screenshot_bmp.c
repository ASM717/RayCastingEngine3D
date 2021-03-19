#include "../cub3d.h"

static void	ft_screen_pack(t_engine *engine)
{
	engine->shot.range = engine->scrHeight - 1;
	while (engine->shot.range >= 0)
	{
		engine->shot.col = 0;
		while (engine->shot.col < engine->scrWidth)
		{
			engine->shot.colorTable = ft_get_pixel(&engine->data,
									   engine->shot.col,
									   engine->shot.range);
			write(engine->shot.fd, &engine->shot.colorTable, 4);
			engine->shot.col++;
		}
		engine->shot.range--;
	}
}

static void	ft_init_shot_header(t_engine *engine)
{
	engine->shot.zero = 0;
	write(engine->shot.fd, &engine->shot.zero, 4);
	engine->shot.bmpOffBits = 54;
	write(engine->shot.fd, &engine->shot.bmpOffBits, 4);
	engine->shot.bmpSize = 40;
	write(engine->shot.fd, &engine->shot.bmpSize, 4);
	write(engine->shot.fd, &engine->scrWidth, 4);
	write(engine->shot.fd, &engine->scrHeight, 4);
	engine->shot.bmpPlane = 1;
	write(engine->shot.fd, &engine->shot.bmpPlane, 2);
	write(engine->shot.fd, &engine->data.bitsPerPixel, 2);
	write(engine->shot.fd, &engine->shot.zero, 24);
}

void		ft_screenshot_make(t_engine *engine)
{
	if (!(engine->shot.fd = open("Cub3D.bmp", O_CREAT |
	O_WRONLY | O_TRUNC, S_IRWXU)))
		write(1, "Error ", 11);
	write(engine->shot.fd, "BM", 2);
	engine->shot.scrSize = 4 * engine->scrWidth * engine->scrHeight +
			engine->shot.bmpOffBits;
	write(engine->shot.fd, &engine->shot.scrSize, 4);
	ft_init_shot_header(engine);
	ft_screen_pack(engine);
	close(engine->shot.fd);
	exit(0);
}