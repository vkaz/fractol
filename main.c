#include "fractol.h"

static int		key_hook(int keycode, t_mlx *param)
{
	if (keycode == 53)
	{
        mlx_destroy_window(param->mlx_ptr, param->win_ptr);
        exit(1);
    }
	return (0);
}

void mani(t_mlx *frac)
{
	double x,xx,y,cx,cy;
	int iteration,hx,hy;
	int itermax = 100;		/* how many iterations to do	*/
	double magnify=1.0;		/* no magnification		*/
	int hxres = 1080;		/* horizonal resolution		*/
	int hyres = 1080;		/* vertical resolution		*/

	for (hy=1;hy<=hyres;hy++)  {
		for (hx=1;hx<=hxres;hx++)  {
			cx = (((float)hx)/((float)hxres)-0.5)/magnify*3.0-0.7;
			cy = (((float)hy)/((float)hyres)-0.5)/magnify*3.0;
			x = 0.0; y = 0.0;
			for (iteration=1;iteration<itermax;iteration++)  {
				xx = x*x-y*y+cx;
				y = 2.0*x*y+cy;
				x = xx;
				if (x*x+y*y>100.0)  iteration = 9999;
			}
			if (iteration<9999)  mlx_pixel_put(frac->mlx_ptr, frac->win_ptr, hx, hy, 0x04fc00);
			else mlx_pixel_put(frac->mlx_ptr, frac->win_ptr, hx, hy, 0x000000);
		}
	}
}

int     main(void)
{
    t_mlx	frac;


    frac.mlx_ptr = mlx_init();
    frac.win_ptr = mlx_new_window(frac.mlx_ptr, 1920, 1080, "Fractol");
    mlx_key_hook(frac.win_ptr, key_hook, &frac);
   // frac(&frac);
    mani(&frac);
    mlx_loop(frac.mlx_ptr);
    return (0);
}

