/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 15:50:47 by abiestro          #+#    #+#             */
/*   Updated: 2018/06/20 21:37:27 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"

/*
 *** position of the "eye"
*/
#define FDF_EYE_X	500
#define FDF_EYE_Y	500
#define FDF_EYE_Z	800

/*
 *** size of the screen
*/
# define FDF_SCREEN_X 1000
# define FDF_SCREEN_Y 1000

typedef struct	s_fdf
{
	int			id;
	void 		*mlx;
	void		*win;
	double		ang_x;
	double		ang_y;
	double		ang_z;
	int			coef_x;
	int			coef_y;
	int			coef_z;
	int			margin_top;
	int			margin_lef;
	int			zoom;
	int			**map;
	int			color;
	int			color_blue;
	int			color_red;
	int			color_green;
	struct s_fdf	*next;
}				t_fdf;

typedef struct	s_controlleur
{
	t_fdf	*o_fdf;
	void	*win;
	void	*mlx;
}				t_controlleur;

void			ft_bresenham(double  *coords, void *mlx, void *window, int color);
int				**parse_file(char *file, int **map);
void			algo_line(float *coordonates, void *mlx, void *window);
void			draw_map(t_fdf *o_fdf);
t_fdf   		fdf_constructor(t_fdf *o_fdf, int i);
#endif
