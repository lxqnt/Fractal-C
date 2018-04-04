/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquint <aquint@42.us.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 12:33:35 by aquint            #+#    #+#             */
/*   Updated: 2017/11/15 15:56:21 by aquint           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void			free_node(t_sketch *shp)
{
	int		nd;

	nd = 0;
	if (shp != NULL)
	{
		if (shp->map != NULL)
		{
			while (nd < shp->maxnd)
			{
				if (shp->map[nd] != NULL)
					free(shp->map[nd++]);
				else
					nd = shp->maxnd;
			}
		}
		free(shp->map);
		if (shp->clr != NULL)
			free(shp->clr);
		free(shp);
	}
	shp = NULL;
}

void			node_filler(t_sketch *shp, int nd)
{
	t_node		*node;

	node = shp->map[nd];
	node->xcor = shp->ox;
	node->ycor = shp->oy;
	node->x = shp->ox;
	node->y = shp->oy;
}

int				set_nodes(t_sketch *shp, int size)
{
	int		nd;

	if (!(shp->map = (t_node**)ft_memalloc(sizeof(t_node*) * (size + 1))))
		return (-3);
	nd = 0;
	shp->oy = shp->winsz / -2;
	while (shp->oy < (shp->winsz / 2))
	{
		shp->ox = shp->winsz / -2;
		while (shp->ox < (shp->winsz / 2))
		{
			if (!(shp->map[nd] = (t_node*)ft_memalloc(sizeof(t_node))))
				return (-3);
			node_filler(shp, nd++);
			shp->ox++;
		}
		shp->oy++;
	}
	return (0);
}

int				read_input(char *str, t_sketch *shp)
{
	if (ft_strcmp(str, "-julia") == 0)
		shp->f_map = 1;
	else if (ft_strcmp(str, "-mandelbrot") == 0)
		shp->f_map = 2;
	else if (ft_strcmp(str, "-sierpinski") == 0)
		shp->f_map = 3;
	else if (ft_strcmp(str, "-rabbit") == 0)
		shp->f_map = 4;
	else if (ft_strcmp(str, "-ships") == 0)
		shp->f_map = 5;
	else
		return (-4);
	return (0);
}

int				set_window(t_sketch *shp, char *str)
{
	int err;

	if ((err = read_input(str, shp)) != 0)
		return (err);
	shp->winsz = 1000;
	shp->iter_m = 50;
	shp->scale = 200;
	if (!(shp->clr = (t_color*)malloc(sizeof(t_color))))
		return (-3);
	albers(shp);
	shp->maxnd = shp->winsz * shp->winsz;
	if ((err = set_nodes(shp, shp->maxnd)) != 0)
		return (err);
	if (!(shp->mlx = mlx_init()))
		return (-2);
	if (!(shp->win = mlx_new_window(shp->mlx, 1000, 1000, "Fractal")))
		return (-2);
	shp->ox = 0;
	shp->oy = 0;
	return (0);
}
