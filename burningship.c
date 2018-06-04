/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:25:15 by vkaznodi          #+#    #+#             */
/*   Updated: 2018/05/29 15:25:18 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_burningship(t_mlx *mlx)
{
	int		bpp;
	int		sizeline;
	int		end;

	mlx->img = mlx_new_image(mlx->mlx, mlx->w, mlx->h);
	mlx->data = (int*)mlx_get_data_addr(mlx->img, &bpp, &sizeline, &end);
	mlx->bpp = bpp;
	mlx->sizeline = sizeline;
	mlx->end = end;
	mlx->zoom = 1.0;
	mlx->movex = 0;
	mlx->movey = 0;
	burningship(mlx);
}

void	burningship_iter(t_mlx *mlx)
{
	mlx->newre = 0;
	mlx->newim = 0;
	mlx->oldre = 0;
	mlx->oldim = 0;
	mlx->i = 0;
	while (mlx->i < mlx->maxiteration)
	{
		mlx->oldre = mlx->newre;
		mlx->oldim = mlx->newim;
		mlx->newre = mlx->oldre * mlx->oldre - mlx->oldim * mlx->oldim
			+ mlx->cr;
		mlx->newim = fabs(2 * mlx->oldre * mlx->oldim) + mlx->ci;
		if ((mlx->newre * mlx->newre + mlx->newim * mlx->newim) > 4)
			break ;
		mlx->i++;
	}
}

void	burningship(t_mlx *mlx)
{
	mlx->y = -1;
	while (++mlx->y < mlx->h)
	{
		mlx->x = -1;
		while (++mlx->x < mlx->w)
		{
			mlx->cr = 1.5 * (mlx->x - mlx->w / 2) / (0.5 * mlx->zoom *
				(mlx->w - 300)) + mlx->movex;
			mlx->ci = (mlx->y - mlx->h / 2) / (0.5 * mlx->zoom *
				(mlx->h - 300)) + mlx->movey;
			burningship_iter(mlx);
			if (mlx->i == mlx->maxiteration)
				pix_to_img(mlx, mlx->x, mlx->y, mlx->c1);
			else
				pix_to_img(mlx, mlx->x, mlx->y, mlx->c2);
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	print(mlx);
}
