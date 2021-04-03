/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:33:32 by amuriel           #+#    #+#             */
/*   Updated: 2021/04/03 11:49:43 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_arr_string_len(char **arr)
{
	int i;

	i = 0;
	while (!arr)
		return (0);
	while (arr[i])
		i++;
	return (i);
}

void	ft_check_map_player(t_engine *engine, int i, int j)
{
	ft_check_closed_map1(engine, i, j);
	ft_check_closed_map2(engine, i, j);
	if (ft_strchr("NSWE", engine->world_map[i][j])
	&& engine->pm.flag_pos_pl)
		ft_print_error("Error!\nMore than one player on the map!\n");
	ft_check_player_position1(engine, i, j);
}

void	ft_parse_world_map(t_engine *engine)
{
	int i;
	int j;

	engine->pm.flag_pos_pl = 0;
	engine->pm.countlines = ft_arr_string_len(engine->world_map);
	i = 0;
	while (i < engine->pm.countlines)
	{
		j = 0;
		while (j < (int)ft_strlen(engine->world_map[i]))
		{
			if ((ft_strchr("NSWE012 ", engine->world_map[i][j]) == 0))
				ft_print_error("Error!\nInvalid map!\n");
			if ((engine->world_map[i][j] != '1') &&
			(engine->world_map[i][j] != ' '))
				ft_check_map_player(engine, i, j);
			j++;
		}
		i++;
	}
	if (engine->pm.flag_pos_pl == 0)
		ft_print_error("Error!\nInvalid map!\n");
}

void	ft_correct_permission(t_engine *engine, char *line)
{
	if (*line == 'R' && *(line + 1) == ' ')
	{
		if (ft_check_perm_double(engine) && engine->pm.flag_perm)
			ft_print_error("Error!\nResolution repeats!\n");
		ft_get_resolution(engine);
		engine->pm.param++;
	}
}

int		ft_check_scr_col_tex(t_engine *engine)
{
	if (engine->scr_height == -1 ||
		engine->scr_width == -1 ||
		engine->tex_north == NULL ||
		engine->tex_south == NULL ||
		engine->tex_west == NULL ||
		engine->tex_east == NULL ||
		engine->tex_sprite == NULL ||
		engine->rgb_ceiling.col_r == -1 ||
		engine->rgb_ceiling.col_g == -1 ||
		engine->rgb_ceiling.col_b == -1 ||
		engine->rgb_floor.col_r == -1 ||
		engine->rgb_floor.col_g == -1 ||
		engine->rgb_floor.col_b == -1)
		return (1);
	return (0);
}
