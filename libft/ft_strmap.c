/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoreah <cdoreah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 00:17:27 by cdoreah           #+#    #+#             */
/*   Updated: 2019/10/25 15:36:08 by cdoreah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	char	*tmp;

	if (!s || !f)
		return (NULL);
	str = (char *)malloc(ft_strlen((char *)s) + 1);
	tmp = str;
	if (!str)
		return (NULL);
	while (*s)
		*str++ = f(*s++);
	*str = '\0';
	return (tmp);
}
