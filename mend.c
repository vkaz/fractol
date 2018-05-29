/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mend.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:26:08 by vkaznodi          #+#    #+#             */
/*   Updated: 2018/05/29 15:26:09 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mend_iter(t_mlx *mlx)
{
	mlx->newre = 0;
	mlx->newim = 0;
	mlx->oldre = 0;
	mlx->oldim = 0;
	mlx->i = 0;
	while (mlx->i < mlx->maxiteration)
	{
		mlx->tmp = mlx->newre;
		mlx->newre = (mlx->newre * mlx->newre) - (mlx->newim * mlx->newim)
			+ mlx->cr;
		mlx->newim = (2 * mlx->tmp * mlx->newim) + mlx->ci;
		if ((mlx->newre * mlx->newre) + (mlx->newim * mlx->newim) > 4)
			break ;
		mlx->i++;
	}
}

void		init_mend(t_mlx *mlx)
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
	mlx->movex = -0.5;
	mlx->movey = 0;
	mlx->cr = 0;
	mlx->ci = 0;
	mlx->tmp = 0;
	mend(mlx);
}

void		mend(t_mlx *mlx)
{
	mlx->y = -1;
	while (++mlx->y < mlx->h)
	{
		mlx->x = -1;
		while (++mlx->x < mlx->w)
		{
			mlx->cr = 1.5 * (mlx->x - mlx->w / 2) / (0.5 * mlx->zoom * mlx->w)
				+ mlx->movex;
			mlx->ci = (mlx->y - mlx->h / 2) / (0.5 * mlx->zoom * mlx->h)
				+ mlx->movey;
			mend_iter(mlx);
			if (mlx->i == mlx->maxiteration)
				pix_to_img(mlx, mlx->x, mlx->y, mlx->c1);
			else
				pix_to_img(mlx, mlx->x, mlx->y, mlx->c2);
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
