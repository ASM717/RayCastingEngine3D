/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:29:22 by amuriel           #+#    #+#             */
/*   Updated: 2021/04/01 16:30:11 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_correct_texture(char *line)
{
	if ((*line == 'N' && *(line + 1) == 'O'
	&& *(line + 2) == ' ') ||
	(*line == 'S' && *(line + 1) == 'O'
	&& *(line + 2) == ' ') ||
	(*line == 'W' && *(line + 1) == 'E'
	&& *(line + 2) == ' ') ||
	(*line == 'E' && *(line + 1) == 'A'
	&& *(line + 2) == ' ') ||
	(*line == 'S' && *(line + 1) == ' '))
		return (1);
	return (0);
}

void	ft_norm_pm3(t_engine *engine, char *line)
{
	if (ft_check_scr_col_tex(engine))
		ft_print_error("Error map!\nSomething is missing!\n");
	if (engine->pm.tmp != NULL)
	{
		line = ft_strjoin_pm(engine->pm.tmp, line);
		free(engine->pm.tmp);
		engine->pm.tmp = ft_strdup(line);
		free(line);
		engine->world_map = ft_split(engine->pm.tmp, '+');
	}
	else
		ft_print_error("Error!\nInvalid map!\n");
	ft_parse_world_map(engine);
}

void	ft_norm_pm1(t_engine *engine, char *line)
{
	if (engine->pm.tmp && ft_strlen(line) == 0
	&& engine->pm.param == 8)
		ft_print_error("Error!\nInvalid map!\n");
}

void	ft_init_pm_start(t_engine *engine)
{
	engine->pm.flag_color = 0;
	engine->pm.flag_text = 0;
	engine->pm.param = 0;
	engine->pm.tmp = NULL;
}

void	ft_valid_open_map(t_engine *engine, char **argv)
{
	if (ft_strncmp(".cub", argv[1] + ft_strlen(argv[1]) - 4, 4))
		ft_print_error("Error!\nThe name of the map must end with .cub\n");
	if ((engine->pm.fd = open(argv[1], O_DIRECTORY)) != -1)
		ft_print_error("Error\nInvalid directory!\n");
	if ((engine->pm.fd = open(argv[1], O_RDONLY)) < 0)
		ft_print_error("Error\nSome problem with open file!\n");
}
