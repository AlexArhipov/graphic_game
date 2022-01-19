/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 19:40:48 by avivien           #+#    #+#             */
/*   Updated: 2020/12/25 19:40:50 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		valid_strucs(char *s)
{
	char	*ss;
	char	*st;
	int		fd;

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
	s = ft_move(s);
	fd = open(st, O_RDONLY);
	free(st);
	close(fd);
	if (fd < 1 || *s != '\0')
		return (0);
	return (1);
}

int		chek_ras(char *s)
{
	char	c;
	int		r1;
	int		r2;

	r1 = 0;
	r2 = 0;
	c = *s++;
	s = ft_move(s);
	while (*s >= '0' && *s <= '9')
		r1 = (r1 * 10) + (*s++ - '0');
	s = ft_move(s);
	while (*s >= '0' && *s <= '9')
		r2 = (r2 * 10) + (*s++ - '0');
	s = ft_move(s);
	if (*s == '\0' && c == 'R' && r1 > 0 && r2 > 0)
		return (1);
	return (0);
}

int		chek_color(char *s)
{
	char	c;
	int		i;
	int		r;
	int		sum;

	i = 3;
	sum = 0;
	c = *s++;
	while (i--)
	{
		s = ft_move(s);
		r = -1;
		while (*s >= '0' && *s <= '9')
		{
			(r < 0) ? r = 0 : 0;
			r = (r * 10) + (*s++ - '0');
		}
		(*s == ',') ? s++ : 0;
		(r >= 0 && r <= 255) ? sum++ : 0;
	}
	s = ft_move(s);
	if (*s == '\0' && sum == 3 && (c == 'C' || c == 'F'))
		return (1);
	return (0);
}

int		chek_tekst(char *s)
{
	if (*s == 'N')
		if (*(s + 1) == 'O')
			return (valid_strucs(s + 2) * 2);
	if (*s == 'S')
		if (*(s + 1) == 'O')
			return (valid_strucs(s + 2) * 3);
	if (*s == 'W')
		if (*(s + 1) == 'E')
			return (valid_strucs(s + 2) * 4);
	if (*s == 'E')
		if (*(s + 1) == 'A')
			return (valid_strucs(s + 2) * 5);
	if ((*s == 'S') && (*(s + 1) == ' ' ||
	((*(s + 1) >= '2' && (*(s + 1) <= '9')) ||
	(*(s + 1) == 'a') || (*(s + 1) == 'b'))))
		return (valid_strucs(s + 1) * 6);
	return (0);
}

int		chek_map(int fd, int r_map, t_all *mall)
{
	int		i;
	int		fl;
	char	**mal;
	char	*line;
	int		m;

	i = 0;
	if (!(mal = (char **)malloc(sizeof(char *) * (r_map + 1))))
		return (0);
	while ((m = get_next_line(fd, &line)) >= 0)
	{
		(strlen(line) > 0) ? fl = 1 : 0;
		(strlen(line) > 0) ? mal[i++] = line : free(line);
		if (m == 0)
		{
			mal[i] = NULL;
			break ;
		}
		if (fl == 1 && strlen(line) == 0)
			return (0);
	}
	fl = chek_map_musor(mal, mall) * chek_map_border(mal, r_map)
	* chek_map_play(mal);
	free_mas(&mal);
	return (fl);
}
