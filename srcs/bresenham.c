/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:52:00 by abiestro          #+#    #+#             */
/*   Updated: 2018/06/19 11:47:13 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_bresenham(double *coords, void *mlx, void *window)
{
	double	dx;
	double	dy;
	double	sx;
	double	sy;
	int		err;
	int		e2;

	dx = abs((int)coords[2] - (int)coords[0]);
	dy = abs((int)coords[3] - (int)coords[1]);
	sx = (coords[0] < coords[2]) ? 1 : -1;
	sy = (coords[1] < coords[3]) ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;
	while (coords[0] > 0 && coords[1] > 0 && ((int)coords[0] != (int)coords[2] || (int)coords[1] != (int)coords[3]))
	{
		if ((int)coords[0] == (int)coords[2] && (int)coords[1] == (int)coords[3])
			return ;
		mlx_pixel_put(mlx, window, coords[0], coords[1], 0xE628AB);
		e2 = err;
		if (e2 >= -dx)
		{
			err -= dy;
			coords[0] += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			coords[1] += sy;
		}
	}
}
