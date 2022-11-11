/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <danierod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:36:58 by danierod          #+#    #+#             */
/*   Updated: 2022/11/09 19:27:15 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include "mlx_linux/mlx.h"

typedef struct	m_number
{
	double	a;
	double	b;
	double	c;
	double	j;
	double	k;
	double	n;
	double	x;
	double	y;
	double	z;
	double	zx;
	double	zy;
	double	zz;	
}	m_nb;
typedef struct	s_data
{
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}	t_data;

typedef struct t_arg
{
	m_nb	nb;
	t_data	data;
	void	*wdw;
	void	*mlx;
}	t_a;


void    mandelbrot(t_a *arg);
void    cross(t_a *arg);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void    mlx_ignition(t_a *arg);

#endif