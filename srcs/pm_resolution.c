
#include "../cub3d.h"

int		ft_isdigit_pm(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

void	ft_get_resolution(t_engine *engine)
{
	if ((ft_isdigit_pm(engine->pm.tmp2[1]) &&
	ft_isdigit_pm(engine->pm.tmp2[2])) && !engine->pm.tmp2[3])
	{
		engine->scr_width = ft_atoi(engine->pm.tmp2[1]);
		engine->scr_height = ft_atoi(engine->pm.tmp2[2]);

		if (engine->scr_width > 1920 || ft_strlen(engine->pm.tmp2[2]) > 4)
			engine->scr_width = 1920;
		if (engine->scr_height > 1080 || ft_strlen(engine->pm.tmp2[2]) > 4)
			engine->scr_height = 1080;
		if (engine->scr_width < 800)
			engine->scr_width = 800;
		if (engine->scr_height < 600)
			engine->scr_height = 600;
		printf("%d\n", engine->scr_width);
		printf("%d\n", engine->scr_height);
	}
	else
		ft_print_error("Error permission symbol's\n");
}