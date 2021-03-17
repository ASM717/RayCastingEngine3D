#include "../cub3d.h"

void 	ft_init_shot(t_engine *engine)
{
//	t_shot *shot;
//
//	shot = malloc(1 * sizeof(t_shot));
	engine->shot.scrWidth = engine->scrWidth;
	engine->shot.scrHeight = engine->scrHeight;
	engine->shot.bitCount = 24;
	engine->shot.widthInBytes = ((engine->shot.scrWidth *
			engine->shot.bitCount + 31) / 32) * 4;
	engine->shot.imageSize = engine->shot.widthInBytes *
			engine->shot.scrHeight;
	engine->shot.bmpSize = 40;
	//engine->shot.buffS = malloc(engine->shot.imageSize);

}

void		some_func(t_engine *engine)
{
	if (sizeof(t_bmpFileHeader) != 14 && sizeof(t_bmpInfoHeader) != 40)
	{
		write(1, "Err", 5);
	}
	ft_init_shot(engine);

	t_bmpInfoHeader bmpInfoHeader;
	t_bmpFileHeader bmpFileHeader;
	int 			fd;

	fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	bmpFileHeader = (t_bmpFileHeader){ 0 };
	bmpInfoHeader = (t_bmpInfoHeader){ 0 };
	ft_memcpy(&bmpFileHeader, "BM", 2);
	bmpFileHeader.bmpSize = 54 + engine->shot.imageSize;
	bmpFileHeader.bmpOffBits = 54;
	bmpInfoHeader.bmpSize = 40;
	bmpInfoHeader.bmpWidth = engine->shot.scrWidth;
	bmpInfoHeader.bmpHeight = engine->shot.scrHeight;
	bmpInfoHeader.bmpBitCount = engine->shot.bitCount;
	bmpInfoHeader.bmpSizeImage = engine->shot.imageSize;

	engine->shot.buffS = malloc(engine->shot.imageSize);

	int range;
	int col;

	range = engine->shot.scrHeight - 1;

	while (range >= 0)
	{
		col = 0;
		while (col < engine->shot.scrWidth)
		{
			engine->shot.buffS[range * engine->shot.widthInBytes + col * 3 + 0] = 255; //blue
			engine->shot.buffS[range * engine->shot.widthInBytes + col * 3 + 1] = 0; //red
			engine->shot.buffS[range * engine->shot.widthInBytes + col * 3 + 2] = 0; //green
			col++;
		}
		range--;
	}
	write(fd, &bmpFileHeader, sizeof(bmpFileHeader));
	write(fd, &bmpInfoHeader, sizeof(bmpInfoHeader));
	write(fd, engine->shot.buffS, engine->shot.imageSize);
	close(fd);
	free(engine->shot.buffS);
}