/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:31:11 by amuriel           #+#    #+#             */
/*   Updated: 2021/04/01 16:31:43 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_check_texture_double(t_engine *engine)
{
	if (engine->tex_north == NULL &&
	engine->tex_south == NULL &&
	engine->tex_west == NULL &&
	engine->tex_east == NULL &&
	engine->tex_sprite == NULL)
		return (0);
	return (1);
}

int		ft_check_color_double(t_engine *engine)
{
	if (engine->rgb_ceiling.col_r == -1 &&
	engine->rgb_ceiling.col_g == -1 &&
	engine->rgb_ceiling.col_b == -1 &&
	engine->rgb_floor.col_r == -1 &&
	engine->rgb_floor.col_g == -1 &&
	engine->rgb_floor.col_b == -1)
		return (0);
	return (1);
}

void	ft_correct_colors(t_engine *engine, char *line)
{
	if ((*line == 'F' && *(line + 1) == ' ')
		|| (*line == 'C' && *(line + 1) == ' '))
	{
		if (ft_check_color_double(engine) && engine->pm.flag_color == 2)
			ft_print_error("Error!\nDouble colors!\n");
		if (ft_get_rgb_color(engine, line))
			ft_print_error("Error!\nInvalid map!\n");
		engine->pm.param++;
	}
}

void	ft_norm_pm2(t_engine *engine, char *line)
{
	free(engine->pm.tmp);
	engine->pm.tmp = ft_strdup(line);
}

void	ft_correct_texture2(t_engine *engine, char *line)
{
	if (ft_check_texture_double(engine) && engine->pm.flag_text == 5)
		ft_print_error("Error!\nDouble textures!\n");
	if (ft_get_texture_parse(engine, line))
		ft_print_error("Error!\nInvalid parse texture!\n");
	engine->pm.param++;
}
