/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoreah <cdoreah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 22:56:51 by cdoreah           #+#    #+#             */
/*   Updated: 2019/10/06 13:44:53 by cdoreah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		i;
	int		begin;
	int		end;
	char	*str;

	i = 0;
	if (!s)
		return (0);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	begin = i;
	while (s[i + 1])
		i++;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i--;
	end = i;
	str = ft_strnew(end - begin + 1);
	if (!str)
		return (0);
	i = 0;
	while (begin <= end)
		str[i++] = s[begin++];
	return (str);
}
