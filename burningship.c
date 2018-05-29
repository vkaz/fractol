#include "fractol.h"

void	init_burningship(t_mlx *mlx)
{
	int		bpp;
	int 	sizeline;
	int 	end;

	mlx->img = mlx_new_image(mlx->mlx, mlx->W, mlx->H);
	mlx->data = (int*)mlx_get_data_addr(mlx->img, &bpp, &sizeline, &end);
	mlx->bpp = bpp;
	mlx->sizeline = sizeline;
	mlx->end = end;
	mlx->zoom = 1.0;
	mlx->moveX = 0;
	mlx->moveY = 0;
	burningship(mlx);
}

void	burningship_iter(t_mlx *mlx)
{
	mlx->cr = 1.5 * (mlx->x - mlx->W / 2) / (0.5 * mlx->zoom * (mlx->W - 300)) + mlx->moveX;
	mlx->ci = (mlx->y - mlx->H / 2) / (0.5 * mlx->zoom * (mlx->H - 300)) + mlx->moveY;
	mlx->newRe = 0;
	mlx->newIm = 0;
	mlx->oldRe = 0;
	mlx->oldIm = 0;
	mlx->i = 0;
	while (mlx->i < mlx->maxIteration)
	{
		mlx->oldRe = mlx->newRe;
		mlx->oldIm = mlx->newIm;
		mlx->newRe = mlx->oldRe * mlx->oldRe - mlx->oldIm * mlx->oldIm + mlx->cr;
		mlx->newIm = fabs(2 * mlx->oldRe * mlx->oldIm) + mlx->ci;
		if ((mlx->newRe * mlx->newRe + mlx->newIm * mlx->newIm) > 4)
			break ;
		mlx->i++;
	}
}

void 	burningship(t_mlx *mlx)
{
	mlx->y = -1;
	while (++mlx->y < mlx->H)
	{
		mlx->x = -1;
		while (++mlx->x < mlx->W)
		{
			burningship_iter(mlx);
			if (mlx->i == mlx->maxIteration)
			 	pix_to_img(mlx, mlx->x, mlx->y, mlx->c1);
			else
				pix_to_img(mlx, mlx->x, mlx->y, mlx->c2);
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}