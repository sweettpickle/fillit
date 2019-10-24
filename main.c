#include "biblio.h"

void insert_struct(char const *mas)
{
	int i;
	t_tetris *block;

	i = 0;
	while (mas[i])
	{
		if (mas[i] == '#')

		i++;
	}
}

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
	if (check_errors(mas))
	{
		printf("error");
		return (1);
	}
	printf("%s", mas);
	return (0);
}

int		main(int argc, char **argv)
{
	char *mas;

	mas = ft_strnew(1);
	if (argc != 2)
		return 0;
	if (get_and_check_tetrimino(argv[1], mas))
		return (1);
	insert_struct(mas);
//	clear(mas);
	return (0);
}