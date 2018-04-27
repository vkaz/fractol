#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct		s_mlx
{
	void			*mlx;
	int				img;
	void			*win;
	double			x;
	double			y;
	double			xx;
	double			cx;
	double			cy;
	double			magnify;
	int				iteration;
	int				hx;
	int				hy;
	int				itermax;
	int				hxres;
	int				hyres;
}					t_mlx;

#endif