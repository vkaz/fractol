#include "fractol.h"

int		mouse_julia(int x, int y, t_mlx *e)
{
	if (x < 0 || x >= e->W || y < 0 || y >= e->H)
		return (0);
	if (ft_strcmp(e->name, "julia") == 0)
	{
		e->cRe = (double)(x - 500) / (double)(500);
		e->cIm = (double)(y - 500) / (double)(500);
		juliaa(e);
	}
	return (0);
}