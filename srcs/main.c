/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:08:51 by amuriel           #+#    #+#             */
/*   Updated: 2021/02/03 16:34:13 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void 	init_struct(t_engine *game)
{
	game->side.east = NULL;
	game->side.north = NULL;
	game->side.south = NULL;
	game->side.west = NULL;

	game->screen.height = 0;
	game->screen.width = 0;
}

int		main(void)
{
	int			fd;
	char		*line;
	t_engine	*game;

	fd = open("maps/map.cub", O_RDONLY);
	init_struct(game);
	while (get_next_line(fd, &line))
	{

	}
}