#include "biblio.h"

//void insert_struct(t_tetris *mas_tetrims, char const *mas)
//{
//	int i;
//
//	i = 0;
//	while (mas[i])
//	{
//		if (mas[i] == '#')
//
//		i++;
//	}
//}

int		get_and_check_tetrimino(char *argv, char const *mas)
{
	int fd;
	char *str;

	str = ft_strnew(4);
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &str))
	{
		mas = ft_strjoin(mas, str);
		mas = ft_strjoin(mas, "\n");
		ft_bzero(&str, 4);
	}
	if (valide_block(mas))
		return (1);
	printf("%s", mas);
	return (0);
}

int		main(int argc, char **argv)
{
	char *mas;
//	int size;
//	t_tetris *mas_tetrims;

	mas = ft_strnew(1);
	if (argc != 2)
		return 0;
	if (get_and_check_tetrimino(argv[1], mas))
	{
		printf("error");
		return (1);
	}
//	if (!(mas_tetrims = (t_tetris*)malloc(size)))
//		return (1);
//	insert_struct(mas_tetrims, mas);
//	ft_strdel(&mas);
//	solve_tetris(mas_tetrims);
	return (0);
}