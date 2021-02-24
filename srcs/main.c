/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:08:51 by amuriel           #+#    #+#             */
/*   Updated: 2021/02/24 19:27:39 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_rgb	ft_rgb(int r, int g, int b)
{
	t_rgb	rgb;

	rgb.r = r;
	rgb.g = g;
	rgb.b = b;
	rgb.color = ((r * 256 * 256) + (g * 256) + b);
	return (rgb);
}

void	ft_init_all_struct(t_engine *engine)
{
	engine->side.east = NULL;
	engine->side.north = NULL;
	engine->side.south = NULL;
	engine->side.west = NULL;
	engine->screen.height = -1;
	engine->screen.width = -1;
	engine->keyb.w = 0;
	engine->keyb.s = 0;
	engine->keyb.d = 0;
	engine->keyb.a = 0;
	engine->keyb.escape = 0;
	engine->keyb.left = 0;
	engine->keyb.right = 0;
	// game->data.addr = NULL;
	// game->data.bits_per_pixel = 0;
	// game->data.endian = 0;
	// game->data.endian = 0;
	// game->data.img = 0;
	// game->data.win = 0;
	// game->data.mlx = 0;
	engine->map = NULL;
	engine->sprite = NULL;
	engine->f_rgb = ft_rgb(-1, -1, -1);
	engine->c_rgb = ft_rgb(-1, -1, -1);
}

void	ft_init_start_parser(t_parser *parser)
{
	parser->flag = 0;
	parser->size = 0;
	parser->head = 0;
	parser->line = 0;
}

int	ft_square(char c)
{
	if (c != ' ' || c != '1')
		return (1);
	return (0);
}

int		ft_indent(int i, int j, char **s)
{
	if (i == 0 || i == ft_str_array_map_len(s) - 1)
		return (1);
	if (j == 0 || j == ft_strlen(s[i]) - 1)
		return (1);
	if (s[i][j - 1] == ' ' || s[i][j + 1] == ' ')
		return (1);
	if (s[i - 1][j] == ' ' || s[i + 1][j] == ' ')
		return (1);
	if (j > (ft_strlen(s[i - 1]) - 1) || j > (ft_strlen(s[i + 1]) - 1))
		return (1);
	return (0);
}

int		ft_player_verification(char c, t_parser *parser) //*
{
	if (ft_strchr("WESN", c))
	{
		if (parser->flag_verif == 1) //* or &
			return (1);
		parser->flag_verif = 1;
	}
	return (0);
}

int		ft_str_array_map_len(char **s)
{
	int	length;

	length = 0;
	if (!s)
		return (0);
	while (s[length])
		length++;
	return (length);
}

int		ft_map_verification(char **s, t_parser *parser)
{
	int	i;
	int	j;
	int	count;

	parser->flag_verif = 0;
	i = 0;
	count = ft_str_array_map_len(s);
	while (i < count)
	{
		j = 0;
		while (j < ft_strlen(s[i]))
		{
			if (ft_square(s[i][j]) && ft_indent(i, j, s))
				return (-1);
			if (ft_player_verification(s[i][j], parser))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

char	**ft_build_map(t_parser *parser)
{
	t_engine	engine;
	int			i;
	t_list		*tmp;

	i = 0;
	engine.map = ft_calloc((parser->size + 1), sizeof(char *));
	tmp = parser->head;
	while (tmp)
	{
		engine.map[i] = ft_strdup(tmp->content);
		i++;
		tmp = tmp->next;
	}
	ft_lstclear(&parser->head, &free);
	return (engine.map);
}

void	ft_free_array_str(char **s)
{
	int i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

int		ft_parser2(t_parser *parser, t_engine *engine)
{
	int sz;

	sz = 0;
	engine->map = 0;
	engine->map = ft_split(parser->line, ' ');
	//parser->flag = ft_check_texture(game->map, game);
	if (parser->flag == 1 && parser->line)
	{
		ft_lstadd_back(&(parser->head), ft_lstnew(parser->line));
		sz++;
		parser->line = NULL;
	}
	if (parser->flag)
		ft_free_array_str(engine->map);
	engine->map = NULL;
	return (sz);
}

#include <stdio.h>

int		ft_start_parser(int fd, t_parser *parser, t_engine *engine)
{
	ft_init_start_parser(parser);

	ft_init_all_struct(engine);

	while (parser->flag != -1 && get_next_line(fd, &parser->line))
		parser->size += ft_parser2(parser, engine);
	printf("\nflag %d\n", parser->flag);
	ft_lstadd_back(&parser->head, ft_lstnew(parser->line));
	parser->size++;
	engine->map = ft_build_map(parser);
	if (ft_map_verification(engine->map, parser))
		parser->flag = -1;
	return (parser->flag);
}

void	ft_err_print(char *s)
{
	write(2, s, ft_strlen(s));
	exit(EXIT);
}

int		ft_file_exist(char *s)
{
	int i;

	i = 0;
	while (s[i] != '.' && s[i])
		i++;
	if (ft_strncmp(&s[i], ".cub", ft_strlen(&s[i])) == 0)
	{
		return (1);
	}
	return (0);
}

int		ft_exist_screensave(char *s)
{
	if (ft_strncmp(s, "--save", ft_strlen(s)))
		return (0);
	return (1);
}

// void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
//     char    *dst;

//     dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//     *(unsigned int*)dst = color;
// }

int		main(int ac, char **av)
{
	int			fd;
	t_engine	engine;
	t_parser	parser;


	if (ac < 2 || ac > 3)
		ft_err_print("ERROR! Need 2 or 3 argc\n");

	if (!ft_file_exist(av[1]))
		ft_err_print("ERROR! File not exist\n");

	if (ac == 3 && !ft_exist_screensave(av[2]))
		ft_err_print("ERROR!\n");
	fd = open(av[1], O_RDONLY);

	if (fd < 0)
		ft_err_print("ERROR!\n");

	if (ft_start_parser(fd, &parser, &engine) == -1)
		ft_err_print("ERROR!\n");
	printf("\nStepan %d\n", ac);

	// if (ac == 2)
	// 	ft_start_game(&game);
	// else if (ac == 3)
	// 	ft_screenshoting(&game);
	return (0);
}
