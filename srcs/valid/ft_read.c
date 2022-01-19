/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 19:39:07 by avivien           #+#    #+#             */
/*   Updated: 2020/12/25 19:39:09 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char		*read_strucs(char *s)
{
	char *ss;
	char *st;

	s = ft_move(s);
	if (!(ss = (char *)malloc((sizeof(char)) * (ft_lens(s) + 1))))
	{
		write(1, "malloc error\n", 13);
		exit(1);
	}
	st = ss;
	while (*s && *s != ' ')
		*ss++ = *s++;
	*ss = '\0';
	return (st);
}

void		read_color_c(char *s, t_all *mall)
{
	int i;

	i = -1;
	s = ft_move(++s);
	while (++i < 3)
	{
		s = ft_move(s);
		mall->win.m_up[i] = 0;
		while (*s >= '0' && *s <= '9')
			mall->win.m_up[i] = (mall->win.m_up[i] * 10) + (*s++ - '0');
		(*s == ',') ? s++ : 0;
	}
}

void		read_color_f(char *s, t_all *mall)
{
	int i;

	i = -1;
	s = ft_move(++s);
	while (++i < 3)
	{
		s = ft_move(s);
		mall->win.m_down[i] = 0;
		while (*s >= '0' && *s <= '9')
			mall->win.m_down[i] = (mall->win.m_down[i] * 10 + *s++ - '0');
		(*s == ',') ? s++ : 0;
	}
}

void		read_valid_map_2(char *line, t_all *mall)
{
	line = ft_move(line);
	if (*line == 'R')
	{
		line = ft_move(++line);
		mall->win.r_win[0] = 0;
		mall->win.r_win[1] = 0;
		while (*line >= '0' && *line <= '9')
			mall->win.r_win[0] = (mall->win.r_win[0] * 10 + *line++ - '0');
		line = ft_move(line);
		while (*line >= '0' && *line <= '9')
			mall->win.r_win[1] = (mall->win.r_win[1] * 10 + *line++ - '0');
	}
	if (*line == 'N' || *line == 'S' || *line == 'W' || *line == 'E')
	{
		(*line == 'N') ? mall->win.t_no = read_strucs(line + 2) : 0;
		((*line == 'S') && (*(line + 1) == 'O')) ?
		mall->win.t_so = read_strucs(line + 2) : 0;
		(*line == 'W') ? mall->win.t_we = read_strucs(line + 2) : 0;
		(*line == 'E') ? mall->win.t_ea = read_strucs(line + 2) : 0;
		((*line == 'S') && *(line + 1) == ' ') ?
		mall->win.t_s = read_strucs(line + 1) : 0;
	}
	(*line == 'F' && *(line + 1) == ' ') ? read_color_f(line, mall) : 0;
	(*line == 'C' && *(line + 1) == ' ') ? read_color_c(line, mall) : 0;
}

t_all		*ft_read_file(int fd, t_all *mall, int r_map, int i)
{
	int		m;
	char	*line;
	int		count;

	count = ST;
	mall->map = malloc(sizeof(char *) * (r_map + 1));
	while ((m = get_next_line(fd, &line)) >= 0)
	{
		if (strlen(line) > 1 && count > 0)
		{
			count--;
			read_valid_map_2(line, mall);
		}
		(strlen(line) > 1 && count <= 0) ? mall->map[i++] = line : 0;
		((strlen(line) > 1 && count) || (strlen(line) == 0)) ? free(line) : 0;
		if (m == 0)
		{
			mall->map[i] = NULL;
			break ;
		}
	}
	close(fd);
	find_play(mall);
	return (mall);
}
