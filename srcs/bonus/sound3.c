/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 19:09:10 by avivien           #+#    #+#             */
/*   Updated: 2020/12/24 19:09:11 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	wclosedoor(t_all *mall)
{
	pid_t pid;

	if (mall->cat.closed == 0)
	{
		mall->cat.closed = 1;
		pid = fork();
		if (pid == 0)
		{
			system("afplay srcs/sound/pos.mp3");
			exit(0);
		}
	}
}

void	wopendoor(t_all *mall)
{
	pid_t pid;

	if (mall->cat.opend == 0)
	{
		mall->cat.opend = 1;
		pid = fork();
		if (pid == 0)
		{
			system("afplay srcs/sound/open.mp3");
			exit(0);
		}
	}
}

void	wkey(t_all *mall)
{
	pid_t pid;

	mall->guikey = 1;
	pid = fork();
	if (pid == 0)
	{
		system("afplay srcs/sound/key.mp3");
		if (mall->cat.stopcat != 1)
			system("afplay srcs/sound/find3.mp3");
		system("afplay srcs/sound/rikmon1.mp3");
		exit(0);
	}
}

void	wlookkey(t_all *mall)
{
	pid_t pid;

	if (mall->cat.lookkey == 0)
	{
		mall->cat.lookkey++;
		if (mall->cat.door == 0)
		{
			pid = fork();
			if (pid == 0)
			{
				system("afplay srcs/sound/find2.mp3");
				exit(0);
			}
		}
		else
		{
			mall->cat.stopcat = 1;
			pid = fork();
			if (pid == 0)
			{
				system("afplay srcs/sound/find1.mp3");
				exit(0);
			}
		}
	}
}

void	wmon(t_all *mall)
{
	pid_t pid;

	(void)(mall);
	pid = fork();
	if (pid == 0)
	{
		system("afplay srcs/sound/rikmon2.wav");
		exit(0);
	}
}
