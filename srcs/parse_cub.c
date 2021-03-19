#include "../cub3d.h"

char	*ft_strjoin_pars(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(str = malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 2)))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		++i;
	}
	free(s1);
	str[i++] = ' ';
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		++i;
		++j;
	}
	str[i] = '\0';
	return (str);
}

void	ft_err_print(char *s)
{
	write(2, s, ft_strlen(s));
	exit(-1);
}

void 	ft_var_zero(t_engine *engine)
{
	engine->scrWidth = 0;
	engine->scrHeight = 0;
	engine->texNorth = NULL;
	engine->texSouth = NULL;
	engine->texWest = NULL;
	engine->texEast = NULL;
	engine->texSprite = NULL;
	engine->rgbCeiling.colR = -1;
	engine->rgbCeiling.colG = -1;
	engine->rgbCeiling.colB = -1;
	engine->rgbFloor.colR = -1;
	engine->rgbFloor.colG = -1;
	engine->rgbFloor.colB = -1;
}

int 	ft_start_parse(t_engine *engine)
{
	char *tmp;

	tmp = NULL;
	engine->pm.fd = open("map.cub", O_RDONLY);
	if (engine->pm.fd < 0)
		ft_err_print("Check! Map file doesn't exist!");
	ft_var_zero(engine);
	while (get_next_line(engine->pm.fd, &engine->pm.line))
	{
		if (tmp)
			engine->pm.line = ft_strjoin_pars(tmp, engine->pm.line);
		tmp = engine->pm.line;

	}
}