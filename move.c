/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:26:16 by vkaznodi          #+#    #+#             */
/*   Updated: 2018/05/29 15:26:17 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_julia(int x, int y, t_mlx *e)
{
	if (x < 0 || x >= e->w || y < 0 || y >= e->h)
		return (0);
	if (ft_strcmp(e->name, "julia") == 0 && e->mouse_stop > 0)
	{
		e->cre = (double)(x - 500) / (double)(500);
		e->cim = (double)(y - 500) / (double)(500);
		juliaa(e);
	}
	return (0);
}

void	move_on_map(int keycode, t_mlx *param)
{
	if (keycode == 124)
		param->movex += 0.005;
	if (keycode == 126)
		param->movey -= 0.005;
	if (keycode == 125)
		param->movey += 0.005;
	if (keycode == 123)
		param->movex -= 0.005;
}

int		mouse_zoom(int keycode, int x, int y, t_mlx *param)
{
	if (x < 0 || x >= param->w || y < 0 || y >= param->w)
		return (0);
	if (keycode == 5)
	{
		param->zoom = param->zoom * 1.1;
		param->movex += ((x - (param->w / 1.5)) / ((param->w / 1.5) *
			param->zoom));
		param->movey += ((y - (param->h / 1.5)) / ((param->h / 1.5) *
			param->zoom));
	}
	if (keycode == 4)
	{
		param->zoom = param->zoom / 1.1;
		param->movex += ((x - (param->w / 2)) / ((param->w / 2) * param->zoom));
		param->movey += ((y - (param->h / 2)) / ((param->h / 2) * param->zoom));
	}
	putt(param);
	return (0);
}
