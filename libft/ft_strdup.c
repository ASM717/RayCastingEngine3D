/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:55:40 by amuriel           #+#    #+#             */
/*   Updated: 2020/11/01 20:26:49 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	length;
	void	*new;

	length = ft_strlen(s1) + 1;
	new = malloc(length);
	if (new == NULL)
		return (NULL);
	return ((char *)ft_memcpy(new, s1, length));
}
