#include "fractol.h"

void	check(t_mlx *mlx)
{
	if (ft_strcmp(mlx->name, "mandelbrot") == 0)
	{
		init_mend(mlx);
		mlx->fractal = 0;
		return ;
	}
	else if (ft_strcmp(mlx->name, "julia") == 0)
	{
		init_julia(mlx);
		mlx->fractal = 0;
		return ;
	}
	else if (ft_strcmp(mlx->name, "burningship") == 0)
	{
		init_burningship(mlx);
		mlx->fractal = 0;
		return ;
	}
	mlx->fractal = 1;
}

void	initt(t_mlx *mlx)
{
	mlx->C = 255;
	mlx->H = 1080;
	mlx->W = 1920;
	mlx->c1 = 0x623324;
	mlx->c2 = 0x00ff65;
	mlx->maxIteration = 100;
}

int      main (int argc, char **argv)
{
	t_mlx	mlx;

	initt(&mlx);
	if (argc != 2)
		error_arg();
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, mlx.W, mlx.H, "fractol");
	mlx.name = argv[1];
	check(&mlx);
	if (mlx.fractal == 1)
		error_arg();
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_hook(mlx.win, 6, 1L >> 6, mouse_julia, &mlx);
	// mlx_hook(mlx.win, 4, 0, mouse_zoom, &xml);
	// mlx_loop_hook(mlx.mlx, zoooooom, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}