/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scash <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:45:18 by scash             #+#    #+#             */
/*   Updated: 2019/11/07 14:19:24 by cdoreah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "biblio.h"

void	clear_square(int size, char **square)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(square[i]);
		i++;
	}
	free(square);
}

char	**create_square(int size, char **squar)
{
	char	**square;
	int		i;
	int		j;

	i = 0;
	if (squar != NULL)
		clear_square(size, squar);
	square = malloc(sizeof(char *) * size + 1);
	i = 0;
	while (i < size)
	{
		j = 0;
		square[i] = ft_strnew(size);
		while (j < size)
		{
			square[i][j] = '.';
			j++;
		}
		i++;
	}
	square[size] = NULL;
	return (square);
}

int		get_min_size(t_tetris *mas_tetrims, int num)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	max = 0;
	while (i < num)
	{
		j = 0;
		while (j < 4)
		{
			max = mas_tetrims[i].x[j] > max ? mas_tetrims[i].x[j] : max;
			max = mas_tetrims[i].y[j] > max ? mas_tetrims[i].y[j] : max;
			j++;
		}
		i++;
	}
	return (max + 1);
}
