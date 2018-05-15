#include "fractol.h"

void	mend_iter(t_mlx *mlx)
{
	mlx->newRe = 1.5 * (mlx->x - W / 2) / (0.5 * mlx->zoom * W) + mlx->moveX;
	mlx->newIm = (mlx->y - H / 2) / (0.5 * mlx->zoom * H) + mlx->moveY;
	mlx->i = 0;
	while (mlx->i < mlx->maxIteration)
	{
		mlx->oldRe = mlx->newRe;
		mlx->oldIm = mlx->newIm;
		mlx->newRe = mlx->oldRe * mlx->oldRe - mlx->oldIm * mlx->oldIm + mlx->newRe;
		mlx->newIm = 2 * mlx->oldRe * mlx->oldIm + mlx->newIm;
		if ((mlx->newRe * mlx->newRe + mlx->newIm * mlx->newIm) > 4)
			break ;
		mlx->i++;
	}
}

void	init_mend(t_mlx *mlx)
{
	int		bpp;
	int 	sizeline;
	int 	end;

	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, W, H, "fractol");
	mlx->img = mlx_new_image(mlx->mlx, W, H);
	mlx->data = (int*)mlx_get_data_addr(mlx->img, &bpp, &sizeline, &end);
	mlx->bpp = bpp;
	mlx->sizeline = sizeline;
	mlx->end = end;
	mlx->zoom = 1;
	mlx->moveX = -0.5;
	mlx->moveY = 0;
	mlx->maxIteration = 42;
	mlx->newRe = 0;
	mlx->newIm = 0;
	mlx->oldRe = 0;
	mlx->oldIm = 0;
}

void 	mend(t_mlx *mlx)
{
	mlx->y = -1;
	while (++mlx->y < H)
	{
		mlx->x = -1;
		while (++mlx->x < W)
		{
			mend_iter(mlx);
			if (mlx->i == mlx->maxIteration)
			 	pix_to_img(mlx, mlx->x, mlx->y, 0x90f966);
			else
				pix_to_img(mlx, mlx->x, mlx->y, 0x00ff65);
		}
	}
}