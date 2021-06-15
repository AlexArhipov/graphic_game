/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:44:45 by avivien           #+#    #+#             */
/*   Updated: 2020/12/24 23:44:46 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		ft_abs(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

void	find_play(t_all *mall)
{
	int i;
	int j;

	i = 0;
	while (mall->map[(++i) + 1])
	{
		j = 0;
		while (mall->map[i][(++j) + 1])
			if ((mall->map[i][j] == 'S') || (mall->map[i][j] == 'W')
				|| (mall->map[i][j] == 'E') || (mall->map[i][j] == 'N'))
			{
				if (mall->map[i][j] == 'N')
					mall->plr.rad = M_PI;
				if (mall->map[i][j] == 'W')
					mall->plr.rad = M_PI / 2;
				if (mall->map[i][j] == 'S')
					mall->plr.rad = 0;
				if (mall->map[i][j] == 'E')
					mall->plr.rad = 3 * M_PI / 2;
				X = j;
				Y = i;
			}
	}
}
