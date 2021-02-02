/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 13:02:16 by amuriel           #+#    #+#             */
/*   Updated: 2021/02/02 11:31:08 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//void    ft_putstr(char *str)
//{
//    int i;
//
//    i = 0;
//    while (str[i] != '\0')
//    {
//        write(1, &str[i], 1);
//        i++;
//    }
//    write(1, "\n", 1);
//}
//
//char	**make_map(t_list **head, int size)
//{
//	char	  **map = ft_calloc(size + 1, sizeof(char *));
//	int		  i = -1;
//	t_list	*tmp = *head;
//
//	while (tmp)
//	{
//		map[++i] = tmp->content;
//		tmp= tmp->next;
//	}
//	i = -1;
//	while (map[++i])
//		ft_putstr(map[i]);
//	return (map);
//}
//
//int		main(int argc, char **argv)
//{
//	int      fd = open(argv[1], O_RDONLY);
//	char	  *line = NULL;
//	t_list	*head = NULL;
//    if (argc == 2)
//    {
//	    while (get_next_line(fd, &line))
//		    ft_lstadd_back(&head, ft_lstnew(line));
//	    ft_lstadd_back(&head, ft_lstnew(line));
//	    make_map(&head, ft_lstsize(head));
//    }
//}