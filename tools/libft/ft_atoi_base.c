/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 14:27:05 by abiestro          #+#    #+#             */
/*   Updated: 2018/04/11 11:35:04 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_check(char *base)
{
	int i;
	int j;
	int isbad;

	i = 0;
	isbad = 0;
	while (base[i] && isbad == 0)
	{
		j = 0;
		while (j < i)
		{
			if (base[j] == base[i])
			{
				isbad = 1;
			}
			j++;
		}
		if (base[i] == '-' || base[j] == '+')
			isbad = 1;
		i++;
	}
	if (i <= 1 || isbad == 1)
		i = 0;
	return (i);
}

static int			ft_belongs_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int					ft_atoi_base(char *str, char *base)
{
	int value;
	int i;
	int negate;
	int sizbs;

	value = 0;
	i = 0;
	negate = 1;
	sizbs = ft_check(base);
	if (sizbs == 0)
		return (0);
	if (str[i] == '-')
		negate = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_belongs_base(str[i], base) != -1)
	{
		value = value * sizbs + ft_belongs_base(str[i], base);
		i++;
	}
	if (str[i] != '\0' && str[i] != '-' && str[i] != '+')
		return (0);
	return (value * negate);
}
