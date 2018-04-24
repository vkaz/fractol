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
	double			c_re;
	double			c_im;
	double			x_new;
	int				row;
	int				col;
	int				width;
	int				height;
	int				i;
}					t_mlx;

#endif