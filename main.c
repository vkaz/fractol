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

void	print(t_mlx *mlx)
{
	PUT(mlx->mlx, mlx->win, 0, 40, CC, "1 and 2 change color");
	PUT(mlx->mlx, mlx->win, 0, 60, CC, "move by arrows");
	PUT(mlx->mlx, mlx->win, 0, 80, CC, "change shade by c and x");
	PUT(mlx->mlx, mlx->win, 0, 100, CC, "+ to increase iteration");
	PUT(mlx->mlx, mlx->win, 0, 120, CC, "- to decrease iteration");
	PUT(mlx->mlx, mlx->win, 0, 140, CC, "change zoom by mouse wheel");
}

void	initt(t_mlx *mlx)
{
	mlx->c = 255;
	mlx->h = 720;
	mlx->w = 1080;
	mlx->c1 = 0xff0008;
	mlx->c2 = 0x00ff65;
	mlx->maxiteration = 100;
	mlx->mouse_stop = 1;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, mlx->w, mlx->h, "fractol");
}

int		main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc != 2)
		error_arg();
	initt(&mlx);
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
