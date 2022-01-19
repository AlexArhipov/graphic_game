/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:55:12 by avivien           #+#    #+#             */
/*   Updated: 2020/11/11 12:03:26 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_len1(char *s, int fl)
{
	int i;

	i = 0;
	if (s == 0)
		return (0);
	while (s[i])
	{
		if (fl == 1 || fl == 3)
			if (s[i] == 10)
			{
				if (fl == 1)
					return (i + 1);
				return (i);
			}
		i++;
	}
	if (fl == 2 || fl == 3)
		return (i);
	return (0);
}

char	*ft_strdup2(char *src)
{
	char	*mal;
	int		i;

	if (src == 0)
		return (0);
	i = 0;
	while (src[i] && src[i] != '\n')
		i++;
	if (!(mal = malloc(i + 1 * sizeof(char))))
	{
		free(src);
		return (0);
	}
	i = 0;
	while (src[i] && src[i] != '\n')
	{
		mal[i] = src[i];
		i++;
	}
	mal[i] = '\0';
	return (mal);
}

char	*ft_strdup1(char *src)
{
	int		i;
	int		j;
	char	*mal;

	if (src == 0)
		return (0);
	i = ft_len1(src, 3);
	if (src[i] == 0)
	{
		free(src);
		return (0);
	}
	if (!(mal = malloc((ft_len1(src, 2) - i) * sizeof(char))))
	{
		free(src);
		return (0);
	}
	j = 0;
	i++;
	while (src[i])
		mal[j++] = src[i++];
	mal[j] = '\0';
	free(src);
	return (mal);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	int		j;
	char	*mal;
	int		i;
	char	*st;
	char	*st1;

	i = 0;
	j = 0;
	if (s1)
		i = ft_len1(s1, 2);
	if (!(mal = malloc((i + ft_len1(s2, 2) + 1) * sizeof(char))))
	{
		free(s1);
		return (0);
	}
	st = mal;
	st1 = s1;
	if (s1)
		while (*s1)
			*mal++ = *s1++;
	while (*s2)
		*mal++ = *s2++;
	*mal = '\0';
	free(st1);
	return (st);
}

int		chek(int i)
{
	if (i < 0)
		return (-1);
	if (i > 10000000)
		i = 10000000;
	return (i);
}
