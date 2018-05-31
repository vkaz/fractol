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

void	check_bonus(t_mlx *mlx)
{
	if (ft_strcmp(mlx->name, "bonus1") == 0)
	{
		init_bonus1(mlx);
		mlx->fractal = 0;
		return ;
	}
	else if (ft_strcmp(mlx->name, "bonus2") == 0)
	{
		init_bonus2(mlx);
		mlx->fractal = 0;
		return ;
	}
	else if (ft_strcmp(mlx->name, "bonus3") == 0)
	{
		init_bonus3(mlx);
		mlx->fractal = 0;
		return ;
	}
	else if (ft_strcmp(mlx->name, "bonus4") == 0)
	{
		init_bonus4(mlx);
		mlx->fractal = 0;
		return ;
	}
	mlx->fractal = 1;
}

void	check(t_mlx *mlx)
{
	if (ft_strcmp(mlx->name, "mandelbrot") == 0)
	{
		init_mend(mlx);
		mlx->fractal = 0;
		return ;
	}
	if (ft_strcmp(mlx->name, "julia") == 0)
	{
		init_julia(mlx);
		mlx->fractal = 0;
		return ;
	}
	if (ft_strcmp(mlx->name, "burningship") == 0)
	{
		init_burningship(mlx);
		mlx->fractal = 0;
		return ;
	}
	else 
		check_bonus(mlx);
}

void	print(t_mlx *mlx)
{
	char	*s;

	s = ft_itoa(mlx->maxiteration);
	PUT(mlx->mlx, mlx->win, 10, 40, CC, "1 and 2 change color");
	PUT(mlx->mlx, mlx->win, 10, 60, CC, "move by arrows");
	PUT(mlx->mlx, mlx->win, 10, 80, CC, "change shade by c and x");
	PUT(mlx->mlx, mlx->win, 10, 100, CC, "+ to increase iteration");
	PUT(mlx->mlx, mlx->win, 10, 120, CC, "- to decrease iteration");
	PUT(mlx->mlx, mlx->win, 10, 140, CC, "change zoom by mouse wheel");
	PUT(mlx->mlx, mlx->win, 10, 160, CC, "iteration ");
	PUT(mlx->mlx, mlx->win, 110, 160, CC, s);
	free(s);
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
