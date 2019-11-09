/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biblio.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scash <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:32:40 by scash             #+#    #+#             */
/*   Updated: 2019/11/07 14:41:53 by cdoreah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT1_BIBLIO_H
# define FILLIT1_BIBLIO_H

# include "libft/libft.h"

typedef struct	s_tetris
{
	char	id;
	int		x[4];
	int		y[4];
}				t_tetris;

void			filter_mas(t_tetris *mas_tetrims, int id);
t_tetris		*insert_struct(char const *mas);
int				right_rows(char const *mas);
int				right_columns(char const *mas);
int				number_tetrimino(char const *mas);
int				valide_figure(char const *mas, int i, int j);
int				valide_block(char const *mas);
int				get_and_check_tetrimino(char *argv, char **mas);
char			**create_square(int size, char **squar);
int				get_min_size(t_tetris *mas_tetrims, int num);
int				number_tetrimino(char const *mas);
int				put_tetrimino(char **square, int i, int j, t_tetris tet);
int				get_and_check_tetrimino(char *argv, char **mas);
void			del_tet(t_tetris tet, char **square);

#endif
