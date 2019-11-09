/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoreah <cdoreah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:54:53 by cdoreah           #+#    #+#             */
/*   Updated: 2019/11/06 19:13:03 by cdoreah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		print(char *str)
{
	while (*str != '\0')
	{
		if (*str > 31 && *str < 127)
		{
			str++;
		}
		else
			return (0);
	}
	return (1);
}

int				ft_str_is_printable(char *str)
{
	int			check;

	if (*str == '\0')
		return (1);
	check = print(str);
	if (check == 1)
		return (1);
	return (0);
}
