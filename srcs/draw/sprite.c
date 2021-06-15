/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 20:43:10 by avivien           #+#    #+#             */
/*   Updated: 2020/12/24 20:45:21 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		sort_dist(t_all *mall)
{
	int			i;
	int			j;
	t_sprite	temp;

	i = -1;
	while (++i < mall->cas - 1)
	{
		j = mall->cas;
		while (--j > i)
			if (mall->smap[j - 1].dist < mall->smap[j].dist)
			{
				temp = mall->smap[j - 1];
				mall->smap[j - 1] = mall->smap[j];
				mall->smap[j] = temp;
			}
	}
}

void		caunt_dist(t_all *mall)
{
	int i;

	i = -1;
	while (++i < mall->cas)
		mall->smap[i].dist = (X - mall->smap[i].y) * (X - mall->smap[i].y)
		+ (Y - mall->smap[i].x) * (Y - mall->smap[i].x);
	sort_dist(mall);
}

void		put_t(t_vtext *text, t_vtext *textm)
{
	text->w = textm->w;
	text->h = textm->h;
	text->bpp = textm->bpp;
	text->line_l = textm->line_l;
	text->en = textm->en;
	text->textur = textm->textur;
}

static void	draw_ps1_while(t_all *mall, t_vtext *text, int sp_scinx)
{
	int sp_w;

	sp_w = ft_abs((int)(XX / text->text_posy));
	text->xs1 = -sp_w / 2 + sp_scinx - 1;
	(text->xs1 < 0) ? text->xs1 = -1 : 0;
	text->xs2 = sp_w / 2 + sp_scinx;
	(text->xs2 >= XX) ? text->xs2 = XX - 1 : 0;
	while (++text->xs1 < text->xs2)
	{
		text->textx = (int)((text->xs1 - (-sp_w / 2 +
		sp_scinx)) * text->w / sp_w);
		text->ys1 = (-(ft_abs((int)(YY / text->text_posy))) / 2 + YY
		/ mall->ray.mcam) - 1;
		(text->ys1 < 0) ? text->ys1 = -1 : 0;
		if (text->text_posy > 0 && text->xs1 > 0 && text->xs1 < XX
		&& text->text_posy < mall->dmas[text->xs1])
			while (++text->ys1 < text->ys2)
			{
				text->texty = (int)(((int)(text->ys1 - YY / mall->ray.mcam +
						(ft_abs((int)(YY / text->text_posy))) / 2) * text->h)
						/ (ft_abs((int)(YY / text->text_posy))));
				((*pix_color(text) != 0xffffff)) ? mmp(mall, text->xs1,
				text->ys1, (int)*pix_color(text)) : 0;
			}
	}
}

void		draw_ps(t_all *mall)
{
	int		i;
	double	intdet;
	t_vtext	text;
	int		sp_scinx;
	double	sm;

	caunt_dist(mall);
	i = -1;
	while (++i < mall->cas)
	{
		if (mall->smap[i].sp == '0')
			continue;
		sm = 0.5;
		cas_t(mall->smap[i].sp, &text, mall, i);
		intdet = 1.0 / (PLANX * mall->plr.diry - PLANY * mall->plr.dirx);
		text.text_posy = intdet * (-PLANY * (mall->smap[i].y + sm - X)
		+ PLANX * (mall->smap[i].x + sm - Y));
		sp_scinx = (int)((XX / 2) * (1 + (intdet * (mall->plr.diry *
		(mall->smap[i].y + sm - X) - mall->plr.dirx *
		(mall->smap[i].x + sm - Y))) / text.text_posy));
		text.ys2 = (ft_abs((int)(YY / text.text_posy))) / 2 +
		YY / mall->ray.mcam;
		(text.ys2 >= YY) ? text.ys2 = YY - 1 : 0;
		draw_ps1_while(mall, &text, sp_scinx);
	}
}
