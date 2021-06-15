/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 19:56:40 by avivien           #+#    #+#             */
/*   Updated: 2020/12/24 19:56:42 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void		draw_ray_1(t_all *mall, int x)
{
	draw_ray_start(mall, x);
	if (mall->ray.raydirx < 0)
	{
		mall->ray.stepx = -1;
		mall->ray.sidedistx = (X - mall->ray.mapx) * mall->ray.deltadistx;
	}
	else
	{
		mall->ray.stepx = 1;
		mall->ray.sidedistx = (mall->ray.mapx + 1.0 - X) * mall->ray.deltadistx;
	}
	if (mall->ray.raydiry < 0)
	{
		mall->ray.stepy = -1;
		mall->ray.sidedisty = (Y - mall->ray.mapy) * mall->ray.deltadisty;
	}
	else
	{
		mall->ray.stepy = 1;
		mall->ray.sidedisty = (mall->ray.mapy + 1.0 - Y) * mall->ray.deltadisty;
	}
}

static void		draw_ray_if1(t_all *mall)
{
	if (mall->map[mall->ray.mapy][mall->ray.mapx] == 'A')
	{
		if (mall->cat.door == 0 || mall->cat.door == 1)
			wlookdoor(mall);
	}
	if (mall->map[mall->ray.mapy][mall->ray.mapx] == 'K')
	{
		wlookkey(mall);
	}
	if (MRAY == '5' && mall->cat.lokcreat == 0)
		wcreate(mall);
	if (MRAY == 'Q' && mall->cat.lokkor == 0)
		wkorona(mall);
	if (MRAY == '1' || MRAY == '5' || MRAY == '8' || MRAY == '9' ||
	MRAY == 'F' || MRAY == 'L' || MRAY == 'B' || MRAY == 'I' ||
	MRAY == 'G' || MRAY == 'A' || MRAY == '4')
		mall->ray.hit = 1;
}

static void		draw_ray_while1(t_all *mall, int x)
{
	draw_ray_1(mall, x);
	while (mall->ray.hit == 0)
	{
		if (mall->ray.sidedistx < mall->ray.sidedisty)
		{
			mall->ray.sidedistx += mall->ray.deltadistx;
			mall->ray.mapx += mall->ray.stepx;
			mall->ray.side = 0;
		}
		else
		{
			mall->ray.sidedisty += mall->ray.deltadisty;
			mall->ray.mapy += mall->ray.stepy;
			mall->ray.side = 1;
		}
		draw_ray_if1(mall);
	}
	if (mall->ray.side == 0)
		mall->ray.sh = (mall->ray.mapx - X + (double)(1 -
		mall->ray.stepx) / 2) / mall->ray.raydirx;
	else
		mall->ray.sh = (mall->ray.mapy - Y + (double)(1 -
		mall->ray.stepy) / 2) / mall->ray.raydiry;
}

double			draw_ray(t_all *mall, int x)
{
	draw_ray_while1(mall, x);
	if (mall->map[mall->ray.mapy][mall->ray.mapx] == '5')
		draw_line(mall, &mall->text.sf1, x);
	else if (mall->map[mall->ray.mapy][mall->ray.mapx] == '8')
		draw_line(mall, &mall->text.sf2, x);
	else if (mall->map[mall->ray.mapy][mall->ray.mapx] == '9')
		draw_line(mall, &mall->text.sf3, x);
	else if (mall->map[mall->ray.mapy][mall->ray.mapx] == 'L')
	{
		draw_line(mall, &mall->text.l, x);
		wlogovo(mall);
	}
	else if (mall->map[mall->ray.mapy][mall->ray.mapx] == 'F' ||
	mall->map[mall->ray.mapy][mall->ray.mapx] == 'I')
		draw_line(mall, &mall->text.so1, x);
	else if (mall->map[mall->ray.mapy][mall->ray.mapx] == 'A')
	{
		if (mall->plr.key == 0)
			draw_line(mall, &mall->text.d1, x);
		else
			(mall->cat.opend == 0) ? opendoor(mall, x) : 0;
	}
	else
		draw_ray_if2(mall, x);
	return (mall->ray.sh);
}
