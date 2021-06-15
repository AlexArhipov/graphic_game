/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:06:45 by avivien           #+#    #+#             */
/*   Updated: 2020/12/24 23:06:47 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	monstr_look1_1(t_all *mall, t_ray *ray, double lens)
{
	ray->raydirx = -(ray->mapx - X) / lens;
	ray->raydiry = -(ray->mapy - Y) / lens;
	if (ray->raydiry == 0)
		ray->deltadistx = 0;
	else
	{
		if (ray->raydirx == 0)
			ray->deltadistx = 1;
		else
			ray->deltadistx = fabs(1 / ray->raydirx);
	}
	if (ray->raydirx == 0)
		ray->deltadisty = 0;
	else
	{
		if (ray->raydiry == 0)
			ray->deltadisty = 1;
		else
			ray->deltadisty = fabs(1 / ray->raydiry);
	}
	ray->hit = 0;
}

static void	monstr_look1(t_all *mall, int c, t_ray *ray, double lens)
{
	monstr_look1_1(mall, ray, lens);
	if (ray->raydirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = ((mall->smap[c].y) - ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - (mall->smap[c].y))
		* ray->deltadistx;
	}
	if (ray->raydiry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = ((mall->smap[c].x) - ray->mapy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1.0 -
		(mall->smap[c].x)) * ray->deltadisty;
	}
}

static void	monstr_look2(t_ray *ray)
{
	if (ray->sidedistx < ray->sidedisty)
	{
		ray->sidedistx += ray->deltadistx;
		ray->mapx += ray->stepx;
		ray->side = 0;
	}
	else
	{
		ray->sidedisty += ray->deltadisty;
		ray->mapy += ray->stepy;
		ray->side = 1;
	}
}

void		monstr_look(t_all *mall, int c)
{
	t_ray	ray;
	double	lens;

	ray.mapx = floor(mall->smap[c].y);
	ray.mapy = floor(mall->smap[c].x);
	lens = sqrt(pow(ray.mapx - X, 2) + pow(ray.mapy - Y, 2));
	monstr_look1(mall, c, &ray, lens);
	while (ray.hit == 0)
	{
		monstr_look2(&ray);
		if ((ray.mapx == (int)X) && (ray.mapy == (int)Y))
		{
			if (mall->atakmod == 1 || mall->fails == 1
			|| mall->smap[c].mon.start == 0)
			{
				mall->smap[c].mon.ray.raydirx = ray.raydirx;
				mall->smap[c].mon.ray.raydiry = ray.raydiry;
			}
			mall->smap[c].mon.start = 1;
			break ;
		}
		(mall->map[(int)ray.mapy][(int)ray.mapx] == '1') ? ray.hit = 1 : 0;
	}
}
