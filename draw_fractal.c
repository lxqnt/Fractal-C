/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquint <aquint@42.us.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 12:33:50 by aquint            #+#    #+#             */
/*   Updated: 2017/11/22 16:14:55 by aquint           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void			node_color(t_sketch *shp, int nd)
{
	int i_i;

	i_i = (int)shp->map[nd]->i;
	if (i_i == 0)
		shp->map[nd]->c = shp->clr->back;
	else if ((i_i > 20 && i_i < 51) || (i_i > 100 && i_i < 120))
		node_color_iter(shp, nd, i_i);
	else
	{
		if ((i_i % 5) == 1)
			shp->map[nd]->c = shp->clr->b;
		else if ((i_i % 5) == 2)
			shp->map[nd]->c = shp->clr->c;
		else if ((i_i % 5) == 3)
			shp->map[nd]->c = shp->clr->d;
		else if ((i_i % 5) == 4)
			shp->map[nd]->c = shp->clr->e;
		else if ((i_i % 5) == 0)
			shp->map[nd]->c = shp->clr->a;
	}
}

void			fractal_types(t_sketch *shp, int nd)
{
	double x;
	double y;

	x = ((shp->map[nd]->x + shp->ox) / shp->scale);
	y = ((shp->map[nd]->y + shp->oy) / shp->scale);
	shp->map[nd]->i = 0;
	if (shp->f_map == 3)
		shp->map[nd]->i = sierpinski(x + 500, y + 500);
	else if (shp->f_map == 2)
		mandelbrot(shp, x, y, nd);
	else if (shp->f_map == 1)
		julia(shp, x, y, nd);
	else if (shp->f_map == 4)
		bunny(shp, x, y, nd);
	else if (shp->f_map == 5)
		burning_ships(shp, x, y, nd);
}

void			color_set(t_sketch *shp, int nd, int color)
{
	unsigned int clr;

	if (color != 0)
		shp->map[nd]->c = color;
	clr = mlx_get_color_value(shp->mlx, shp->map[nd]->c);
	shp->img_loc[nd] = clr;
}

unsigned int	*img_set(t_sketch *shp, int size)
{
	int bpp;
	int en;

	bpp = 0;
	en = 1;
	shp->img = mlx_new_image(shp->mlx, size, size);
	shp->img_loc = (unsigned int*)mlx_get_data_addr(shp->img, &bpp, &size, &en);
	return (shp->img_loc);
}

void			draw_fractal(t_sketch *shp)
{
	int nd;
	int size;

	size = 1000;
	nd = 0;
	img_set(shp, size);
	while (nd < shp->maxnd)
	{
		fractal_types(shp, nd);
		node_color(shp, nd);
		color_set(shp, nd++, 0);
	}
	mlx_put_image_to_window(shp->mlx, shp->win, shp->img, 0, 0);
	mlx_destroy_image(shp->mlx, shp->img);
	shp->img_loc = NULL;
}
