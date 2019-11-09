/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scash <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:19:58 by scash             #+#    #+#             */
/*   Updated: 2019/11/07 14:34:12 by cdoreah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "biblio.h"

int		right_rows(char const *mas)
{
	int	i;
	int	row;
	int	count;

	i = 0;
	row = 0;
	count = 0;
	while (mas[i] != '\0')
	{
		if (mas[i] == '#')
			count++;
		if (mas[i] != '\n' && (mas[i + 1] == '\n' || mas[i + 1] == '\0'))
			row++;
		if (mas[i] == '\n' && (mas[i + 1] == '\n' || mas[i + 1] == '\0'))
		{
			if (row != 4 || count != 4)
				return (1);
			row = 0;
			count = 0;
		}
		i++;
	}
	return (0);
}

int		right_columns(char const *mas)
{
	int i;
	int coloum;

	i = 0;
	coloum = 0;
	while (mas[i] != '\0')
	{
		if (mas[i] != '\n')
			coloum++;
		else if (mas[i] == '\n' && mas[i - 1] == '\n')
		{
			i++;
			continue ;
		}
		else
		{
			if (coloum != 4)
				return (1);
			coloum = 0;
		}
		i++;
	}
	return (0);
}

void	tchecker(char const *mas, int i, int j, int *count)
{
	if (j + 1 < 20 && mas[i + 1] == '#')
		*count = *count + 1;
	if (j - 1 >= 0 && mas[i - 1] == '#')
		*count = *count + 1;
	if (j + 5 < 20 && mas[i + 5] == '#')
		*count = *count + 1;
	if (j - 5 >= 0 && mas[i - 5] == '#')
		*count = *count + 1;
}

int		valide_figure(char const *mas, int i, int j)
{
	int count;
	int l;

	count = 0;
	l = 0;
	while (mas[i])
	{
		if (mas[i] == '\n' && mas[i - 1] != '\n')
			l++;
		if (l != 0 && l % 4 == 0)
		{
			l = 0;
			if (count != 6 && count != 8)
				return (1);
			count = 0;
			j = 0;
			i++;
		}
		if (mas[i] == '#')
			tchecker(mas, i, j, &count);
		i++;
		j++;
	}
	return (0);
}

int		valide_block(char const *mas)
{
	int i;

	i = 0;
	if (right_rows(mas) || right_columns(mas))
		return (1);
	while (mas[i] != '\0')
	{
		if (mas[i] != '.' && mas[i] != '#' && mas[i] != '\n')
			return (1);
		i++;
	}
	if (valide_figure(mas, 0, 0) || !mas[0] || number_tetrimino(mas) > 26)
		return (1);
	return (0);
}
