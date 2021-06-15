/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move1key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:46:24 by avivien           #+#    #+#             */
/*   Updated: 2020/12/24 23:46:26 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		key_relis(int key, t_all *mall)
{
	if (key == 13)
		mall->plr.mov[0] = 0;
	if (key == 1)
		mall->plr.mov[1] = 0;
	if (key == 6)
		mall->plr.krot[0] = 0;
	if (key == 7)
		mall->plr.krot[1] = 0;
	if (key == 2)
		mall->plr.mov[2] = 0;
	if (key == 0)
		mall->plr.mov[3] = 0;
	return (0);
}

int		mouse(int x, int y, t_all *mall)
{
	if (x > XX / 2)
	{
		mall->plr.mrot[1] = x - XX / 2;
		mall->plr.mrot[0] = 1;
	}
	if (x < XX / 2)
	{
		mall->plr.mrot[0] = XX / 2 - x;
		mall->plr.mrot[1] = 1;
	}
	if (y > YY / 2 || y < YY / 2)
		mall->plr.mcam = y - YY / 2;
	return (1);
}

int		clicm(int key, int x, int y, t_all *mall)
{
	(void)(x);
	(void)(y);
	if (key == 1 && mall->plr.hend)
		if (mall->plr.ammo > 0)
		{
			mall->fails = 1;
			mall->plr.ammo -= 2;
			mall->plr.bam = 1;
		}
	if (mall->plr.ammo <= 0)
		wendp(mall);
	return (0);
}

int		ft_key_press(int key, t_all *mall)
{
	if (key == 13)
		mall->plr.mov[0] = 1;
	if (key == 1)
		mall->plr.mov[1] = 1;
	if (key == 6)
		mall->plr.krot[0] = 1;
	if (key == 7)
		mall->plr.krot[1] = 1;
	if (key == 2)
		mall->plr.mov[2] = 1;
	if (key == 0)
		mall->plr.mov[3] = 1;
	if (key == 53)
	{
		free(mall->smap);
		free(mall->dmas);
		system("killall afplay");
		exit(0);
	}
	return (0);
}

int		render_next_frame(t_all *mall)
{
	mlx_hook(mall->win.win, 6, (0), &mouse, mall);
	mlx_hook(mall->win.win, 3, (0), &key_relis, mall);
	mlx_hook(mall->win.win, 2, (0), &ft_key_press, mall);
	mlx_hook(mall->win.win, 4, (0), &clicm, mall);
	return (0);
}
