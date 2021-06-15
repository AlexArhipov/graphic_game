/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2pred.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:47:13 by avivien           #+#    #+#             */
/*   Updated: 2020/12/24 23:47:35 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		move2pr1(t_all *mall)
{
	if (mall->map[(int)(Y)][(int)(X + mall->plr.dirx * SP)] == 'B')
		if (mall->map[(int)(Y)][(int)(X + PLANX * SP) + 2] != '1')
		{
			mall->map[(int)(Y)][(int)(X + PLANX * SP) + 1] = '0';
			wmoveb(mall);
			mall->map[(int)(Y)][(int)((X + PLANX * SP)) + 2] = 'B';
		}
	if ((mall->map[(int)(Y)][(int)(X + mall->plr.dirx * SP)] == 'A') ||
		(mall->map[(int)(Y + mall->plr.diry * SP)][(int)X] == 'A'))
	{
		if (mall->plr.key == 0)
			wclosedoor(mall);
		else
		{
			wopendoor(mall);
			X = mall->plr.tx;
			Y = mall->plr.ty;
			mall->cat.level = 1;
			mall->atakmod = 1;
			mall->cat.lookmonstr = 0;
			system("killall afplay");
			wlevel1(mall);
		}
	}
}

void		move3if1(t_all *mall)
{
	if ((mall->map[(int)(Y)][(int)(X + mall->plr.dirx * SP)] != '1') &&
		(mall->map[(int)(Y)][(int)(X + mall->plr.dirx * SP)] != '2') &&
		(mall->map[(int)(Y)][(int)(X + mall->plr.dirx * SP)] != '3') &&
		(mall->map[(int)(Y)][(int)(X + mall->plr.dirx * SP)] != 'M') &&
		(mall->map[(int)(Y)][(int)(X + mall->plr.dirx * SP)] != '5') &&
		(mall->map[(int)(Y)][(int)(X + mall->plr.dirx * SP)] != '4') &&
		(mall->map[(int)(Y)][(int)(X + mall->plr.dirx * SP)] != '8') &&
		(mall->map[(int)(Y)][(int)(X + mall->plr.dirx * SP)] != '9') &&
		(mall->map[(int)(Y)][(int)(X + mall->plr.dirx * SP)] != 'A') &&
		(mall->map[(int)(Y)][(int)(X + mall->plr.dirx * SP)] != 'F') &&
		(mall->map[(int)(Y)][(int)(X + mall->plr.dirx * SP)] != 'I') &&
		(mall->map[(int)(Y)][(int)(X + mall->plr.dirx * SP)] != 'B'))
		X += SP * mall->plr.dirx;
}

void		move3if2(t_all *mall)
{
	if ((mall->map[(int)(Y + mall->plr.diry * SP)][(int)X] != '1') &&
		(mall->map[(int)(Y + mall->plr.diry * SP)][(int)X] != '2') &&
		(mall->map[(int)(Y + mall->plr.diry * SP)][(int)X] != '3') &&
		(mall->map[(int)(Y + mall->plr.diry * SP)][(int)X] != 'M') &&
		(mall->map[(int)(Y + mall->plr.diry * SP)][(int)X] != '5') &&
		(mall->map[(int)(Y + mall->plr.diry * SP)][(int)X] != '4') &&
		(mall->map[(int)(Y + mall->plr.diry * SP)][(int)X] != '8') &&
		(mall->map[(int)(Y + mall->plr.diry * SP)][(int)X] != '9') &&
		(mall->map[(int)(Y + mall->plr.diry * SP)][(int)X] != 'A') &&
		(mall->map[(int)(Y + mall->plr.diry * SP)][(int)X] != 'F') &&
		(mall->map[(int)(Y + mall->plr.diry * SP)][(int)X] != 'I') &&
		(mall->map[(int)(Y + mall->plr.diry * SP)][(int)X] != 'B'))
		Y += SP * mall->plr.diry;
}

void		move3if3(t_all *mall)
{
	if ((mall->map[(int)(Y)][(int)(X - mall->plr.dirx * SP)] != '1') &&
		(mall->map[(int)(Y)][(int)(X - mall->plr.dirx * SP)] != '2') &&
		(mall->map[(int)(Y)][(int)(X - mall->plr.dirx * SP)] != '3') &&
		(mall->map[(int)(Y)][(int)(X - mall->plr.dirx * SP)] != 'M') &&
		(mall->map[(int)(Y)][(int)(X - mall->plr.dirx * SP)] != '5') &&
		(mall->map[(int)(Y)][(int)(X - mall->plr.dirx * SP)] != '4') &&
		(mall->map[(int)(Y)][(int)(X - mall->plr.dirx * SP)] != '8') &&
		(mall->map[(int)(Y)][(int)(X - mall->plr.dirx * SP)] != '9') &&
		(mall->map[(int)(Y)][(int)(X - mall->plr.dirx * SP)] != 'A') &&
		(mall->map[(int)(Y)][(int)(X - mall->plr.dirx * SP)] != 'F') &&
		(mall->map[(int)(Y)][(int)(X - mall->plr.dirx * SP)] != 'I') &&
		(mall->map[(int)(Y)][(int)(X - mall->plr.dirx * SP)] != 'B'))
		X -= SP * mall->plr.dirx;
}

void		move3if4(t_all *mall)
{
	if ((mall->map[(int)(Y - mall->plr.diry * SP)][(int)X] != '1') &&
		(mall->map[(int)(Y - mall->plr.diry * SP)][(int)X] != '2') &&
		(mall->map[(int)(Y - mall->plr.diry * SP)][(int)X] != '3') &&
		(mall->map[(int)(Y - mall->plr.diry * SP)][(int)X] != 'M') &&
		(mall->map[(int)(Y - mall->plr.diry * SP)][(int)X] != '4') &&
		(mall->map[(int)(Y - mall->plr.diry * SP)][(int)X] != '5') &&
		(mall->map[(int)(Y - mall->plr.diry * SP)][(int)X] != '8') &&
		(mall->map[(int)(Y - mall->plr.diry * SP)][(int)X] != '9') &&
		(mall->map[(int)(Y - mall->plr.diry * SP)][(int)X] != 'A') &&
		(mall->map[(int)(Y - mall->plr.diry * SP)][(int)X] != 'F') &&
		(mall->map[(int)(Y - mall->plr.diry * SP)][(int)X] != 'I') &&
		(mall->map[(int)(Y - mall->plr.diry * SP)][(int)X] != 'B'))
		Y -= SP * mall->plr.diry;
}
