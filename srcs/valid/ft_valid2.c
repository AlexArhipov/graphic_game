/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 19:40:57 by avivien           #+#    #+#             */
/*   Updated: 2020/12/25 19:40:59 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void		chek_map_musor1(char c, t_all *mall, int i, int j)
{
	if (c == 'T')
	{
		mall->plr.tx = j;
		mall->plr.ty = i;
	}
}

int				chek_map_musor(char **map, t_all *mall)
{
	int i;
	int j;
	int val;

	i = -1;
	val = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (M != '0' && M != '1' && M != '2' && M == '3' && M == '4' &&
			M != '5' && M != '6' && M != '7' && M != '8' && M != '8' &&
			M != '9' && M != ' ' && M != 'M' && M != 'G' && M != 'I' &&
			M != 'F' && M != 'Q' && M != 'P' && M != 'K')
				return (0);
			(M == 'S' || M == 'N' || M == 'W' || M == 'E') ? val++ : 0;
			(M == '2' || M == '3' || M == '6' || M == '7' || M == 'O'
			|| M == 'K' || M == 'P' || M == 'M' || M == 'Q') ? mall->cas++ : 0;
			chek_map_musor1(M, mall, i, j);
		}
	}
	if (val != 1)
		return (0);
	return (1);
}

int				chek_map_border(char **map, int r_map)
{
	int i;
	int j;

	j = -1;
	while (map[0][++j])
		if (map[0][j] == '0' || map[0][j] == 'S' || map[0][j] == 'N' ||
		map[0][j] == 'W' || map[0][j] == 'E' || map[0][j] == '2')
			return (0);
	i = -1;
	while (map[++i][j])
	{
		j = 0;
		while (M == ' ' && M)
			j++;
		if (M == '0' || M == 'S' || M == 'N' || M == 'W' || M == 'E')
			return (0);
	}
	j = -1;
	i = r_map - 1;
	while (map[i][++j])
		if (M == '0' || M == 'S' || M == 'N' || M == 'W'
		|| M == 'E' || M == '2')
			return (0);
	return (1);
}

int				chek_map_play(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[++i + 1])
	{
		j = 0;
		while (map[i][++j])
		{
			if (M == '0' || M == 'S' || M == 'N' ||
			M == 'W' || M == 'E' || M == '2')
				if ((map[i - 1][j] == ' ' || map[i - 1][j] == '\0') ||
					(map[i + 1][j] == ' ' || map[i + 1][j] == '\0') ||
					(map[i][j - 1] == ' ' || map[i][j - 1] == '\0') ||
					(map[i][j + 1] == ' ' || map[i][j + 1] == '\0') ||
					(map[i + 1][j + 1] == ' ' || map[i + 1][j + 1] == '\0') ||
					(map[i - 1][j - 1] == ' ' || map[i - 1][j - 1] == '\0') ||
					(map[i + 1][j - 1] == ' ' || map[i + 1][j - 1] == '\0') ||
					(map[i - 1][j + 1] == ' ' || map[i - 1][j + 1] == '\0') ||
					j > (int)strlen(map[i + 1]) || j > (int)strlen(map[i - 1]))
					return (0);
		}
	}
	return (1);
}

int				cheker_valid_map(char *name, int r_map, t_all *mall)
{
	int		fd;
	char	*line;
	int		v[ST + 1];
	int		m;
	int		count;

	count = ST;
	fd = 0;
	while (fd < 10)
		v[fd++] = 0;
	fd = open(name, O_RDONLY);
	while (count && (m = get_next_line(fd, &line)) >= 0)
	{
		if (strlen(line) > 1)
			count -= cheker_valid_map_2(line, v);
		free(line);
		if (m == 0)
			break ;
	}
	v[ST] = chek_map(fd, r_map, mall);
	close(fd);
	if (v[0] == 1 && v[1] == 1 && v[2] == 1 && v[3] == 1 && v[4] == 1
		&& v[5] == 1 && v[6] == 1 && v[7] == 1 && v[ST] == 1 && m > 0)
		return (1);
	return (0);
}
