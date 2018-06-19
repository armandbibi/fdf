/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 14:32:49 by abiestro          #+#    #+#             */
/*   Updated: 2018/04/04 14:42:07 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	void *s;

	s = str1;
	while (n)
	{
		*(unsigned char *)s = *(unsigned char *)str2;
		s++;
		str2++;
		n--;
	}
	return (str1);
}
