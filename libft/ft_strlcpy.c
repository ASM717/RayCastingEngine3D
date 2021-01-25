/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:47:20 by amuriel           #+#    #+#             */
/*   Updated: 2020/11/02 19:10:49 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char		*destination;
	const char	*source;
	size_t		i;
	int			number;

	if (!dst || !src)
		return (0);
	destination = dst;
	source = src;
	number = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (number);
	while (source[i] && i < dstsize - 1)
	{
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
	return (number);
}
