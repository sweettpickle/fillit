/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoreah <cdoreah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 21:56:20 by cdoreah           #+#    #+#             */
/*   Updated: 2019/10/06 13:44:53 by cdoreah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char *copy_h;
	const char *copy_n;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			copy_h = haystack;
			copy_n = needle;
			while ((*copy_h == *copy_n) && (*copy_h && *copy_n))
			{
				copy_h++;
				copy_n++;
			}
			if (!*copy_n)
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
