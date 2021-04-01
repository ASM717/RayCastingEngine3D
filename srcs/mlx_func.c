/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:52:32 by amuriel           #+#    #+#             */
/*   Updated: 2021/04/01 15:53:42 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_restart(t_engine *engine)
{
	ft_keycode_movement(engine);
	engine->z_buff = malloc(sizeof(double) * engine->scr_width);
	ft_raycast(engine);
	if (engine->screen_flag == 0)
		mlx_put_image_to_window(engine->data.mlx, engine->data.win,
		engine->data.img, 0, 0);
	free(engine->z_buff);
	if (engine->screen_flag == 1)
		ft_screenshot_make(engine);
	return (0);
}

void	ft_screenshot_start(t_engine *engine)
{
	if (!(engine->data.mlx = mlx_init()))
		ft_print_error("Error!\nProblem with mlx_init!\n");
	ft_init_texture(engine);
	engine->data.img = mlx_new_image(engine->data.mlx,
		engine->scr_width, engine->scr_height);
	engine->data.addr = mlx_get_data_addr(engine->data.img,
		&engine->data.bits_per_pixel,
		&engine->data.size_line,
		&engine->data.endian);
	ft_restart(engine);
}

void	ft_mlx_data_continue(t_engine *engine)
{
	mlx_hook(engine->data.win, 2, (1L << 0),
		ft_keycode_used, engine);
	mlx_hook(engine->data.win, 3, (1L << 1),
		ft_keycode_unused, engine);
	mlx_hook(engine->data.win, 33, (1L << 0), ft_exit, engine);
	mlx_loop_hook(engine->data.mlx, ft_restart, engine);
	mlx_loop(engine->data.mlx);
}

void	ft_mlx_data_start(t_engine *engine)
{
	ft_init_keycode(engine);
	if (!(engine->data.mlx = mlx_init()))
		ft_print_error("Error!\nProblem with mlx_init!\n");
	if (!(engine->data.win = mlx_new_window(engine->data.mlx,
		engine->scr_width, engine->scr_height, "Cub3D")))
		ft_print_error("Error!\nProblem with mlx_new_window!\n");
	ft_init_texture(engine);
	engine->data.img = mlx_new_image(engine->data.mlx,
		engine->scr_width, engine->scr_height);
	engine->data.addr = mlx_get_data_addr(engine->data.img,
		&engine->data.bits_per_pixel, &engine->data.size_line,
		&engine->data.endian);
}
