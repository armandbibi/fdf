/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 16:59:26 by abiestro          #+#    #+#             */
/*   Updated: 2018/06/24 23:29:43 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		move_map(int key, t_fdf *o_fdf)
{
	if (key == 123)
		o_fdf->margin_top -= 50;
	if (key == 124)
		o_fdf->margin_top += 50;
	if (key == 126)
		o_fdf->margin_lef -= 50;
	if (key == 125)
		o_fdf->margin_lef += 50;
	mlx_clear_window(o_fdf->mlx, o_fdf->win);
	draw_all_map(o_fdf);
}

static void		transform_map(int key, t_fdf *o_fdf)
{
	if (key == 78)
		o_fdf->zoom--;
	if (key == 69)
		o_fdf->zoom++;
	if (key == 12)
		o_fdf->coef_x++;
	if (key == 13)
		o_fdf->coef_y++;
	if (key == 14)
		o_fdf->coef_z++;
	if (key == 18)
		o_fdf->coef_x--;
	if (key == 19)
		o_fdf->coef_y--;
	if (key == 20)
		o_fdf->coef_z--;
	mlx_clear_window(o_fdf->mlx, o_fdf->win);
	draw_all_map(o_fdf);
}

static void		rotate_map(int key, t_fdf *o_fdf)
{
	if (key == 0)
		o_fdf->ang_x += 0.10;
	if (key == 1)
		o_fdf->ang_y += 0.10;
	if (key == 2)
		o_fdf->ang_z += 0.10;
	if (key == 6)
		o_fdf->ang_x -= 0.10;
	if (key == 7)
		o_fdf->ang_y -= 0.10;
	if (key == 8)
		o_fdf->ang_z -= 0.10;
	mlx_clear_window(o_fdf->mlx, o_fdf->win);
	draw_all_map(o_fdf);
}

static void		color_map(int key, t_fdf *o_fdf)
{
	if (key == 83)
		o_fdf->color_blue -= 30;
	if (key == 86)
		o_fdf->color_blue += 30;
	if (key == 84)
		o_fdf->color_red -= 30;
	if (key == 87)
		o_fdf->color_red += 30;
	if (key == 85)
		o_fdf->color_green -= 30;
	if (key == 88)
		o_fdf->color_green += 30;
	mlx_clear_window(o_fdf->mlx, o_fdf->win);
	draw_all_map(o_fdf);
}

int				deal_key(int key, t_controlleur *controle)
{
	t_fdf *o_fdf;

	o_fdf = controle->o_fdf;
	if (key == 48)
	{
		controle->o_fdf = controle->o_fdf->next;
		mlx_clear_window(o_fdf->mlx, o_fdf->win);
		draw_all_map(controle->o_fdf);
	}
	if (key == 53)
	{
		mlx_destroy_window(o_fdf->mlx, o_fdf->win);
		exit(1);
	}
	if (key == 83 || key == 84 || key == 85 || key == 86 || key == 88)
		color_map(key, o_fdf);
	if (key == 123 || key == 124 || key == 125 || key == 126)
		move_map(key, o_fdf);
	if (key == 69 || key == 78 || key == 12 || key == 13 || key == 14 ||
			key == 18 || key == 19 || key == 20)
		transform_map(key, o_fdf);
	if (key == 0 || key == 1 || key == 2 || key == 6 || key == 7 || key == 8)
		rotate_map(key, o_fdf);
	return (1);
}
