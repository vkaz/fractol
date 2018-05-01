#include "fractol.h"

int         mouse_move(int x, int y, void *data)
{
   t_jul   *d;
   t_mlx   s;

    write(1, "asdf", 4);
    d = (t_jul*)data;
    // if (x < 0 || x > W || y < 0 || y > H || d->mouse_stop)
    //   return (0);
    printf("%f==%f", d->newRe, d->newIm);
    write(1, "asdf", 4);
    d->newRe = -0.7 + x / 1000;
    d->newIm = 0.27015 + y / 100;
    julia(d, &s);
    mlx_clear_window(s.mlx, s.win);
    return (0);
}
