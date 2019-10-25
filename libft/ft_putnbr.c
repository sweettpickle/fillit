/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoreah <cdoreah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 20:34:19 by cdoreah           #+#    #+#             */
/*   Updated: 2019/10/25 15:36:08 by cdoreah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ranks(int c)
{
	int		rez;

	rez = 1;
	while (c > 0)
	{
		rez = rez * 10;
		c--;
	}
	return (rez);
}

static int	numbers(int a)
{
	int		count;

	count = 0;
	while (a != 0)
	{
		a = a / 10;
		count++;
	}
	return (count);
}

void		ft_putnbr(int n)
{
	int		count;

	if (n < 0)
	{
		ft_putchar(45);
		if (n == -2147483648)
		{
			ft_putchar(50);
			n = -147483648;
		}
		n = n * (-1);
	}
	count = numbers(n);
	while (count > 1)
	{
		ft_putchar(n / ranks(count - 1) + 48);
		n = n % ranks(count - 1);
		count--;
	}
	ft_putchar(n % 10 + 48);
}
