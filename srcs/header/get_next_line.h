/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:34:08 by avivien           #+#    #+#             */
/*   Updated: 2020/11/11 12:01:06 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1

# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
int		ft_len1(char *s, int fl);
char	*ft_strjoin1(char *s1, char *s2);
char	*ft_strdup2(char *src);
char	*ft_strdup1(char *src);
int		chek(int i);
#endif
