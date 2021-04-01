/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3dmain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 17:31:29 by amuriel           #+#    #+#             */
/*   Updated: 2021/04/01 17:18:24 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//int 	ft_check_save_argv(char **argv)
//{
//	if (argv[2] > ft_strlen(argv[2]))
//		return (0);
//	else
//		return (1);
//
//}

int		main(int argc, char **argv)
{
	t_engine	engine;

	if (ft_init_engine(&engine) != 0)
		return (-1);
	if (argc == 2 && argv[1])
	{
		engine.screen_flag = 0;
		ft_start_parse(argv, &engine);
		ft_mlx_data_start(&engine);
		ft_mlx_data_continue(&engine);
	}
	else if (argc == 3 && ft_strncmp(argv[2], "--save",
		ft_strlen("--save")) == 0)
	{
		engine.screen_flag = 1;
		ft_start_parse(argv, &engine);
		ft_screenshot_start(&engine);
	}
	else
		ft_print_error("Error!\nWrite correct arguments!\n");
}
