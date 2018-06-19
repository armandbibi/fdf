/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 19:40:14 by abiestro          #+#    #+#             */
/*   Updated: 2018/04/05 17:57:59 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *fraiche;
	char *fr;

	if ((fraiche = malloc(sizeof(char) * (ft_strlen(s) + 1))) == 0)
		return (0);
	fr = fraiche;
	while (*s)
		*fr++ = (*f)(*s++);
	*fr = '\0';
	return (fraiche);
}
