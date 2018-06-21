/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:52:00 by abiestro          #+#    #+#             */
/*   Updated: 2018/06/21 20:40:43 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_bresenham(double *coords, void *mlx, void *window, int color)
{
	double		err;
	double		e2;
	double		c2[4];

	c2[0] = abs((int)coords[2] - (int)coords[0]);
	c2[1] = abs((int)coords[3] - (int)coords[1]);
	c2[2] = (coords[0] < coords[2]) ? 1 : -1;
	c2[3] = (coords[1] < coords[3]) ? 1 : -1;
	err = (c2[0] > c2[1] ? c2[0] : -c2[1]) / 2;
	while (((int)coords[0] != (int)coords[2] ||
			(int)coords[1] != (int)coords[3]))
	{
		mlx_pixel_put(mlx, window, abs((int)coords[0]) % FDF_SCREEN_X, abs((int)coords[1]) % FDF_SCREEN_Y, color);
		e2 = err;
		if (e2 >= -c2[0])
		{
			err -= c2[1];
			coords[0] += c2[2];
		}
		if (e2 < c2[1])
		{
			err += c2[0];
			coords[1] += c2[3];
		}
	}
}
