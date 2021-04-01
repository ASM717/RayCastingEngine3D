/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:35:29 by amuriel           #+#    #+#             */
/*   Updated: 2021/04/01 16:36:52 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_check_more_players(t_engine *engine)
{
	if (engine->pos_x || engine->pos_y)
		return (1);
	return (0);
}

void	ft_check_player_position2(t_engine *engine, int i, int j)
{
	if (ft_strchr("W", engine->world_map[i][j]))
	{
		engine->pm.flag_pos_pl = 1;
		engine->dir_x = 0;
		engine->dir_y = -1;
		engine->plane_x = -0.66;
		engine->plane_y = 0;
	}
	else if (ft_strchr("E", engine->world_map[i][j]))
	{
		engine->pm.flag_pos_pl = 1;
		engine->dir_x = 0;
		engine->dir_y = 1;
		engine->plane_x = 0.66;
		engine->plane_y = 0;
	}
}

void	ft_check_player_position1(t_engine *engine, int i, int j)
{
	if (ft_strchr("NSWE", engine->world_map[i][j]))
	{
		engine->pos_x = i + 0.5;
		engine->pos_y = j + 0.5;
	}
	if (ft_strchr("N", engine->world_map[i][j]))
	{
		engine->pm.flag_pos_pl = 1;
		engine->dir_x = -1;
		engine->dir_y = 0;
		engine->plane_x = 0;
		engine->plane_y = 0.66;
	}
	else if (ft_strchr("S", engine->world_map[i][j]))
	{
		engine->pm.flag_pos_pl = 1;
		engine->dir_x = 1;
		engine->dir_y = 0;
		engine->plane_x = 0;
		engine->plane_y = -0.66;
	}
	ft_check_player_position2(engine, i, j);
}

void	ft_check_closed_map2(t_engine *engine, int i, int j)
{
	if (engine->world_map[i - 1][j - 1] == ' ')
		ft_print_error("Error!\nMap error_6!\n");
	if (engine->world_map[i + 1][j + 1] == ' ')
		ft_print_error("Error!\nMap error_7!\n");
	if (engine->world_map[i - 1][j + 1] == ' ')
		ft_print_error("Error!\nMap error_8!\n");
	if (engine->world_map[i + 1][j - 1] == ' ')
		ft_print_error("Error!\nMap error_9!\n");
}

void	ft_check_closed_map1(t_engine *engine, int i, int j)
{
	if (i == 0 || i == engine->pm.countlines - 1)
		ft_print_error("Error!\nMap error_1!\n");
	if (j == 0 || j == (int)ft_strlen(engine->world_map[i]) - 1)
		ft_print_error("Error!\nMap error_2!\n");
	if (engine->world_map[i][j - 1] == ' ' ||
	engine->world_map[i][j + 1] == ' ')
		ft_print_error("Error!\nMap error_3!\n");
	if (j >= ((int)ft_strlen(engine->world_map[i + 1]) - 1) ||
	j >= ((int)ft_strlen(engine->world_map[i - 1]) - 1))
		ft_print_error("Error!\nMap error_4!\n");
	if ((engine->world_map[i + 1][j]) == ' ' ||
	(engine->world_map[i - 1][j]) == ' ')
		ft_print_error("Error!\nMap error_5!\n");
}
