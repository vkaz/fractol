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
	double				x;
	double				y;
	int				*data;
	int				color;
	double			magnify;
	int				i;
	double			ci;
	double			cr;
	double			tmp;
	int 			fractal;
	int 			C;
	char			*name;
	double			h_x;
	double			h_y;
	int 			H;
	int 			W;
	unsigned int 			c1;
	unsigned int 			c2;
}					t_mlx;

void        juliaa(t_mlx *mlx);
int         mouse_move(int x, int y, void *data);
void        pix_to_img(t_mlx *data, int x, int y, int color);
void 		mend(t_mlx *mlx);
void 		burningship(t_mlx *mlx);
void		init_burningship(t_mlx *mlx);
void		init_mend(t_mlx *mlx);
void		init_julia(t_mlx *mlx);
int			key_hook(int keycode, t_mlx *param);
void		error_arg(void);
void		check(t_mlx *mlx);
int		mouse_julia(int x, int y, t_mlx *e);

#endif