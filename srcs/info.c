/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 18:10:05 by abiestro          #+#    #+#             */
/*   Updated: 2018/06/24 18:17:01 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	add_information_prime(t_fdf *m)
{
	mlx_string_put(m->mlx, m->win,
			FDF_SCREEN_X - 150, 150, 0xFFFFFF, "top = ");
	mlx_string_put(m->mlx, m->win,
			FDF_SCREEN_X - 55, 150, 0xFFFFFF, ft_itoa(m->margin_top));
	mlx_string_put(m->mlx, m->win,
			FDF_SCREEN_X - 150, 170, 0xFFFFFF, "angle_z");
	mlx_string_put(m->mlx, m->win,
			FDF_SCREEN_X - 55, 170, 0xFFFFFF, ft_itoa(m->ang_x));
	mlx_string_put(m->mlx, m->win,
			FDF_SCREEN_X - 150, 190, 0xFFFFFF, "angle_y");
	mlx_string_put(m->mlx, m->win,
			FDF_SCREEN_X - 55, 190, 0xFFFFFF, ft_itoa(m->ang_y));
	mlx_string_put(m->mlx, m->win,
			FDF_SCREEN_X - 150, 210, 0xFFFFFF, "angle_z");
	mlx_string_put(m->mlx, m->win,
			FDF_SCREEN_X - 55, 210, 0xFFFFFF, ft_itoa(m->ang_z));
}

void		add_information(t_fdf *m)
{
	mlx_string_put(m->mlx, m->win,
			FDF_SCREEN_X - 150, 50, 0xFFFFFF, "coef_x = ");
	mlx_string_put(m->mlx, m->win,
			FDF_SCREEN_X - 55, 50, 0xFFFFFF, ft_itoa(m->coef_x));
	mlx_string_put(m->mlx, m->win,
			FDF_SCREEN_X - 150, 70, 0xFFFFFF, "coef_y = ");
	mlx_string_put(m->mlx, m->win,
			FDF_SCREEN_X - 55, 70, 0xFFFFFF, ft_itoa(m->coef_y));
	mlx_string_put(m->mlx, m->win,
			FDF_SCREEN_X - 150, 90, 0xFFFFFF, "coef_z = ");
	mlx_string_put(m->mlx, m->win,
			FDF_SCREEN_X - 55, 90, 0xFFFFFF, ft_itoa(m->coef_z));
	mlx_string_put(m->mlx, m->win,
			FDF_SCREEN_X - 150, 110, 0xFFFFFF, "zoom = ");
	mlx_string_put(m->mlx, m->win,
			FDF_SCREEN_X - 55, 110, 0xFFFFFF, ft_itoa(m->zoom));
	mlx_string_put(m->mlx, m->win,
			FDF_SCREEN_X - 150, 130, 0xFFFFFF, "left = ");
	mlx_string_put(m->mlx, m->win,
			FDF_SCREEN_X - 55, 130, 0xFFFFFF, ft_itoa(m->margin_lef));
	add_information_prime(m);
}
