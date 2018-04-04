/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquint <aquint@42.us.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 12:33:50 by aquint            #+#    #+#             */
/*   Updated: 2017/11/15 16:01:33 by aquint           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int				main(int argc, char **argv)
{
	t_sketch	*shp;
	int			err;

	shp = NULL;
	if (argc == 2)
	{
		if (!(shp = (t_sketch*)ft_memalloc(sizeof(t_sketch))))
			err = -3;
		else
			err = set_window(shp, argv[1]);
		if (err == 0)
		{
			draw_fractal(shp);
			options(shp);
			mlx_hook(shp->win, 6, 0, mov_win, shp);
			mlx_mouse_hook(shp->win, m_win, shp);
			mlx_hook(shp->win, 2, 3, x_win, shp);
			mlx_loop(shp->mlx);
		}
	}
	else
		err = 1;
	if (err != 0)
		print_error(err);
	return (0);
}
