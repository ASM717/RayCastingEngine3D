/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:19:11 by amuriel           #+#    #+#             */
/*   Updated: 2020/11/02 18:30:16 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*destination;
	unsigned char	*source;
	size_t			i;

	if (dst == src)
		return (dst);
	destination = (unsigned char*)dst;
	source = (unsigned char*)src;
	if (dst > src)
	{
		i = len;
		while (i-- > 0)
			destination[i] = source[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			destination[i] = source[i];
			i++;
		}
	}
	return (destination);
}
