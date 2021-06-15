/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 21:40:05 by avivien           #+#    #+#             */
/*   Updated: 2020/12/24 21:40:09 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_VALID_H
# define CUB_VALID_H

int			valid_strucs(char *s);
int			chek_ras(char *s);
int			chek_color(char *s);
int			chek_tekst(char *s);
int			chek_map(int fd, int r_map, t_all *mall);
int			cheker_valid_map_2(char *line, int val[9]);
int			chek_map_musor(char **map, t_all *mall);
int			chek_map_border(char **map, int r_map);
int			chek_map_play(char **map);
int			cheker_valid_map(char *name, int r_map, t_all *mall);
char		*read_strucs(char *s);
void		read_color_c(char *s, t_all *mall);
void		read_color_f(char *s, t_all *mall);
void		read_valid_map_2(char *line, t_all *mall);
t_all		*ft_read_file(int fd, t_all *mall, int r_map, int i);
char		*ft_move(char *s);
int			ft_lens(char *s);
void		free_mas(char ***fmal);
int			caunt_map(char *name);
void		find_play(t_all *mall);
#endif
