#include "fractol.h"

void	mend_iter(t_mlx *mlx)
{
	
	mlx->cr = 1.5 * (mlx->x - mlx->W / 2) / (0.5 * mlx->zoom * mlx->W) + mlx->moveX;
	mlx->ci = (mlx->y - mlx->H / 2) / (0.5 * mlx->zoom * mlx->H) + mlx->moveY;
	mlx->newRe = 0; 
	mlx->newIm = 0;
	mlx->oldRe = 0;
	mlx->oldIm = 0;
	mlx->i = 0;
	while (mlx->i < mlx->maxIteration)
	{
		mlx->tmp = mlx->newRe;
		mlx->newRe = (mlx->newRe * mlx->newRe) - (mlx->newIm * mlx->newIm) + mlx->cr;
		mlx->newIm = (2 * mlx->tmp * mlx->newIm) + mlx->ci;
		if ((mlx->newRe * mlx->newRe) + (mlx->newIm * mlx->newIm) > 4)
			break ;
		mlx->i++;
	}
}

void	init_mend(t_mlx *mlx)
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
	mlx->moveX = -0.5;
	mlx->moveY = 0;
	mlx->cr = 0;
	mlx->ci = 0;
	mlx->tmp = 0;
	mend(mlx);
}

void 	mend(t_mlx *mlx)
{
	mlx->y = -1;
	while (++mlx->y < mlx->H)
	{
		mlx->x = -1;
		while (++mlx->x < mlx->W)
		{
			mend_iter(mlx);
			if (mlx->i == mlx->maxIteration)
			 	pix_to_img(mlx, mlx->x, mlx->y, mlx->c1);
			else
				pix_to_img(mlx, mlx->x, mlx->y, mlx->c2);
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}