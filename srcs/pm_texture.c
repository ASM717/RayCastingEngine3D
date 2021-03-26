
#include "../cub3d.h"

int		ft_check_fd_texture(char *tmp2)
{
	int fd;
	int	x;

	fd = open(tmp2, O_RDONLY);
	x = fd;
	close(fd);
	if (x  < 0)
		ft_print_error("Error texture fd!\n");
	return (0);
}

int		ft_checker_space_tx(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			count++;
		i++;
	}
	return (count);
}

int		ft_get_texture_parse(t_engine *engine, char *line)
{
	char	**var;

	var = ft_split(line, ' ');
	if (ft_checker_space_tx(line) !=
	((int)ft_strlen(var[0]) + (int)ft_strlen(var[1])))
		ft_print_error("Map Error! Texture undefined\n");
	ft_check_fd_texture(var[1]);
	if (*line == 'N' && *(line + 1) == 'O'
	&& *(line + 2) == ' ')
	{
		engine->tex_north = ft_strdup(var[1]);
		printf("%s\n", engine->tex_north);
	}
	else if (*line == 'S' && *(line + 1) == 'O'
	&& *(line + 2) == ' ')
	{
		engine->tex_south = ft_strdup(var[1]);
		printf("%s\n", engine->tex_south);
	}
	else if (*line == 'W' && *(line + 1) == 'E'
	&& *(line + 2) == ' ')
	{
		engine->tex_west = ft_strdup(var[1]);
		printf("%s\n", engine->tex_west);
	}
	else if (*line == 'E' && *(line + 1) == 'A'
	&& *(line + 2) == ' ')
	{
		engine->tex_east = ft_strdup(var[1]);
		printf("%s\n", engine->tex_east);
	}
	else if (*line == 'S' && *(line + 1) == ' ')
	{
		engine->tex_sprite = ft_strdup(var[1]);
		printf("%s\n", engine->tex_sprite);
	}
	ft_free_array(&var);
	return (0);
}