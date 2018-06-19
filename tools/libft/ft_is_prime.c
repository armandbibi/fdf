/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 02:50:25 by abiestro          #+#    #+#             */
/*   Updated: 2018/02/15 09:51:28 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int racine;
	int prime;

	prime = 1;
	racine = 2;
	if (nb < 2)
		prime = 0;
	while (racine <= nb / 2 && prime == 1)
	{
		if (nb % racine == 0)
			prime = 0;
		racine++;
	}
	if (nb == 2)
		prime = 1;
	return (prime);
}
