/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 11:56:41 by amuriel           #+#    #+#             */
/*   Updated: 2021/02/02 11:29:24 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_words(char const *s, char c)
{
	unsigned int nbr;
	unsigned int tmp;

	nbr = 0;
	tmp = 0;
	while (*s != '\0')
	{
		if (tmp == 0 && *s != c && *s)
		{
			tmp = 1;
			nbr++;
		}
		if (tmp == 1 && *s == c)
			tmp = 0;
		s++;
	}
	return (nbr);
}

size_t	nbwords(char const *s, char c)
{
	unsigned int length;

	length = 0;
	while (*s && *s != c)
	{
		length++;
		s++;
	}
	return (length);
}

void	*ft_free(char **arr, size_t i)
{
	while (i--)
		free(arr[i]);
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	if (!(arr = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			if (!(arr[i] = (char *)malloc(sizeof(char) * (nbwords(s, c) + 1))))
				return (ft_free(arr, i));
			j = 0;
			while (*s != c && *s != '\0')
				arr[i][j++] = *s++;
			arr[i++][j] = '\0';
		}
	}
	arr[i] = (NULL);
	return (arr);
}
