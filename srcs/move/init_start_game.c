/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_start_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:45:23 by avivien           #+#    #+#             */
/*   Updated: 2020/12/24 23:45:24 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	init_start_game(t_all *mall)
{
	mall->plr.ammo = 16;
	mall->plr.bam = 0;
	mall->plr.hp = 150;
	mall->plr.hend = 0;
	mall->tbam = 0;
	mall->fails = 0;
	mall->tdoor = 0;
	mall->plr.wshag = 0;
	mall->plr.isk = 0;
	mall->sound = 0;
	mall->cat.door = 0;
	mall->cat.wstart = 0;
	mall->cat.grobnica = 0;
	mall->cat.level = 0;
	mall->cat.lookmonstr = 0;
	mall->atakmod = 0;
	mall->plr.key = 0;
	mall->cat.opend = 0;
	mall->cat.closed = 0;
	mall->cat.lookkey = 0;
	mall->cat.stopcat = 0;
	mall->guikey = 0;
	mall->find = 0;
	mall->cat.lokkor = 0;
	mall->cat.lokcreat = 0;
}

static void	init_start_game2(t_all *mall)
{
	mall->plr.mov[0] = 0;
	mall->plr.mov[1] = 0;
	mall->plr.mov[2] = 0;
	mall->plr.mov[3] = 0;
	mall->plr.krot[0] = 0;
	mall->plr.krot[1] = 0;
	mall->plr.mrot[0] = 0;
	mall->plr.mrot[1] = 0;
	if (mall->win.r_win[0] > 2560)
		mall->win.r_win[0] = 2560;
	if (mall->win.r_win[1] > 1440)
		mall->win.r_win[1] = 1440;
}

void		initstr(t_all *mall)
{
	mall->ray.mcam = 2;
	mall->plr.dirx = sin(mall->plr.rad);
	mall->plr.diry = cos(mall->plr.rad);
	if ((int)mall->plr.rad == (int)(M_PI / 2) ||
	(int)mall->plr.rad == (int)(3 * M_PI / 2))
		mall->plr.planex = 0;
	else if (mall->plr.rad == 0)
		mall->plr.planex = -0.66;
	else
		mall->plr.planex = 0.66;
	if ((int)mall->plr.rad == (int)M_PI || mall->plr.rad == 0)
		mall->plr.planey = 0;
	else if ((int)mall->plr.rad == (int)(M_PI / 2))
		mall->plr.planey = 0.66;
	else
		mall->plr.planey = -0.66;
	init_start_game2(mall);
	init_start_game(mall);
}
