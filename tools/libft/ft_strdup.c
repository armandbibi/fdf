/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 18:28:27 by abiestro          #+#    #+#             */
/*   Updated: 2018/04/11 12:45:19 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *str)
{
	int		i;
	char	*dup;

	i = 0;
	while (str[i] != 0)
		i++;
	if ((dup = (char *)malloc(sizeof(*dup) * (i + 1))) == 0)
		return (0);
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
