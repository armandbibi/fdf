/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 19:52:15 by abiestro          #+#    #+#             */
/*   Updated: 2018/04/03 20:13:50 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char *n;
	char *h;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		n = (char *)needle;
		h = (char *)haystack;
		while (*n == *h)
		{
			n++;
			h++;
			if (*n == '\0')
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
