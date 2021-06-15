/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monstr2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:40:16 by avivien           #+#    #+#             */
/*   Updated: 2020/12/24 23:40:24 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	monstr_move1(t_all *mall, int i)
{
	if (mall->smap[i].sp != 'R')
	{
		mall->map[(int)mall->smap[i].x][(int)mall->smap[i].y] = '0';
		mall->smap[i].x += SM * SDY;
		mall->smap[i].y += SM * SDX;
		mall->map[(int)mall->smap[i].x][(int)mall->smap[i].y] = 'M';
	}
}

static void	monstr_else(t_all *mall, int i)
{
	SDX = cos(acos(SDX) / M_PI * 33);
	SDY = sin(acos(SDY) / M_PI * 33);
}

void		monstr_move(t_all *mall, int i)
{
	if (mall->smap[i].mon.start != 0)
	{
		if (mall->smap[i].dist <= 75 && mall->cat.lookmonstr == 0)
			wlookmonstr(mall);
		if ((mall->map[(int)(SIX + SDY * SM +
		0.5)][(int)(SIY + SDX * SM + 0.5)] != '1') &&
			(mall->map[(int)(SIX + SDY * SM +
			0.5)][(int)(SIY + SDX * SM - 0.5)] != '1') &&
			(mall->map[(int)(SIX + SDY * SM -
			0.5)][(int)(SIY + SDX * SM + 0.5)] != '1') &&
			(mall->map[(int)(SIX + SDY * SM -
			0.5)][(int)(SIY + SDX * SM - 0.5)] != '1') &&
			(mall->map[(int)(SIX + SDY * SM +
			0.5)][(int)(SIY + SDX * SM + 2.5)] != 'M') &&
			(mall->map[(int)(SIX + SDY * SM +
			0.5)][(int)(SIY + SDX * SM - 2.5)] != 'M') &&
			(mall->map[(int)(SIX + SDY * SM -
			0.5)][(int)(SIY + SDX * SM + 2.5)] != 'M') &&
			(mall->map[(int)(SIX + SDY * SM -
			0.5)][(int)(SIY + SDX * SM - 2.5)] != 'M') &&
			(mall->smap[i].dist >= 1.5))
			monstr_move1(mall, i);
		else
			monstr_else(mall, i);
	}
}
