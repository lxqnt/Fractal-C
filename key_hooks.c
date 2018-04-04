/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquint <aquint@42.us.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 12:33:50 by aquint            #+#    #+#             */
/*   Updated: 2017/11/15 15:50:26 by aquint           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static int	move_zoom(int keycode, t_sketch *shp)
{
	if (keycode == 24)
		scale(shp, 1);
	else if (keycode == 27)
		scale(shp, -1);
	else if (keycode == 124)
		shp->ox -= 50;
	else if (keycode == 126)
		shp->oy += 50;
	else if (keycode == 123)
		shp->ox += 50;
	else if (keycode == 125)
		shp->oy -= 50;
	else if (keycode == 34)
		shp->s_c = 1;
	else
		return (0);
	return (1);
}

static int	reset_status(int keycode, t_sketch *shp)
{
	if (keycode == 49)
	{
		shp->scale = 200;
		shp->ox = 0;
		shp->oy = 0;
		shp->iter_m = 50;
		shp->s_c = 0;
		return (1);
	}
	else if (keycode == 260)
		options(shp);
	else if (keycode == 262)
		status(shp);
	return (0);
}

static int	colors_iter(int keycode, t_sketch *shp)
{
	if (keycode == 46)
		shp->iter_m *= 1.5;
	else if (keycode == 37)
		shp->iter_m /= 1.5;
	else if (keycode == 0)
		albers(shp);
	else if (keycode == 3)
		flavin(shp);
	else if (keycode == 15)
		rothko(shp);
	else if (keycode == 8)
		casablanca(shp);
	else
		return (0);
	if (shp->iter_m < 1)
		shp->iter_m = 1;
	if (shp->iter_m > 1000)
		shp->iter_m = 1000;
	return (1);
}

static int	next(int keycode, t_sketch *shp)
{
	if (keycode == 45)
	{
		shp->f_map += 1;
		if (shp->f_map == 6)
			shp->f_map = 1;
		shp->scale = 200;
		shp->ox = 0;
		shp->oy = 0;
		shp->iter_m = 50;
		shp->s_c = 0;
		return (1);
	}
	return (0);
}

int			x_win(int keycode, t_sketch *shp)
{
	int reset;

	reset = 0;
	reset += move_zoom(keycode, shp);
	reset += reset_status(keycode, shp);
	reset += colors_iter(keycode, shp);
	reset += next(keycode, shp);
	if (keycode == 53 || keycode == 12)
	{
		mlx_destroy_window(shp->mlx, shp->win);
		free_node(shp);
		exit(0);
	}
	if (reset >= 1)
	{
		mlx_clear_window(shp->mlx, shp->win);
		draw_fractal(shp);
	}
	return (0);
}
