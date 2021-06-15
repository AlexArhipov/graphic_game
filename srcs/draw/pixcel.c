/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixcel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 20:29:58 by avivien           #+#    #+#             */
/*   Updated: 2020/12/24 20:30:00 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

unsigned int	*pix_color(t_vtext *text)
{
	return ((unsigned int *)(text->textur + text->line_l * text->texty
	+ text->textx * (text->bpp / 8)));
}

void			mmp(t_all *mall, int x, int y, int color)
{
	char *dst;

	dst = mall->win.addr + (y * mall->win.line_l + x * (mall->win.bpp / 8));
	*(unsigned int*)dst = color;
}

static void		opendoor1(t_all *mall, int x)
{
	if (mall->tdoor < 100)
		mall->tdoor += 0.0005;
	if (mall->tdoor < 5)
		draw_line(mall, &mall->text.d1, x);
	if (mall->tdoor >= 5 && mall->tdoor < 10)
		draw_line(mall, &mall->text.d2, x);
	if (mall->tdoor >= 10 && mall->tdoor < 15)
		draw_line(mall, &mall->text.d3, x);
	if (mall->tdoor >= 15 && mall->tdoor < 20)
		draw_line(mall, &mall->text.d3, x);
	if (mall->tdoor >= 20 && mall->tdoor < 25)
		draw_line(mall, &mall->text.d4, x);
	if (mall->tdoor >= 25 && mall->tdoor < 30)
		draw_line(mall, &mall->text.d5, x);
	if (mall->tdoor >= 30 && mall->tdoor < 35)
		draw_line(mall, &mall->text.d6, x);
	if (mall->tdoor >= 35 && mall->tdoor < 40)
		draw_line(mall, &mall->text.d7, x);
	if (mall->tdoor >= 40 && mall->tdoor < 45)
		draw_line(mall, &mall->text.d8, x);
}

void			opendoor(t_all *mall, int x)
{
	opendoor1(mall, x);
	if (mall->tdoor >= 45 && mall->tdoor < 50)
		draw_line(mall, &mall->text.d9, x);
	if (mall->tdoor >= 50 && mall->tdoor < 55)
		draw_line(mall, &mall->text.d10, x);
	if (mall->tdoor >= 55 && mall->tdoor < 60)
		draw_line(mall, &mall->text.d11, x);
	if (mall->tdoor >= 60 && mall->tdoor < 65)
		draw_line(mall, &mall->text.d12, x);
	if (mall->tdoor >= 65 && mall->tdoor < 70)
		draw_line(mall, &mall->text.d13, x);
	if (mall->tdoor >= 70 && mall->tdoor < 75)
		draw_line(mall, &mall->text.d14, x);
	if (mall->tdoor >= 75 && mall->tdoor < 80)
		draw_line(mall, &mall->text.d15, x);
	if (mall->tdoor >= 80 && mall->tdoor < 85)
		draw_line(mall, &mall->text.d16, x);
	if (mall->tdoor >= 85 && mall->tdoor < 90)
		draw_line(mall, &mall->text.d17, x);
	if (mall->tdoor >= 90)
		draw_line(mall, &mall->text.d18, x);
}
