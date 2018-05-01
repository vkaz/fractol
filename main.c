#include "fractol.h"

static int		key_hook(int keycode, t_mlx *param)
{
	if (keycode == 53)
	{
        mlx_destroy_window(param->mlx, param->win);
        exit(1);
    }
	return (0);
}

void mani(t_mlx *frac)
{
	while (frac->hy <= H)
	{
		frac->hx = 1;
		while (frac->hx <= W)
		{
			frac->cx = (((float)frac->hx) / (W) - 0.5) / frac->magnify * 3.0 - 0.7;
			frac->cy = (((float)frac->hy) / (H) - 0.5) / frac->magnify * 3.0;
			frac->x = 0.0;
			frac->y = 0.0;
			frac->iteration = 1;
			while (frac->iteration < frac->itermax)
			{
				frac->xx = frac->x * frac->x - frac->y * frac->y + frac->cx;
				frac->y = 2.0 * frac->x * frac->y + frac->cy;
				frac->x = frac->xx;
				if ((frac->x * frac->x + frac->y * frac->y) > 100.0)
					frac->iteration = 1001;
				frac->iteration++;
			}
			if (frac->iteration < 1001)
				mlx_pixel_put(frac->mlx, frac->win, frac->hx, frac->hy, 0x04fc00);
			else
				mlx_pixel_put(frac->mlx, frac->win, frac->hx, frac->hy, 0x0061ff);
			frac->hx++;
		}
		frac->hy++;
	}
}

void	init(t_mlx *frac, t_jul *jul)
{
	frac->x = 0;
	frac->xx = 0;
	frac->y = 0;
	frac->cx = 0;
	frac->cy = 0;
	frac->iteration = 0;
	frac->itermax = 1000;
	frac->magnify = 1.0;
	frac->hy = 1;
	jul->zoom = 1;
	jul->moveX = 0;
	jul->moveY = 0;
	jul->maxIteration = 300;
	jul->cIm = 0.27015;
	jul->cRe = -0.7;
}

int     main(void)
{
    t_mlx	frac;
	t_jul	jul;

	init(&frac, &jul);
    frac.mlx = mlx_init();
    frac.win = mlx_new_window(frac.mlx, W, H, "Fractol");
	//frac.img = mlx_new_image(frac.mlx, frac.hxres, frac.hyres);
	//frac.data = mlx_get_data_addr(frac.img, 8, 10, 100);
	//mlx_put_image_to_window(frac.mlx, frac.win, frac.img, 0, 0);
	//mlx_destroy_image(frac.mlx, frac.img);
	julia(&jul, &frac);
	mlx_hook(frac.win, 6, (1L << 6), mouse_move, (void*)&jul);
    mlx_key_hook(frac.win, key_hook, &frac);
    //mani(&frac);
    mlx_loop(frac.mlx);
    return (0);
}

