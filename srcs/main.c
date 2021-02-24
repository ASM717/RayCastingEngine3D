/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:08:51 by amuriel           #+#    #+#             */
/*   Updated: 2021/02/24 18:33:57 by amuriel          ###   ########.fr       */
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

void	ft_init_all_struct(t_engine *game)
{
	game->side.east = NULL;
	game->side.north = NULL;
	game->side.south = NULL;
	game->side.west = NULL;
	game->screen.height = -1;
	game->screen.width = -1;
	game->keyb.w = 0;
	game->keyb.s = 0;
	game->keyb.d = 0;
	game->keyb.a = 0;
	game->keyb.escape = 0;
	game->keyb.left = 0;
	game->keyb.right = 0;
	// game->data.addr = NULL;
	// game->data.bits_per_pixel = 0;
	// game->data.endian = 0;
	// game->data.endian = 0;
	// game->data.img = 0;
	// game->data.win = 0;
	// game->data.mlx = 0;
	game->map = NULL;
	game->sprite = NULL;
	game->f_rgb = ft_rgb(-1, -1, -1);
	game->c_rgb = ft_rgb(-1, -1, -1);
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

int		ft_indent(int i, int j, char **str)
{
	if (i == 0 || i == ft_str_array_map_len(str) - 1)
		return (1);
	if (j == 0 || j == ft_strlen(str[i]) - 1)
		return (1);
	if (str[i][j - 1] == ' ' || str[i][j + 1] == ' ')
		return (1);
	if (str[i - 1][j] == ' ' || str[i + 1][j] == ' ')
		return (1);
	if (j > (ft_strlen(str[i - 1]) - 1) || j > (ft_strlen(str[i + 1]) - 1))
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

int		ft_str_array_map_len(char **str)
{
	int	length;

	length = 0;
	if (!str)
		return (0);
	while (str[length])
		length++;
	return (length);
}

int		ft_map_verification(char **str, t_parser *parser)
{
	int	i;
	int	j;
	int	count;

	parser->flag_verif = 0;
	i = 0;
	count = ft_str_array_map_len(str);
	while (i < count)
	{
		j = 0;
		while (j < ft_strlen(str[i]))
		{
			if (ft_square(str[i][j]) && ft_indent(i, j, str))
				return (-1);
			if (ft_player_verification(str[i][j], parser))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

char	**ft_build_map(t_parser *parser)
{
	t_engine	game;
	int			i;
	t_list		*tmp;

	i = 0;
	game.map = ft_calloc((parser->size + 1), sizeof(char *));
	tmp = parser->head;
	while (tmp)
	{
		game.map[i] = ft_strdup(tmp->content);
		i++;
		tmp = tmp->next;
	}
	ft_lstclear(&parser->head, &free);
	return (game.map);
}

void	ft_free_array_str(char **s)
{
	int i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

int		ft_parser2(t_engine *game)
{
	t_parser parser;

	game->map = 0;
	parser.size = 0;
	game->map = ft_split(parser.line, ' ');
	//parser->flag = ft_check_texture(game->map, game);
	if (parser.flag == 1 && parser.line)
	{
		ft_lstadd_back(&(parser.head), ft_lstnew(parser.line));
		parser.size++;
		parser.line = NULL;
	}
	if (parser.flag)
		ft_free_array_str(game->map);
	game->map = NULL;
	return (parser.size);
}

int		ft_start_parser(int fd, t_parser *parser, t_engine *game)
{
	ft_init_start_parser(parser);
	ft_init_all_struct(game);
	while (parser->flag != -1 && get_next_line(fd, &parser->line))
		parser->size += ft_parser2(game);
	ft_lstadd_back(&parser->head, ft_lstnew(parser->line));
	parser->size++;
	game->map = ft_build_map(parser);
	if (ft_map_verification(game->map, parser))
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
	t_engine	game;
	t_parser	parser;

	if (ac < 2 || ac > 3)
		ft_err_print("ERROR!\n");
	if (!ft_file_exist(av[1]))
		ft_err_print("ERROR!\n");
	if (ac == 3 && !ft_exist_screensave(av[2]))
		ft_err_print("ERROR!\n");
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_err_print("ERROR!\n");
	if (ft_start_parser(fd, &parser, &game) == -1)
		ft_err_print("ERROR!\n");
	// if (ac == 2)
	// 	ft_start_game(&game);
	// else if (ac == 3)
	// 	ft_screenshoting(&game);
	return (0);
}
