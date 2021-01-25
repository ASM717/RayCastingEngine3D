/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:56:10 by amuriel           #+#    #+#             */
/*   Updated: 2020/11/01 20:22:12 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*destination;
	unsigned char	*source;
	size_t			i;

	i = 0;
	destination = (unsigned char*)dst;
	source = (unsigned char*)src;
	while (i < n)
	{
		destination[i] = source[i];
		if (destination[i] == (unsigned char)c)
			return (destination + i + 1);
		i++;
	}
	return (NULL);
}
