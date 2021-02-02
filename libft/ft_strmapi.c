/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:16:12 by amuriel           #+#    #+#             */
/*   Updated: 2021/02/02 11:29:24 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*tmp;
	unsigned int	i;
	unsigned int	length;

	if (!s || !f)
		return (NULL);
	length = ft_strlen(s);
	if (!(tmp = (char *)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		tmp[i] = f(i, s[i]);
		++i;
	}
	tmp[i] = '\0';
	return (tmp);
}
