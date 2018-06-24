/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 20:09:58 by abiestro          #+#    #+#             */
/*   Updated: 2018/06/24 22:37:23 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		**add_line(int **map, int size, char *line)
{
	int		**map_alloc;
	int		i;
	char	**split;

	i = -1;
	if (!(map_alloc = malloc(sizeof(int*) * (size + 2))))
		return (0);
	while (++i < size)
		map_alloc[i] = map[i];
	i = 0;
	split = ft_strsplit(line, ' ');
	while (split[i])
		i++;
	if (!(map_alloc[size] = (int *)malloc(sizeof(int) * (i + 1))))
		return (0);
	i = 0;
	while (split[i])
	{
		map_alloc[size][i] = ft_atoi(split[i]);
		free(split[i++]);
	}
	map_alloc[size][i] = 1000;
	free(map);
	free(split);
	return (map_alloc);
}

int				**parse_file(char *file, int **map)
{
	char	*line;
	int		size;
	int		fd;

	size = 0;
	map = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		exit(1);
	while (get_next_line(fd, &line))
	{
		map = add_line(map, size++, line);
		map[size] = NULL;
		free(line);
	}
	close(fd);
	return (map);
}
