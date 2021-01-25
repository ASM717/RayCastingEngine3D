/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:00:43 by amuriel           #+#    #+#             */
/*   Updated: 2020/11/04 17:59:06 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int lendst;
	unsigned int i;

	lendst = ft_strlen(dst);
	i = 0;
	if (dstsize <= lendst)
		return (dstsize + ft_strlen(src));
	while (src[i] && lendst + i < (dstsize - 1))
	{
		dst[lendst + i] = src[i];
		i++;
	}
	dst[lendst + i] = '\0';
	return (ft_strlen(src) + lendst);
}
