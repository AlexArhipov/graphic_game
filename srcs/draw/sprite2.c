/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 21:05:22 by avivien           #+#    #+#             */
/*   Updated: 2020/12/24 21:05:24 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	cas_t1(t_vtext *text, t_all *mall, int i)
{
	if (mall->smap[i].mon.tatak >= 15 && mall->smap[i].mon.tatak < 25)
	{
		put_t(text, &mall->text.ma2);
		mall->smap[i].mon.tatak++;
	}
	if (mall->smap[i].mon.tatak >= 25)
	{
		put_t(text, &mall->text.ma1);
		mall->smap[i].mon.tatak++;
		if (mall->smap[i].mon.tatak > 30)
		{
			mall->smap[i].mon.tatak = 0;
			mall->plr.hp -= 20;
			if (mall->plr.hp <= 0)
			{
				wdefp(mall);
				free(mall->smap);
				free(mall->dmas);
				system("killall afplay");
				exit(0);
			}
			wran(mall);
		}
	}
}

void		cas_t5(t_vtext *text, t_all *mall, int i)
{
	if (((SDX > 0 && mall->plr.dirx > 0) || (SDX < 0 && mall->plr.dirx < 0)) &&
		((SDY > 0 && mall->plr.diry > 0) || (SDY < 0 && mall->plr.diry < 0)))
	{
		if (mall->smap[i].mon.tshag >= 0 && mall->smap[i].mon.tshag < 5)
		{
			put_t(text, &mall->text.mzm1);
			mall->smap[i].mon.tshag++;
		}
		if (mall->smap[i].mon.tshag >= 5 && mall->smap[i].mon.tshag < 10)
		{
			put_t(text, &mall->text.mz0);
			mall->smap[i].mon.tshag++;
		}
		if (mall->smap[i].mon.tshag >= 10)
		{
			put_t(text, &mall->text.mzp1);
			mall->smap[i].mon.tshag++;
			if (mall->smap[i].mon.tshag > 15)
				mall->smap[i].mon.tshag = 0;
		}
	}
}

void		cas_t6(char c, t_vtext *text, t_all *mall)
{
	if (c == 'D')
		put_t(text, &mall->text.mde);
	if (c == '2')
		put_t(text, &mall->text.s);
	if (c == '3')
		put_t(text, &mall->text.s);
	if (c == 'Q')
		put_t(text, &mall->text.q);
	if (c == '6')
		put_t(text, &mall->text.p1);
	if (c == '7')
		put_t(text, &mall->text.p2);
	if (c == 'P')
		put_t(text, &mall->text.tel);
	if (c == 'K')
		put_t(text, &mall->text.key);
	if (c == 'O')
		put_t(text, &mall->text.p1);
}

int			cas_t7(t_vtext *text, t_all *mall, int i)
{
	if (mall->smap[i].dist <= 3)
	{
		if (mall->smap[i].mon.tatak >= 0 && mall->smap[i].mon.tatak < 5)
		{
			put_t(text, &mall->text.ma5);
			mall->smap[i].mon.tatak++;
			wmon(mall);
		}
		if (mall->smap[i].mon.tatak >= 5 && mall->smap[i].mon.tatak < 10)
		{
			put_t(text, &mall->text.ma4);
			mall->smap[i].mon.tatak++;
		}
		if (mall->smap[i].mon.tatak >= 10 && mall->smap[i].mon.tatak < 15)
		{
			put_t(text, &mall->text.ma3);
			mall->smap[i].mon.tatak++;
		}
		cas_t1(text, mall, i);
		return (1);
	}
	return (0);
}
