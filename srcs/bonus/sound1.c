/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 19:05:28 by avivien           #+#    #+#             */
/*   Updated: 2020/12/24 19:05:30 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	wdefp(t_all *mall)
{
	pid_t pid;

	(void)(mall);
	pid = fork();
	if (pid == 0)
	{
		system("afplay srcs/sound/dead.wav");
		exit(0);
	}
}

void	wdefm(t_all *mall)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		system("afplay srcs/sound/deadm.mp3");
		if (mall->cat.level == 1)
			system("afplay srcs/sound/wall.mp3");
		exit(0);
	}
}

void	wmoveb(t_all *mall)
{
	pid_t pid;

	(void)(mall);
	pid = fork();
	if (pid == 0)
	{
		system("afplay srcs/sound/bkam.mp3");
		exit(0);
	}
}

void	wcreate(t_all *mall)
{
	pid_t pid;

	mall->cat.lokcreat++;
	pid = fork();
	if (pid == 0)
	{
		system("afplay srcs/sound/my_create.mp3");
		exit(0);
	}
}

void	wkorona(t_all *mall)
{
	pid_t pid;

	mall->cat.lokkor++;
	pid = fork();
	if (pid == 0)
	{
		system("afplay srcs/sound/kor.mp3");
		exit(0);
	}
}
