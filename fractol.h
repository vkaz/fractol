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
	void			*mlx_ptr;
	void			*win_ptr;
	double			x;
	double			y;
	double			radius;
	int				width;
	int				height;
	int				n;
}					t_mlx;

#endif