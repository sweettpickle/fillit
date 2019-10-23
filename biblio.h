#ifndef FILLIT1_BIBLIO_H
# define FILLIT1_BIBLIO_H

# include "libft/libft.h"
# include <stdio.h>

int right_rows(char const *mas);
int right_coloms(char const *mas);
int number_tetrimino(char const *mas);
int right_contacts(char const *mas);
int check_errors(char const *mas);
int get_and_check_tetrimino(char *argv);

#endif