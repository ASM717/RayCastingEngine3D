/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot_bmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 02:55:01 by amuriel           #+#    #+#             */
/*   Updated: 2021/03/22 02:55:06 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_screen_pack(t_engine *engine)
{
	engine->shot.range = engine->scr_height - 1;
	while (engine->shot.range >= 0)
	{
		engine->shot.col = 0;
		while (engine->shot.col < engine->scr_width)
		{
			engine->shot.color_table = ft_get_pixel(&engine->data,
									   engine->shot.col,
									   engine->shot.range);
			write(engine->shot.fd, &engine->shot.color_table, 4);
			engine->shot.col++;
		}
		engine->shot.range--;
	}
}

static void	ft_init_shot_header(t_engine *engine)
{
	engine->shot.zero = 0;
	write(engine->shot.fd, &engine->shot.zero, 4);
	engine->shot.bmp_off_bits = 54;
	write(engine->shot.fd, &engine->shot.bmp_off_bits, 4);
	engine->shot.bmp_size = 40;
	write(engine->shot.fd, &engine->shot.bmp_size, 4);
	write(engine->shot.fd, &engine->scr_width, 4);
	write(engine->shot.fd, &engine->scr_height, 4);
	engine->shot.bmp_plane = 1;
	write(engine->shot.fd, &engine->shot.bmp_plane, 2);
	write(engine->shot.fd, &engine->data.bits_per_pixel, 2);
	write(engine->shot.fd, &engine->shot.zero, 24);
}

void		ft_screenshot_make(t_engine *engine)
{
	if (!(engine->shot.fd = open("Cub3D.bmp", O_CREAT |
	O_WRONLY | O_TRUNC, S_IRWXU)))
		write(1, "Error ", 11);
	write(engine->shot.fd, "BM", 2);
	engine->shot.scr_size = 4 * engine->scr_width * engine->scr_height +
			engine->shot.bmp_off_bits;
	write(engine->shot.fd, &engine->shot.scr_size, 4);
	ft_init_shot_header(engine);
	ft_screen_pack(engine);
	close(engine->shot.fd);
	exit(0);
}
