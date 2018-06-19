/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:22:17 by abiestro          #+#    #+#             */
/*   Updated: 2018/04/10 16:23:17 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char const	*nextword(const char *s, char c)
{
	while (*s && *s != c)
		s++;
	while (*s && *s == c)
		s++;
	return ((char *)s);
}

static int			lenword(const char *s, char c)
{
	int i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char			*saveword(char *dest, const char *src, char c)
{
	int i;

	i = 0;
	if ((dest = malloc(sizeof(char) * (lenword(src, c)))) == 0)
		return (0);
	while (src[i] && src[i] != c)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char				**ft_strsplit(char const *str, char c)
{
	char		**tab;
	int			i;
	const char	*s;

	while (*str == c)
		str++;
	s = str;
	i = 0;
	while (*s && ++i)
		s = nextword(s, c);
	if ((tab = malloc(sizeof(char *) * (i + 1))) == 0)
		return (NULL);
	i = 0;
	while (*str)
	{
		tab[i] = saveword(tab[i], str, c);
		str = nextword(str, c);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
