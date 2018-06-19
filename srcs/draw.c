/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 15:32:52 by abiestro          #+#    #+#             */
/*   Updated: 2018/06/19 20:02:18 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

double	rotate_x(double i, double j, double k, t_fdf *o_fdf)
{
	double d;

	(void)k;
	d = i * cos(o_fdf->ang_x)  - j * sin(o_fdf->ang_x);
	d += (j * sin(o_fdf->ang_y)  + i * cos(o_fdf->ang_y));
	return (d);
}

double	rotate_y(double i, double j, double k, t_fdf *o_fdf)
{
	double d;

	(void)k;
	d = i * sin(o_fdf->ang_x)  + j * cos(o_fdf->ang_x);
	d += (j * cos(o_fdf->ang_y)  - i * sin(o_fdf->ang_y));
	return (d);
}

double	rotate_z(int i, double j, double k, t_fdf *o_fdf)
{
	double d;

	(void)j;
	d = i * cos(o_fdf->ang_z)  - (k- 48) * sin(o_fdf->ang_z);
	return (k);
}

void draw_map(t_fdf *o_fdf)
{
	double coord[4];
	int i;
	int j;
	double a;
	double b;
	double c;

	i = 0;
	while (o_fdf->map[i])
	{
		j = 0;
		while (o_fdf->map[i][j])
		{
			if (o_fdf->map[i + 1] && o_fdf->map[i + 1][j])
			{
				a = rotate_x(i, j, o_fdf->map[i][j], o_fdf);
				b = rotate_y(i, j, o_fdf->map[i][j], o_fdf);
				c = rotate_z(i, j, o_fdf->map[i][j], o_fdf);
				coord[1] = o_fdf->margin_lef + o_fdf->zoom * ((a - b) * o_fdf->coef_x - (c - 48) * o_fdf->coef_z);
				coord[0] = o_fdf->margin_top + o_fdf->zoom * ((a + b) * o_fdf->coef_y);
				a = rotate_x(i + 1, j, o_fdf->map[i + 1][j], o_fdf);
				b = rotate_y(i + 1, j, o_fdf->map[i + 1][j], o_fdf);
				c = rotate_z(i + 1, j, o_fdf->map[i + 1][j], o_fdf);
				coord[3] = o_fdf->margin_lef + o_fdf->zoom * ((a - b) * o_fdf->coef_x - (c - 48) * o_fdf->coef_z);
				coord[2] = o_fdf->margin_top + o_fdf->zoom * ((a + b) * o_fdf->coef_y);
				ft_bresenham(coord, o_fdf->mlx, o_fdf->win);
			}
			if (o_fdf->map[i][j + 1])
			{
				a = rotate_x(i, j, o_fdf->map[i][j], o_fdf);
				b = rotate_y(i, j, o_fdf->map[i][j], o_fdf);
				c = rotate_z(i, j, o_fdf->map[i][j], o_fdf);
				coord[1] = o_fdf->margin_lef + o_fdf->zoom * ((a - b) * o_fdf->coef_x - (c - 48) * o_fdf->coef_z);
				coord[0] = o_fdf->margin_top + o_fdf->zoom * ((a + b) * o_fdf->coef_y);
				a = rotate_x(i, j + 1, o_fdf->map[i][j + 1], o_fdf);
				b = rotate_y(i, j + 1, o_fdf->map[i][j + 1], o_fdf);
				c = rotate_z(i, j + 1, o_fdf->map[i][j + 1], o_fdf);
				coord[3] = o_fdf->margin_lef + o_fdf->zoom * ((a - b) * o_fdf->coef_x - (c - 48) * o_fdf->coef_z);
				coord[2] = o_fdf->margin_top + o_fdf->zoom * ((a + b) * o_fdf->coef_y);
				ft_bresenham(coord, o_fdf->mlx, o_fdf->win);
			}
			j++;
		}
		i++;
	}
}

/*
if (o_fdf->map[i + 1] && o_fdf->map[i + 1][j])
{
	coord[1] = o_fdf->margin_lef + o_fdf->zoom * ((i - j) * o_fdf->coef_x - (o_fdf->map[i][j] - 48) * o_fdf->coef_z);
	coord[0] = o_fdf->margin_top + o_fdf->zoom * ((i + j) * o_fdf->coef_y);
	coord[3] = o_fdf->margin_lef + o_fdf->zoom * (((i + 1) - j) * o_fdf->coef_x - (o_fdf->map[i + 1][j] - 48) * o_fdf->coef_z);
	coord[2] = o_fdf->margin_top + o_fdf->zoom * (((i + 1) + j) * o_fdf->coef_y);
	ft_bresenham(coord, o_fdf->mlx, o_fdf->win);
}
if (o_fdf->map[i][j + 1])
{
	coord[1] = o_fdf->margin_lef + o_fdf->zoom * ((i - j) * o_fdf->coef_x - (o_fdf->map[i][j] - 48) * o_fdf->coef_z);
	coord[0] = o_fdf->margin_top + o_fdf->zoom * ((i + j) * o_fdf->coef_y);
	coord[3] = o_fdf->margin_lef + o_fdf->zoom * ((i - (j + 1)) * o_fdf->coef_x - (o_fdf->map[i][j + 1] - 48) * o_fdf->coef_z);
	coord[2] = o_fdf->margin_top + o_fdf->zoom * ((i + (j + 1)) * o_fdf->coef_y);
	ft_bresenham(coord, o_fdf->mlx, o_fdf->win);
}*/
