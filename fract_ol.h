/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <danierod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:36:58 by danierod          #+#    #+#             */
/*   Updated: 2022/11/22 11:38:17 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include "mlx_linux/mlx.h"
# include <X11/Xlib.h>

# define MI 50
# define RS 1000

typedef struct t_key
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	esc;
}	t_k;

typedef struct	t_number
{
	double	k;
	double	j;
	double	ir;
	double	ii;
	double	xoffset;
	double	yoffset;
	double	xzoom;
	double	yzoom;
	double	n;
	double	real;
	double	img;
	double	x;
	double	y;
	double	z;
	double	zx;
	double	zy;
	double	zz;	
}	t_nb;
typedef struct	t_data
{
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}	t_dt;

typedef struct t_arg
{
	t_k		key;
	t_nb	nb;
	t_dt	data;
	void	*wdw;
	void	*mlx;
}	t_a;


int    rec_jul(double real, double img, t_a *arg);
void    julia(t_a *arg);
void    julia_coord(t_a *arg);

void    mandelbrot(t_a *arg);
int    rec_man(double real, double img, t_a *arg);
void	mandel_coord(t_a *arg);


int	leave(t_a *arg);

void	get_key(t_a *arg);
int	key_press(int key, t_a *arg);
int	key_release(int key, t_a *arg);
void    key_up(t_a *arg, int dir);
void    key_down(t_a *arg, int dir);
void    key_left(t_a *arg, int dir);
void    key_right(t_a *arg, int dir);

void	my_mlx_pixel_put(t_dt *data, int x, int y, int color);
void    mlx_ignition(t_a *arg);

void    circle(t_a *arg);
void    cross(t_a *arg);

void	set_coord(t_a *arg);


int	pseudo_main(void);

#endif