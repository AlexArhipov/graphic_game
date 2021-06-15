/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move3if.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:49:36 by avivien           #+#    #+#             */
/*   Updated: 2020/12/24 23:49:37 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		move3if5(t_all *mall)
{
	if ((mall->map[(int)(Y)][(int)(X + PLANX * SP)] != '1') &&
		(mall->map[(int)(Y)][(int)(X + PLANX * SP)] != '2') &&
		(mall->map[(int)(Y)][(int)(X + PLANX * SP)] != '3') &&
		(mall->map[(int)(Y)][(int)(X + PLANX * SP)] != 'M') &&
		(mall->map[(int)(Y)][(int)(X + PLANX * SP)] != '5') &&
		(mall->map[(int)(Y)][(int)(X + PLANX * SP)] != '8') &&
		(mall->map[(int)(Y)][(int)(X + PLANX * SP)] != '9') &&
		(mall->map[(int)(Y)][(int)(X + PLANX * SP)] != '4') &&
		(mall->map[(int)(Y)][(int)(X + PLANX * SP)] != 'A') &&
		(mall->map[(int)(Y)][(int)(X + PLANX * SP)] != 'F') &&
		(mall->map[(int)(Y)][(int)(X + PLANX * SP)] != 'I') &&
		(mall->map[(int)(Y)][(int)(X + PLANX * SP)] != 'B'))
		X += SP * PLANX;
}

void		move3if6(t_all *mall)
{
	if ((mall->map[(int)(Y + PLANY * SP)][(int)X] != '1') &&
		(mall->map[(int)(Y + PLANY * SP)][(int)X] != '2') &&
		(mall->map[(int)(Y + PLANY * SP)][(int)X] != 'M') &&
		(mall->map[(int)(Y + PLANY * SP)][(int)X] != '5') &&
		(mall->map[(int)(Y + PLANY * SP)][(int)X] != '4') &&
		(mall->map[(int)(Y + PLANY * SP)][(int)X] != '8') &&
		(mall->map[(int)(Y + PLANY * SP)][(int)X] != '9') &&
		(mall->map[(int)(Y + PLANY * SP)][(int)X] != 'A') &&
		(mall->map[(int)(Y + PLANY * SP)][(int)X] != 'F') &&
		(mall->map[(int)(Y + PLANY * SP)][(int)X] != 'I') &&
		(mall->map[(int)(Y + PLANY * SP)][(int)X] != 'B'))
		Y += SP * PLANY;
}

void		move3if7(t_all *mall)
{
	if ((mall->map[(int)(Y)][(int)(X - PLANX * SP)] != '1') &&
		(mall->map[(int)(Y)][(int)(X - PLANX * SP)] != '2') &&
		(mall->map[(int)(Y)][(int)(X - PLANX * SP)] != '3') &&
		(mall->map[(int)(Y)][(int)(X - PLANX * SP)] != 'M') &&
		(mall->map[(int)(Y)][(int)(X - PLANX * SP)] != '5') &&
		(mall->map[(int)(Y)][(int)(X - PLANX * SP)] != '4') &&
		(mall->map[(int)(Y)][(int)(X - PLANX * SP)] != '8') &&
		(mall->map[(int)(Y)][(int)(X - PLANX * SP)] != '9') &&
		(mall->map[(int)(Y)][(int)(X - PLANX * SP)] != 'A') &&
		(mall->map[(int)(Y)][(int)(X - PLANX * SP)] != 'F') &&
		(mall->map[(int)(Y)][(int)(X - PLANX * SP)] != 'I') &&
		(mall->map[(int)(Y)][(int)(X - PLANX * SP)] != 'B'))
		X -= SP * PLANX;
}

void		move3if8(t_all *mall)
{
	if ((mall->map[(int)(Y - PLANY * SP)][(int)X] != '1') &&
		(mall->map[(int)(Y - PLANY * SP)][(int)X] != '2') &&
		(mall->map[(int)(Y - PLANY * SP)][(int)X] != '3') &&
		(mall->map[(int)(Y - PLANY * SP)][(int)X] != 'M') &&
		(mall->map[(int)(Y - PLANY * SP)][(int)X] != '5') &&
		(mall->map[(int)(Y - PLANY * SP)][(int)X] != '4') &&
		(mall->map[(int)(Y - PLANY * SP)][(int)X] != '8') &&
		(mall->map[(int)(Y - PLANY * SP)][(int)X] != '9') &&
		(mall->map[(int)(Y - PLANY * SP)][(int)X] != 'A') &&
		(mall->map[(int)(Y - PLANY * SP)][(int)X] != 'F') &&
		(mall->map[(int)(Y - PLANY * SP)][(int)X] != 'I') &&
		(mall->map[(int)(Y - PLANY * SP)][(int)X] != 'B'))
		Y -= SP * PLANY;
}

void		move_asd(t_all *mall)
{
	if (mall->plr.mov[1] == 1)
	{
		move3if3(mall);
		move3if4(mall);
	}
	if (mall->plr.mov[2] == 1)
	{
		move3if5(mall);
		move3if6(mall);
	}
	if (mall->plr.mov[3] == 1)
	{
		move3if7(mall);
		move3if8(mall);
	}
}
