/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:49:12 by amuriel           #+#    #+#             */
/*   Updated: 2021/04/01 16:23:20 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_main_sprites(t_engine *engine)
{
	engine->s = 0;
	ft_sort_swap(engine);
	while (engine->s < engine->sprite_num)
	{
		ft_sprite_calculation1(engine);
		ft_sprite_calculation2(engine);
		engine->stripe = engine->draw_start_x;
		while (engine->stripe < engine->draw_end_x)
		{
			engine->spr_text_x = (int)(256 * (engine->stripe -
			(engine->sprite_w / 2 + engine->sprite_scr_x)) *
			TEX_WIDTH / engine->sprite_w) / 256;
			ft_sprite_calculation3(engine);
			engine->stripe++;
		}
		engine->s++;
	}
	free(engine->sprite_dist);
	free(engine->sprite_order);
	free(engine->str_spr);
}
