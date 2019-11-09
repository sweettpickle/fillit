/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetriminos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scash <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:28:46 by scash             #+#    #+#             */
/*   Updated: 2019/11/07 20:09:39 by cdoreah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "biblio.h"

int			number_tetrimino(char const *mas)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (mas[i])
	{
		if (mas[i] == '\n' && (mas[i + 1] == '\n' || mas[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

int			put_tetrimino(char **square, int i, int j, t_tetris tet)
{
	int		k;
	int		size;

	k = 0;
	size = ft_strlen(*square);
	while (k < 4)
	{
		if (i + tet.y[k] >= size || j + tet.x[k] >= size)
			return (0);
		if (square[i + tet.y[k]][j + tet.x[k]] != '.')
			return (0);
		k++;
	}
	k = 0;
	while (k < 4)
	{
		square[i + tet.y[k]][j + tet.x[k]] = tet.id;
		k++;
	}
	return (1);
}

int			get_and_check_tetrimino(char *argv, char **mas)
{
	int		fd;
	char	*str;
	char	*tmp;
	int		l;

	*mas = ft_strnew(0);
	fd = open(argv, O_RDONLY);
	while ((l = get_next_line(fd, &str)))
	{
		tmp = ft_strjoin(*mas, str);
		free(*mas);
		*mas = tmp;
		tmp = ft_strjoin(*mas, "\n");
		free(*mas);
		*mas = tmp;
		free(str);
	}
	if (valide_block(*mas))
	{
		free(*mas);
		ft_putstr("error\n");
		return (1);
	}
	return (0);
}

void		del_tet(t_tetris tet, char **square)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (square[i])
	{
		j = 0;
		while (square[i][j])
		{
			square[i][j] = square[i][j] == tet.id ? '.' : square[i][j];
			j++;
		}
		i++;
	}
}
