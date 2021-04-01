/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 11:58:24 by amuriel           #+#    #+#             */
/*   Updated: 2021/04/01 17:20:15 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy_gnl(char *dst, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strnew_gnl(unsigned int buf_size)
{
	char	*s;

	if (!(s = malloc(sizeof(char) * (buf_size + 1))))
		return (NULL);
	s[buf_size] = '\0';
	while (buf_size != 0)
	{
		s[buf_size] = '\0';
		buf_size--;
	}
	return (s);
}

char	*ft_strdup_gnl(const char *s1)
{
	char	*str;
	int		i;

	str = malloc(ft_strlen_gnl(s1) + 1);
	i = 0;
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin_new_gnl(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(str = malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		++i;
	}
	free(s1);
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		++i;
		++j;
	}
	str[i] = '\0';
	return (str);
}
