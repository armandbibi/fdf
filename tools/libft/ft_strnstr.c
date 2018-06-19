/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 21:54:58 by abiestro          #+#    #+#             */
/*   Updated: 2018/04/10 17:27:11 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*h;
	char	*n;
	int		j;

	if (needle == haystack)
		return ((char *)haystack);
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len)
	{
		j = (int)len;
		h = (char *)haystack;
		n = (char *)needle;
		while (*h && *h == *n && j--)
		{
			h++;
			n++;
			if (!*n)
				return ((char *)haystack);
		}
		len--;
		haystack++;
	}
	return (0);
}
