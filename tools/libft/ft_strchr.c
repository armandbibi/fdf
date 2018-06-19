/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 18:24:13 by abiestro          #+#    #+#             */
/*   Updated: 2018/04/10 16:29:23 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str && *str != c)
		str++;
	if (c == '\0' && *str == '\0')
		return ((char *)str);
	if (*str)
		return ((char *)str);
	return (NULL);
}
