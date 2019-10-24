int		right_rows(char const *mas)
{
	int i;
	int row;
	int count;

	i = 0;
	row = 0;
	count = 0;
	while (mas[i] != '\0')
	{
		if (mas[i] == '#')
			count++;
		if (mas[i] != '\n' && (mas[i + 1] == '\n' || mas[i + 1] == '\0'))
			row++;
		if (mas[i] == '\n' && (mas[i + 1] == '\n' || mas[i + 1] == '\0'))
		{
			if (row != 4 || count != 4)
				return (1);
			row = 0;
			count = 0;
		}
		i++;
	}
	return (0);
}

int		right_columns(char const *mas)
{
	int i;
	int coloum;

	i = 0;
	coloum = 0;
	while (mas[i] != '\0')
	{
		if (mas[i] != '\n')
			coloum++;
		else if (mas[i] == '\n' && mas[i - 1] == '\n')
		{
			i++;
			continue ;
		}
		else
		{
			if (coloum != 4)
				return (1);
			coloum = 0;
		}
		i++;
	}
	return (0);
}

int		number_tetrimino(char const *mas)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (mas[i])
	{
		if (mas[i] == '\n' && (mas[i + 1] == '\n' || mas[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

int		right_figure(char const *mas)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (mas[i])
	{
		if (mas[i] == '\n' && (mas[i + 1] == '\n' || mas[i + 1] == '\0'))
		{
			if (count != 6 && count != 8)
				return (1);
			j = 0;
			count = 0;
		}
		if (mas[i] == '#')
		{
			if (j + 1 < 20 && mas[i + 1] == '#')
				count++;
			if (j - 1 >= 0 && mas[i - 1] == '#')
				count++;
			if (j + 5 < 20 && mas[i + 5] == '#')
				count++;
			if (j - 5 >= 0 && mas[i - 5] == '#')
				count++;
		}
		i++;
		j++;
	}
	return (0);
}

int		check_errors(char const *mas)
{
	int i;

	i = 0;
	if (right_rows(mas) || right_columns(mas))
		return (1);
	while (mas[i] != '\0')
	{
		if (mas[i] != '.' && mas[i] != '#' && mas[i] != '\n')
			return (1);
		i++;
	}
	if (!mas[0] || number_tetrimino(mas) > 26 || right_figure(mas))
		return (1);
	return (0);
}