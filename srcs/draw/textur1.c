/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textur1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 21:07:12 by avivien           #+#    #+#             */
/*   Updated: 2020/12/24 21:07:13 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		color_tekf(t_all *mall, t_vtext *text)
{
	double roud;

	text->ys1 = YY / mall->ray.mcam + 1;
	while (++text->ys1 < YY)
	{
		roud = (0.5 * YY) / (text->ys1 - YY / mall->ray.mcam);
		text->stepx = roud * (DIRX + PLANX - (DIRX - PLANX))
		/ mall->win.r_win[0];
		text->stepy = roud * ((DIRY + PLANY) - (DIRY - PLANY))
		/ mall->win.r_win[0];
		text->text_posx = X + roud * (mall->plr.dirx - PLANX);
		text->text_posy = Y + roud * (mall->plr.diry - PLANY);
		text->xs1 = -1;
		while (++text->xs1 < mall->win.r_win[0])
		{
			text->textx = (int)(text->w * (text->text_posx -
			((int)(text->text_posx)))) & (text->w - 1);
			text->texty = (int)(text->h * (text->text_posy -
			((int)(text->text_posy)))) & (text->h - 1);
			text->text_posx += text->stepx;
			text->text_posy += text->stepy;
			mmp(mall, text->xs1, text->ys1, (int)*pix_color(text));
		}
	}
}

void		color_tekc(t_all *mall, t_vtext *text)
{
	double roud;

	text->ys1 = (int)(YY / mall->ray.mcam - 1);
	while (--text->ys1 > 0)
	{
		roud = (0.5 * YY) / (YY / mall->ray.mcam - text->ys1);
		text->stepx = roud * ((mall->plr.dirx + PLANX) - (DIRX - PLANX))
		/ mall->win.r_win[0];
		text->stepy = roud * ((mall->plr.diry + PLANY) - (DIRY - PLANY))
		/ mall->win.r_win[0];
		text->text_posx = X + roud * (mall->plr.dirx - PLANX);
		text->text_posy = Y + roud * (mall->plr.diry - PLANY);
		text->xs1 = -1;
		while (++text->xs1 < mall->win.r_win[0])
		{
			text->textx = (int)(text->w * (text->text_posx -
			((int)(text->text_posx)))) & (text->w - 1);
			text->texty = (int)(text->h * (text->text_posy -
			((int)(text->text_posy)))) & (text->h - 1);
			text->text_posx += text->stepx;
			text->text_posy += text->stepy;
			mmp(mall, text->xs1, text->ys1, (int)*pix_color(text));
		}
	}
}
