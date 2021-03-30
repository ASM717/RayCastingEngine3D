/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pm_rgb_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:31:45 by amuriel           #+#    #+#             */
/*   Updated: 2021/03/30 14:31:49 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_check_rgb(char *s)
{
	int color;

	color = ft_atoi(s);
	if (color < 0 || color > 255)
		ft_print_error("Error RGB number!\n");
	return (color);
}

void	ft_get_rgb_color_c(t_engine *engine, char **var)
{
	engine->rgb_ceiling.col_r = ft_check_rgb(var[0]);
	engine->rgb_ceiling.col_g = ft_check_rgb(var[1]);
	engine->rgb_ceiling.col_b = ft_check_rgb(var[2]);
}

void	ft_get_rgb_color_f(t_engine *engine, char **var)
{
	engine->rgb_floor.col_r = ft_check_rgb(var[0]);
	engine->rgb_floor.col_g = ft_check_rgb(var[1]);
	engine->rgb_floor.col_b = ft_check_rgb(var[2]);
}

int		ft_get_rgb_color(t_engine *engine, char *line)
{
	char **var;

	if (engine->pm.tmp2[2])
		return (1);
	var = ft_split(engine->pm.tmp2[1], ',');
	if ((ft_isdigit_pm(var[0]) && ft_isdigit_pm(var[1]) &&
	ft_isdigit_pm(var[2])) && !var[3])
	{
		if (*line == 'F' && *(line + 1) == ' ')
			ft_get_rgb_color_f(engine, var);
		else if (*line == 'C' && *(line + 1) == ' ')
			ft_get_rgb_color_c(engine, var);
	}
	else
		ft_print_error("Error!\nInvalid input color!\n");
	engine->pm.flag_color++;
	ft_free_array(&var);
	return (0);
}
