/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoreah <cdoreah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:03:54 by cdoreah           #+#    #+#             */
/*   Updated: 2019/11/06 19:13:03 by cdoreah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memccpy(void *dest,
		const void *src, int c, size_t n)
{
	unsigned char		*c_dest;
	const unsigned char	*c_src;
	unsigned char		a;

	c_dest = dest;
	c_src = src;
	a = c;
	while (n--)
	{
		*c_dest = *c_src;
		if (*c_src == a)
		{
			c_dest++;
			return (c_dest);
		}
		c_dest++;
		c_src++;
	}
	return (NULL);
}
