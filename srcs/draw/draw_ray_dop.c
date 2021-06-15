/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 19:56:40 by avivien           #+#    #+#             */
/*   Updated: 2020/12/24 20:26:57 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	draw_ray_if2_1(t_all *mall, int x)
{
	if (mall->ray.side == 0)
		(CL == 0) ? DL(mall, &mall->text.ea, x) : DL(mall, &mall->text.ea1, x);
	else
		(CL == 0) ? DL(mall, &mall->text.so, x) : DL(mall, &mall->text.so1, x);
}

static void	draw_ray_if2_2(t_all *mall, int x)
{
	if (mall->ray.side == 0)
		(CL == 0) ? DL(mall, &mall->text.ea, x) : DL(mall, &mall->text.ea1, x);
	else
		(CL == 0) ? DL(mall, &mall->text.no, x) : DL(mall, &mall->text.no1, x);
}

static void	draw_ray_if2_3(t_all *mall, int x)
{
	if (mall->ray.side == 0)
		(CL == 0) ? DL(mall, &mall->text.we, x) : DL(mall, &mall->text.we1, x);
	else
		(CL == 0) ? DL(mall, &mall->text.so, x) : DL(mall, &mall->text.so1, x);
}

static void	draw_ray_if2_4(t_all *mall, int x)
{
	if (mall->ray.side == 0)
		(CL == 0) ? DL(mall, &mall->text.we, x) : DL(mall, &mall->text.we1, x);
	else
		(CL == 0) ? DL(mall, &mall->text.no, x) : DL(mall, &mall->text.no1, x);
}

void		draw_ray_if2(t_all *mall, int x)
{
	if (MRAY == 'B' || MRAY == '4')
		draw_line(mall, &mall->text.bstone, x);
	else if (mall->map[mall->ray.mapy][mall->ray.mapx] == 'G')
		draw_line(mall, &mall->text.so1, x);
	else if (mall->ray.mapy >= Y && mall->ray.mapx > X)
		draw_ray_if2_1(mall, x);
	else if (mall->ray.mapy < Y && mall->ray.mapx > X)
		draw_ray_if2_2(mall, x);
	else if (mall->ray.mapy > Y && mall->ray.mapx <= X)
		draw_ray_if2_3(mall, x);
	else
		draw_ray_if2_4(mall, x);
}
