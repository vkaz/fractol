#include "fractol.h"

int		key_hook(int keycode, t_mlx *param)
{
	if (keycode == 53)
	{
		mlx_destroy_window(param->mlx, param->win);
		mlx_destroy_image(param->mlx, param->mlx);
		//system("leaks fractol");
        exit(1);
    }
    if (keycode == 24)
    {
    	param->x = param->W / 12;
    	param->y = param->H / 12;
    	param->zoom = param->zoom * 1.2;
    	param->x = param->x * 1.2;
    	param->y = param->y * 1.2;
		juliaa(param);
    }
    if (keycode == 27)
    {
    	param->x = param->W * 12;
    	param->y = param->H * 12;
    	param->zoom = param->zoom / 1.2;
    	param->x = param->x / 1.2;
    	param->y = param->y / 1.2;
		juliaa(param);
    }
    if (keycode == 69)
    {
    	param->maxIteration += 50;
    	juliaa(param);
    }
    if (keycode == 78)
    {
    	param->maxIteration -= 50;
    	juliaa(param);
    }
    if (keycode == 8)
    {
    	param->c1 *= param->c1;
    	param->c2 *= param->c2;
    	param->C -= 55;
    	juliaa(param);
    }
   	if (keycode == 7)
    {
    	param->c1 /= param->c1;
    	param->c2 /= param->c2;
    	param->C += 55;
    	juliaa(param);
    }
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