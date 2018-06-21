/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:53:03 by abiestro          #+#    #+#             */
/*   Updated: 2018/06/21 18:46:14 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# define END_LINE '\n'

typedef struct		s_reader
{
	char			*rest;
	char			*new_line;
	int				fd;
	struct s_reader	*next;
}					t_reader;

int					get_next_line(const int fd, char **line);
#endif
