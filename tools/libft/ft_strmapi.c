/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 19:52:13 by abiestro          #+#    #+#             */
/*   Updated: 2018/04/05 17:58:37 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*fraiche;
	char	*fr;

	if ((fraiche = malloc(sizeof(char) * (ft_strlen(s) + 1))) == 0)
		return (0);
	i = 0;
	fr = fraiche;
	while (*s)
		*fr++ = (*f)(i++, *s++);
	*fr = '\0';
	return (fraiche);
}
