/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquint <aquint@42.us.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:25:34 by aquint            #+#    #+#             */
/*   Updated: 2017/11/22 15:54:17 by aquint           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "./libft/libft.h"
# include "./minilibx/mlx.h"
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

typedef struct	s_color
{
	int a;
	int b;
	int c;
	int d;
	int e;
	int f;
	int g;
	int h;
	int i;
	int j;
	int back;
}				t_color;

typedef struct	s_node
{
	double			x;
	double			y;
	double			i;
	int				xcor;
	int				ycor;
	int				c;
}				t_node;

typedef	struct	s_sketch
{
	t_color			*clr;
	t_node			**map;
	void			*mlx;
	void			*win;
	void			*img;
	int				winsz;
	int				f_map;
	int				iter_m;
	int				maxnd;
	int				s_c;
	float			ox;
	float			oy;
	float			scale;
	float			c_x;
	float			c_y;
	unsigned int	*img_loc;
}				t_sketch;

/*
** set_color.c
*/

void			albers(t_sketch *shp);
void			flavin(t_sketch *shp);
void			rothko(t_sketch *shp);
void			casablanca(t_sketch *shp);
void			node_color_iter(t_sketch *shp, int nd, int i_i);

/*
** key_hooks.c && mouse_hooks.c
*/

void			scale(t_sketch *shp, int n);
int				x_win(int keycode, t_sketch *shp);
int				m_win(int button, int x, int y, t_sketch *shp);
int				mov_win(int x, int y, t_sketch *shp);

/*
** Usage_Error.c
*/

void			print_error(int err);
void			options(t_sketch *shp);
void			status(t_sketch *shp);

/*
** draw_fractol.c
*/

void			node_color(t_sketch *shp, int nd);
void			fractal_types(t_sketch *shp, int nd);
void			draw_fractal(t_sketch *shp);
unsigned int	*img_set(t_sketch *shp, int size);
void			color_set(t_sketch *shp, int nd, int color);

/*
** fractal_types.c
*/

void			mandelbrot(t_sketch *shp, double x, double y, int nd);
void			julia(t_sketch *shp, double x, double y, int nd);
int				sierpinski(long x, long y);
void			bunny(t_sketch *shp, double x, double y, int nd);
void			burning_ships(t_sketch *shp, double x, double y, int nd);

/*
** setup.c
*/

void			free_node(t_sketch *shp);
int				read_input(char *str, t_sketch *shp);
void			node_filler(t_sketch *shp, int nd);
int				set_nodes(t_sketch *shp, int size);
int				set_window(t_sketch *shp, char *str);

#endif
