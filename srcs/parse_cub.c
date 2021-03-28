
#include "../cub3d.h"

void	ft_free_array(char ***arr)
{
	int	i;

	i = 0;
	if (*arr == NULL)
		return ;
	while ((*arr)[i])
	{
		free((*arr)[i]);
		(*arr)[i] = NULL;
		i++;
	}
	free(*arr);
	*arr = NULL;
}

char	*ft_strjoin_pm(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(str = malloc(ft_strlen(s1) + ft_strlen(s2) + 2)))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		++i;
	}
	str[i++] = '+';
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		++i;
		++j;
	}
	free(s2);
	str[i] = '\0';
	return (str);
}

void	ft_print_error(char *s)
{
	write(2, s, ft_strlen(s));
	exit(-1);
}

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

void	ft_check_player_position1(t_engine *engine, int i, int j)
{
	if (ft_strchr("NSWE", engine->world_map[i][j]))
	{
		engine->pos_x = i + 0.5;
		printf("posx - %f\n", engine->pos_x);
		engine->pos_y = j + 0.5;
		printf("posy - %f\n", engine->pos_y);
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
	else if (ft_strchr("W", engine->world_map[i][j]))
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

void	ft_check_closed_map2(t_engine *engine, int i, int j)
{
	if (engine->world_map[i - 1][j - 1] == ' ')
		ft_print_error("Map error_6!\n");
	if (engine->world_map[i + 1][j + 1] == ' ')
		ft_print_error("Map error_7!\n");
	if (engine->world_map[i - 1][j + 1] == ' ')
		ft_print_error("Map error_8!\n");
	if (engine->world_map[i + 1][j - 1] == ' ')
		ft_print_error("Map error_9!\n");
}

void	ft_check_closed_map1(t_engine *engine, int i, int j)
{
	if (i == 0 || i == engine->pm.countlines - 1)
		ft_print_error("Map error_1!\n");
	if (j == 0 || j == (int)ft_strlen(engine->world_map[i]) - 1)
		ft_print_error("Map error_2!\n");
	if (engine->world_map[i][j - 1] == ' ' ||
	engine->world_map[i][j + 1] == ' ')
		ft_print_error("Map error_3!\n");
	if (j >= ((int)ft_strlen(engine->world_map[i + 1]) - 1) ||
	j > ((int)ft_strlen(engine->world_map[i - 1]) - 1))
		ft_print_error("Map error_4!\n");
	if ((engine->world_map[i + 1][j]) == ' ' ||
	(engine->world_map[i - 1][j]) == ' ')
		ft_print_error("Map error_5!\n");
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
			if ((engine->world_map[i][j] != '1') &&
			(engine->world_map[i][j] != ' '))
			{
				ft_check_closed_map1(engine, i, j);
				ft_check_closed_map2(engine, i, j);
				ft_check_player_position1(engine, i, j);
			}
			j++;
		}
		i++;
	}
	if (engine->pm.flag_pos_pl == 0)
		ft_print_error("Map Error!!!\n");
}

void	ft_correct_permission(t_engine *engine, char *line)
{
	if (*line == 'R' && *(line + 1) == ' ')
	{
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

int 	ft_start_parse(char **argv, t_engine *engine)
{
	int		fd;
	char	*line;

	engine->pm.param = 0;
	engine->pm.tmp = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_print_error("Error open file!\n");
	while (get_next_line(fd, &line))
	{
		engine->pm.tmp2 = ft_split(line, ' ');
		ft_correct_permission(engine, line);
		if ((*line == 'F' && *(line + 1) == ' ')
		|| (*line == 'C' && *(line + 1) == ' '))
		{
			if (ft_get_rgb_color(engine, line))
				ft_print_error("Error map!\n");
			engine->pm.param++;
		}
		else if ((*line == 'N' && *(line + 1) == 'O'
		&& *(line + 2) == ' ') ||
		(*line == 'S' && *(line + 1) == 'O'
		&& *(line + 2) == ' ') ||
		(*line == 'W' && *(line + 1) == 'E'
		&& *(line + 2) == ' ') ||
		(*line == 'E' && *(line + 1) == 'A'
		&& *(line + 2) == ' ') ||
		(*line == 'S' && *(line + 1) == ' '))
		{
			if (ft_get_texture_parse(engine, line))
				ft_print_error("Error parse texture!\n");
			engine->pm.param++;
		}
		else
		{
			if (engine->pm.tmp && (*line == ' ' || *line == '1'))
				line = ft_strjoin_pm(engine->pm.tmp, line);
		}
		if (engine->pm.param == 8)
		{
			free(engine->pm.tmp);
			engine->pm.tmp = ft_strdup(line);
		}
		ft_free_array(&engine->pm.tmp2);
		free(line);
	}
	if (ft_check_scr_col_tex(engine))
		ft_print_error("Error map! Something is missing!\n");
	line = ft_strjoin_pm(engine->pm.tmp, line);
	free(engine->pm.tmp);
	engine->pm.tmp = ft_strdup(line);
	free(line);
	engine->world_map = ft_split(engine->pm.tmp, '+');
	ft_parse_world_map(engine);
	close(fd);
	return (0);
}