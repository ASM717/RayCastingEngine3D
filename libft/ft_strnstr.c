/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 10:35:12 by amuriel           #+#    #+#             */
/*   Updated: 2021/02/02 11:29:24 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	sub_len;

	i = 0;
	sub_len = ft_strlen(needle);
	if (sub_len == 0)
		return ((char *)haystack);
	while (*haystack && i + sub_len <= len)
	{
		if (ft_strncmp(haystack, needle, sub_len) == 0)
			return ((char *)haystack);
		i++;
		haystack++;
	}
	return (NULL);
}
