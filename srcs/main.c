/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:08:51 by amuriel           #+#    #+#             */
/*   Updated: 2021/02/08 11:38:50 by amuriel          ###   ########.fr       */
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

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		main(void)
{
//	int		fd = open(argv[1], O_RDONLY);
//	char	*line = NULL;
//	t_list	*head = NULL;
	void    *mlx;
	void    *mlx_win;
	t_data  data;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	data.img = mlx_new_image(mlx, 1920, 1080);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length,
								 &data.endian);
	my_mlx_pixel_put(&data, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, data.img, 0, 0);
	mlx_loop(mlx);

//	if (argc == 2)
//	{
//		while (get_next_line(fd, &line))
//			ft_lstadd_back(&head, ft_lstnew(line));
//		ft_lstadd_back(&head, ft_lstnew(line));
//		make_map(&head, ft_lstsize(head));
//	}
}