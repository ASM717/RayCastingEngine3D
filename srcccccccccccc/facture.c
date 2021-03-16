/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   facture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 13:44:55 by amuriel           #+#    #+#             */
/*   Updated: 2021/03/02 14:16:24 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3dold.h"

int		ft_control_directoria(char *s)
{
	int	i;
	int	fd;

	fd = open(s, O_RDONLY);
	i = fd;
	close(fd);
	if (i < 0)
		return (-1);
	return (0);
}

int		ft_settings_facture(char *facture, char **path_arr)
{
	if (*path_arr || ft_control_directoria(facture))
		return (-1);
	*path_arr = ft_strdup(facture);
	return (0);
}


int		ft_control_rgb(char *s)
{
	int color;

	color = ft_atoi(s);
	if (color < 0 || color > 255 || ft_permission(s))
		return (-1);
	return (0);
}

int		ft_settings_rgb(char *str, t_rgb *rgb)
{
	char **string;

	string = ft_split(str, ',');
	if (ft_control_rgb(string[0]) || ft_control_rgb(string[1]) ||
										ft_control_rgb(string[2]))
		return (-1);
	*rgb = ft_rgb(ft_atoi(string[0]), ft_atoi(string[1]),
											ft_atoi(string[2]));
	ft_free_array_str(string);
	return (0);
}

int		ft_facture(char **s, t_engine *engine)
{
	if (!(*s))
		return (0);
	if (ft_strncmp(s[0], "R", 2) == 0)
		return (ft_permission_window(s[1], s[2], engine));
	else if (ft_strncmp(s[0], "NO", 2) == 0)
		return (ft_settings_facture(s[1], &engine->side.north));
	else if (ft_strncmp(s[0], "SO", 2) == 0)
		return (ft_settings_facture(s[1], &engine->side.south));
	else if (ft_strncmp(s[0], "WE", 2) == 0)
		return (ft_settings_facture(s[1], &engine->side.west));
	else if (ft_strncmp(s[0], "EA", 2) == 0)
		return (ft_settings_facture(s[1], &engine->side.east));
	else if (ft_strncmp(s[0], "S", 1) == 0)
		return (ft_settings_facture(s[1], &engine->sprite));
	else if (ft_strncmp(s[0], "F", 1) == 0)
		return (ft_settings_rgb(s[1], &engine->f_rgb));
	else if (ft_strncmp(s[0], "C", 1) == 0)
		return (ft_settings_rgb(s[1], &engine->c_rgb));
	return (1);
}
