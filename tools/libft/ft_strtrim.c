/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 21:11:59 by abiestro          #+#    #+#             */
/*   Updated: 2018/04/10 16:23:55 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char *sub;
	char *end;

	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	end = (char *)s;
	if (*s == '\0')
		return (ft_strdup((char *)s));
	while (*end)
		end++;
	end--;
	while (*end == ' ' || *end == '\t' || *end == '\n')
		end--;
	if ((sub = malloc(sizeof(char) * (end - s + 2))) == 0)
		return (0);
	ft_strncpy(sub, s, (end - s + 1));
	sub[end - s + 1] = '\0';
	return (char *)sub;
}
