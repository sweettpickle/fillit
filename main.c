#include "libft/libft.h"
#include <stdio.h>

int right_rows(char const *mas)
{
	int i;
	int row;

	i = 0;
	row = 0;
	while (mas[i] != '\0')
	{
		if (mas[i] != '\n' && (mas[i + 1] == '\n' || mas[i + 1] == '\0'))
			row++;
		if (mas[i] == '\n' && (mas[i + 1] == '\n' || mas[i + 1] == '\0'))
		{
			if (row != 4)
				return (1);
			row = 0;
		}
		i++;
	}
	return (0);
}

int right_colom(char const *mas)
{
	int i;
	int colom;

	i = 0;
	colom = 0;
	while (mas[i] != '\0')
	{
		if (mas[i] != '\n')
			colom++;
		else if (mas[i] == '\n' && mas[i - 1] == '\n')
		{
			i++;
			continue ;
		}
		else
		{
			if (colom != 4)
				return (1);
			colom = 0;
		}
		i++;
	}
	return (0);
}

int check_errors(char const *mas)
{
	int i;

	i = 0;
	if (right_rows(mas) || right_colom(mas))
		return (1);
//	if (right_colom(mas))
//		return (1);
	while (mas[i] != '\0')
	{
		if (mas[i] != '.' && mas[i] != '#' && mas[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

void function(char *argv)
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
		printf("error!");
		return ;
	}
//	printf("%d", i);
	printf("%s", mas);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return 0;
	function(argv[1]);
	return 0;
}