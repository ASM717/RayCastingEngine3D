/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 21:44:06 by amuriel           #+#    #+#             */
/*   Updated: 2021/02/02 11:29:24 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	*tmp;

	if (c == 0)
		return ((void*)(s + ft_strlen(s)));
	tmp = (char*)s;
	ptr = NULL;
	while (*(tmp))
	{
		if (*tmp == (char)c)
			ptr = tmp;
		tmp++;
	}
	if (ptr != NULL)
		return (ptr);
	return (NULL);
}
