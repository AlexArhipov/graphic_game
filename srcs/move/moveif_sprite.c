/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveif_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:51:55 by avivien           #+#    #+#             */
/*   Updated: 2020/12/24 23:51:56 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		move_sp1(t_all *mall, int i)
{
	if (mall->map[(int)(Y)][(int)X] == 'P')
	{
		i = -1;
		while (++i < mall->cas)
		{
			if ((mall->smap[i].x == (int)(Y)) && (mall->smap[i].y == (int)(X)))
				mall->smap[i].sp = '0';
		}
		mall->plr.hend = 1;
		wpodbor(mall);
		mall->map[(int)(Y)][(int)X] = '0';
	}
	if (mall->map[(int)(Y)][(int)X] == 'K' && mall->plr.hend)
	{
		i = -1;
		while (++i < mall->cas)
			if ((mall->smap[i].x == (int)(Y)) && (mall->smap[i].y == (int)(X)))
				mall->smap[i].sp = '0';
		wkey(mall);
		mall->plr.key = 1;
		mall->atakmod = 1;
		mall->guikey = 0;
		mall->map[(int)(Y)][(int)X] = '0';
	}
}

void		move_sp2(t_all *mall, int i)
{
	if (mall->map[(int)(Y)][(int)X] == 'Q')
	{
		system("killall afplay");
		exit(0);
	}
	if (mall->map[(int)(Y)][(int)(X)] == 'M')
	{
		i = -1;
		while (++i < mall->cas)
		{
			if ((mall->smap[i].x == (int)(Y)) &&
			(mall->smap[i].y == (int)(X)) && mall->smap[i].sp != 'R')
				mall->smap[i].sp = '0';
		}
		mall->map[(int)(Y)][(int)(X)] = '0';
	}
}

void		rots1(t_all *mall)
{
	double olddirx;
	double oldolanex;

	if (mall->plr.mrot[0] != 1)
	{
		olddirx = mall->plr.dirx;
		mall->plr.dirx = mall->plr.dirx * cos(-MSR[0])
		- mall->plr.diry * sin(-MSR[0]);
		mall->plr.diry = olddirx * sin(-MSR[0]) + mall->plr.diry * cos(-MSR[0]);
		oldolanex = PLANX;
		PLANX = PLANX * cos(-MSR[0]) - PLANY * sin(-MSR[0]);
		PLANY = oldolanex * sin(-MSR[0]) + PLANY * cos(-MSR[0]);
	}
	if (mall->plr.mrot[1] != 1)
	{
		olddirx = mall->plr.dirx;
		mall->plr.dirx = mall->plr.dirx * cos(MSR[1]) -
		mall->plr.diry * sin(MSR[1]);
		mall->plr.diry = olddirx * sin(MSR[1]) + mall->plr.diry * cos(MSR[1]);
		oldolanex = PLANX;
		PLANX = PLANX * cos(MSR[1]) - PLANY * sin(MSR[1]);
		PLANY = oldolanex * sin(MSR[1]) + PLANY * cos(MSR[1]);
	}
}

void		rots2(t_all *mall)
{
	double olddirx;
	double oldolanex;

	if (mall->plr.krot[0] == 1)
	{
		olddirx = mall->plr.dirx;
		mall->plr.dirx = mall->plr.dirx * cos(-KSR[0]) -
		mall->plr.diry * sin(-KSR[0]);
		mall->plr.diry = olddirx * sin(-KSR[0]) + mall->plr.diry * cos(-KSR[0]);
		oldolanex = PLANX;
		PLANX = PLANX * cos(-KSR[0]) - PLANY * sin(-KSR[0]);
		PLANY = oldolanex * sin(-KSR[0]) + PLANY * cos(-KSR[0]);
	}
	if (mall->plr.krot[1] == 1)
	{
		olddirx = mall->plr.dirx;
		mall->plr.dirx = mall->plr.dirx * cos(KSR[1]) -
		mall->plr.diry * sin(KSR[1]);
		mall->plr.diry = olddirx * sin(KSR[1]) + mall->plr.diry * cos(KSR[1]);
		oldolanex = PLANX;
		PLANX = PLANX * cos(KSR[1]) - PLANY * sin(KSR[1]);
		PLANY = oldolanex * sin(KSR[1]) + PLANY * cos(KSR[1]);
	}
}

void		movew(t_all *mall, int i)
{
	if (mall->plr.mov[0] == 1)
	{
		if (mall->map[(int)(Y)][(int)(X + mall->plr.dirx * SP)] == '3')
		{
			if (mall->map[(int)(Y)][(int)(X + PLANX * SP) + 3] != '1')
			{
				mall->map[(int)(Y)][(int)(X + PLANX * SP) + 1] = '0';
				i = -1;
				while (++i < mall->cas)
				{
					if (SIX == (int)(Y) && SIY == (int)(X + DIRX * SP))
					{
						mall->smap[i].y = (int)(X + mall->plr.dirx * SP) + 1;
						mall->find++;
						(mall->find == 2) ? mall->map[19][119] = '0' : 0;
					}
				}
				wmoveb(mall);
				mall->map[(int)(Y)][(int)((X + PLANX * SP)) + 2] = '3';
			}
		}
		move2pr1(mall);
		move3if1(mall);
		move3if2(mall);
	}
}
