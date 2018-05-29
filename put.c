#include "fractol.h"

void	putt(t_mlx *mlx)
{
	if (ft_strcmp(mlx->name, "mandelbrot") == 0)
		mend(mlx);
	else if (ft_strcmp(mlx->name, "julia") == 0)
		juliaa(mlx);
	else if (ft_strcmp(mlx->name, "burningship") == 0)
		burningship(mlx);
}

void	keys(t_mlx *param, int keycode)
{
	if (keycode == 69)
    	param->maxIteration += 50;
    if (keycode == 78)
    	param->maxIteration -= 50;
    if (keycode == 8)
    	param->C -= 55;
   	if (keycode == 7)
    	param->C += 55;
    if (keycode == 18)
    {
    	param->c1 = 0xed6d6d;
    	param->c2 = 0xfcec5a;
    }
    if (keycode == 19)
    {
    	param->c1 = 0x68ff49;
    	param->c2 = 0x5032fc;
    }
    putt(param);
}

int		key_hook(int keycode, t_mlx *param)
{
	if (keycode == 53)
	{
		mlx_destroy_window(param->mlx, param->win);
		mlx_destroy_image(param->mlx, param->mlx);
        exit(1);
    }
    if (keycode == 24)
    {
    	param->x = param->W / 12;
    	param->y = param->H / 12;
    	param->zoom = param->zoom * 1.2;
    	param->x = param->x * 1.2;
    	param->y = param->y * 1.2;
    }
    if (keycode == 27)
    {
    	param->x = param->W * 12;
    	param->y = param->H * 12;
    	param->zoom = param->zoom / 1.2;
    	param->x = param->x / 1.2;
    	param->y = param->y / 1.2;
    }
    if (keycode == 69 || keycode == 78 || keycode == 8 || keycode == 7
    	|| keycode == 18 || keycode == 19)
    	keys(param, keycode);
    putt(param);
	return (0);
}

void	error_arg(void)
{
	write(1, "\033[33mUsage <filename> [mandelbrot/julia/burningship]\n", 53);
	exit(1);
}

void        pix_to_img(t_mlx *data, int x, int y, int color)
{
	if (data->i != data->maxIteration)
		color = color % data->C * data->i;
	data->data[data->W * y + x]= color;
}