#include "fractol.h"

int		mouse_julia(int x, int y, t_mlx *e)
{
	if (x < 0 || x >= e->W || y < 0 || y >= e->H)
		return (0);
	e->cr = x * 2;
	e->cr = y * 2 - 800;
	juliaa(e);
	return (0);
}