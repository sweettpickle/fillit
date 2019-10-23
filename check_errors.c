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

int right_coloms(char const *mas)
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

int number_tetrimino(char const *mas)
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

int right_contacts(char const *mas)
{
	int i;
	int j;
	int count;

	i = 1;
	j = 1;
	count = 0;
	while (mas[i])
	{
		if (mas[i] == '\n' && mas[i + 1] == '\n')
		{
			if (count != 6 && count != 8)
				return (1);
			j = 1;
			count = 0;
		}
		if (mas[i] == '#')
		{
			if ((mas[i + 1] == '#' && j + 1 < 20) || (j - 1 >= 0 && mas[i - 1] == '#'))
				count++;
			if (mas[i + 5] == '#' || ((j - 5 >= 0) && mas[i - 5]))
				count++;
		}
		i++;
		j++;
	}
	return (0);
}

int check_errors(char const *mas)
{
	int i;

	i = 0;
	if (right_rows(mas) || right_coloms(mas))
		return (1);
	while (mas[i] != '\0')
	{
		if (mas[i] != '.' && mas[i] != '#' && mas[i] != '\n')
			return (1);
		i++;
	}
	if (!mas[0] || number_tetrimino(mas) > 26 || right_contacts(mas))
		return (1);
	return (0);
}