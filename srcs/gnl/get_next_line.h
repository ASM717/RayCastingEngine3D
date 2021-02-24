/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 11:56:54 by amuriel           #+#    #+#             */
/*   Updated: 2021/02/24 11:54:13 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1024
# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen_gnl(const char *s);
char	*ft_strcpy(char *dst, const char *src);
void	ft_strclr(char **s);
char	*ft_strchr(const char *s, int c);
char	*ft_strnew(unsigned int size);
char	*ft_strdup(const char *s1);
char	*ft_strjoin_new(char *s1, char *s2);
char	*line_checker(char **str, char **line, int *read_end);
int		get_next_line(int fd, char **line);

#endif
