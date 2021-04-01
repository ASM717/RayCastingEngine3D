/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_func_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:23:00 by amuriel           #+#    #+#             */
/*   Updated: 2021/04/01 17:53:26 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			ft_number_sprites(t_engine *engine)
{
	int	count;
	int	x;
	int	y;

	x = 0;
	count = 0;
	engine->pm.count_lines2 = ft_arr_string_len(engine->world_map);
	while (x < engine->pm.count_lines2)
	{
		y = 0;
		while (y < (int)ft_strlen(engine->world_map[x]))
		{
			if (engine->world_map[x][y] == '2')
				count++;
			y++;
		}
		x++;
	}
	return (count);
}

void		ft_correct_sprite(t_engine *engine)
{
	engine->pm.count_lines1 = ft_arr_string_len(engine->world_map);
	engine->sprite_num = ft_number_sprites(engine);
}

t_sprite	*ft_get_sprites(t_engine *engine)
{
	t_sprite	*str_spr;
	int			x;
	int			y;
	int			i;

	i = 0;
	ft_correct_sprite(engine);
	str_spr = malloc(sizeof(t_sprite) * engine->sprite_num);
	engine->sprite_order = malloc(sizeof(int) * engine->sprite_num);
	x = 0;
	while (x < engine->pm.count_lines1)
	{
		y = 0;
		while (y < (int)ft_strlen(engine->world_map[x]))
		{
			if (engine->world_map[x][y] == '2')
			{
				str_spr[i].x_str = x + 0.5;
				str_spr[i++].y_str = y + 0.5;
			}
			y++;
		}
		x++;
	}
	return (str_spr);
}
