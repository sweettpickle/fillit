/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoreah <cdoreah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 22:27:00 by cdoreah           #+#    #+#             */
/*   Updated: 2019/10/25 15:36:09 by cdoreah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*copy_b;
	const char	*copy_l;
	size_t		n;

	if (!*little)
		return ((char *)big);
	while (*big && len)
	{
		if (*big == *little)
		{
			copy_b = big;
			copy_l = little;
			n = len;
			while ((*copy_b == *copy_l) && (*copy_b && *copy_l) && n--)
			{
				copy_b++;
				copy_l++;
			}
			if (!*copy_l)
				return ((char *)big);
		}
		len--;
		big++;
	}
	return (NULL);
}
