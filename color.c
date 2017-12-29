/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okovalov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 14:15:28 by okovalov          #+#    #+#             */
/*   Updated: 2017/03/20 15:42:03 by okovalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		pix_color1(t_prm *param, int x, int y, int i)
{
	int		j;
	double	ci;

	ci = i + 1 - (log(2) / param->zn) / log(2);
	j = 4 * (W * y + x);
	if (j < H * W * 4)
	{
		param->line[j] = (unsigned char)(sin(0.04 * ci + 4) * 230 + 25);
		param->line[j + 1] = (unsigned char)(sin(0.04 * ci + 2) * 230 + 25);
		param->line[j + 2] = (unsigned char)(sin(0.04 * ci + 1) * 230 + 25);
	}
}

void		pix_color2(t_prm *param, int x, int y, int i)
{
	int		j;

	j = 4 * (W * y + x);
	if (j < H * W * 4)
	{
		param->line[j] = (unsigned char)(sin(0.09 * i + 0) * 128 + 128);
		param->line[j + 1] = (unsigned char)(sin(0.09 * i + 2) * 128 + 128);
		param->line[j + 2] = (unsigned char)(sin(0.09 * i + 4) * 128 + 128);
	}
}

void		parametr(t_prm *param)
{
	param->zoom = 0.7;
	param->sw = 0;
	param->sh = 0;
	if (param->frctl == 50)
	{
		param->sw = -0.7;
		param->sh = 0;
	}
	if (param->frctl == 51)
	{
		param->sw = -0.2;
		param->sh = -0.7;
	}
	if (param->frctl == 49)
	{
		param->old_rp = -0.7;
		param->old_ip = 0.27015;
	}
	if (param->frctl == 53)
	{
		param->old_rp = -0.77469;
		param->old_ip = 0.12424;
	}
	param->color = 1;
}
