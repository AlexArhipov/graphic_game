/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baam.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:44:09 by avivien           #+#    #+#             */
/*   Updated: 2020/12/24 23:44:10 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	baaam1(t_all *mall, t_ray *ray)
{
	int c;

	c = -1;
	while (++c < mall->cas)
		if (((int)ray->mapy == (int)mall->smap[c].x)
		&& ((int)ray->mapx == (int)mall->smap[c].y))
		{
			mall->smap[c].sp = 'R';
			mall->smap[c].mon.hp -= 8;
			wranmon(mall);
			if (mall->smap[c].mon.hp <= 0)
			{
				mall->smap[c].sp = 'D';
				wdefm(mall);
				if (mall->cat.level == 1)
					mall->map[19][104] = '0';
			}
		}
}

static void	baaam2(t_all *mall, t_ray *ray)
{
	ray->hit = 0;
	if (ray->raydirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (X - ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - X) * ray->deltadistx;
	}
	if (ray->raydiry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (Y - ray->mapy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1.0 - Y) * ray->deltadisty;
	}
}

static void	baaam3(t_all *mall, t_ray *ray)
{
	ray->raydirx = mall->plr.dirx;
	ray->raydiry = mall->plr.diry;
	ray->mapx = (int)X;
	ray->mapy = (int)Y;
	if (ray->raydiry != 0)
	{
		if (ray->raydirx == 0)
			ray->deltadistx = 1;
		else
			ray->deltadistx = fabs(1 / ray->raydirx);
	}
	if (ray->raydirx != 0)
	{
		if (ray->raydiry == 0)
			ray->deltadisty = 1;
		else
			ray->deltadisty = fabs(1 / ray->raydiry);
	}
	baaam2(mall, ray);
}

void		baaam(t_all *mall)
{
	t_ray ray;

	baaam3(mall, &ray);
	while (ray.hit == 0)
	{
		if (ray.sidedistx < ray.sidedisty)
		{
			ray.sidedistx += ray.deltadistx;
			ray.mapx += ray.stepx;
			ray.side = 0;
		}
		else
		{
			ray.sidedisty += ray.deltadisty;
			ray.mapy += ray.stepy;
			ray.side = 1;
		}
		if (mall->map[(int)ray.mapy][(int)ray.mapx] == 'M')
		{
			baaam1(mall, &ray);
			break ;
		}
		(mall->map[(int)ray.mapy][(int)ray.mapx] == '1') ? ray.hit = 1 : 0;
	}
}
