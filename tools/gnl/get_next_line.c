/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 12:51:09 by abiestro          #+#    #+#             */
/*   Updated: 2018/04/30 21:32:03 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_reader	*ft_get_reader(int fd,
		t_reader **save, t_reader *reader)
{
	t_reader	*s;

	s = *save;
	while (s)
	{
		if (s->fd == fd)
		{
			reader = s;
			if (reader->rest)
			{
				reader->new_line = ft_strdup(&reader->rest[1]);
				ft_strdel(&reader->rest);
			}
			return (reader);
		}
		s = s->next;
	}
	if (!(reader = (t_reader *)malloc(sizeof(*reader))))
		return (0);
	reader->new_line = NULL;
	reader->rest = NULL;
	reader->fd = fd;
	reader->next = *save;
	*save = reader;
	return (*save);
}

static int		ft_build_line(t_reader *reader, int fd)
{
	char	*tmp;
	int		size;
	char	*tmp2;

	if (!reader->new_line)
		reader->new_line = ft_strnew(0);
	else if (ft_strchr(reader->new_line, END_LINE))
		return (1);
	tmp = ft_strnew(BUFF_SIZE);
	while (!(ft_strchr(reader->new_line, END_LINE))
			&& (size = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp2 = ft_strnew(ft_strlen(reader->new_line) + ft_strlen(tmp));
		ft_strcat(ft_strcpy(tmp2, reader->new_line), tmp);
		free(reader->new_line);
		reader->new_line = ft_strdup(tmp2);
		ft_strdel(&tmp2);
		ft_strclr(tmp);
	}
	if (size == -1)
		return (-1);
	ft_strdel(&tmp);
	return (size);
}

int				get_next_line(const int fd, char **line)
{
	static t_reader *save = NULL;
	size_t			limit;
	t_reader		*reader;

	if (!(reader = ft_get_reader(fd, &save,
					reader = NULL)) || (ft_build_line(reader, fd)) == -1)
		return (-1);
	if (!reader->new_line || !*reader->new_line)
	{
		ft_strdel(&reader->rest);
		if (*reader->new_line)
		{
			ft_strdel(&reader->new_line);
			free(reader);
			reader = reader->next;
		}
		*line = NULL;
		return (0);
	}
	limit = ft_strlen(reader->new_line) -
		ft_strlen(ft_strchr(reader->new_line, END_LINE));
	*line = ft_strncpy(ft_strnew(limit), reader->new_line, limit);
	reader->rest = ft_strdup(&reader->new_line[limit]);
	ft_strdel(&reader->new_line);
	return (1);
}
