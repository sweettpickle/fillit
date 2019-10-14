/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoreah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:21:22 by cdoreah           #+#    #+#             */
/*   Updated: 2019/10/06 13:44:53 by cdoreah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len_s;

	i = 0;
	len_s = ft_strlen((char *)src);
	while (*dest && size)
	{
		dest++;
		size--;
		i++;
	}
	if (size-- == 0)
		return (i + len_s);
	while (*src)
	{
		if (size)
		{
			*dest++ = *src;
			size--;
		}
		src++;
	}
	*dest = '\0';
	return (i + len_s);
}
