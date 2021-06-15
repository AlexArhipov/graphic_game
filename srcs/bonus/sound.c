/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 19:04:51 by avivien           #+#    #+#             */
/*   Updated: 2020/12/24 19:04:53 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	wlevel1(t_all *mall)
{
	if (mall->cat.level == 0)
		system("afplay srcs/sound/sound1.mp3 &");
	else
		system("afplay srcs/sound/sound2.mp3 &");
}

void	wbam(t_all *mall)
{
	pid_t pid;

	if (mall->plr.bam == 1)
	{
		pid = fork();
		if (pid == 0)
		{
			system("afplay srcs/sound/f4.wav");
			exit(0);
		}
	}
}

void	wpodbor(t_all *mall)
{
	pid_t pid;

	(void)(mall);
	pid = fork();
	if (pid == 0)
	{
		system("afplay srcs/sound/podbor.mp3");
		system("afplay srcs/sound/gun.mp3");
		exit(0);
	}
}

void	wlookmonstr(t_all *mall)
{
	pid_t pid;

	mall->cat.lookmonstr++;
	pid = fork();
	if (pid == 0)
	{
		if (mall->cat.level == 0)
			system("afplay srcs/sound/lookm.mp3");
		else
			system("afplay srcs/sound/tvar.mp3");
		exit(0);
	}
}

void	wlookdoor(t_all *mall)
{
	pid_t pid;

	if (mall->cat.door == 0)
	{
		mall->cat.door = 1;
		pid = fork();
		if (pid == 0)
		{
			system("afplay srcs/sound/enter.mp3");
			exit(0);
		}
	}
}
