/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 11:04:22 by amuriel           #+#    #+#             */
/*   Updated: 2021/04/03 14:05:24 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_print_error(char *s)
{
	write(2, s, ft_strlen(s));
	exit(-1);
}

void	ft_pm_start_valid_open_map(t_engine *engine, char **argv)
{
	ft_init_pm_start(engine);
	ft_valid_open_map(engine, argv);
}

void	ft_correct_perm_color(t_engine *engine, char *line)
{
	ft_correct_permission(engine, line);
	ft_correct_colors(engine, line);
}

void	ft_check_impossible_symbol(t_engine *engine, char *line)
{
	int i;

	if (ft_strlen(line) && engine->pm.param < 8 && *line != 'R'
	&& (*line != 'N' && *(line + 1) != 'O')
	&& (*line != 'S' && *(line + 1) != 'O')
	&& (*line != 'W' && *(line + 1) != 'E')
	&& (*line != 'E' && *(line + 1) != 'A')
	&& (*line != 'S')
	&& (*line != 'F')
	&& (*line != 'C'))
	{
		i = 0;
		while (line[i])
		{
			if (line[i] != ' ')
				ft_print_error("Error!\nInvalid map\n");
			i++;
		}
	}
}

int		ft_start_parse(char **argv, t_engine *engine)
{
	char	*line;

	ft_pm_start_valid_open_map(engine, argv);
	while (get_next_line(engine->pm.fd, &line))
	{
		engine->pm.tmp2 = ft_split(line, ' ');
		ft_correct_perm_color(engine, line);
		if (ft_correct_texture(line))
			ft_correct_texture2(engine, line);
		else
		{
			ft_norm_pm1(engine, line);
			if (engine->pm.tmp && (*line == ' ' ||
			*line == '1' || *line == '0'))
				line = ft_strjoin_pm(engine->pm.tmp, line);
		}
		ft_check_impossible_symbol(engine, line);
		if (engine->pm.param == 8 && (*line == ' ' ||
		*line == '1' || *line == '0'))
			ft_norm_pm2(engine, line);
		ft_free_array(&engine->pm.tmp2);
		free(line);
	}
	ft_norm_pm3(engine, line);
	return (0);
}
