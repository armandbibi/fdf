/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 18:46:32 by abiestro          #+#    #+#             */
/*   Updated: 2018/04/11 11:29:54 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_checker(char *c)
{
	unsigned int	i;
	unsigned int	j;
	int				isbad;

	i = 0;
	isbad = 0;
	while (isbad == 0 && c[i])
	{
		if (c[i] == '+' || c[i] == '-')
			isbad = 1;
		j = 0;
		while (j < i)
		{
			if (c[i] == c[j])
				isbad = 1;
			j++;
		}
		i++;
	}
	if (i <= 1 || isbad == 1)
		i = 0;
	return (i);
}

static void			ft_rec(unsigned int nb, unsigned int sizbase, char *strbase)
{
	if (nb >= sizbase)
		ft_rec(nb / sizbase, sizbase, strbase);
	ft_putchar(strbase[nb % sizbase]);
}

void				ft_putnbr_base(int nbr, char *base)
{
	unsigned int i;

	if (ft_checker(base) != 0)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			i = nbr * -1;
		}
		else
			i = nbr;
		ft_rec(i, ft_checker(base), base);
	}
}
