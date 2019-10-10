/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoreah <cdoreah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:51:54 by cdoreah           #+#    #+#             */
/*   Updated: 2019/10/06 13:44:53 by cdoreah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ranks(int c)
{
	int rez;

	rez = 1;
	while (c > 0)
	{
		rez = rez * 10;
		c--;
	}
	return (rez);
}

static int		numbers(int a)
{
	int count;

	count = 0;
	while (a != 0)
	{
		a = a / 10;
		count++;
	}
	return (count);
}

void			ft_putnbr_fd(int n, int fd)
{
	int count;

	if (n < 0)
	{
		ft_putchar_fd(45, fd);
		if (n == -2147483648)
		{
			ft_putchar_fd(50, fd);
			n = -147483648;
		}
		n = n * (-1);
	}
	count = numbers(n);
	while (count > 1)
	{
		ft_putchar_fd(n / ranks(count - 1) + 48, fd);
		n = n % ranks(count - 1);
		count--;
	}
	ft_putchar_fd(n % 10 + 48, fd);
}
