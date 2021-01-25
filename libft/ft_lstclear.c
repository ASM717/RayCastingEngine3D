/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:58:53 by amuriel           #+#    #+#             */
/*   Updated: 2020/11/04 14:56:16 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *elem;
	t_list *tmp;

	tmp = *lst;
	while (tmp)
	{
		elem = tmp->next;
		if (del)
			del(tmp->content);
		free(tmp);
		tmp = elem;
	}
	*lst = NULL;
}
