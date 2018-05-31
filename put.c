/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:26:23 by vkaznodi          #+#    #+#             */
/*   Updated: 2018/05/29 15:26:24 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		putt(t_mlx *mlx)
{
	if (ft_strcmp(mlx->name, "mandelbrot") == 0)
		mend(mlx);
	else if (ft_strcmp(mlx->name, "julia") == 0)
		juliaa(mlx);
	else if (ft_strcmp(mlx->name, "burningship") == 0)
		burningship(mlx);
}

void		keys(t_mlx *param, int keycode)
{
	if (keycode == 69)
		param->maxiteration += 50;
	if (keycode == 78)
		param->maxiteration -= 50;
	if (keycode == 8)
		param->c -= 25;
	if (keycode == 7)
		param->c += 25;
	if (keycode == 18)
	{
		param->c1 = 0xffff00;
		param->c2 = 0xfcec5a;
	}
	if (keycode == 19)
	{
		param->c1 = 0x68ff49;
		param->c2 = 0x5032fc;
	}
	if (keycode == 49)
		param->mouse_stop *= -1;
	putt(param);
}

int			key_hook(int keycode, t_mlx *param)
{
	if (keycode == 53)
	{
		mlx_destroy_window(param->mlx, param->win);
		mlx_destroy_image(param->mlx, param->mlx);
		exit(1);
	}
	if (keycode == 69 || keycode == 78 || keycode == 8 || keycode == 7
		|| keycode == 18 || keycode == 19 || keycode == 49)
		keys(param, keycode);
	if (keycode <= 126 && keycode >= 123)
		move_on_map(keycode, param);
	putt(param);
	return (0);
}

void		error_arg(void)
{
	write(1, "\033[33mUsage <filename> [mandelbrot/julia/burningship]\n", 53);
	exit(1);
}

void		pix_to_img(t_mlx *data, int x, int y, int color)
{
	if (data->i != data->maxiteration)
		color = color % data->c * data->i;
	data->data[data->w * y + x] = color;
}
