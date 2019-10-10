#include "libft/libft.h"

#include <stdio.h>

int check(char const *mas)
{
	int i;
	int row;
	int symbol;

	i = 0;
	row = 0;
	symbol = 0;
	while (mas[i])
	{
		if (mas[i] == '\n')
			row++;
		if (mas[i] == '.' || mas[i] == '#')
			symbol++;
		i++;
	}
	if (row != 4 || symbol != 16)
	{
		printf("!!!");
		return (0);
	}
	printf("True!");
	return (1);
}

void function(char *argv)
{
	int fd;
	char *str;
	char *mas;
	int i;

	i = 0;
	str = ft_strnew(4);
	mas = ft_strnew(1);
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &str))
	{
		mas = ft_strjoin(mas, str);
		mas = ft_strjoin(mas, "\n");
		if (!ft_strcmp(str, ""))
		{
			check(mas);
		}
		ft_bzero(&str, 4);
		i++;
	}
//	printf("%d", i);
//	printf("%s\n", mas);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return 0;
	function(argv[1]);
	return 0;
}