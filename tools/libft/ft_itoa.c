/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:15:12 by abiestro          #+#    #+#             */
/*   Updated: 2018/04/10 16:30:06 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	nb;
	int				i;
	int				sign;

	i = 1;
	nb = (n < 0) ? -n : n;
	sign = 0;
	if (n < 0 && i++)
		sign = 1;
	while ((n /= 10))
		i++;
	if ((str = malloc(sizeof(char) * (i + 1))) == 0)
		return (0);
	str[i] = '\0';
	while (i--)
	{
		str[i] = nb % 10 + 48;
		nb /= 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}
