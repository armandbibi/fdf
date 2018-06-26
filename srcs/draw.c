/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 15:32:52 by abiestro          #+#    #+#             */
/*   Updated: 2018/06/25 21:37:55 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static double	rotate(double *i, double *j, double *k, t_fdf *o_fdf)
{
	double a;
	double b;
	double c;

	a = *i;
	b = *j;
	c = *k;
	*i = (a * cos(o_fdf->ang_x) - b * sin(o_fdf->ang_x));
	*j = (b * cos(o_fdf->ang_x) + a * sin(o_fdf->ang_x));
	a = *i;
	b = *j;
	*k = (c * cos(o_fdf->ang_z) - a * sin(o_fdf->ang_z));
	*i = (a * cos(o_fdf->ang_z) + c * sin(o_fdf->ang_z));
	a = *i;
	c = *k;
	*j = (b * cos(o_fdf->ang_y) - c * sin(o_fdf->ang_y));
	*k = (c * cos(o_fdf->ang_y) + b * sin(o_fdf->ang_y));
	return (1);
}

static void		draw_left(t_fdf *o_fdf, int i, int j)
{
	double coord[4];
	double a;
	double b;
	double c;

	a = i;
	b = j;
	c = o_fdf->map[i][j];
	rotate(&a, &b, &c, o_fdf);
	coord[1] = o_fdf->margin_lef + o_fdf->zoom *
		((a - b) * o_fdf->coef_x - (c / 5) * o_fdf->coef_z);
	coord[0] = o_fdf->margin_top + o_fdf->zoom * ((a + b) * o_fdf->coef_y);
	a = i + 1;
	b = j;
	c = o_fdf->map[i + 1][j];
	rotate(&a, &b, &c, o_fdf);
	coord[3] = o_fdf->margin_lef + o_fdf->zoom *
		((a - b) * o_fdf->coef_x - (c / 5) * o_fdf->coef_z);
	coord[2] = o_fdf->margin_top + o_fdf->zoom * ((a + b) * o_fdf->coef_y);
	o_fdf->color = o_fdf->color_blue + o_fdf->color_red + o_fdf->color_green;
	ft_bresenham(coord, o_fdf);
}

static void		draw_top(t_fdf *o_fdf, int i, int j)
{
	double coord[4];
	double a;
	double b;
	double c;

	a = i;
	b = j;
	c = o_fdf->map[i][j];
	rotate(&a, &b, &c, o_fdf);
	coord[1] = o_fdf->margin_lef + o_fdf->zoom *
		((a - b) * o_fdf->coef_x - (c / 5) * o_fdf->coef_z);
	coord[0] = o_fdf->margin_top + o_fdf->zoom * ((a + b) * o_fdf->coef_y);
	a = i;
	b = j + 1;
	c = o_fdf->map[i][j + 1];
	rotate(&a, &b, &c, o_fdf);
	coord[3] = o_fdf->margin_lef + o_fdf->zoom *
		((a - b) * o_fdf->coef_x - (c / 5) * o_fdf->coef_z);
	coord[2] = o_fdf->margin_top + o_fdf->zoom * ((a + b) * o_fdf->coef_y);
	ft_bresenham(coord, o_fdf);
}

void			draw_map(t_fdf *o_fdf)
{
	int i;
	int j;
	int k;

	i = 0;
	while (o_fdf->map[i])
	{
		j = 0;
		while (o_fdf->map[i][j] != 1000)
		{
			if (o_fdf->map[i + 1] && o_fdf->map[i + 1][j] != 1000)
			{
				k = 0;
				while (o_fdf->map[i + 1][k] != 1000 && k != j)
					k++;
				if (k == j)
					draw_left(o_fdf, i, j);
			}
			if (o_fdf->map[i][j + 1] != 1000)
				draw_top(o_fdf, i, j);
			j++;
		}
		i++;
	}
}
