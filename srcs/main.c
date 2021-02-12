/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:08:51 by amuriel           #+#    #+#             */
/*   Updated: 2021/02/11 18:19:29 by amuriel          ###   ########.fr       */
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

void	my_mlx_pixel_put(t_win *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_l + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void ft_init_player(char **map, t_plr *plr)
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

char	**make_map(t_list **head, int size)
{
	char	  **map = ft_calloc(size + 1, sizeof(char *));
	int		  i = -1;
	t_list	*tmp = *head;

	while (tmp)
	{
		map[++i] = tmp->content;
		tmp= tmp->next;
	}
	i = -1;
	while (map[++i])
		ft_putstr(map[i]);
	return (map);
}

void	ft_scale_img(t_win *win, t_point point)
{
	t_point end;

	end.y = (point.y + 1) * SCALE;
	end.x = (point.x + 1) *SCALE;
	point.x *= SCALE;
	point.y *= SCALE;
	while (point.y < end.y)
	{
		while (point.x < end.x)
			mlx_pixel_put(win->mlx, win->win, point.x++, point.y, 0xFFFFFF);
		point.y -= SCALE;
		point.y++;
	}

}

void	draw_screen(t_all *all)
{
	t_point point;
	t_win *win = all->win;

	win->img = mlx_new_image(win->mlx, 640, 480);
	win->addr = mlx_get_data_addr(win->img, &win->bpp, &win->line_l, &win->en);
	ft_bzero(&point, sizeof(t_point));
	while (all->map[point.y])
	{
		point.x = 0;
		while (all->map[point.y][point.y])
		{
			if (all->map[point.y][point.y] == '1')
				ft_scale_img(all->win, point);
			point.x++;
		}
		point.y++;
	}
	//ft_draw_player(all, all->plr);
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
	mlx_destroy_image(win->mlx, win->img);

}

int		key_press(int key, t_all *all)
{
	mlx_clear_window(all->win->win, all->win->win);
	if (key == W)
	{
		all->plr->y += sin(all->plr->dir) * 4;
		all->plr->x += cos(all->plr->dir) * 4;
	}
	if (key == S)
	{
		all->plr->y -= sin(all->plr->dir) * 4;
		all->plr->x -= cos(all->plr->dir) * 4;
	}
	if (key == A)
		all->plr->dir -= 0.1;
	if (key == D)
		all->plr->dir += 0.1;
	if (key == ESC)
		exit(0);
	draw_screen(all);
	return (0);
}

char	**ft_read_map(char *av1, t_plr *plr)
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

int		main(int argc, char **argv)
{
	t_win win;
	t_plr plr;
	t_all all;

	if (argc == 2)
		all.map = ft_read_map(argv[1], &plr);
	else
		return (write(2, "ERROR", 7));
	ft_init_player(all.map, &plr);
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, 640, 480, "cub2d");
	win.img = mlx_new_image(win.mlx, 640, 480);
	win.addr = mlx_get_data_addr(win.img, &win.bpp, &win.line_l, &win.en);
	all.plr = &plr;
	all.win = &win;
	draw_screen(&all);
	mlx_hook(win.win, 2, (1L << 0), &key_press, &all);
	mlx_loop(win.mlx);
}
