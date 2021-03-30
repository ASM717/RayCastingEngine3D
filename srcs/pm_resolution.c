/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pm_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:24:49 by amuriel           #+#    #+#             */
/*   Updated: 2021/03/30 14:25:39 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		ft_check_perm_double(t_engine *engine)
{
	if (engine->scr_height == -1 || engine->scr_width == -1)
		return (0);
	return (1);
}

void	ft_get_resolution(t_engine *engine)
{
	engine->pm.flag_perm = 0;
	if ((ft_isdigit_pm(engine->pm.tmp2[1]) &&
	ft_isdigit_pm(engine->pm.tmp2[2])) && !engine->pm.tmp2[3])
	{
		engine->scr_width = ft_atoi(engine->pm.tmp2[1]);
		engine->scr_height = ft_atoi(engine->pm.tmp2[2]);
		if (engine->scr_width > 1920 || ft_strlen(engine->pm.tmp2[2]) > 4)
			engine->scr_width = 1920;
		if (engine->scr_height > 1080 || ft_strlen(engine->pm.tmp2[2]) > 4)
			engine->scr_height = 1080;
		if (engine->scr_width < 640)
			engine->scr_width = 640;
		if (engine->scr_height < 480)
			engine->scr_height = 480;
		engine->pm.flag_perm = 1;
	}
	else
		ft_print_error("Error!\nInvalid permission symbol's\n");
}
