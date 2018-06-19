/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 18:17:39 by abiestro          #+#    #+#             */
/*   Updated: 2018/04/05 13:23:12 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *mem;
	void *m;

	if ((mem = malloc(sizeof(void) * size)) == 0)
		return (0);
	m = mem;
	while (size--)
	{
		*(unsigned char *)m = '\0';
		m++;
	}
	return (mem);
}
