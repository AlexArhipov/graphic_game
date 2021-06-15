/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 20:58:29 by avivien           #+#    #+#             */
/*   Updated: 2020/12/24 21:03:29 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void		cas_t2(t_vtext *text, t_all *mall, int i)
{
	if (((SDX < 0 && DIRX > 0) || (SDX > 0 && DIRX < 0)) &&
		((SDY < 0 && DIRY > 0) || (SDY > 0 && DIRY < 0)))
	{
		if (mall->smap[i].mon.tshag >= 0 && mall->smap[i].mon.tshag < 5)
		{
			put_t(text, &mall->text.mm1);
			mall->smap[i].mon.tshag++;
		}
		if (mall->smap[i].mon.tshag >= 5 && mall->smap[i].mon.tshag < 10)
		{
			put_t(text, &mall->text.m0);
			mall->smap[i].mon.tshag++;
		}
		if (mall->smap[i].mon.tshag >= 10)
		{
			put_t(text, &mall->text.mp1);
			mall->smap[i].mon.tshag++;
			if (mall->smap[i].mon.tshag > 15)
				mall->smap[i].mon.tshag = 0;
		}
	}
}

static void		cas_t3(t_vtext *text, t_all *mall, int i)
{
	if (((SDX <= 0 && DIRX >= 0) && (SDY >= 0 && DIRY >= 0)) ||
		((SDX >= 0 && DIRX >= 0) && (SDY >= 0 && DIRY <= 0)) ||
		((SDX >= 0 && DIRX <= 0) && (SDY <= 0 && DIRY <= 0)) ||
		((SDX <= 0 && DIRX <= 0) && (SDY <= 0 && DIRY >= 0)))
	{
		if (mall->smap[i].mon.tshag >= 0 && mall->smap[i].mon.tshag < 5)
		{
			put_t(text, &mall->text.mrm1);
			mall->smap[i].mon.tshag++;
		}
		if (mall->smap[i].mon.tshag >= 5 && mall->smap[i].mon.tshag < 10)
		{
			put_t(text, &mall->text.mr0);
			mall->smap[i].mon.tshag++;
		}
		if (mall->smap[i].mon.tshag >= 10)
		{
			put_t(text, &mall->text.mrp1);
			mall->smap[i].mon.tshag++;
			if (mall->smap[i].mon.tshag > 15)
				mall->smap[i].mon.tshag = 0;
		}
	}
}

static void		cas_t4(t_vtext *text, t_all *mall, int i)
{
	if (((SDX > 0 && DIRX < 0) && (SDY > 0 && DIRY > 0)) ||
		((SDX > 0 && DIRX > 0) && (SDY < 0 && DIRY > 0)) ||
		((SDX < 0 && DIRX > 0) && (SDY < 0 && DIRY < 0)) ||
		((SDX < 0 && DIRX < 0) && (SDY > 0 && DIRY < 0)))
	{
		if (mall->smap[i].mon.tshag >= 0 && mall->smap[i].mon.tshag < 5)
		{
			put_t(text, &mall->text.mlm1);
			mall->smap[i].mon.tshag++;
		}
		if (mall->smap[i].mon.tshag >= 5 && mall->smap[i].mon.tshag < 10)
		{
			put_t(text, &mall->text.ml0);
			mall->smap[i].mon.tshag++;
		}
		if (mall->smap[i].mon.tshag >= 10)
		{
			put_t(text, &mall->text.mlp1);
			mall->smap[i].mon.tshag++;
			if (mall->smap[i].mon.tshag > 15)
				mall->smap[i].mon.tshag = 0;
		}
	}
}

void			cas_t(char c, t_vtext *text, t_all *mall, int i)
{
	if (c == 'M' || c == 'R')
	{
		if (mall->smap[i].sp == 'R')
		{
			put_t(text, &mall->text.mj);
			return ;
		}
		if (cas_t7(text, mall, i))
			return ;
		cas_t2(text, mall, i);
		cas_t5(text, mall, i);
		cas_t4(text, mall, i);
		cas_t3(text, mall, i);
	}
	cas_t6(c, text, mall);
}
