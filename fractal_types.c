/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_types.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquint <aquint@42.us.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 12:33:50 by aquint            #+#    #+#             */
/*   Updated: 2017/11/22 16:14:55 by aquint           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		sierpinski(long x, long y)
{
	int c;

	c = 0;
	x = ft_abs(x);
	y = ft_abs(y);
	while (x >= 1 || y >= 1)
	{
		if ((x % 3) == 1 && (y % 3) == 1)
			return (5 + c);
		x /= 3;
		y /= 3;
		c++;
	}
	return (1);
}

void	mandelbrot(t_sketch *shp, double x, double y, int nd)
{
	double xnew;
	double x1;
	double y1;

	x1 = x;
	y1 = y;
	while ((x * x) + (y * y) <= 4 && shp->map[nd]->i < shp->iter_m)
	{
		xnew = (x * x) - (y * y) + ((shp->map[nd]->x + shp->ox) / shp->scale);
		y = 2 * x * y + ((shp->map[nd]->y + shp->oy) / shp->scale);
		x = xnew;
		shp->map[nd]->i++;
	}
}

void	julia(t_sketch *shp, double x, double y, int nd)
{
	double xnew;

	while ((x * x) + (y * y) <= 4 && shp->map[nd]->i < shp->iter_m)
	{
		xnew = (x * x) - (y * y) + shp->c_x;
		y = 2 * x * y + shp->c_y;
		x = xnew;
		shp->map[nd]->i++;
	}
}

void	bunny(t_sketch *shp, double x, double y, int nd)
{
	double xnew;

	while ((x * x) + (y * y) <= 4 && shp->map[nd]->i < shp->iter_m)
	{
		xnew = (x * x) - (y * y) - 0.123;
		y = 2 * x * y + (0.745);
		x = xnew;
		shp->map[nd]->i++;
	}
}

void	burning_ships(t_sketch *shp, double x, double y, int nd)
{
	double xnew;
	double x1;
	double y1;

	x1 = x;
	y1 = y;
	while ((x * x) + (y * y) <= 4 && shp->map[nd]->i < shp->iter_m)
	{
		xnew = (x * x) - (y * y) + ((shp->map[nd]->x + shp->ox) / shp->scale);
		y = fabs(2 * x * y + ((shp->map[nd]->y + shp->oy) / shp->scale));
		x = fabs(xnew);
		shp->map[nd]->i++;
	}
}
