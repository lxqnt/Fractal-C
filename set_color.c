/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquint <aquint@42.us.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 07:42:40 by aquint            #+#    #+#             */
/*   Updated: 2017/12/03 07:43:08 by aquint           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	flavin(t_sketch *shp)
{
	shp->clr->a = 0xfefce1;
	shp->clr->b = 0xed88a6;
	shp->clr->c = 0xb84467;
	shp->clr->d = 0xfef818;
	shp->clr->e = 0xf8e824;
	shp->clr->f = 0x4cbadc;
	shp->clr->g = 0x0076f8;
	shp->clr->h = 0x15d26d;
	shp->clr->i = 0xc95459;
	shp->clr->j = 0xc6963e;
	shp->clr->back = 0x000000;
}

void	albers(t_sketch *shp)
{
	shp->clr->a = 0xec772f;
	shp->clr->b = 0xf0a43c;
	shp->clr->c = 0xe98f21;
	shp->clr->d = 0xf1cf59;
	shp->clr->e = 0xf3df36;
	shp->clr->f = 0xad2d10;
	shp->clr->g = 0xa75106;
	shp->clr->h = 0xE7CB53;
	shp->clr->i = 0xe6ad06;
	shp->clr->j = 0xf0cd69;
	shp->clr->back = 0xf3e7e2;
}

void	rothko(t_sketch *shp)
{
	shp->clr->a = 0x376c51;
	shp->clr->b = 0x00778E;
	shp->clr->c = 0x324a5c;
	shp->clr->d = 0x324a5c;
	shp->clr->e = 0x005C42;
	shp->clr->f = 0x012D52;
	shp->clr->g = 0x1d4868;
	shp->clr->h = 0x003797;
	shp->clr->i = 0xE35E00;
	shp->clr->j = 0xE41101;
	shp->clr->back = 0x939898;
}

void	casablanca(t_sketch *shp)
{
	shp->clr->a = 0xf8f8f8;
	shp->clr->b = 0xdadada;
	shp->clr->c = 0xc2c2c2;
	shp->clr->d = 0x9b9b9b;
	shp->clr->e = 0x131313;
	shp->clr->f = 0x131313;
	shp->clr->g = 0x9b9b9b;
	shp->clr->h = 0xc2c2c2;
	shp->clr->i = 0xdadada;
	shp->clr->j = 0xf8f8f8;
	shp->clr->back = 0xD10F0F;
}

void	node_color_iter(t_sketch *shp, int nd, int i_i)
{
	if ((i_i % 5) == 1)
		shp->map[nd]->c = shp->clr->g;
	else if ((i_i % 5) == 2)
		shp->map[nd]->c = shp->clr->h;
	else if ((i_i % 5) == 3)
		shp->map[nd]->c = shp->clr->i;
	else if ((i_i % 5) == 4)
		shp->map[nd]->c = shp->clr->j;
	else if ((i_i % 5) == 0)
		shp->map[nd]->c = shp->clr->f;
}
