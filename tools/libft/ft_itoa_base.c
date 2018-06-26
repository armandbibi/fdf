/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:15:12 by abiestro          #+#    #+#             */
/*   Updated: 2018/06/25 19:41:19 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	reverse(char *str, int length)
{
	int		start;
	int		end;
	char	tmp;

	start = 0;
	end = length - 1;
	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}

char		*ft_unsigned_itoa(uintmax_t num, char *str, int base, int max_size)
{
	int				i;
	unsigned int	rem;

	i = 0;
	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}
	while (num != 0 && max_size-- > 0)
	{
		rem = num % base;
		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num = num / base;
	}
	str[i] = '\0';
	reverse(str, i);
	return (str);
}

char		*ft_itoa(intmax_t num, char *str, int base)
{
	int i;
	int isnegative;
	int rem;

	i = 0;
	isnegative = 0;
	if (num < 0 && base == 10)
	{
		isnegative = 1;
		num = -num;
	}
	while (num != 0)
	{
		rem = num % base;
		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num = num / base;
	}
	if (isnegative)
		str[i++] = '-';
	str[i] = '\0';
	reverse(str, i);
	return (str);
}
