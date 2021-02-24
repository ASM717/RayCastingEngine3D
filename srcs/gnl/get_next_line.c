/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 11:55:04 by amuriel           #+#    #+#             */
/*   Updated: 2021/02/24 11:54:29 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strclr(char **s)
{
	if (*s)
	{
		free(*s);
		*s = NULL;
	}
}

char	*ft_strchr(const char *s, int c)
{
	char *str;

	str = (char*)s;
	if (c == 0)
		return ((char*)(s + ft_strlen_gnl(s)));
	while (*(str))
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	return (NULL);
}

char	*line_checker(char **str, char **line, int *read_end)
{
	char	*point_ent;

	point_ent = 0;
	*read_end = 1;
	if (*str)
		if ((point_ent = ft_strchr(*str, '\n')))
		{
			*point_ent++ = '\0';
			if (!(*line = ft_strdup(*str)))
				*read_end = 2;
			if (*point_ent)
				ft_strcpy(*str, point_ent);
			else
				ft_strclr(&(*str));
		}
		else
		{
			if (!(*line = ft_strdup(*str)))
				*read_end = 2;
			ft_strclr(&(*str));
		}
	else
		*line = ft_strnew(0);
	return (point_ent);
}

int		get_next_line(int fd, char **line)
{
	static char	*str[1024];
	char		*buff;
	char		*point_ent;
	int			read_end;

	if (!(buff = malloc(BUFFER_SIZE + 1)) || BUFFER_SIZE <= 0 || !line
		|| fd > 1023 || (read(fd, buff, 0) == -1))
		return (-1);
	point_ent = line_checker(&str[fd], line, &read_end);
	if (read_end == 2)
		return (-1);
	while (!point_ent && (read_end = read(fd, buff, BUFFER_SIZE)))
	{
		buff[read_end] = '\0';
		if ((point_ent = ft_strchr(buff, '\n')))
		{
			*point_ent++ = '\0';
			if (*point_ent && !(str[fd] = ft_strdup(point_ent)))
				return (-1);
		}
		if (!(*line = ft_strjoin_new(*line, buff)))
			return (-1);
	}
	free(buff);
	return (point_ent ? 1 : 0);
}
