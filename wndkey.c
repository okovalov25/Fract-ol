/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wndkey.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okovalov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 14:17:52 by okovalov          #+#    #+#             */
/*   Updated: 2017/03/20 15:44:52 by okovalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			exit_x(void *par)
{
	par = NULL;
	exit(1);
	return (0);
}

int			key(int keycode, t_prm *param)
{
	if (keycode == 53)
		exit(1);
	else if (keycode == 123)
		param->sw += 0.1 / param->zoom;
	else if (keycode == 124)
		param->sw -= 0.1 / param->zoom;
	else if (keycode == 125)
		param->sh -= 0.1 / param->zoom;
	else if (keycode == 126)
		param->sh += 0.1 / param->zoom;
	else if (keycode == 18)
		param->color = 1;
	else if (keycode == 19)
		param->color = 2;
	mlx_destroy_image(param->mlx, param->img);
	param->img = mlx_new_image(param->mlx, W, H);
	param->line = mlx_get_data_addr(param->img,
							&param->bpp, &param->sl, &param->nd);
	runonimg(param);
	return (1);
}

int			mousejul(int x, int y, t_prm *param)
{
	if (x >= 0 && x <= W && y >= 0 && y <= H)
	{
		param->old_ip = x * (2.0 / W) - 1.0;
		param->old_rp = y * (2.0 / H) - 1.0;
	}
	mlx_destroy_image(param->mlx, param->img);
	param->img = mlx_new_image(param->mlx, W, H);
	param->line = mlx_get_data_addr(param->img,
							&param->bpp, &param->sl, &param->nd);
	runonimg(param);
	return (1);
}

int			mouse(int button, int x, int y, t_prm *param)
{
	if (button == 4)
	{
		param->zoom *= 1.2;
		param->sw += (x - W / 2) / (W * 2.5) / param->zoom;
		param->sh += (y - H / 2) / (H * 2.5) / param->zoom;
	}
	else if (button == 5)
	{
		param->zoom /= 1.2;
		param->sw -= (x - W / 2) / (W * 2.5) / param->zoom;
		param->sh -= (y - H / 2) / (H * 2.5) / param->zoom;
	}
	mlx_destroy_image(param->mlx, param->img);
	param->img = mlx_new_image(param->mlx, W, H);
	param->line = mlx_get_data_addr(param->img,
							&param->bpp, &param->sl, &param->nd);
	runonimg(param);
	return (1);
}
