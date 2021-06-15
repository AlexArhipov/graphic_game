/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdefine.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 21:39:54 by avivien           #+#    #+#             */
/*   Updated: 2020/12/24 21:39:55 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_HDEFINE_H
# define CUB_HDEFINE_H
# define MT mall->text
# define XX mall->win.r_win[0]
# define YY mall->win.r_win[1]
# define SP 0.1f
# define SM 0.1f
# define L line_l
# define MGA mlx_get_data_addr
# define MFI mlx_xpm_file_to_image
# define MM mall->map[j][i]
# define M map[i][j]
# define ST 8
# define MSR 0.002 / M_PI  * mall->plr.mrot
# define KSR 0.7 / M_PI  * mall->plr.krot
# define MSV 0.02 * mall->plr.mcam
# define X mall->plr.x
# define Y mall->plr.y
# define SDX mall->smap[i].mon.ray.raydirx
# define SDY mall->smap[i].mon.ray.raydiry
# define MRAY mall->map[mall->ray.mapy][mall->ray.mapx]
# define SIY mall->smap[i].y
# define SIX mall->smap[i].x
# define PLANX mall->plr.planex
# define PLANY mall->plr.planey
# define MX mall->win.mlx
# define CL mall->cat.level
# define DL draw_line
# define DIRX mall->plr.dirx
# define DIRY mall->plr.diry
#endif
