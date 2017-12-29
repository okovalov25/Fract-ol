/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okovalov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 15:08:32 by okovalov          #+#    #+#             */
/*   Updated: 2017/03/20 14:28:25 by okovalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		fract1(int x, int y, t_prm *param)
{
	double	rp;
	double	ip;
	int		i;

	i = -1;
	rp = (2 * x - W) / (param->zoom * W) + param->sw;
	ip = (2 * y - H) / (param->zoom * H) + param->sh;
	while (++i < MI && (param->zn = rp * rp + ip * ip) < 4)
	{
		param->new_rp = rp;
		param->new_ip = ip;
		rp = pow(param->new_rp, 2) - pow(param->new_ip, 2) + param->old_rp;
		ip = 2 * param->new_rp * param->new_ip + param->old_ip;
	}
	if (i < MI)
	{
		if (param->color == 1)
			pix_color1(param, x, y, i);
		else
			pix_color2(param, x, y, i);
	}
}

void		fract2(int x, int y, t_prm *param)
{
	double	rp;
	double	ip;
	int		i;

	i = -1;
	rp = (2 * x - W) / (param->zoom * W) + param->sw;
	ip = (2 * y - H) / (param->zoom * H) + param->sh;
	param->new_rp = 0;
	param->new_ip = 0;
	while (++i < MI && (param->zn = param->new_rp * param->new_rp
						+ param->new_ip * param->new_ip) < 4)
	{
		param->old_rp = param->new_rp;
		param->old_ip = param->new_ip;
		param->new_rp = param->old_rp * param->old_rp
			- param->old_ip * param->old_ip + rp;
		param->new_ip = 2 * (param->old_rp * param->old_ip) + ip;
	}
	if (i < MI)
	{
		if (param->color == 1)
			pix_color1(param, x, y, i);
		else
			pix_color2(param, x, y, i);
	}
}

void		fract3(int x, int y, t_prm *param)
{
	double	rp;
	double	ip;
	int		i;

	i = -1;
	rp = (2 * x - W) / (param->zoom * W) + param->sw;
	ip = (2 * y - H) / (param->zoom * H) + param->sh;
	param->new_rp = rp;
	param->new_ip = ip;
	while (++i < MI && (param->zn = param->new_rp
						* param->new_rp + param->new_ip * param->new_ip) < 4)
	{
		param->old_ip = param->new_ip;
		param->new_ip = fabs((double)(2 * (param->new_rp
									* param->new_ip) + ip));
		param->new_rp = fabs((double)(param->new_rp * param->new_rp
									- param->old_ip * param->old_ip + rp));
	}
	if (i < MI)
	{
		if (param->color == 1)
			pix_color1(param, x, y, i);
		else
			pix_color2(param, x, y, i);
	}
}

void		fract4(int x, int y, t_prm *param)
{
	double	rp;
	double	ip;
	int		i;
	double	tmp;

	i = -1;
	rp = (2 * x - W) / (param->zoom * W) + param->sw;
	ip = (2 * y - H) / (param->zoom * H) + param->sh;
	tmp = 1.0;
	while (++i < MI && tmp > 0.000001)
	{
		param->old_rp = rp;
		param->old_ip = ip;
		tmp = (rp * rp + ip * ip) * (rp * rp + ip * ip);
		rp = (2 * rp * tmp + rp * rp - ip * ip) / (3.0 * tmp);
		ip = (2 * ip * (tmp - param->old_rp)) / (3.0 * tmp);
		tmp = (rp - param->old_rp) * (rp - param->old_rp)
			+ (ip - param->old_ip) * (ip - param->old_ip);
	}
	if (param->color == 1)
		pix_color2(param, x, y, i);
	else
		pix_color1(param, x, y, i);
}
