
#include "../cub3d.h"

int		ft_check_rgb(char *s)
{
	int color;

	color = ft_atoi(s);
	if (color < 0 || color > 255)
		ft_print_error("Error RGB number!\n");
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
			engine->rgb_floor.col_g = ft_check_rgb(var[1]);
			engine->rgb_floor.col_b = ft_check_rgb(var[2]);
		}
		else if (*line == 'C' && *(line + 1) == ' ')
		{
			engine->rgb_ceiling.col_r = ft_check_rgb(var[0]);
			engine->rgb_ceiling.col_g = ft_check_rgb(var[1]);
			engine->rgb_ceiling.col_b = ft_check_rgb(var[2]);
		}
	}
	else
		ft_print_error("Error!\nInvalid input color!\n");
	engine->pm.flag_color++;
	ft_free_array(&var);
	return (0);
}