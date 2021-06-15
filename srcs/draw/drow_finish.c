/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_finish.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 20:27:59 by avivien           #+#    #+#             */
/*   Updated: 2020/12/24 20:28:00 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	finish_draw(t_all *mall)
{
	mlx_mouse_move(mall->win.win, XX / 2, YY / 2);
	mlx_clear_window(mall->win.mlx, mall->win.win);
	mall->win.img = mlx_new_image(mall->win.mlx, XX, YY);
	mall->win.addr = mlx_get_data_addr(mall->win.img, &mall->win.bpp,
	&mall->win.line_l, &mall->win.en);
	(mall->cat.level == 0) ? color_tekf(mall, &mall->text.f) :
	color_tekf(mall, &mall->text.f1);
	(mall->cat.level == 0) ? color_tekc(mall, &mall->text.c) :
	color_tekc(mall, &mall->text.c1);
	ft_draw(mall);
	(mall->plr.hend != 0) ? hud(mall) : 0;
	(mall->cat.wstart <= 100) ? mall->cat.wstart++ : 0;
	(mall->cat.wstart == 100) ? wstart(mall) : 0;
	(mall->plr.hend != 0) ? shot_gun(mall) : 0;
	(mall->plr.key == 1) ? drowkey(mall, &mall->text.icon) : 0;
	mlx_put_image_to_window(mall->win.mlx, mall->win.win, mall->win.img, 0, 0);
	if (mall->save == 1)
	{
		write_bmp(mall);
		system("killall afplay");
		exit(0);
	}
	mlx_destroy_image(mall->win.mlx, mall->win.img);
}
