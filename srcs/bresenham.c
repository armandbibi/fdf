/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:52:00 by abiestro          #+#    #+#             */
/*   Updated: 2018/06/22 21:39:34 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fill_pixel(t_fdf *o_fdf, long x, long y)
{
	int i;

	i = 4 * x + y * FDF_SCREEN_Y;
	i = i % ( 4 * FDF_SCREEN_Y * FDF_SCREEN_X);
	if (i > 4 && i < 4 * FDF_SCREEN_X * FDF_SCREEN_Y)
		o_fdf->img_str[i + 1] = (char)o_fdf->color_blue;
}

void	ft_bresenham(double *coords, t_fdf *o_fdf)
{
	double		err;
	double		e2;
	double		c2[4];
	int			k;

	k = 0;
	c2[0] = abs((int)coords[2] - (int)coords[0]);
	c2[1] = abs((int)coords[3] - (int)coords[1]);
	c2[2] = (coords[0] < coords[2]) ? 1 : -1;
	c2[3] = (coords[1] < coords[3]) ? 1 : -1;
	err = (c2[0] > c2[1] ? c2[0] : -c2[1]) / 2;
	while (((int)coords[0] != (int)coords[2] ||
			(int)coords[1] != (int)coords[3]) && k++ < FDF_SCREEN_X)
	{
		fill_pixel(o_fdf, (long)abs((int)coords[0]), (long)abs((int)coords[1]) );
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
