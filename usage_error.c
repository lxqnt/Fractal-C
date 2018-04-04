/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquint <aquint@42.us.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 12:33:50 by aquint            #+#    #+#             */
/*   Updated: 2017/11/15 16:01:33 by aquint           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void			print_error(int err)
{
	if (err == 1)
		ft_putstr("error: only one argument accepted\n");
	if (err == -2)
		ft_putstr("error: mlx window setup\n");
	if (err == -3)
		ft_putstr("error: malloc\n");
	if (err == -4)
		ft_putstr("error: illegal option\n");
	ft_putstr("usage: ./fractol ");
	ft_putstr("[-julia -mandelbrot -sierpinski -rabbit -ships]\n");
}

void			options(t_sketch *shp)
{
	ft_putstr("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	ft_putstr("*              KEY              *\n");
	ft_putstr("* n = next fractal              *\n");
	ft_putstr("* option = status               *\n");
	ft_putstr("* -/+ or mouse scroll = zoom    *\n");
	ft_putstr("* mouse click = location zoom   *\n");
	ft_putstr("* i = infinite zoom             *\n");
	ft_putstr("* space bar = reset             *\n");
	ft_putstr("* m = more iterations           *\n");
	ft_putstr("* l = less iteration            *\n");
	ft_putstr("* arrows = translation          *\n");
	ft_putstr("* color options                 *\n");
	ft_putstr("*   * a = albers                *\n");
	ft_putstr("*   * r = rothko                *\n");
	ft_putstr("*   * f = flavin                *\n");
	ft_putstr("*   * c = casablanca            *\n");
	ft_putstr("* command = guide               *\n");
	ft_putstr("* esc/q = quit                  *\n");
	if (shp->f_map == 1)
		ft_putstr("* mouse position = c value      *\n");
	ft_putstr("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
}

static void		print_float_const(float n)
{
	int n1;

	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	ft_putstr(ft_itoa(n));
	n1 = (int)(n * 250) % 100;
	ft_putchar('.');
	ft_putstr(ft_itoa(n1));
}

void			status(t_sketch *shp)
{
	ft_putstr("\n----------------------------------\n");
	ft_putstr("               Status               \n");
	ft_putstr(" Zoom = ");
	ft_putstr(ft_itoa(shp->scale / 10));
	ft_putstr("\n Fractal = ");
	if (shp->f_map == 1)
		ft_putstr("Julia Set");
	if (shp->f_map == 2)
		ft_putstr("Mandelbrot Set");
	if (shp->f_map == 3)
		ft_putstr("Sierpinski Carpet");
	if (shp->f_map == 4)
		ft_putstr("Douady's Rabbit");
	if (shp->f_map == 5)
		ft_putstr("Burning Ships");
	ft_putstr("\n Iterations = ");
	ft_putstr(ft_itoa(shp->iter_m));
	if (shp->f_map == 1)
	{
		ft_putstr("\n X Constant Value = ");
		print_float_const(shp->c_x);
		ft_putstr("\n Y Constant Value = ");
		print_float_const(shp->c_y);
	}
	ft_putstr("\n----------------------------------\n");
}
