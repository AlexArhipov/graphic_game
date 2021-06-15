/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixcel1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 20:31:41 by avivien           #+#    #+#             */
/*   Updated: 2020/12/24 20:31:43 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	drowkey(t_all *mall, t_vtext *text)
{
	int				yy;
	unsigned int	*dst;

	text->dxs1 = 1.0 * 4000 / XX;
	text->dys1 = 1.0 * 2500 / YY;
	text->xs1 = 0;
	while (++text->xs1 < (text->w / text->dxs1 - 1) && text->xs1 < XX - 1)
	{
		text->textx = text->xs1 * text->dxs1;
		(text->textx >= text->w) ? text->textx = text->w - 1 : 0;
		text->ys1 = YY - text->h / text->dys1;
		yy = 0;
		while (text->ys1 < YY - 1)
		{
			text->ys1++;
			yy++;
			text->texty = yy * text->dys1;
			(text->texty >= text->h) ? text->texty = text->h - 1 : 0;
			dst = ((unsigned int *)(text->textur + text->line_l *
			text->texty + text->textx * (text->bpp / 8)));
			(*dst != 0xFFFFFF) ? mmp(mall, text->xs1, yy, (int)*dst) : 0;
		}
	}
}

void	drowpat(t_all *mall, t_vtext *text)
{
	int				y;
	int				yy;
	unsigned int	*dst;

	text->dxs1 = 1.0 * 2000 / XX;
	text->dys1 = 1.0 * 1500 / YY;
	text->xs1 = 0;
	while (++text->xs1 < (text->w / text->dxs1 - 1) && text->xs1 < XX - 1)
	{
		text->textx = text->xs1 * text->dxs1;
		(text->textx >= text->w) ? text->textx = text->w - 1 : 0;
		y = YY - text->h / text->dys1;
		yy = 0;
		while (y < YY - 1)
		{
			y++;
			yy++;
			text->texty = yy * text->dys1;
			(text->texty >= text->h) ? text->texty = text->h - 1 : 0;
			dst = ((unsigned int *)(text->textur + text->line_l *
			text->texty + text->textx * (text->bpp / 8)));
			(*dst != 0xFFFFFF) ? mmp(mall, text->xs1, y, (int)*dst) : 0;
		}
	}
}

void	drowpat2(t_all *mall, t_vtext *text)
{
	unsigned int *dst;

	text->dxs1 = 1.0 * 2000 / XX;
	text->dys1 = 1.0 * 1500 / YY;
	text->xs2 = 0;
	text->xs1 = XX - text->w / text->dxs1;
	while (text->xs1 < XX - 1)
	{
		text->xs1++;
		text->xs2++;
		text->textx = text->xs2 * text->dxs1;
		(text->textx >= text->w) ? text->textx = text->w - 1 : 0;
		text->ys1 = YY - text->h / text->dys1;
		text->ys2 = 0;
		while (text->ys1 < YY - 1)
		{
			text->ys1++;
			text->ys2++;
			text->texty = text->ys2 * text->dys1;
			(text->texty >= text->h) ? text->texty = text->h - 1 : 0;
			dst = ((unsigned int *)(text->textur + text->line_l *
					text->texty + text->textx * (text->bpp / 8)));
			(*dst != 0xFFFFFF) ? mmp(mall, text->xs1, text->ys1, (int)*dst) : 0;
		}
	}
}
