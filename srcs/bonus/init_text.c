/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 19:14:26 by avivien           #+#    #+#             */
/*   Updated: 2020/12/24 19:14:27 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void		init_texture1(t_all *mall)
{
	MT.icon.t_adr = MFI(MX, "srcs/t/posi.xpm", &MT.icon.w, &MT.icon.h);
	MT.icon.textur = MGA(MT.icon.t_adr, &MT.icon.bpp, &MT.icon.L, &MT.icon.en);
	MT.tek4.t_adr = MFI(MX, "srcs/t/king.xpm", &MT.tek4.w, &MT.tek4.h);
	MT.tek4.textur = MGA(MT.tek4.t_adr, &MT.tek4.bpp, &MT.tek4.L, &MT.tek4.en);
	MT.so1.t_adr = MFI(MX, "srcs/t/w20.xpm", &MT.so1.w, &MT.so1.h);
	MT.so1.textur = MGA(MT.so1.t_adr, &MT.so1.bpp, &MT.so1.line_l, &MT.so1.en);
	MT.no1.t_adr = MFI(MX, "srcs/t/w21.xpm", &MT.no1.w, &MT.no1.h);
	MT.no1.textur = MGA(MT.no1.t_adr, &MT.no1.bpp, &MT.no1.line_l, &MT.no1.en);
	MT.we1.t_adr = MFI(MX, "srcs/t/w22.xpm", &MT.we1.w, &MT.we1.h);
	MT.we1.textur = MGA(MT.we1.t_adr, &MT.we1.bpp, &MT.we1.line_l, &MT.we1.en);
	MT.ea1.t_adr = MFI(MX, "srcs/t/w23.xpm", &MT.ea1.w, &MT.ea1.h);
	MT.ea1.textur = MGA(MT.ea1.t_adr, &MT.ea1.bpp, &MT.ea1.line_l, &MT.ea1.en);
	MT.c1.t_adr = MFI(MX, "srcs/t/p22.xpm", &MT.c1.w, &MT.c1.h);
	MT.c1.textur = MGA(MT.c1.t_adr, &MT.c1.bpp, &MT.c1.line_l, &MT.c1.en);
	MT.f1.t_adr = MFI(MX, "srcs/t/f22.xpm", &MT.f1.w, &MT.f1.h);
	MT.f1.textur = MGA(MT.f1.t_adr, &MT.f1.bpp, &MT.f1.line_l, &MT.f1.en);
	MT.so.t_adr = MFI(MX, mall->win.t_so, &MT.so.w, &MT.so.h);
	MT.so.textur = MGA(MT.so.t_adr, &MT.so.bpp, &MT.so.line_l, &MT.so.en);
	MT.no.t_adr = MFI(MX, mall->win.t_no, &MT.no.w, &MT.no.h);
	MT.no.textur = MGA(MT.no.t_adr, &MT.no.bpp, &MT.no.line_l, &MT.no.en);
	MT.we.t_adr = MFI(MX, mall->win.t_we, &MT.we.w, &MT.we.h);
	MT.we.textur = MGA(MT.we.t_adr, &MT.we.bpp, &MT.we.line_l, &MT.we.en);
	MT.ea.t_adr = MFI(MX, mall->win.t_ea, &MT.ea.w, &MT.ea.h);
	MT.ea.textur = MGA(MT.ea.t_adr, &MT.ea.bpp, &MT.ea.line_l, &MT.ea.en);
}

static void		init_texture2(t_all *mall)
{
	MT.d1.t_adr = MFI(MX, "srcs/t/d1.xpm", &MT.d1.w, &MT.d1.h);
	MT.d1.textur = MGA(MT.d1.t_adr, &MT.d1.bpp, &MT.d1.line_l, &MT.d1.en);
	MT.d2.t_adr = MFI(MX, "srcs/t/d2.xpm", &MT.d2.w, &MT.d2.h);
	MT.d2.textur = MGA(MT.d2.t_adr, &MT.d2.bpp, &MT.d2.line_l, &MT.d2.en);
	MT.d3.t_adr = MFI(MX, "srcs/t/d3.xpm", &MT.d3.w, &MT.d3.h);
	MT.d3.textur = MGA(MT.d3.t_adr, &MT.d3.bpp, &MT.d3.line_l, &MT.d3.en);
	MT.d4.t_adr = MFI(MX, "srcs/t/d4.xpm", &MT.d4.w, &MT.d4.h);
	MT.d4.textur = MGA(MT.d4.t_adr, &MT.d4.bpp, &MT.d4.line_l, &MT.d4.en);
	MT.d5.t_adr = MFI(MX, "srcs/t/d5.xpm", &MT.d5.w, &MT.d5.h);
	MT.d5.textur = MGA(MT.d5.t_adr, &MT.d5.bpp, &MT.d5.line_l, &MT.d5.en);
	MT.d6.t_adr = MFI(MX, "srcs/t/d6.xpm", &MT.d6.w, &MT.d6.h);
	MT.d6.textur = MGA(MT.d6.t_adr, &MT.d6.bpp, &MT.d6.line_l, &MT.d6.en);
	MT.d7.t_adr = MFI(MX, "srcs/t/d7.xpm", &MT.d7.w, &MT.d7.h);
	MT.d7.textur = MGA(MT.d7.t_adr, &MT.d7.bpp, &MT.d7.line_l, &MT.d7.en);
	MT.d8.t_adr = MFI(MX, "srcs/t/d8.xpm", &MT.d8.w, &MT.d8.h);
	MT.d8.textur = MGA(MT.d8.t_adr, &MT.d8.bpp, &MT.d8.line_l, &MT.d8.en);
	MT.d9.t_adr = MFI(MX, "srcs/t/d9.xpm", &MT.d9.w, &MT.d9.h);
	MT.d9.textur = MGA(MT.d9.t_adr, &MT.d9.bpp, &MT.d9.line_l, &MT.d9.en);
	MT.d10.t_adr = MFI(MX, "srcs/t/d10.xpm", &MT.d10.w, &MT.d10.h);
	MT.d10.textur = MGA(MT.d10.t_adr, &MT.d10.bpp, &MT.d10.line_l, &MT.d10.en);
	MT.d11.t_adr = MFI(MX, "srcs/t/d11.xpm", &MT.d11.w, &MT.d11.h);
	MT.d11.textur = MGA(MT.d11.t_adr, &MT.d11.bpp, &MT.d11.line_l, &MT.d11.en);
	MT.d12.t_adr = MFI(MX, "srcs/t/d12.xpm", &MT.d12.w, &MT.d12.h);
	MT.d12.textur = MGA(MT.d12.t_adr, &MT.d12.bpp, &MT.d12.line_l, &MT.d12.en);
}

static void		init_texture3(t_all *mall)
{
	MT.d13.t_adr = MFI(MX, "srcs/t/d13.xpm", &MT.d13.w, &MT.d13.h);
	MT.d13.textur = MGA(MT.d13.t_adr, &MT.d13.bpp, &MT.d13.line_l, &MT.d13.en);
	MT.d14.t_adr = MFI(MX, "srcs/t/d14.xpm", &MT.d14.w, &MT.d14.h);
	MT.d14.textur = MGA(MT.d14.t_adr, &MT.d14.bpp, &MT.d14.line_l, &MT.d14.en);
	MT.d15.t_adr = MFI(MX, "srcs/t/d15.xpm", &MT.d15.w, &MT.d15.h);
	MT.d15.textur = MGA(MT.d15.t_adr, &MT.d15.bpp, &MT.d15.line_l, &MT.d15.en);
	MT.d16.t_adr = MFI(MX, "srcs/t/d16.xpm", &MT.d16.w, &MT.d16.h);
	MT.d16.textur = MGA(MT.d16.t_adr, &MT.d16.bpp, &MT.d16.line_l, &MT.d16.en);
	MT.d17.t_adr = MFI(MX, "srcs/t/d17.xpm", &MT.d17.w, &MT.d17.h);
	MT.d17.textur = MGA(MT.d17.t_adr, &MT.d17.bpp, &MT.d17.line_l, &MT.d17.en);
	MT.d18.t_adr = MFI(MX, "srcs/t/d18.xpm", &MT.d18.w, &MT.d18.h);
	MT.d18.textur = MGA(MT.d18.t_adr, &MT.d18.bpp, &MT.d18.line_l, &MT.d18.en);
	MT.pl.t_adr = MFI(MX, "srcs/t/redpl.xpm", &MT.pl.w, &MT.pl.h);
	MT.pl.textur = MGA(MT.pl.t_adr, &MT.pl.bpp, &MT.pl.line_l, &MT.pl.en);
	MT.plf.t_adr = MFI(MX, "srcs/t/redplf.xpm", &MT.plf.w, &MT.plf.h);
	MT.plf.textur = MGA(MT.plf.t_adr, &MT.plf.bpp, &MT.plf.line_l, &MT.plf.en);
	MT.pr.t_adr = MFI(MX, "srcs/t/redpr.xpm", &MT.pr.w, &MT.pr.h);
	MT.pr.textur = MGA(MT.pr.t_adr, &MT.pr.bpp, &MT.pr.line_l, &MT.pr.en);
	MT.prf.t_adr = MFI(MX, "srcs/t/redprf.xpm", &MT.prf.w, &MT.prf.h);
	MT.prf.textur = MGA(MT.prf.t_adr, &MT.prf.bpp, &MT.prf.line_l, &MT.prf.en);
	MT.c.t_adr = MFI(MX, "srcs/t/sky8.xpm", &MT.c.w, &MT.c.h);
	MT.c.textur = MGA(MT.c.t_adr, &MT.c.bpp, &MT.c.line_l, &MT.c.en);
	MT.f.t_adr = MFI(MX, "srcs/t/gras2.xpm", &MT.f.w, &MT.f.h);
	MT.f.textur = MGA(MT.f.t_adr, &MT.f.bpp, &MT.f.line_l, &MT.f.en);
}

static void		init_texture4(t_all *mall)
{
	MT.mj.t_adr = MFI(MX, "srcs/t/mj.xpm", &MT.mj.w, &MT.mj.h);
	MT.mj.textur = MGA(MT.mj.t_adr, &MT.mj.bpp, &MT.mj.line_l, &MT.mj.en);
	MT.m0.t_adr = MFI(MX, "srcs/t/m0.xpm", &MT.m0.w, &MT.m0.h);
	MT.m0.textur = MGA(MT.m0.t_adr, &MT.m0.bpp, &MT.m0.line_l, &MT.m0.en);
	MT.mp1.t_adr = MFI(MX, "srcs/t/m+1.xpm", &MT.mp1.w, &MT.mp1.h);
	MT.mp1.textur = MGA(MT.mp1.t_adr, &MT.mp1.bpp, &MT.mp1.line_l, &MT.mp1.en);
	MT.mm1.t_adr = MFI(MX, "srcs/t/m-1.xpm", &MT.mm1.w, &MT.mm1.h);
	MT.mm1.textur = MGA(MT.mm1.t_adr, &MT.mm1.bpp, &MT.mm1.L, &MT.mm1.en);
	MT.mlm1.t_adr = MFI(MX, "srcs/t/ml-1.xpm", &MT.mlm1.w, &MT.mlm1.h);
	MT.mlm1.textur = MGA(MT.mlm1.t_adr, &MT.mlm1.bpp, &MT.mlm1.L, &MT.mlm1.en);
	MT.mlp1.t_adr = MFI(MX, "srcs/t/ml+1.xpm", &MT.mlp1.w, &MT.mlp1.h);
	MT.mlp1.textur = MGA(MT.mlp1.t_adr, &MT.mlp1.bpp, &MT.mlp1.L, &MT.mlp1.en);
	MT.ml0.t_adr = MFI(MX, "srcs/t/ml0.xpm", &MT.ml0.w, &MT.ml0.h);
	MT.ml0.textur = MGA(MT.ml0.t_adr, &MT.ml0.bpp, &MT.ml0.L, &MT.ml0.en);
	MT.mrm1.t_adr = MFI(MX, "srcs/t/mr-1.xpm", &MT.mrm1.w, &MT.mrm1.h);
	MT.mrm1.textur = MGA(MT.mrm1.t_adr, &MT.mrm1.bpp, &MT.mrm1.L, &MT.mrm1.en);
	MT.mrp1.t_adr = MFI(MX, "srcs/t/mr+1.xpm", &MT.mrp1.w, &MT.mrp1.h);
	MT.mrp1.textur = MGA(MT.mrp1.t_adr, &MT.mrp1.bpp, &MT.mrp1.L, &MT.mrp1.en);
	MT.mr0.t_adr = MFI(MX, "srcs/t/mr0.xpm", &MT.mr0.w, &MT.mr0.h);
	MT.mr0.textur = MGA(MT.mr0.t_adr, &MT.mr0.bpp, &MT.mr0.L, &MT.mr0.en);
	MT.s.t_adr = MFI(MX, "srcs/t/o1.xpm", &MT.s.w, &MT.s.h);
	MT.s.textur = MGA(MT.s.t_adr, &MT.s.bpp, &MT.s.line_l, &MT.s.en);
	MT.mde.t_adr = MFI(MX, "srcs/t/mde.xpm", &MT.mde.w, &MT.mde.h);
	MT.mde.textur = MGA(MT.mde.t_adr, &MT.mde.bpp, &MT.mde.line_l, &MT.mde.en);
}

void			init_texture(t_all *mall)
{
	init_texture1(mall);
	init_texture2(mall);
	init_texture3(mall);
	init_texture4(mall);
	init_texture6(mall);
	init_texture7(mall);
	MT.csec1.t_adr = MFI(MX, "srcs/t/jso1.xpm", &MT.csec1.w, &MT.csec1.h);
	MT.csec1.textur = MGA(MT.csec1.t_adr, &MT.csec1.bpp,
	&MT.csec1.line_l, &MT.csec1.en);
	MT.p1.t_adr = MFI(MX, "srcs/t/p1.xpm", &MT.p1.w, &MT.p1.h);
	MT.p1.textur = MGA(MT.p1.t_adr, &MT.p1.bpp, &MT.p1.line_l, &MT.p1.en);
	MT.p2.t_adr = MFI(MX, "srcs/t/p2.xpm", &MT.p2.w, &MT.p2.h);
	MT.p2.textur = MGA(MT.p2.t_adr, &MT.p2.bpp, &MT.p2.line_l, &MT.p2.en);
	MT.l.t_adr = MFI(MX, "srcs/t/l1.xpm", &MT.l.w, &MT.l.h);
	MT.l.textur = MGA(MT.l.t_adr, &MT.l.bpp, &MT.l.line_l, &MT.l.en);
	MT.bstone.t_adr = MFI(MX, "srcs/t/stone.xpm",
	&MT.bstone.w, &MT.bstone.h);
	MT.bstone.textur = MGA(MT.bstone.t_adr, &MT.bstone.bpp,
	&MT.bstone.L, &MT.bstone.en);
	MT.sf1.t_adr = MFI(MX, "srcs/t/sel1.xpm", &MT.sf1.w, &MT.sf1.h);
	MT.sf1.textur = MGA(MT.sf1.t_adr, &MT.sf1.bpp, &MT.sf1.line_l, &MT.sf1.en);
	MT.sf2.t_adr = MFI(MX, "srcs/t/sel2.xpm", &MT.sf2.w, &MT.sf2.h);
	MT.sf2.textur = MGA(MT.sf2.t_adr, &MT.sf2.bpp, &MT.sf2.line_l, &MT.sf2.en);
	MT.sf3.t_adr = MFI(MX, "srcs/t/sel3.xpm", &MT.sf3.w, &MT.sf3.h);
	MT.sf3.textur = MGA(MT.sf3.t_adr, &MT.sf3.bpp, &MT.sf3.line_l, &MT.sf3.en);
}
