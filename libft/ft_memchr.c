/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:59:26 by amuriel           #+#    #+#             */
/*   Updated: 2020/11/02 19:20:50 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char *str;
	unsigned char		charac;
	size_t				i;

	str = s;
	charac = c;
	i = 0;
	while (i < n)
	{
		if (str[i] == charac)
			return ((void*)(str + i));
		i++;
	}
	return (NULL);
}
