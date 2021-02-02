/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuriel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:38:04 by amuriel           #+#    #+#             */
/*   Updated: 2021/02/02 11:29:24 by amuriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_length(unsigned int num)
{
	size_t length;

	length = 0;
	while (num >= 10)
	{
		num /= 10;
		length++;
	}
	return (length + 1);
}

char	*ft_itoa(int n)
{
	char	*s;
	size_t	i;
	size_t	length;
	size_t	nbr;

	i = 0;
	nbr = n;
	nbr = n < 0 ? -nbr : nbr;
	length = ft_length(nbr);
	if (n < 0)
		length++;
	if (!(s = (char *)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	if (n < 0)
		s[0] = '-';
	i = length - 1;
	while (nbr >= 10)
	{
		s[i] = nbr % 10 + 48;
		nbr /= 10;
		i--;
	}
	s[i] = nbr % 10 + 48;
	s[length] = '\0';
	return (s);
}
