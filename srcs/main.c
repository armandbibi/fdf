/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 20:35:35 by abiestro          #+#    #+#             */
/*   Updated: 2018/06/19 17:37:01 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_map(int key, t_fdf *o_fdf)
{
	if (key == 123)
	{
		o_fdf->margin_top-= 10 * o_fdf->zoom;
		mlx_clear_window(o_fdf->mlx, o_fdf->win);
		draw_map(o_fdf);
	}
	if (key == 124)
	{
		o_fdf->margin_top += 10 * o_fdf->zoom;
		mlx_clear_window(o_fdf->mlx, o_fdf->win);
		draw_map(o_fdf);
	}
	if (key == 126)
	{
		o_fdf->margin_lef -= 10 * o_fdf->zoom;
		mlx_clear_window(o_fdf->mlx, o_fdf->win);
		draw_map(o_fdf);
	}
	if (key == 125)
	{
		o_fdf->margin_lef += 10 * o_fdf->zoom;
		mlx_clear_window(o_fdf->mlx, o_fdf->win);
		draw_map(o_fdf);
	}
}

static void zoom_map(int key, t_fdf *o_fdf)
{
	if (key == 69)
	{
		o_fdf->zoom++;
		mlx_clear_window(o_fdf->mlx, o_fdf->win);
		draw_map(o_fdf);
	}
	if (key == 78)
	{
		o_fdf->zoom--;
		mlx_clear_window(o_fdf->mlx, o_fdf->win);
		draw_map(o_fdf);
	}
}

static void dilate_map(int key, t_fdf *o_fdf)
{	
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
	draw_map(o_fdf);
}

static void rotate_map(int key, t_fdf *o_fdf)
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
	draw_map(o_fdf);
}

int	deal_key(int key, t_fdf *o_fdf)
{
	if (key)
		printf("%d\n", key);
	if (key == 49)
		mlx_clear_window(o_fdf->mlx, o_fdf->win);
	if (key == 53)
	{
		mlx_destroy_window(o_fdf->mlx, o_fdf->win);
		exit(1);
	}
	if (key == 69 || key == 78)
		zoom_map(key, o_fdf);
	if (key == 123 || key == 124 || key == 125 || key == 126)
		move_map(key, o_fdf);
	if (key == 12 || key == 13 || key == 14 || key == 18 || key == 19 || key == 20)
		dilate_map(key, o_fdf);
	if (key == 0 || key == 1 || key == 2 || key == 6 || key == 7 || key == 8)
		rotate_map(key, o_fdf);
	return (1);
}

t_fdf	fdf_constructor(t_fdf *o_fdf)
{
	o_fdf->ang_x = 360 / 3.14159265;
	o_fdf->ang_y = 90 / 3.14159265;
	o_fdf->ang_z = 0;
	o_fdf->coef_x = 1;
	o_fdf->zoom = 1;
	o_fdf->coef_y = 3;
	o_fdf->coef_z = 1;
	o_fdf->margin_top = 100;
	o_fdf->margin_lef = 300;
	return (*o_fdf);
}

int	main(int ac, char **av)
{
	t_fdf	o_fdf;

	if (ac < 2)
		return (0);
	o_fdf = fdf_constructor(&o_fdf);
	o_fdf.map = NULL;
	o_fdf.map = parse_file(av[1], o_fdf.map);
	o_fdf.mlx = mlx_init();
	o_fdf.win = mlx_new_window(o_fdf.mlx, FDF_SCREEN_X, FDF_SCREEN_Y, av[1]);
	draw_map(&o_fdf);
	mlx_key_hook(o_fdf.win, deal_key, &o_fdf);
	mlx_loop(o_fdf.mlx);
	return (0);
}
