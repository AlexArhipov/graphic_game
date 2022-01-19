/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 19:38:50 by avivien           #+#    #+#             */
/*   Updated: 2020/12/25 19:38:53 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*ft_move(char *s)
{
	while (*s == ' ' && *s)
		s++;
	return (s);
}

int		ft_lens(char *s)
{
	int i;

	i = 0;
	while (*s && *s != ' ')
	{
		i++;
		s++;
	}
	return (i);
}

void	free_mas(char ***mal)
{
	int i;

	i = 0;
	while ((*mal)[i])
	{
		free((*mal)[i]);
		i++;
	}
	free(*mal);
}

int		caunt_map(char *name)
{
	int		i;
	int		fd;
	int		m;
	char	*line;

	i = 0;
	fd = open(name, O_RDONLY);
	while ((m = get_next_line(fd, &line)) >= 0)
	{
		if (strlen(line) > 0)
			i++;
		free(line);
		if (m == 0)
			break ;
	}
	close(fd);
	return (i - ST);
}

int		cheker_valid_map_2(char *line, int val[9])
{
	line = ft_move(line);
	(*line == 'R') ? val[1] = chek_ras(line) : 0;
	(*line == 'N' || *line == 'S' || *line == 'W' ||
	*line == 'E') ? val[chek_tekst(line)] = 1 : 0;
	(*line == 'F' && *(line + 1) == ' ') ? val[0] = chek_color(line) : 0;
	(*line == 'C' && *(line + 1) == ' ') ? val[7] = chek_color(line) : 0;
	return (1);
}
