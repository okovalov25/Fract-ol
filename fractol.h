/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okovalov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 12:18:37 by okovalov          #+#    #+#             */
/*   Updated: 2017/03/20 16:14:20 by okovalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include "libft/libft.h"
# include <stdio.h>
# include <math.h>

# define W 700
# define H 700
# define MI 100

typedef struct	s_allparm
{
	void				*mlx;
	void				*win;
	void				*img;
	int					bpp;
	int					sl;
	int					nd;
	char				*line;
	double				old_rp;
	double				old_ip;
	double				new_rp;
	double				new_ip;
	double				zoom;
	double				sw;
	double				sh;
	double				zn;
	int					color;
	char				frctl;
}				t_prm;

int				exit_x(void *par);
int				key(int keycode, t_prm *param);
int				mousejul(int x, int y, t_prm *param);
int				mouse(int button, int x, int y, t_prm *param);
void			fract1(int x, int y, t_prm *param);
void			fract2(int x, int y, t_prm *param);
void			fract3(int x, int y, t_prm *param);
void			fract4(int x, int y, t_prm *param);
void			pix_color1(t_prm *param, int x, int y, int i);
void			pix_color2(t_prm *param, int x, int y, int i);
void			runonimg(t_prm *param);
void			wnd(t_prm *param);
int				validd(int argc, char **argv);
void			parametr(t_prm *param);
int				main(int argc, char **argv);

#endif
