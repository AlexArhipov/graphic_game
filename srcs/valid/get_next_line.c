/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 21:26:15 by avivien           #+#    #+#             */
/*   Updated: 2020/11/11 12:01:43 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	*buff;
	char		bufdo[chek(BUFFER_SIZE) + 1];
	int			n;

	n = 1;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (-1);
	while (ft_len1(buff, 1) == 0 && n != 0)
	{
		if ((n = read(fd, bufdo, BUFFER_SIZE)) < 0)
			return (-1);
		bufdo[n] = '\0';
		buff = ft_strjoin1(buff, bufdo);
	}
	if (!(*line = ft_strdup2(buff)))
		return (-1);
	buff = ft_strdup1(buff);
	return (n ? 1 : 0);
}
