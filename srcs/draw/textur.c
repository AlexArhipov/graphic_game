/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textur.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 21:07:05 by avivien           #+#    #+#             */
/*   Updated: 2020/12/24 21:07:08 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void		weapenl1(t_all *mall)
{
	if (mall->plr.ammo >= 16)
		drowpat2(mall, &mall->text.g8);
	else if (mall->plr.ammo >= 14)
		drowpat2(mall, &mall->text.g7);
	else if (mall->plr.ammo >= 12)
		drowpat2(mall, &mall->text.g6);
	else if (mall->plr.ammo >= 10)
		drowpat2(mall, &mall->text.g5);
	else if (mall->plr.ammo >= 8)
		drowpat2(mall, &mall->text.g4);
	else if (mall->plr.ammo >= 6)
		drowpat2(mall, &mall->text.g3);
	else if (mall->plr.ammo >= 4)
		drowpat2(mall, &mall->text.g2);
	else if (mall->plr.ammo >= 2)
		drowpat2(mall, &mall->text.g1);
}

void			weapenl(t_all *mall, t_vtext *text)
{
	int sm;

	text->dxs1 = 1.0 * 1500 / XX;
	text->dys1 = 1.0 * 1000 / YY;
	sm = XX / 2 - text->w / text->dxs1;
	text->xs1 = 0;
	while (++text->xs1 < (text->w / text->dxs1 - 1) && text->xs1 < XX - 1)
	{
		text->textx = text->xs1 * text->dxs1;
		(text->textx >= text->w) ? text->textx = text->w - 1 : 0;
		text->ys2 = 0;
		text->ys1 = YY - text->h / text->dys1;
		while (text->ys1 < YY - 1)
		{
			text->ys1++;
			text->ys2++;
			text->texty = text->ys2 * text->dys1;
			(text->texty >= text->h) ? text->texty = text->h - 1 : 0;
			text->dst = ((unsigned int *)(text->textur + text->line_l
			* text->texty + text->textx * (text->bpp / 8)));
			(*text->dst != 0x00F21400) ? mmp(mall, sm + text->xs1,
			text->ys1, (int)*text->dst) : 0;
		}
	}
	weapenl1(mall);
}

static void		weapenr1(t_all *mall)
{
	if (mall->plr.ammo >= 16)
		drowpat(mall, &mall->text.g8);
	else if (mall->plr.ammo >= 14)
		drowpat(mall, &mall->text.g7);
	else if (mall->plr.ammo >= 12)
		drowpat(mall, &mall->text.g6);
	else if (mall->plr.ammo >= 10)
		drowpat(mall, &mall->text.g5);
	else if (mall->plr.ammo >= 8)
		drowpat(mall, &mall->text.g4);
	else if (mall->plr.ammo >= 6)
		drowpat(mall, &mall->text.g3);
	else if (mall->plr.ammo >= 4)
		drowpat(mall, &mall->text.g2);
	else if (mall->plr.ammo >= 2)
		drowpat(mall, &mall->text.g1);
}

void			weapenr(t_all *mall, t_vtext *text)
{
	int sm;

	sm = XX / 2;
	text->xs1 = 0;
	text->dxs1 = 1.0 * 1500 / XX;
	text->dys1 = 1.0 * 1000 / YY;
	while (++text->xs1 < (text->w / text->dxs1 - 1) && text->xs1 < XX - 1)
	{
		text->textx = text->xs1 * text->dxs1;
		(text->textx >= text->w) ? text->textx = text->w - 1 : 0;
		text->ys1 = YY - text->h / text->dys1;
		text->ys2 = 0;
		while (text->ys1 < YY - 1)
		{
			text->ys1++;
			text->ys2++;
			text->texty = text->ys2 * text->dys1;
			(text->texty >= text->h) ? text->texty = text->h - 1 : 0;
			text->dst = ((unsigned int *)(text->textur + text->line_l *
			text->texty + text->textx * (text->bpp / 8)));
			(*text->dst != 0x00F21400) ? mmp(mall, sm + text->xs1,
			text->ys1, (int)*text->dst) : 0;
		}
	}
	weapenr1(mall);
}

void			hud(t_all *mall)
{
	int i;

	i = XX / 2 - XX / 100;
	while (++i < XX / 2 + XX / 100)
		mmp(mall, i, YY / 2, 0XFFFFFF);
	i = YY / 2 - YY / 100 - 1;
	while (++i < YY / 2 + YY / 100)
		mmp(mall, XX / 2, i, 0XFFFFFF);
}
