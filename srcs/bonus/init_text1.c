/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_text1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 19:42:36 by avivien           #+#    #+#             */
/*   Updated: 2020/12/24 19:42:37 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_texture6(t_all *mall)
{
	MT.mzm1.t_adr = MFI(MX, "srcs/t/mz-1.xpm", &MT.mzm1.w, &MT.mzm1.h);
	MT.mzm1.textur = MGA(MT.mzm1.t_adr, &MT.mzm1.bpp, &MT.mzm1.L, &MT.mzm1.en);
	MT.mzp1.t_adr = MFI(MX, "srcs/t/mz+1.xpm", &MT.mzp1.w, &MT.mzp1.h);
	MT.mzp1.textur = MGA(MT.mzp1.t_adr, &MT.mzp1.bpp, &MT.mzp1.L, &MT.mzp1.en);
	MT.mz0.t_adr = MFI(MX, "srcs/t/mz0.xpm", &MT.mz0.w, &MT.mz0.h);
	MT.mz0.textur = MGA(MT.mz0.t_adr, &MT.mz0.bpp, &MT.mz0.line_l, &MT.mz0.en);
	MT.ma1.t_adr = MFI(MX, "srcs/t/ma1.xpm", &MT.ma1.w, &MT.ma1.h);
	MT.ma1.textur = MGA(MT.ma1.t_adr, &MT.ma1.bpp, &MT.ma1.line_l, &MT.ma1.en);
	MT.ma2.t_adr = MFI(MX, "srcs/t/ma2.xpm", &MT.ma2.w, &MT.ma2.h);
	MT.ma2.textur = MGA(MT.ma2.t_adr, &MT.ma2.bpp, &MT.ma2.line_l, &MT.ma2.en);
	MT.ma3.t_adr = MFI(MX, "srcs/t/ma3.xpm", &MT.ma3.w, &MT.ma3.h);
	MT.ma3.textur = MGA(MT.ma3.t_adr, &MT.ma3.bpp, &MT.ma3.line_l, &MT.ma3.en);
	MT.ma4.t_adr = MFI(MX, "srcs/t/ma4.xpm", &MT.ma4.w, &MT.ma4.h);
	MT.ma4.textur = MGA(MT.ma4.t_adr, &MT.ma4.bpp, &MT.ma4.line_l, &MT.ma4.en);
	MT.ma5.t_adr = MFI(MX, "srcs/t/ma5.xpm", &MT.ma5.w, &MT.ma5.h);
	MT.ma5.textur = MGA(MT.ma5.t_adr, &MT.ma5.bpp, &MT.ma5.line_l, &MT.ma5.en);
	MT.key.t_adr = MFI(MX, "srcs/t/pos.xpm", &MT.key.w, &MT.key.h);
	MT.key.textur = MGA(MT.key.t_adr, &MT.key.bpp, &MT.key.line_l, &MT.key.en);
	MT.tel.t_adr = MFI(MX, "srcs/t/guns.xpm", &MT.tel.w, &MT.tel.h);
	MT.tel.textur = MGA(MT.tel.t_adr, &MT.tel.bpp, &MT.tel.line_l, &MT.tel.en);
	MT.q.t_adr = MFI(MX, "srcs/t/kor.xpm", &MT.q.w, &MT.q.h);
	MT.q.textur = MGA(MT.q.t_adr, &MT.q.bpp, &MT.q.line_l, &MT.q.en);
}

void	init_texture7(t_all *mall)
{
	MT.g1.t_adr = MFI(MX, "srcs/t/1p.xpm", &MT.g1.w, &MT.g1.h);
	MT.g1.textur = MGA(MT.g1.t_adr, &MT.g1.bpp, &MT.g1.line_l, &MT.g1.en);
	MT.g2.t_adr = MFI(MX, "srcs/t/2p.xpm", &MT.g2.w, &MT.g2.h);
	MT.g2.textur = MGA(MT.g2.t_adr, &MT.g2.bpp, &MT.g2.line_l, &MT.g2.en);
	MT.g3.t_adr = MFI(MX, "srcs/t/3p.xpm", &MT.g3.w, &MT.g3.h);
	MT.g3.textur = MGA(MT.g3.t_adr, &MT.g3.bpp, &MT.g3.line_l, &MT.g3.en);
	MT.g4.t_adr = MFI(MX, "srcs/t/4p.xpm", &MT.g4.w, &MT.g4.h);
	MT.g4.textur = MGA(MT.g4.t_adr, &MT.g4.bpp, &MT.g4.line_l, &MT.g4.en);
	MT.g5.t_adr = MFI(MX, "srcs/t/5p.xpm", &MT.g5.w, &MT.g5.h);
	MT.g5.textur = MGA(MT.g5.t_adr, &MT.g5.bpp, &MT.g5.line_l, &MT.g5.en);
	MT.g6.t_adr = MFI(MX, "srcs/t/6p.xpm", &MT.g6.w, &MT.g6.h);
	MT.g6.textur = MGA(MT.g6.t_adr, &MT.g6.bpp, &MT.g6.line_l, &MT.g6.en);
	MT.g7.t_adr = MFI(MX, "srcs/t/7p.xpm", &MT.g7.w, &MT.g7.h);
	MT.g7.textur = MGA(MT.g7.t_adr, &MT.g7.bpp, &MT.g7.line_l, &MT.g7.en);
	MT.g8.t_adr = MFI(MX, "srcs/t/8p.xpm", &MT.g8.w, &MT.g8.h);
	MT.g8.textur = MGA(MT.g8.t_adr, &MT.g8.bpp, &MT.g8.line_l, &MT.g8.en);
}
