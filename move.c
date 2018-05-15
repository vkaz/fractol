#include "fractol.h"

int		mouse_move_hook(int x, int y, t_env *e)
{
	if (x < 0 || x >= e->win_width || y < 0 || y >= e->win_height ||
			e->mouse_stop == 1)
		return (0);
	e->option_x = x;
	e->option_y = y;
	e->fractal(e);
	return (0);
}