/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:25:56 by vkaznodi          #+#    #+#             */
/*   Updated: 2018/05/29 15:25:58 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	else if (ft_strcmp(mlx->name, "bonus") == 0)
	{
		init_bonus(mlx);
		mlx->fractal = 0;
		return ;
	}
	mlx->fractal = 1;
}

void	initt(t_mlx *mlx)
{
	mlx->c = 255;
	mlx->h = 720;
	mlx->w = 1080;
	mlx->c1 = 0xff0008;
	mlx->c2 = 0x00ff65;
	mlx->maxiteration = 100;
}

int		main(int argc, char **argv)
{
	t_mlx	mlx;

	initt(&mlx);
	if (argc != 2)
		error_arg();
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, mlx.w, mlx.h, "fractol");
	mlx.name = argv[1];
	check(&mlx);
	if (mlx.fractal == 1)
		error_arg();
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_hook(mlx.win, 6, 0, mouse_julia, &mlx);
	mlx_hook(mlx.win, 4, 0, mouse_zoom, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
