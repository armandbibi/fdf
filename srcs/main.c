/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 20:35:35 by abiestro          #+#    #+#             */
/*   Updated: 2018/06/24 18:17:24 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			draw_all_map(t_fdf *m)
{
	t_fdf	*s;
	int		a;
	int		c;

	s = m;
	m->img = mlx_new_image(m->mlx, FDF_SCREEN_Y, FDF_SCREEN_X);
	m->img_str = mlx_get_data_addr(m->img, &a, &m->img_len, &c);
	draw_map(m);
	while (s->next != m)
	{
		s = s->next;
		s->img = m->img;
		s->img_str = m->img_str;
		draw_map(s);
	}
	mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
	add_information(m);
}

t_fdf			fdf_constructor(t_fdf *o_fdf, int i)
{
	o_fdf->id = i;
	o_fdf->ang_x = 0 / 3.14159265;
	o_fdf->ang_y = 0 / 3.14159265;
	o_fdf->ang_z = 0 / 3.14159265;
	o_fdf->coef_x = 1;
	o_fdf->zoom = 1;
	o_fdf->coef_y = 1;
	o_fdf->coef_z = 1;
	o_fdf->margin_top = 100 * i;
	o_fdf->margin_lef = 100 * i;
	return (*o_fdf);
}

void			add_map(t_fdf *o_fdf, void *mlx, void *win, char *str)
{
	t_fdf *tmp;
	t_fdf *tmp2;

	tmp2 = o_fdf;
	while (tmp2->next != o_fdf)
		tmp2 = tmp2->next;
	tmp = malloc(sizeof(t_fdf));
	fdf_constructor(tmp, 2);
	tmp->mlx = mlx;
	tmp->win = win;
	tmp->map = NULL;
	tmp->map = parse_file(str, o_fdf->map);
	tmp->color = 0xFF;
	tmp->color_blue = 0x0;
	tmp->color_red = 0x0;
	tmp->color_green = 0xff;
	tmp->next = o_fdf;
	tmp2->next = tmp;
}

static t_fdf	*new_fdf(t_fdf *o_fdf, void *mlx, void *win, char *str)
{
	o_fdf = malloc(sizeof(t_fdf));
	fdf_constructor(o_fdf, 1);
	o_fdf->mlx = mlx;
	o_fdf->win = win;
	o_fdf->map = NULL;
	o_fdf->map = parse_file(str, o_fdf->map);
	o_fdf->color = 0xFF;
	o_fdf->color_blue = 0xFF;
	o_fdf->color_red = 0xFF;
	o_fdf->color_green = 0xFF;
	o_fdf->next = o_fdf;
	return (o_fdf);
}

int				main(int ac, char **av)
{
	t_fdf			*o_fdf;
	int				i;
	void			*mlx;
	void			*win;
	t_controlleur	controle;

	i = 2;
	mlx = mlx_init();
	win = mlx_new_window(mlx, FDF_SCREEN_X, FDF_SCREEN_Y, "FDF");
	if (ac < 2)
		return (0);
	o_fdf = 0;
	o_fdf = new_fdf(o_fdf, mlx, win, av[1]);
	while (av[i])
		add_map(o_fdf, mlx, win, av[i++]);
	draw_all_map(o_fdf);
	controle.o_fdf = o_fdf;
	controle.win = win;
	controle.mlx = mlx;
	mlx_key_hook(o_fdf->win, deal_key, &controle);
	mlx_loop(controle.mlx);
	return (0);
}
