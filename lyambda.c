#include "fractol.h"

void	init_lyam(t_mlx *mlx)
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
	mlx->moveX = 0;
	mlx->moveY = 0;
	mlx->maxIteration = 42;
	mlx->cIm = 0.27015;
	mlx->cRe = -0.7;
	mlx->newRe = 0;
	mlx->newIm = 0;
	mlx->oldRe = 0;
	mlx->oldIm = 0;
}

void	lyam_iter(t_mlx *mlx)
{
	double pr, pi;
	pr = 1.5 * (mlx->x - W / 2) / (0.5 * mlx->zoom * W) + mlx->moveX;
	pi = (mlx->y - H / 2) / (0.5 * mlx->zoom * H) + mlx->moveY;
	mlx->i = 0;
	while (mlx->i < mlx->maxIteration)
	{
		mlx->oldRe = mlx->newRe;
		mlx->oldIm = mlx->newIm;
		mlx->newRe = mlx->oldRe * mlx->oldRe - mlx->oldIm * mlx->oldIm + pr;
		mlx->newIm = 2 * mlx->oldRe * mlx->oldIm + pi;
		if ((mlx->newRe * mlx->newRe + mlx->newIm * mlx->newIm) > 4)
			break ;
		mlx->i++;
	}
}

void 	lyam(t_mlx *mlx)
{
	mlx->y = 0;
	while (mlx->y < H)
	{
		mlx->x = 0;
		while (mlx->x < W)
		{
			lyam_iter(mlx);
			printf("%i ", mlx->i);
			if (mlx->i == mlx->maxIteration)
			 	pix_to_img(mlx, mlx->x, mlx->y, 0xd2f700);
			else
				pix_to_img(mlx, mlx->x, mlx->y, 0x00ff65);
			mlx->x++;
		}
		mlx->y++;
	}
}