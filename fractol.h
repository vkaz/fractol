#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include "libft/libft.h"

# define H 		720
# define W	 	1080

typedef struct		s_jul
{
	double			cRe;
	double			cIm;
	double			newRe;
	double			newIm;
	double			oldRe;
	double			oldIm;
	double			zoom;
	double			moveX;
	double			moveY;
	int				maxIteration;
	int				x;
	int				y;
}					t_jul;

typedef struct		s_mlx
{
	t_jul			*julia;
	void			*mlx;
	void			*img;
	void			*win;
	char			*data;
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
	char			mouse_stop;
}					t_mlx;

typedef struct		s_img
{
	void			*seld;
	char			*buff;
	int				bpp;
	int				bpl;
	int				end;
}					t_img;

typedef struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_color;

void julia(t_jul *jul, t_mlx *scr);
int         mouse_move(int x, int y, void *data);

#endif