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

t_mlx   sqr(t_mlx a)
{
    t_mlx   c;

    c.x = a.x * a.x - a.y * a.y;
	c.y = 2 * a.x * a.y;
	return (c);
}

double  mod(t_mlx a)
{
    return (sqrt(a.x * a.x + a.y * a.y));
}

t_mlx   add(t_mlx a, t_mlx *b)
{
    t_mlx   c;

    c.x = a.x + b->x;
    c.y = a.y + b->y;
    return (c);
}

t_mlx   mapPoint(t_mlx *c)
{
    int     l;
    
    l = (c->width < c->height) ? c->width:c->height;
    c->x = 2 * c->radius * (c->x - c->width / 2.0) / 1;
    c->y = 2 * c->radius * (c->y - c->height / 2.0) / 1;
    return (*c);
}

void    julia(t_mlx *frac)
{
    int     x;
    int     y;
    int     i;
    t_mlx   z0, z1;

    x = 0;
    while (x++ <= frac->width)
    {
        y = 0;
        while (y++ <= frac->height)
        {
            i = 1;
            z0 = mapPoint(frac);
            while (i++ <= frac->n)
            {
                z1 = add(sqr(z0), frac);
                if (mod(z1) > frac->radius)
                    mlx_pixel_put(frac->mlx_ptr, frac->win_ptr, x, y, 0x0800ff);
               // i++;
            }
            z0 = z1;
            //y++;
        }
        if (i > frac->n)
            mlx_pixel_put(frac->mlx_ptr, frac->win_ptr, x, y, 0x0800ff);
        //x++;
    }
}

void    init(t_mlx *frac)
{
    frac->width = 80;
    frac->height = 60;
    frac->radius = 4;
    frac->x = 4;
    frac->y = 8;
    frac->n = 10;
}

int     main(void)
{
    t_mlx	frac;


    frac.mlx_ptr = mlx_init();
    frac.win_ptr = mlx_new_window(frac.mlx_ptr, 1920, 1080, "Fractol");
    mlx_key_hook(frac.win_ptr, key_hook, &frac);
    init(&frac);
    julia(&frac);
    mlx_loop(frac.mlx_ptr);
    return (0);
}