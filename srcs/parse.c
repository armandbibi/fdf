/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 20:09:58 by abiestro          #+#    #+#             */
/*   Updated: 2018/06/21 19:29:24 by abiestro         ###   ########.fr       */
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
	printf("\n");
	if (!(map_alloc[size] = (int *)malloc(sizeof(int) * (i + 1))))
		return (0);
	i = -1;
	while (split[++i])
	{
		map_alloc[size][i] = ft_atoi(split[i]);
		free(split[i]);
	}
	printf("size : %d\n", size);
	map_alloc[size][i] = 1000;
	map_alloc[size + 1] = NULL;
	free(map);
	free(split);
	return (map_alloc);
}

static void seemap(int **map, char *file)
{
	int i;
	int j;

	printf("%s\n", file);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != 1000)
			printf("-%3d -", map[i][j++]);
		printf("\n");
		i++;
	}

}

int				**parse_file(char *file, int **map)
{
	char	*line;
	int		size;
	int		fd;

	size = 0;
	map = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		map = add_line(map, size++, line);
		free(line);
	}
	seemap(map, file);
	close(fd);
	return (map);
}
