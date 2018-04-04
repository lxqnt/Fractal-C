/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquint <aquint@42.us.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 12:33:50 by aquint            #+#    #+#             */
/*   Updated: 2017/11/15 15:50:26 by aquint           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	scale(t_sketch *shp, int n)
{
	float scale;

	scale = 1.5;
	if (n < 0)
	{
		shp->scale /= scale;
		shp->ox /= scale;
		shp->oy /= scale;
	}
	else
	{
		shp->scale *= scale;
		shp->ox *= scale;
		shp->oy *= scale;
	}
	if (shp->scale > (2147483647) && shp->s_c == 0)
	{
		shp->scale /= scale;
		shp->ox /= scale;
		shp->oy /= scale;
	}
}

int		mov_win(int x, int y, t_sketch *shp)
{
	if (shp->f_map == 1)
	{
		if ((x >= 0 && x <= 1000) && (y >= 0 && y <= 1000))
		{
			shp->c_x = x - 500;
			shp->c_y = y - 500;
			shp->c_x /= 250;
			shp->c_y /= 250;
			mlx_clear_window(shp->mlx, shp->win);
			draw_fractal(shp);
		}
	}
	return (0);
}

int		m_win(int button, int x, int y, t_sketch *shp)
{
	if (button == 1)
	{
		shp->ox += ((x - 500));
		shp->oy += ((y - 500));
	}
	if (button == 4 || button == 5)
	{
		if (button == 4)
			scale(shp, 1);
		else if (button == 5)
			scale(shp, -1);
		mlx_clear_window(shp->mlx, shp->win);
		draw_fractal(shp);
	}
	return (0);
}
