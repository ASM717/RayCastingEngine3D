

#include "../cub3d.h"

char	*ft_strjoin_pars(char *s1, char *s2)
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
	free(s1);
	str[i++] = '+';
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		++i;
		++j;
	}
	str[i] = '\0';
	return (str);
}

void	ft_print_error(char *s)
{
	write(2, s, ft_strlen(s));
	exit(-1);
}

void 	ft_var_zero(t_engine *engine)
{
	engine->scr_width = 0;
	engine->scr_height = 0;
	engine->tex_north = NULL;
	engine->tex_south = NULL;
	engine->tex_west = NULL;
	engine->tex_east = NULL;
	engine->tex_sprite = NULL;
	engine->rgb_ceiling.col_r = -1;
	engine->rgb_ceiling.col_g = -1;
	engine->rgb_ceiling.col_b = -1;
	engine->rgb_floor.col_r = -1;
	engine->rgb_floor.col_g = -1;
	engine->rgb_floor.col_b = -1;
}

int		ft_arr_string_len(char **map)
{
	int i;

	i = 0;
	while (!map)
		return (0);
	while (map[i])
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
		ft_print_error("Error! Map without player position!\n");
}

int 	ft_start_parse(char **argv, t_engine *engine)
{
	int		fd;

	engine->pm.param = 0;
	engine->pm.tmp = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_print_error("Error open file!\n");
	while (get_next_line(fd, &engine->pm.line))
	{
		engine->pm.tmp2 = ft_split(engine->pm.line, ' ');
		if (*engine->pm.line == 'R' && *(engine->pm.line + 1) == ' ')
		{
			ft_get_resolution(engine);
			engine->pm.param++;
		}
		else if ((*engine->pm.line == 'F' && *(engine->pm.line + 1) == ' ')
		|| (*engine->pm.line == 'C' && *(engine->pm.line + 1) == ' '))
		{
			if (ft_get_rgb_color(engine))
				ft_print_error("Error map!\n");
			engine->pm.param++;
		}
		else if ((*engine->pm.line == 'N' && *(engine->pm.line + 1) == 'O'
		&& *(engine->pm.line + 2) == ' ') ||
		(*engine->pm.line == 'S' && *(engine->pm.line + 1) == 'O'
		&& *(engine->pm.line + 2) == ' ') ||
		(*engine->pm.line == 'W' && *(engine->pm.line + 1) == 'E'
		&& *(engine->pm.line + 2) == ' ') ||
		(*engine->pm.line == 'E' && *(engine->pm.line + 1) == 'A'
		&& *(engine->pm.line + 2) == ' ') ||
		(*engine->pm.line == 'S' && *(engine->pm.line + 1) == ' '))
		{
			if (ft_get_texture_parse(engine))
				ft_print_error("Error parse texture!\n");
			engine->pm.param++;
		}
		else
		{
			if (engine->pm.tmp && (*engine->pm.line == ' ' ||
			*engine->pm.line == '1'))
				engine->pm.line = ft_strjoin_pars(engine->pm.tmp,
									  engine->pm.line);
		}
		if (engine->pm.param == 8)
			engine->pm.tmp = engine->pm.line;
	}
	engine->world_map = ft_split(engine->pm.tmp, '+');
	ft_parse_world_map(engine);
	close(fd);
	return (0);
}