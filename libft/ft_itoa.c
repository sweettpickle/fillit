/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoreah <cdoreah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:14:20 by cdoreah           #+#    #+#             */
/*   Updated: 2019/10/06 13:44:53 by cdoreah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		numbers(int a)
{
	size_t		count;

	count = 0;
	if (!a)
		return (1);
	while (a)
	{
		a = a / 10;
		count++;
	}
	return (count);
}

char				*ft_itoa(int n)
{
	size_t			len;
	char			*nb;
	unsigned int	tmp;

	len = numbers(n);
	tmp = n;
	if (n < 0)
	{
		len++;
		tmp = -n;
	}
	nb = ft_strnew(len);
	if (!nb)
		return (NULL);
	nb[--len] = tmp % 10 + '0';
	while (tmp /= 10)
		nb[--len] = tmp % 10 + '0';
	if (n < 0)
		nb[0] = '-';
	return (nb);
}
