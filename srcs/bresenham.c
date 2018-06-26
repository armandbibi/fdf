/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:52:00 by abiestro          #+#    #+#             */
/*   Updated: 2018/06/26 21:14:20 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		fill_pixel(t_fdf *o_fdf, long x, long y)
{
	int i;

	i = abs(((int)x + (int)y * FDF_SCREEN_Y) * 4);
	i = i % (4 * FDF_SCREEN_X * FDF_SCREEN_Y);
	o_fdf->img_str[i + 0] = (char)o_fdf->color_blue;
	o_fdf->img_str[i + 2] = (char)o_fdf->color_green;
	o_fdf->img_str[i + 1] = (char)o_fdf->color_red;
}

static double	take_care_error(double err, double e2,
		double *c2, double *coords)
{
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
	return (err);
}

void			ft_bresenham(double *coords, t_fdf *o_fdf)
{
	double		err;
	double		e2;
	double		c2[4];
	int			k;

	k = 0;
	e2 = 0;
	coords[0] += 4000;
	coords[1] += 4000;
	coords[2] += 4000;
	coords[3] += 4000;
	c2[0] = abs((int)coords[2] - (int)coords[0]);
	c2[1] = abs((int)coords[3] - (int)coords[1]);
	c2[2] = (coords[0] < coords[2]) ? 1 : -1;
	c2[3] = (coords[1] < coords[3]) ? 1 : -1;
	err = (c2[0] > c2[1] ? c2[0] : -c2[1]) / 2;
	while ((abs((int)coords[0]) != abs((int)coords[2]) ||
				abs((int)coords[1]) != abs((int)coords[3])) && k++ < 1000)
	{
		if (!o_fdf->pass_wall || (coords[0] > 4000 && coords[1] > 4000
					&& coords[0] < 4000 && coords[1] < 4000))
			fill_pixel(o_fdf, (long)coords[0], (long)coords[1]);
		err = take_care_error(err, e2, c2, coords);
	}
}
