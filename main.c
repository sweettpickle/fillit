#include "biblio.h"

int get_and_check_tetrimino(char *argv)
{
	int fd;
	char *str;
	char *mas;

	str = ft_strnew(4);
	mas = ft_strnew(1);
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

int main(int argc, char **argv)
{
	if (argc != 2)
		return 0;
	if (get_and_check_tetrimino(argv[1]))
		return (1);
	return (0);
}