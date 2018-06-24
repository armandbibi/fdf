/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 15:50:47 by abiestro          #+#    #+#             */
/*   Updated: 2018/06/24 23:07:02 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"

/*
 *** size of the screen
*/
# define FDF_SCREEN_X 1000
# define FDF_SCREEN_Y 1000

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	void			*img;
	int				**map;
	char			*img_str;
	int				img_len;
	int				img_bpp;
	struct s_fdf	*next;
	double			ang_x;
	double			ang_y;
	double			ang_z;
	int				id;
	int				coef_x;
	int				coef_y;
	int				coef_z;
	int				margin_top;
	int				margin_lef;
	int				zoom;
	int				color;
	int				color_blue;
	int				color_red;
	int				color_green;
	int				map_size_x;
	int				map_size_y;
}					t_fdf;

typedef struct		s_controlleur
{
	t_fdf			*o_fdf;
	void			*win;
	void			*mlx;
}					t_controlleur;

void				ft_bresenham(double *coords, t_fdf *o_fdf);
int					**parse_file(char *file, int **map);
void				algo_line(float *coordonates, void *mlx, void *window);
void				draw_map(t_fdf *o_fdf);
t_fdf				fdf_constructor(t_fdf *o_fdf, int i);
int					deal_key(int key, t_controlleur *controle);
void				add_map(t_fdf *o_fdf, void *mlx, void *win, char *str);
void				draw_all_map(t_fdf *m);
void				add_information(t_fdf *m);
#endif
