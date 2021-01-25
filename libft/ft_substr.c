/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:46:10 by amuriel           #+#    #+#             */
/*   Updated: 2020/11/03 19:53:54 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*string;

	if (!s)
		return (0);
	i = 0;
	j = 0;
	string = (char *)malloc(sizeof(char) * (len + 1));
	if (!string)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			string[j] = s[i];
			j++;
		}
		i++;
	}
	string[j] = 0;
	return (string);
}
