#include "fractol.h"

void julia(t_jul *jul, t_mlx *mlx)
{
    int     i;

	jul->y = 0;
    while (jul->y < H)
    {
        jul->x = 0;
        while (jul->x < W)
        {
            jul->newRe = 1.5 * (jul->x - W / 2) / (0.5 * jul->zoom * W) + jul->moveX;
            jul->newIm = (jul->y - H / 2) / (0.5 * jul->zoom * H) + jul->moveY;
            i = 0;
            while (i < jul->maxIteration)
            {
                jul->oldRe = jul->newRe;
                jul->oldIm = jul->newIm;
                jul->newRe = jul->oldRe * jul->oldRe - jul->oldIm * jul->oldIm + jul->cRe;
                jul->newIm = 2 * jul->oldRe * jul->oldIm + jul->cIm;
                if ((jul->newRe * jul->newRe + jul->newIm * jul->newIm) > 4)
                    i = 301;
                i++;
            }
            if (i < 301)
				mlx_pixel_put(mlx->mlx, mlx->win, jul->x, jul->y, 0x04fc00);
		    else
				mlx_pixel_put(mlx->mlx, mlx->win, jul->x, jul->y, 0x0061ff);
            jul->x++;
        }
        jul->y++;
    }
}
