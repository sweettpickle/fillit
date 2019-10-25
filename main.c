#include "biblio.h"

void insert_struct(t_tetris **mas_tetrims, char const *mas)
{
	int i;
	int count;
	int id;
	int num;

    i = 0;
    id = 0;
    num = 0;
    count = number_tetrimino(mas);
    *mas_tetrims = malloc(sizeof(t_tetris) * count);
    while (*mas)
    {
        if (*mas == '\n' && *(mas + 1) == '\n')
        {
            id++;
            i = 0;
            num = 0;
        }
		else if (*mas == '#')
        {
            mas_tetrims[id]->id = 'A' + id;
            mas_tetrims[id]->x[num] = i % 4;
            mas_tetrims[id]->y[num] = i / 4;
            num++;
            i++;
        }
		else if (*mas == '.')
		    i++;
		mas++;
	}
}

void    filter_mas(t_tetris **mas_tetrims) {
    int num;
    int min_y;
    int min_x;

    num = 0;
    min_y = 4;
    min_x = 4;
    while (num < 4) {
        min_x = *mas_tetrims[num]->x < min_x ? *mas_tetrims[num]->x : min_x;
        min_y = *mas_tetrims[num]->y < min_y ? *mas_tetrims[num]->y : min_y;
        num++;
    }
    num = 0;
    while (num < 4)
    {
        *mas_tetrims[num]->x -= min_x;
        *mas_tetrims[num]->y -= min_y;
        num++;
    }
}

int		get_and_check_tetrimino(char *argv, t_tetris **mas_tetrims)
{
	int     fd;
	char    *str;
	char    *mas;

	str = ft_strnew(4);
    mas = ft_strnew(1);
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &str))
	{
		mas = ft_strjoin(mas, str);
		mas = ft_strjoin(mas, "\n");
		ft_bzero(&str, 4);
	}
	if (valide_block(mas))
		return (1);
	insert_struct(mas_tetrims, mas);
	filter_mas(mas_tetrims);
	return (0);
}

void print_tet(t_tetris    *mas_tetrims, int num)
{
    int i;
    int j;
    int id;

    i = 0;
    j = 0;
    id = 0;
    while(i < 4)
    {
        j = 0;
        while(j < 4)
        {
            while(id < 4)
            {
                if (mas_tetrims[num].x[id] == j && mas_tetrims[num].y[id] == i)
            }
            j++;
        }
        i++;
    }
}

int		main(int argc, char **argv)
{
	t_tetris    *mas_tetrims;

	if (argc != 2)
		return 0;
	if (get_and_check_tetrimino(argv[1], &mas_tetrims))
	{
		printf("error");
		return (1);
	}
	return (0);
}
