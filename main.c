/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scash <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:15:58 by scash             #+#    #+#             */
/*   Updated: 2019/11/07 17:09:48 by scash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "biblio.h"

void			print_tab(char **tab, int size)
{
	int			i;

	i = 0;
	while (i < size)
	{
		ft_putstr(tab[i]);
		i++;
		ft_putchar('\n');
	}
}

int				eval_tet(t_tetris *mas_tetrims,
		int num, char **square, int size)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (1)
	{
		if (put_tetrimino(square, i, j, *mas_tetrims))
		{
			if (mas_tetrims->id - 'A' == num - 1)
				return (1);
			if (eval_tet((mas_tetrims + 1), num, square, size))
				return (1);
			else
				del_tet(*mas_tetrims, square);
		}
		j++;
		if (j == size)
		{
			j = 0;
			i++;
		}
		if (i == size)
			return (0);
	}
}

void			cleaning(char *mas, char **square,
		int size, t_tetris *mas_tetrims)
{
	int			i;

	i = 0;
	free(mas);
	while (i < size)
		free(square[i++]);
	free(square);
	free(mas_tetrims);
}

int				main(int argc, char **argv)
{
	t_tetris	*mas_tetrims;
	char		*mas;
	int			i;
	char		**square;

	square = NULL;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (0);
	}
	if (get_and_check_tetrimino(argv[1], &mas))
		return (1);
	mas_tetrims = insert_struct(mas);
	i = number_tetrimino(mas);
	while (i-- > 0)
		filter_mas(mas_tetrims, i);
	i = get_min_size(mas_tetrims, number_tetrimino(mas));
	square = create_square(i, square);
	while (!eval_tet(mas_tetrims, number_tetrimino(mas), square, i))
		square = create_square(++i, square);
	print_tab(square, i);
	cleaning(mas, square, i, mas_tetrims);
	return (0);
}
