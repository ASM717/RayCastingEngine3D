/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:43:02 by amuriel           #+#    #+#             */
/*   Updated: 2020/11/02 13:11:00 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *str;

	str = (char*)s;
	if (c == 0)
		return ((char*)(s + ft_strlen(s)));
	while (*(str))
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	return (NULL);
}
