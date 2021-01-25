/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 11:49:36 by amuriel           #+#    #+#             */
/*   Updated: 2020/11/04 13:45:52 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		finish;
	char		*string;

	if (!s1)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	finish = ft_strlen(s1);
	while (finish && ft_strchr(set, s1[finish - 1]))
		finish--;
	string = (char *)malloc(sizeof(char) * (finish + 1));
	if (!string)
		return (NULL);
	ft_memcpy(string, &*s1, finish);
	string[finish] = '\0';
	return (string);
}
