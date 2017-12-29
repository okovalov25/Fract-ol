/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okovalov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 12:17:38 by okovalov          #+#    #+#             */
/*   Updated: 2017/03/20 16:05:11 by okovalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		runonimg(t_prm *param)
{
	int		x;
	int		y;

	y = -1;
	while (++y <= H)
	{
		x = -1;
		while (++x <= W)
		{
			if (param->frctl == 49 || param->frctl == 53)
				fract1(x, y, param);
			else if (param->frctl == 50)
				fract2(x, y, param);
			else if (param->frctl == 52)
				fract4(x, y, param);
			else if (param->frctl == 51)
				fract3(x, y, param);
		}
	}
	mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
	mlx_hook(param->win, 2, 5, key, param);
	mlx_hook(param->win, 17, 1L << 17, exit_x, param);
	mlx_hook(param->win, 6, 0, mousejul, param);
	mlx_mouse_hook(param->win, mouse, param);
	mlx_loop(param->mlx);
}

void		wnd(t_prm *param)
{
	param->mlx = mlx_init();
	param->win = mlx_new_window(param->mlx, W, H, "fract'ol");
	param->img = mlx_new_image(param->mlx, W, H);
	param->line = mlx_get_data_addr(param->img,
							&param->bpp, &param->sl, &param->nd);
	runonimg(param);
}

int			validd(int argc, char **argv)
{
	if ((argc == 2 && ((argv[1][0] != 49 && argv[1][0] != 50
				&& argv[1][0] != 51 && argv[1][0] != 52 && argv[1][0] != 53)
				|| argv[1][1])) || argc > 3 || argc < 2)
	{
		write(1, "Usage : ./fractol <fractalnumber>\n", 34);
		write(1, "1)Julia 2)Mandelbrot 3)Burning ship 4)Newton 5)Dragon\n", 54);
		return (0);
	}
	else if (argc == 3 && (((argv[1][0] != 49 && argv[1][0] != 50
				&& argv[1][0] != 51 && argv[1][0] != 52 && argv[1][0] != 53)
				|| argv[1][1]) || ((argv[2][0] != 49 && argv[2][0] != 50
				&& argv[2][0] != 51 && argv[2][0] != 52 && argv[2][0] != 53)
				|| argv[2][1])))
	{
		write(1, "Usage : ./fractol <fractalnumber> <fractalnumber>\n", 50);
		write(1, "1)Julia 2)Mandelbrot 3)Burning ship 4)Newton 5)Dragon\n", 54);
		return (0);
	}
	return (1);
}

int			main(int argc, char **argv)
{
	t_prm	*param;
	pid_t	id;

	param = (t_prm*)malloc(sizeof(t_prm));
	if (!validd(argc, argv))
		return (0);
	if (argc == 3)
	{
		id = fork();
		if (id != 0)
			param->frctl = argv[1][0];
		else if (id == 0)
			param->frctl = argv[2][0];
	}
	else
		param->frctl = argv[1][0];
	parametr(param);
	wnd(param);
	return (1);
}
