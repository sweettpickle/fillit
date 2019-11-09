/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoreah <cdoreah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:51:51 by cdoreah           #+#    #+#             */
/*   Updated: 2019/11/06 19:13:03 by cdoreah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int	*mas;
	int	len;
	int i;

	i = 0;
	len = max - min;
	if (min >= max)
		return (0);
	mas = (int *)malloc(sizeof(int) * (len));
	if (mas == NULL)
		return (0);
	while (min < max)
		mas[i++] = min++;
	return (mas);
}
