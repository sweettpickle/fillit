/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoreah <cdoreah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 22:40:40 by cdoreah           #+#    #+#             */
/*   Updated: 2019/10/06 13:44:53 by cdoreah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size1;
	size_t	size2;
	char	*str;
	char	*tmp;

	if (!s1 || !s2)
		return (NULL);
	size1 = ft_strlen((char *)s1);
	size2 = ft_strlen((char *)s2);
	if (size1 + size2 < size1 || size1 + size2 < size2)
		return (NULL);
	str = ft_strnew(size1 + size2);
	if (!str)
		return (str);
	tmp = str;
	while (size1--)
		*str++ = *s1++;
	while (size2--)
		*str++ = *s2++;
	return (tmp);
}
