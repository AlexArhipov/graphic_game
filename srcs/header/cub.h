/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 21:39:29 by avivien           #+#    #+#             */
/*   Updated: 2020/12/24 21:39:31 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_CUB_H
# define CUB_CUB_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# include <signal.h>
# include <unistd.h>
# include <sys/types.h>
# include "hdefine.h"
# include "dstrukt.h"
# include "valid.h"
# include "bonus.h"

void			sort_dist(t_all *mall);
void			caunt_dist(t_all *mall);
void			put_t(t_vtext *text, t_vtext *textm);
void			cas_t(char c, t_vtext *text, t_all *mall, int i);
void			draw_ps(t_all *mall);
int				ft_abs(int i);
void			find_play(t_all *mall);
unsigned int	*pix_color(t_vtext *text);
void			mmp(t_all *mall, int x, int y, int color);
void			opendoor(t_all *mall, int x);
void			drowkey(t_all *mall, t_vtext *text);
void			drowpat(t_all *mall, t_vtext *text);
void			drowpat2(t_all *mall, t_vtext *text);
void			color_tekf(t_all *mall, t_vtext *text);
void			color_tekc(t_all *mall, t_vtext *text);
void			weapenr(t_all *mall, t_vtext *text);
void			weapenl(t_all *mall, t_vtext *text);
void			hud(t_all *mall);
void			shot_gun(t_all *mall);
void			monstr_move(t_all *mall, int c);
void			monstr_look(t_all *mall, int c);
void			armagedon(t_all *mall);
void			findsm(t_all *mall);
void			initmonstr(t_all *mall);
void			init_texture(t_all *mall);
void			draw_line(t_all *mall, t_vtext *text, int x);
double			draw_ray(t_all *mall, int x);
void			ft_draw(t_all *mall);
void			draw_ray_start(t_all *mall, int x);
void			cas_t5(t_vtext *text, t_all *mall, int i);
void			cas_t6(char c, t_vtext *text, t_all *mall);
int				cas_t7(t_vtext *text, t_all *mall, int i);
void			initstr(t_all *mall);
int				mouse(int x, int y, t_all *mall);
int				key_relis(int key, t_all *mall);
int				clicm(int key, int x, int y, t_all *mall);
int				ft_key_press(int key, t_all *mall);
int				render_next_frame(t_all *mall);
void			finish_st(t_all *mall);
int				ft_moves(t_all *mall);
void			move2pr1(t_all *mall);
void			move3if1(t_all *mall);
void			move3if2(t_all *mall);
void			move3if3(t_all *mall);
void			move3if4(t_all *mall);
void			move3if5(t_all *mall);
void			move3if6(t_all *mall);
void			move3if7(t_all *mall);
void			move3if8(t_all *mall);
void			move_asd(t_all *mall);
void			move_sp1(t_all *mall, int i);
void			move_sp2(t_all *mall, int i);
void			rots1(t_all *mall);
void			rots2(t_all *mall);
void			movew(t_all *mall, int i);
void			finish_draw(t_all *mall);
void			baaam(t_all *mall);
void			draw_ray_if2(t_all *mall, int x);
void			write_bmp(t_all *mall);
void			bmp_data(t_all *mall, int size, int fd);

#endif
