/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dstrukt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 21:39:44 by avivien           #+#    #+#             */
/*   Updated: 2020/12/24 21:39:45 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_DSTRUKT_H
# define CUB_DSTRUKT_H

typedef struct			s_ray
{
	double				camerax;
	double				raydirx;
	double				raydiry;
	int					mapx;
	int					mapy;
	double				sidedistx;
	double				sidedisty;
	double				deltadistx;
	double				deltadisty;
	int					stepx;
	int					stepy;
	int					hit;
	int					side;
	double				sh;
	double				mcam;
}						t_ray;

typedef struct			s_win
{
	void				*mlx;
	void				*win;
	void				*img;
	void				*addr;
	int					line_l;
	int					bpp;
	int					en;
	char				*t_no;
	char				*t_so;
	char				*t_we;
	char				*t_ea;
	char				*t_s;
	int					m_up[3];
	int					m_down[3];
	int					r_win[2];
}						t_win;

typedef struct			s_monst
{
	int					hp;
	int					hit;
	int					flook;
	int					ftime;
	int					start;
	int					tatak;
	int					tshag;
	t_ray				ray;

}						t_monst;

typedef struct			s_spite
{
	double				x;
	double				y;
	char				sp;
	double				dist;
	t_monst				mon;
}						t_sprite;

typedef struct			s_vtext
{
	int					line_l;
	int					bpp;
	int					en;
	void				*t_adr;
	void				*textur;
	int					h;
	int					w;
	double				stepx;
	double				stepy;
	int					textx;
	int					texty;
	double				wall;
	double				text_posx;
	double				text_posy;
	int					xs1;
	int					xs2;
	int					ys1;
	int					ys2;
	double				dxs1;
	double				dys1;
	unsigned int		*dst;
}						t_vtext;

typedef struct			s_text
{
	t_vtext				no;
	t_vtext				we;
	t_vtext				so;
	t_vtext				ea;
	t_vtext				s;
	t_vtext				c;
	t_vtext				f;
	t_vtext				no1;
	t_vtext				we1;
	t_vtext				so1;
	t_vtext				ea1;
	t_vtext				s1;
	t_vtext				c1;
	t_vtext				f1;
	t_vtext				pl;
	t_vtext				plf;
	t_vtext				pr;
	t_vtext				prf;
	t_vtext				mj;
	t_vtext				mp1;
	t_vtext				mm1;
	t_vtext				m0;
	t_vtext				ma1;
	t_vtext				ma2;
	t_vtext				ma3;
	t_vtext				ma4;
	t_vtext				ma5;
	t_vtext				mlm1;
	t_vtext				mlp1;
	t_vtext				ml0;
	t_vtext				mrm1;
	t_vtext				mrp1;
	t_vtext				mr0;
	t_vtext				mzm1;
	t_vtext				mzp1;
	t_vtext				mz0;
	t_vtext				mde;
	t_vtext				tel;
	t_vtext				l;
	t_vtext				adoor;
	t_vtext				bstone;
	t_vtext				tek4;
	t_vtext				p1;
	t_vtext				p2;
	t_vtext				key;
	t_vtext				q;
	t_vtext				sf1;
	t_vtext				csec1;
	t_vtext				sf2;
	t_vtext				sf3;
	t_vtext				d1;
	t_vtext				d2;
	t_vtext				d3;
	t_vtext				d4;
	t_vtext				d5;
	t_vtext				d6;
	t_vtext				d7;
	t_vtext				d8;
	t_vtext				d9;
	t_vtext				d10;
	t_vtext				d11;
	t_vtext				d12;
	t_vtext				d13;
	t_vtext				d14;
	t_vtext				d15;
	t_vtext				d16;
	t_vtext				d17;
	t_vtext				d18;
	t_vtext				g1;
	t_vtext				g2;
	t_vtext				g3;
	t_vtext				g4;
	t_vtext				g5;
	t_vtext				g6;
	t_vtext				g7;
	t_vtext				g8;
	t_vtext				icon;
}						t_text;

typedef struct			s_plr
{
	double				rad;
	double				x;
	double				y;
	int					mov[4];
	int					mrot[2];
	int					krot[2];
	double				planex;
	double				planey;
	double				dirx;
	double				diry;
	int					mk;
	int					mcam;
	int					ammo;
	int					bam;
	int					hend;
	int					hp;
	int					wshag;
	int					isk;
	int					key;
	int					tx;
	int					ty;
}						t_plr;

typedef struct			s_sound
{
	int					level;
	int					wstart;
	int					grobnica;
	int					door;
	int					lookmonstr;
	int					logovo;
	int					opend;
	int					closed;
	int					lookkey;
	int					stopcat;
	int					lokkor;
	int					lokcreat;
}						t_sound;

typedef struct			s_all
{
	t_win				win;
	t_text				text;
	t_ray				ray;
	t_plr				plr;
	char				**map;
	t_sprite			*smap;
	int					cas;
	double				*dmas;
	int					tbam;
	int					fails;
	double				tdoor;
	int					sound;
	t_sound				cat;
	int					atakmod;
	int					guikey;
	int					save;
	int					find;
}						t_all;
#endif
