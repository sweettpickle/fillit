/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scash <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:50:32 by scash             #+#    #+#             */
/*   Updated: 2019/11/06 19:13:03 by cdoreah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "biblio.h"

void		set_tet(t_tetris *mas_tetrims, int id, int *num, int *i)
{
	mas_tetrims[id].id = 'A' + id;
	mas_tetrims[id].x[*num] = *i % 4;
	mas_tetrims[id].y[*num] = *i / 4;
	*num = *num + 1;
	*i = *i + 1;
}

void		fill(char const *mas, t_tetris *mas_tetrims, int id, int num)
{
	int i;

	i = 0;
	while (*mas)
	{
		if (*mas == '\n')
		{
			if (*(mas + 1) == '\n')
			{
				id++;
				i = 0;
				num = 0;
			}
			else if (*(mas + 1) == '\0')
				break ;
		}
		else if (*mas == '#')
			set_tet(mas_tetrims, id, &num, &i);
		else if (*mas == '.')
			i++;
		mas++;
	}
}

t_tetris	*insert_struct(char const *mas)
{
	int			count;
	int			id;
	int			num;
	t_tetris	*mas_tetrims;

	num = 0;
	id = 0;
	count = number_tetrimino(mas);
	mas_tetrims = malloc(sizeof(t_tetris) * count);
	fill(mas, mas_tetrims, id, num);
	return (mas_tetrims);
}

void		filter_mas(t_tetris *mas_tetrims, int id)
{
	int	num;
	int	min_y;
	int	min_x;

	num = 0;
	min_y = 4;
	min_x = 4;
	while (num < 4)
	{
		min_x = mas_tetrims[id].x[num] < min_x ? mas_tetrims[id].x[num] : min_x;
		min_y = mas_tetrims[id].y[num] < min_y ? mas_tetrims[id].y[num] : min_y;
		num++;
	}
	num = 0;
	while (num < 4)
	{
		mas_tetrims[id].x[num] -= min_x;
		mas_tetrims[id].y[num] -= min_y;
		num++;
	}
}
