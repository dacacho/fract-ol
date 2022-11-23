/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <danierod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:36:58 by danierod          #+#    #+#             */
/*   Updated: 2022/11/23 20:14:16 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include "mlx_linux/mlx.h"
# include <X11/Xlib.h>

typedef struct t_key
{
	int plus;
	int	minus;
	int m_left;
	int	m_up;
	int	m_down;
	int	up;
	int	down;
	int left;
	int right;
	int	w;
	int	s;
	int	a;
	int	d;
	int	esc;
}	t_k;

typedef struct	t_number
{
	int rs;
	int	n;
	int mi;
	double jx;
	double jy;
	double	k;
	double	j;
	double	ir;
	double	ii;
	double	xoffset;
	double	yoffset;
	double	zoom;
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
	char	f;
	void	*wdw;
	void	*mlx;
}	t_a;


void    nb_starting(t_a *arg);

void	refresh(t_a *arg);

int    rec_jul(double real, double img, t_a *arg);
void    julia(t_a *arg);
void    julia_coord(t_a *arg);

void    mandelbrot(t_a *arg);
int    rec_man(double real, double img, t_a *arg);
void	mandel_coord(t_a *arg);

int	leave(t_a *arg);

int	key_press(int key, t_a *arg);
void    pos_n_iter(t_a *arg, char dir, int vel, int opt);
int		mouse_press(int key, int x, int y, t_a *arg);

void	my_mlx_pixel_put(t_dt *data, int x, int y, int color);
void    mlx_ignition(t_a *arg);

void    circle(t_a *arg);
void    cross(t_a *arg);

void	set_coord(t_a *arg);


#endif