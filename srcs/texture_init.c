/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:08:05 by amuriel           #+#    #+#             */
/*   Updated: 2021/04/01 16:08:19 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init_texture2(t_engine *engine, int width, int height)
{
	engine->data_ea.img = mlx_xpm_file_to_image(engine->data.mlx,
		engine->tex_east, &width, &height);
	engine->data_ea.addr = mlx_get_data_addr(engine->data_ea.img,
		&engine->data_ea.bits_per_pixel, &engine->data_ea.size_line,
		&engine->data_ea.endian);
	engine->data_spr.img = mlx_xpm_file_to_image(engine->data.mlx,
		engine->tex_sprite, &width, &height);
	engine->data_spr.addr = mlx_get_data_addr(engine->data_spr.img,
		&engine->data_spr.bits_per_pixel, &engine->data_spr.size_line,
		&engine->data_spr.endian);
}

void	ft_free_texture(t_engine *engine)
{
	free(engine->tex_sprite);
	free(engine->tex_east);
	free(engine->tex_south);
	free(engine->tex_north);
	free(engine->tex_west);
}

void	ft_init_texture(t_engine *engine)
{
	int		width;
	int		height;

	width = TEX_WIDTH;
	height = TEX_HEIGHT;
	engine->data_no.img = mlx_xpm_file_to_image(engine->data.mlx,
		engine->tex_north, &width, &height);
	engine->data_no.addr = mlx_get_data_addr(engine->data_no.img,
		&engine->data_no.bits_per_pixel, &engine->data_no.size_line,
		&engine->data_no.endian);
	engine->data_so.img = mlx_xpm_file_to_image(engine->data.mlx,
		engine->tex_south, &width, &height);
	engine->data_so.addr = mlx_get_data_addr(engine->data_so.img,
		&engine->data_so.bits_per_pixel, &engine->data_so.size_line,
		&engine->data_so.endian);
	engine->data_we.img = mlx_xpm_file_to_image(engine->data.mlx,
		engine->tex_west, &width, &height);
	engine->data_we.addr = mlx_get_data_addr(engine->data_we.img,
		&engine->data_we.bits_per_pixel, &engine->data_we.size_line,
		&engine->data_we.endian);
	ft_init_texture2(engine, width, height);
	ft_free_texture(engine);
}
