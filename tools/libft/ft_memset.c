/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 18:26:17 by abiestro          #+#    #+#             */
/*   Updated: 2018/04/04 17:06:55 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	void *s;

	s = str;
	while (n)
	{
		*(unsigned char*)s = (unsigned char)c;
		s++;
		n--;
	}
	return (str);
}
