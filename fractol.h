/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:25:27 by vkaznodi          #+#    #+#             */
/*   Updated: 2018/05/29 15:25:29 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define CC		0x45f442
# define PUT	mlx_string_put

# include "mlx.h"
# include <math.h>
# include <errno.h>
# include "libft/libft.h"

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	int				bpp;
	int				sizeline;
	int				end;
	double			cre;
	double			cim;
	double			newre;
	double			newim;
	double			oldre;
	double			oldim;
	double			zoom;
	double			movex;
	double			movey;
	int				maxiteration;
	double			x;
	double			y;
	int				*data;
	int				color;
	double			magnify;
	int				i;
	double			ci;
	double			cr;
	double			tmp;
	int				fractal;
	int				c;
	char			*name;
	double			h_x;
	double			h_y;
	int				h;
	int				w;
	unsigned int	c1;
	unsigned int	c2;
	int				mouse_stop;
}					t_mlx;

void				juliaa(t_mlx *mlx);
void				pix_to_img(t_mlx *data, int x, int y, int color);
void				mend(t_mlx *mlx);
void				burningship(t_mlx *mlx);
void				init_burningship(t_mlx *mlx);
void				init_mend(t_mlx *mlx);
void				init_julia(t_mlx *mlx);
int					key_hook(int keycode, t_mlx *param);
void				error_arg(void);
void				check(t_mlx *mlx);
int					mouse_julia(int x, int y, t_mlx *e);
void				putt(t_mlx *mlx);
int					mouse_zoom(int keycode, int x, int y, t_mlx *e);
void				move_on_map(int keycode, t_mlx *e);
void				print(t_mlx *mlx);
void				init_bonus1(t_mlx *mlx);
void				bonus1(t_mlx *mlx);
void				bonus2(t_mlx *mlx);
void				init_bonus2(t_mlx *mlx);
void				init_bonus3(t_mlx *mlx);
void				bonus3(t_mlx *mlx);
void				bonus4(t_mlx *mlx);
void				init_bonus4(t_mlx *mlx);

#endif
