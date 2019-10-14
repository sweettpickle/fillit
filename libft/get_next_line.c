/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdoreah <cdoreah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:56:46 by cdoreah           #+#    #+#             */
/*   Updated: 2019/10/06 13:43:53 by cdoreah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				read_line(const int fd, char **mas)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;
	char		*tmp;

	if ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(*mas, buf);
		ft_strdel(mas);
		*mas = tmp;
		return (1);
	}
	if (!ret)
		return (0);
	return (-1);
}

char			*get_line(char **mas, char **line)
{
	int			len;
	char		*tmp;
	int			len_mas;

	len = 0;
	len_mas = ft_strlen(*mas);
	while ((*mas)[len] != '\n' && len_mas-- > 0)
		len++;
	if ((*mas)[len] == '\n')
	{
		*line = ft_strsub(*mas, 0, len);
		tmp = ft_strdup(*mas + len + 1);
		ft_strdel(mas);
		*mas = tmp;
	}
	else
	{
		*line = ft_strsub(*mas, 0, len);
		ft_strdel(mas);
	}
	return (*line);
}

int				get_next_line(const int fd, char **line)
{
	static char *mas[MAX_FD];
	int			ret;

	if (fd < 0 || fd > MAX_FD)
		return (-1);
	if (!mas[fd])
		mas[fd] = ft_strnew(0);
	if (!line || (ret = read_line(fd, &mas[fd])) < 0)
		return (-1);
	while (ret > 0)
	{
		if (ft_strchr(mas[fd], '\n'))
			break ;
		ret = read_line(fd, &mas[fd]);
	}
	if (!ret && !ft_strcmp(mas[fd], "\0"))
		return (0);
	*line = get_line(&mas[fd], line);
	return (1);
}
