/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoreah <cdoreah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:42:22 by cdoreah           #+#    #+#             */
/*   Updated: 2019/10/06 13:44:53 by cdoreah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned	c;
	char		*str;
	char		*tmp;

	if (!s || !f)
		return (NULL);
	str = (char *)malloc(ft_strlen((char *)s) + 1);
	if (!str)
		return (NULL);
	tmp = str;
	c = 0;
	while (*s)
		*str++ = f(c++, *s++);
	*str = '\0';
	return (tmp);
}
