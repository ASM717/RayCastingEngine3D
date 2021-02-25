/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 13:12:23 by amuriel           #+#    #+#             */
/*   Updated: 2021/02/25 13:33:21 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_permission(char *r)
{
	int i;

	i = 0;
	while (r[i])
	{
		if (ft_isdigit(r[i]) == 0)
			return (-1);
		i++;
	}
	return (0);
}

void	ft_window(t_engine *engine)
{
	if (engine->screen.width > 1920)
		engine->screen.width = 1920;
	if (engine->screen.height > 1080)
		engine->screen.height = 1080;
}

int		ft_permission_window(char *r1, char *r2, t_engine *engine)
{
	if (ft_permission(r1) || ft_permission(r2)
	|| engine->screen.width != -1 || engine->screen.height != -1)
		return (-1);
	engine->screen.width = ft_atoi(r1);
	engine->screen.height = ft_atoi(r2);
	ft_window(engine);
	return (0);
}
