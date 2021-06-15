/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monstr1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 22:50:29 by avivien           #+#    #+#             */
/*   Updated: 2020/12/24 22:50:31 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	armagedon(t_all *mall)
{
	int i;

	i = -1;
	while (++i < mall->cas)
		if (mall->smap[i].sp == 'O')
			mall->smap[i].sp = 'M';
	mall->fails = 1;
}

void	shot_gun(t_all *mall)
{
	int i;

	(mall->fails != 0) ? armagedon(mall) : 0;
	if (mall->plr.bam == 1)
	{
		weapenl(mall, &mall->text.plf);
		(mall->tbam != 8) ? weapenr(mall, &mall->text.pr) : 0;
		mall->tbam++;
		if (mall->tbam == 9)
		{
			wbam(mall);
			weapenr(mall, &mall->text.prf);
			mall->tbam = 0;
			mall->plr.bam = 0;
			i = -1;
			while (++i < mall->cas)
				(mall->smap[i].sp == 'R') ? mall->smap[i].sp = 'M' : 0;
		}
	}
	else
	{
		weapenl(mall, &mall->text.pl);
		weapenr(mall, &mall->text.pr);
	}
}

void	findsm(t_all *mall)
{
	int c;

	(mall->plr.bam == 1 && mall->tbam == 0) ? baaam(mall) : 0;
	mlx_mouse_hide();
	c = -1;
	while (++c < mall->cas)
	{
		if (mall->smap[c].sp == 'M' || mall->smap[c].sp == 'R')
		{
			monstr_look(mall, c);
			monstr_move(mall, c);
		}
	}
	finish_draw(mall);
}

void	initmonstr(t_all *mall)
{
	int j;
	int m;
	int i;

	m = -1;
	j = 0;
	while (mall->map[(1 + (++j))])
	{
		i = 0;
		while (mall->map[j][(1 + (++i))])
			if (MM == '2' || MM == '3' || MM == '6' || MM == '7' || MM == 'O' ||
			MM == 'K' || MM == 'P' || MM == 'M' || MM == 'Q' || MM == 'R'
			|| MM == 'D')
			{
				m++;
				mall->smap[m].x = j;
				mall->smap[m].y = i;
				mall->smap[m].sp = mall->map[j][i];
				mall->smap[m].mon.hp = 10;
				mall->smap[m].mon.start = 0;
				mall->smap[m].mon.tatak = 0;
				mall->smap[m].mon.tshag = 0;
			}
	}
}
