/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:57:45 by amuriel           #+#    #+#             */
/*   Updated: 2021/03/16 17:24:06 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "srcs/gnl/get_next_line.h"
# include "minilibx-linux/mlx.h"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# include <stdio.h>

# define ESC			65307
# define W				119
# define S				115
# define A				97
# define D				100
# define KEY_LEFT		65361
# define KEY_RIGHT		65363

# define mapWidth		24
# define mapHeight		24

# define SCR_WIDTH		1920
# define SCR_HEIGHT		1080

# define TEX_WIDTH		64
# define TEX_HEIGHT		64

# define MOVESPEED		0.2
# define ROTSPEED		0.05

# define NO "textures/marbface.xpm"
# define SO "textures/mountains.xpm"
# define WE "textures/metal.xpm"
# define EA "textures/brick.xpm"
# define SP "textures/barrel.xpm"

char					worldMap[mapWidth][mapHeight];

typedef struct			s_data
{
	void				*img;
	void				*mlx;
	void				*win;
	char				*addr;
	int					bitsPerPixel;
	int					sizeLine;
	int					endian;
}						t_data;

typedef struct			s_rgb
{
	int 				colR;
	int 				colG;
	int 				colB;
	unsigned int 		rgbColor;
}						t_rgb;


typedef struct			s_sprite
{
	double				xStr;
	double				yStr;
}						t_sprite;

typedef struct			s_engine
{
	t_data				data;
	t_data				dataNO;
	t_data				dataSO;
	t_data				dataWE;
	t_data				dataEA;
	t_data				dataSPR;
	t_sprite			*strSpr;
	t_rgb				rgbFloor;
	t_rgb				rgbCeiling;

	int 				scrHeight;
	int 				scrWidth;


	int 				x;
	int 				y;
	double				posX;
	double				posY;
	double				dirX;
	double				dirY;
	double				planeX;
	double				planeY;
	double				rayDirX;
	double				rayDirY;
	int					mapX;
	int					mapY;
	double				sideDistX;
	double				sideDistY;
	double				deltaDistX;
	double				deltaDistY;
	int					stepX;
	int					stepY;
	int					side;
	int					drawStart;
	int					drawEnd;
	double				perpWallDist;
	int 				lineHeight;

	int 				keycodeW;
	int 				keycodeS;
	int 				keycodeA;
	int 				keycodeD;
	int					keycodeLeft;
	int					keycodeRight;

	double				wallX;
	int 				textureX;
	int					textureY;
	char 				wallRoute;
	double				step;
	double				texPos;
	int					color;

	char 				*texNorth;
	char 				*texSouth;
	char 				*texWest;
	char 				*texEast;
	char 				*texSprite;

	double				*zBuff;

	int 				spriteNum;
	int 				*spriteOrder;
	double				*spriteDist;

	double				sortSpriteX;
	double				sortSpriteY;

	double				spriteX;
	double				spriteY;
	double				invDet;
	double				transformX;
	double 				transformY;
	int 				spriteScrX;
	int 				spriteH;
	int 				drawStartY;
	int 				drawEndY;
	int 				spriteW;
	int 				drawStartX;
	int					drawEndX;
	int					stripe;
	int					sprTextX;
	int 				sprTextY;
	int 				tmpSprY;
	int					tmpSprD;
	int 				sprCol;


}						t_engine;

int		check_movement(int x, int y);
void	ft_keycode_handle(t_engine *engine);
int		ft_keycode_used(int keycode, t_engine *engine);
int		ft_keycode_unused(int keycode, t_engine *engine);
int		ft_exit(t_engine *engine);

unsigned	int	get_pixel(t_data *data, int x, int y);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);

void 	ft_main_sprites(t_engine *engine);
void	ft_sort_swap(t_engine *engine);
t_sprite			*ft_get_sprites(t_engine *engine);
int		ft_number_sprites();

int 	ft_init_color_rgb(t_engine *engine);
int 	ft_get_rgb_color_ceiling(t_engine *engine);
int 	ft_get_rgb_color_floor(t_engine *engine);

#endif
