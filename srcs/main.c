/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:08:51 by amuriel           #+#    #+#             */
/*   Updated: 2021/02/12 12:13:32 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// void 	init_struct(t_engine *game)
// {
// 	game->side.east = NULL;
// 	game->side.north = NULL;
// 	game->side.south = NULL;
// 	game->side.west = NULL;

// 	game->screen.height = 0;
// 	game->screen.width = 0;
// }

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

char	**make_map(t_list **head, int size)
{
	int		i;
	char	**map;
	t_list	*tmp;

	i = 0;
	map = ft_calloc((size + 1), sizeof(char *));
	tmp = *head;
	while (tmp)
	{
		map[i] = ft_strdup(tmp->content);
		i++;
		tmp= tmp->next;
	}
	i = 0;
	ft_lstclear(head, &free);
	return (map);
}

char	**ft_read_map(char *av1)
{
	char	*str;
	t_list	*head;
	int		size;
	int		fd;

	str = 0;
	head = 0;
	size = 0;
	fd = open(av1, O_RDONLY);
	while (get_next_line(fd, &str))
	{
		ft_lstadd_back(&head, ft_lstnew(str));
		size++;
		str = NULL;
	}
	close(fd);
	ft_lstadd_back(&head, ft_lstnew(str));
	size++;
	return (make_map(&head, size));
}


void	ft_init_player(char **map, t_plr *plr)
{
	t_point pos;

	ft_bzero(&pos, sizeof(t_point));
	while (map[pos.y])
	{
		pos.x = 0;
		while (map[pos.y][pos.x])
		{
			if (ft_strchr("NEWS", map[pos.y][pos.x]))
			{
				plr->x = pos.x * SCALE;
				plr->y = pos.y * SCALE;
			}
			pos.x++;
		}
		pos.y++;
	}
}

void ft_scale_img(t_win *win, t_point point)
{
	t_point end;

	end.x = (point.x + 1) * SCALE;
	end.y = (point.y + 1) * SCALE;
	point.x *= SCALE;
	point.y *= SCALE;
	while (point.y < end.y)
	{

		while (point.x < end.x)
		{
			mlx_pixel_put(win->mlx, win->win, point.x++, point.y, 0xFFFFFF);
		}
		point.x -= SCALE;
		point.y++;
	}
}

void ft_draw_player(t_win *win, t_plr *pl)
{
	t_point end;
	t_plr plr = *pl;

	end.x = plr.x + SCALE;
	end.y = plr.y + SCALE;
	while (plr.y < end.y)
	{
		while (plr.x < end.x)
		{
			mlx_pixel_put(win->mlx, win->win, plr.x++, plr.y, 0x119911);
		}
		plr.x -= SCALE;
		plr.y++;
	}
}

void	draw_screen(t_all *all)
{
	t_point point;

	ft_bzero(&point, sizeof(t_point));
	while (all->map[point.y])
	{
		point.x = 0;
		while (all->map[point.y][point.x])
		{
			if (all->map[point.y][point.x] == '1')
				ft_scale_img(all->win, point);
			point.x++;
		}
		point.y++;
	}
	ft_draw_player(all->win, all->plr);
}

int		ft_key_press(int key, t_all *all)
{
	mlx_clear_window(all->win->mlx, all->win->win);
	if (key == 119)
		all->plr->y -= 1;
	if (key == 115)
		all->plr->y += 1;
	if (key == 97)
		all->plr->x -= 1;
	if (key == 100)
		all->plr->x += 1;
	if (key == ESC)
		exit(0);
	draw_screen(all);
	return (0);
}

// void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
//     char    *dst;

//     dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//     *(unsigned int*)dst = color;
// }

int		main(int argc, char **argv)
{
	t_win win;
	t_plr plr;
	t_all all;

	if (argc == 2)
		all.map = ft_read_map(argv[1]);
	else
	{
		ft_putendl_fd("Need a map !", 2);
		return(-1);
	}
	ft_init_player(all.map, &plr);
    win.mlx = mlx_init();
    win.win = mlx_new_window(win.mlx, 640, 480, "cub3D");
	// int i = 0;
    // int j = 0;
    // while (all.map[i][j])
    // {
    //     j = 0;
    //     while (all.map[i][j] != '\0')
    //     {
	// 		if (all.map[i][j] == '1')
	// 			mlx_pixel_put(win.mlx, win.win, i, j, 0x00FF0000);
	// 		if (all.map[i][j] == '0')
	// 			mlx_pixel_put(win.mlx, win.win, i, j, 0x0000FF00);
	// 		if (all.map[i][j] == 'N')
	// 			mlx_pixel_put(win.mlx, win.win, i, j, 0x00FFFFFF);
    //         j++;
    //     }
	// 	j = 0;
    //     i++;
    // }
    win.img = mlx_new_image(win.mlx, 1000, 800);
    win.addr = mlx_get_data_addr(win.img, &win.bpp, &win.line_l, &win.en);
	all.plr = &plr;
	all.win = &win;
	draw_screen(&all);
	mlx_hook(win.win, 2, (1L << 0), &ft_key_press, &all);
    mlx_loop(win.mlx);

}
