/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 20:35:35 by abiestro          #+#    #+#             */
/*   Updated: 2018/06/20 21:52:16 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_all_map(t_fdf *m)
{
	t_fdf *s;

	s = m;
	draw_map(s);
	while (s->next != m)
	{
		s = s->next;
		draw_map(s);
	}
}

static void		move_map(int key, t_fdf *o_fdf)
{
	if (key == 123)
		o_fdf->margin_top -= 10 * o_fdf->zoom;
	if (key == 124)
		o_fdf->margin_top += 10 * o_fdf->zoom;
	if (key == 126)
		o_fdf->margin_lef -= 10 * o_fdf->zoom;
	if (key == 125)
		o_fdf->margin_lef += 10 * o_fdf->zoom;
	mlx_clear_window(o_fdf->mlx, o_fdf->win);
	draw_all_map(o_fdf);
}

static void		zoom_map(int key, t_fdf *o_fdf)
{
	if (key == 69)
		o_fdf->zoom++;
	if (key == 78)
		o_fdf->zoom--;
	mlx_clear_window(o_fdf->mlx, o_fdf->win);
	draw_all_map(o_fdf);
}

static void		dilate_map(int key, t_fdf *o_fdf)
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

int	deal_key(int key, t_controlleur *controle)
{
	t_fdf *o_fdf = controle->o_fdf;
	if (key)
		printf("%d\n", key);
	if (key == 30)
	{
		o_fdf->color_blue = 0x00;
		o_fdf->color_red = 0xA200;
		o_fdf->color_green = 0x0000;
		controle->o_fdf = controle->o_fdf->next;
		o_fdf->next->color_blue = 0xFF;
		o_fdf->next->color_red = 0xFF00;
		o_fdf->next->color_green = 0xFF0000;
		mlx_clear_window(o_fdf->mlx, o_fdf->win);
		draw_all_map(o_fdf);
	}
	if (key == 49)
	{
		fdf_constructor(o_fdf, 100);
		mlx_clear_window(o_fdf->mlx, o_fdf->win);
		draw_all_map(o_fdf);
	}
	if (key == 53)
	{
		mlx_destroy_window(o_fdf->mlx, o_fdf->win);
		exit(1);
	}
	if (key == 69 || key == 78)
		zoom_map(key, o_fdf);
	if (key == 123 || key == 124 || key == 125 || key == 126)
		move_map(key, o_fdf);
	if (key == 12 || key == 13 || key == 14 ||
			key == 18 || key == 19 || key == 20)
		dilate_map(key, o_fdf);
	if (key == 0 || key == 1 || key == 2 || key == 6 || key == 7 || key == 8)
		rotate_map(key, o_fdf);
	return (1);
}

t_fdf	fdf_constructor(t_fdf *o_fdf, int i)
{
	o_fdf->id = i;
	o_fdf->ang_x = 0 / 3.14159265;
	o_fdf->ang_y = 0 / 3.14159265;
	o_fdf->ang_z = 0 / 3.14159265;
	o_fdf->coef_x = 1;
	o_fdf->zoom = 5;
	o_fdf->coef_y = 3;
	o_fdf->coef_z = 1;
	o_fdf->margin_top = 100 * i;
	o_fdf->margin_lef = 100 * i;
	return (*o_fdf);
}

static void		add_map(t_fdf *o_fdf, void *mlx, void *win, char *str)
{
	t_fdf *tmp;
	t_fdf *tmp2;

	tmp2 = o_fdf;
	while (tmp2->next != o_fdf)
		tmp2 = tmp2->next;
	tmp = malloc(sizeof(t_fdf));
	fdf_constructor(tmp, 2);
	tmp->color = 0x22AA88;
	tmp->color_blue = 0xA0;
	tmp->color_red = 0xa000;
	tmp->color_green = 0xa00000;
	tmp->map = NULL;
	tmp->map = parse_file(str, o_fdf->map);
	tmp->mlx = mlx;
	tmp->win = win;
	tmp->next = o_fdf;
	tmp2->next = tmp;
}

int	main(int ac, char **av)
{
	t_fdf	*o_fdf;
	int i;
	void *mlx;
	void *win;

	i = 1;
	mlx = mlx_init();
	win = mlx_new_window(mlx, FDF_SCREEN_X, FDF_SCREEN_Y, "FDF");
	if (ac < 2)
		return (0);
	o_fdf = malloc(sizeof(t_fdf));
	fdf_constructor(o_fdf, i);
	o_fdf->map = NULL;
	o_fdf->map = parse_file(av[1], o_fdf->map);
	o_fdf->mlx = mlx;
	o_fdf->win = win;
	o_fdf->color = 0xFFFFFF;
	o_fdf->color_blue = 0xFF;
	o_fdf->color_red = 0xFF00;
	o_fdf->color_green = 0xF00000;
	o_fdf->next = o_fdf;
	draw_map(o_fdf);
	i++;
	while (av[i])
		add_map(o_fdf, mlx, win, av[i++]);
	draw_all_map(o_fdf);


	t_controlleur	controle;
	controle.o_fdf = o_fdf;
	controle.win = win;
	controle.mlx = mlx;
	mlx_key_hook(o_fdf->win, deal_key, &controle);
	mlx_loop(controle.mlx);
	return (0);
}
