/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 19:07:53 by avivien           #+#    #+#             */
/*   Updated: 2020/12/24 19:07:54 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	wendp(t_all *mall)
{
	pid_t pid;

	(void)(mall);
	pid = fork();
	if (pid == 0)
	{
		system("afplay srcs/sound/endbam.mp3");
		exit(0);
	}
}

void	wlogovo(t_all *mall)
{
	pid_t pid;

	if (mall->cat.logovo == 0)
	{
		mall->cat.logovo++;
		pid = fork();
		if (pid == 0)
		{
			system("afplay srcs/sound/logovo.mp3");
			exit(0);
		}
	}
}

void	wstart(t_all *mall)
{
	pid_t pid;

	(void)(mall);
	pid = fork();
	if (pid == 0)
	{
		system("afplay srcs/sound/start2.mp3");
		exit(0);
	}
}

void	wranmon(t_all *mall)
{
	pid_t pid;

	if (mall->plr.bam == 1)
	{
		pid = fork();
		if (pid == 0)
		{
			system("afplay srcs/sound/ranmon2.wav");
			exit(0);
		}
	}
}

void	wran(t_all *mall)
{
	pid_t pid;

	(void)(mall);
	pid = fork();
	if (pid == 0)
	{
		system("afplay srcs/sound/ran.wav");
		exit(0);
	}
}
