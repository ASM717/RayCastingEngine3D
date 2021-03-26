
#include "../cub3d.h"

int		ft_check_rgb(char *s)
{
	int color;

	color = ft_atoi(s);
	if (color < 0 || color > 255)
	{
		printf("Error rgb number\n");
		exit(0);
	}
	return (color);
}

int		ft_get_rgb_color(t_engine *engine, char *line)
{
	char **var;

	if (engine->pm.tmp2[2])
		return (1);
	var = ft_split(engine->pm.tmp2[1], ',');
	if ((ft_isdigit_pm(var[0]) && ft_isdigit_pm(var[1]) &&
	ft_isdigit_pm(var[2])) && !var[3])
	{
		if (*line == 'F' && *(line + 1) == ' ')
		{
			engine->rgb_floor.col_r = ft_check_rgb(var[0]);
			printf("%d\n", engine->rgb_floor.col_r);

			engine->rgb_floor.col_g = ft_check_rgb(var[1]);
			printf("%d\n", engine->rgb_floor.col_g);

			engine->rgb_floor.col_b = ft_check_rgb(var[2]);
			printf("%d\n", engine->rgb_floor.col_b);
		}
		else if (*line == 'C' && *(line + 1) == ' ')
		{
			engine->rgb_ceiling.col_r = ft_check_rgb(var[0]);
			printf("%d\n", engine->rgb_ceiling.col_r);

			engine->rgb_ceiling.col_g = ft_check_rgb(var[1]);
			printf("%d\n", engine->rgb_ceiling.col_g);

			engine->rgb_ceiling.col_b = ft_check_rgb(var[2]);
			printf("%d\n", engine->rgb_ceiling.col_b);
		}
	}
	else
		ft_print_error("Error input color!\n");
	ft_free_array(&var);
	return (0);
}