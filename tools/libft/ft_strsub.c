/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 20:25:58 by abiestro          #+#    #+#             */
/*   Updated: 2018/04/10 16:24:11 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *fr;
	char *f;

	if ((fr = malloc(sizeof(char) * (len + 1))) == 0)
		return (NULL);
	f = fr;
	while (start--)
		s++;
	while (len--)
		*fr++ = *s++;
	*fr = '\0';
	return (f);
}
