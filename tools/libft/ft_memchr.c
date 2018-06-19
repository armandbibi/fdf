/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:18:38 by abiestro          #+#    #+#             */
/*   Updated: 2018/04/04 17:04:18 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	void *s;

	s = (void *)str;
	while (n--)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return (s);
		s++;
	}
	return (NULL);
}
