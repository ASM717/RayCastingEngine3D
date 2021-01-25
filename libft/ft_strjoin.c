/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:00:17 by amuriel           #+#    #+#             */
/*   Updated: 2020/11/02 12:58:13 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*string;
	char	*i;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	string = (char *)malloc(sizeof(char) * (len + 1));
	if (!string)
		return (NULL);
	i = string;
	while (*s1)
		*string++ = *s1++;
	while (*s2)
		*string++ = *s2++;
	*string = '\0';
	return (i);
}
