/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dline.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 19:43:57 by avivien           #+#    #+#             */
/*   Updated: 2020/12/24 19:43:58 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void		draw_line1(t_all *mall, t_vtext *text, int x)
{
	text->texty = (int)text->text_posx;
	text->text_posx += text->stepx;
	text->dst = pix_color(text);
	(text->texty >= text->h) ? text->texty = text->h - 1 : 0;
	(text->textx >= text->w) ? text->textx = text->w - 1 : 0;
	(text->texty < 0) ? text->texty = 0 : 0;
	(text->textx < 0) ? text->textx = 0 : 0;
	(x >= XX) ? x = XX - 1 : 0;
	(text->xs1 >= YY) ? text->xs1 = YY - 1 : 0;
	mmp(mall, x, text->xs1, *text->dst);
	text->xs1++;
}

void			draw_line(t_all *mall, t_vtext *text, int x)
{
	int linelen;

	linelen = (int)(YY / fabs(mall->ray.sh));
	text->xs1 = -linelen / 2 + YY / mall->ray.mcam;
	(text->xs1 < 0) ? text->xs1 = 0 : 0;
	text->xs2 = linelen / 2 + YY / mall->ray.mcam;
	(text->xs2 >= YY) ? text->xs2 = YY - 1 : 0;
	text->wall = (mall->ray.side == 0) ? Y + mall->ray.sh * mall->ray.raydiry :
	X + mall->ray.sh * mall->ray.raydirx;
	text->wall -= floor(text->wall);
	text->textx = (int)(text->wall * text->w);
	(mall->ray.side == 0 && mall->ray.raydirx > 0) ? text->textx = text->w
			- text->textx - 1 : 0;
	(mall->ray.side == 1 && mall->ray.raydiry < 0) ? text->textx = text->w
			- text->textx - 1 : 0;
	text->stepx = 1.0 * text->h / linelen;
	text->text_posx = (text->xs1 - YY / mall->ray.mcam +
			linelen / 2) * text->stepx;
	((int)(text->text_posx) < 0) ? text->text_posx = 0 : 0;
	while (text->xs1 < text->xs2)
		draw_line1(mall, text, x);
}

void			draw_ray_start(t_all *mall, int x)
{
	mall->ray.camerax = 2 * x / (double)XX - 1;
	mall->ray.raydirx = mall->plr.dirx + PLANX * mall->ray.camerax;
	mall->ray.raydiry = mall->plr.diry + PLANY * mall->ray.camerax;
	mall->ray.mapx = (int)X;
	mall->ray.mapy = (int)Y;
	if (mall->ray.raydiry == 0)
		mall->ray.deltadistx = 0;
	else
	{
		if (mall->ray.raydirx == 0)
			mall->ray.deltadistx = 1;
		else
			mall->ray.deltadistx = fabs(1 / mall->ray.raydirx);
	}
	if (mall->ray.raydirx == 0)
		mall->ray.deltadisty = 0;
	else
	{
		if (mall->ray.raydiry == 0)
			mall->ray.deltadisty = 1;
		else
			mall->ray.deltadisty = fabs(1 / mall->ray.raydiry);
	}
	mall->ray.hit = 0;
	mall->ray.side = 0;
}

void			ft_draw(t_all *mall)
{
	int x;

	x = -1;
	while (++x < mall->win.r_win[0])
		mall->dmas[x] = draw_ray(mall, x);
	draw_ps(mall);
}
