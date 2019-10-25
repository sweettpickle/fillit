#ifndef FILLIT1_BIBLIO_H
# define FILLIT1_BIBLIO_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct	s_tetris
{
	char		*id;
	int			x[4];
	int			y[4];
	struct		s_tetris *next;
}				t_tetris;

int				right_rows(char const *mas);
int				right_columns(char const *mas);
int				number_tetrimino(char const *mas);
int				valide_figure(char const *mas);
int				valide_block(char const *mas);
int				get_and_check_tetrimino(char *argv, char const *mas);

#endif
