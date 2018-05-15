#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include "libft/libft.h"

# define H 		1080
# define W	 	1920

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	int				bpp;
	int				sizeline;
	int				end;
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
	int				x1;
	int				y1;
	int				*data;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	int				color;
	int				xx;
	int				cx;
	double			magnify;
	int				cy;
	int				i;
	double			xmin;
	double			xmax;
	double			ymin;
	double			ymax;
	double			zr;
	double			zi;
	double			ci;
	double			cr;
	double			tmp;
	int 			fractal;
}					t_mlx;

void        juliaa(t_mlx *mlx);
void		do_it(t_mlx *data);
int         mouse_move(int x, int y, void *data);
void        pix_to_img(t_mlx *data, int x, int y, int color);
void 	mend(t_mlx *mlx);
void 	lyam(t_mlx *mlx);
void	init_lyam(t_mlx *mlx);
void	init_mend(t_mlx *mlx);
void	init_julia(t_mlx *mlx);

#endif