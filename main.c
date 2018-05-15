#include "fractol.h"

static int		key_hook(int keycode, t_mlx *param)
{
	if (keycode == 53)
	{
		mlx_destroy_window(param->mlx, param->win);
		mlx_destroy_image(param->mlx, param->mlx);
		//system("leaks fractol");
        exit(1);
    }
	return (0);
}

void	error_arg(void)
{
	write(1, "\033[33mUsage <filename> [mandelbrot/julia/burningship]\n", 53);
	exit(1);
}

void	check(t_mlx *mlx, char *str)
{
	if (ft_strcmp(str, "mandelbrot") == 0)
	{
		init_mend(mlx);
		mend(mlx);
		mlx->fractal = 0;
		return ;
	}
	else if (ft_strcmp(str, "julia") == 0)
	{
		init_julia(mlx);
		juliaa(mlx);
		mlx->fractal = 0;
		return ;
	}
	else if (ft_strcmp(str, "burningship") == 0)
	{
		init_lyam(mlx);
		mlx->fractal = 0;
		return ;
	}
	mlx->fractal = 1;
}

int      main (int argc, char **argv)
{
	t_mlx	mlx;

	if (argc != 2)
		error_arg();
	check(&mlx, argv[1]);
	if (mlx.fractal == 1)
		error_arg();
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_loop(mlx.mlx);	
	return (0);
}