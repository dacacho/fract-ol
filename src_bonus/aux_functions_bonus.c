/* ************************************************************************** */
/*	                                                                          */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <danierod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:36:58 by danierod          #+#    #+#             */
/*   Updated: 2022/11/25 20:10:40 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol_bonus.h"

void	refresh(t_a *arg)
{
	if (arg->f == 'm')
		mandelbrot(arg);
	else if (arg->f == 'j')
		julia(arg);
	if (arg->nb.oo)
		cross(arg);
}

void	coords(t_a *arg)
{
	if (arg->f == 'm')
	{
		arg->nb.real = (arg->nb.x - arg->nb.rs / 2 - 175 + arg->nb.xoffset)
			/ (350 + arg->nb.zoom);
		arg->nb.img = ((arg->nb.rs / 2 - arg->nb.y) + arg->nb.yoffset)
			/ (350 + arg->nb.zoom);
		arg->nb.zx = arg->nb.real;
		arg->nb.zy = arg->nb.img;
		arg->nb.ir = (arg->nb.x - arg->nb.rs / 2) / (200 + arg->nb.zoom);
		arg->nb.ii = (arg->nb.rs / 2 - arg->nb.y) / (200 + arg->nb.zoom);
	}
	else if (arg->f == 'j')
	{
		arg->nb.real = (arg->nb.x - arg->nb.rs / 2 + arg->nb.xoffset)
			/ (300 + arg->nb.zoom);
		arg->nb.img = ((arg->nb.rs / 2 - arg->nb.y) + arg->nb.yoffset)
			/ (300 + arg->nb.zoom);
		arg->nb.zx = arg->nb.real;
		arg->nb.zy = arg->nb.img;
		arg->nb.ir = (arg->nb.x - arg->nb.rs / 2) / (200 + arg->nb.zoom);
		arg->nb.ii = (arg->nb.rs / 2 - arg->nb.y) / (200 + arg->nb.zoom);
	}
}

void	psychedelic(t_a *arg, int key)
{
	if (key == arg->key.four)
	{
		arg->nb.rb = 20;
		arg->nb.gb = 20;
		arg->nb.bb = 0;
	}
	else if (key == arg->key.five)
	{
		arg->nb.rb = 15;
		arg->nb.gb = 15;
		arg->nb.bb = 20;
	}
	else if (key == arg->key.six)
	{
		arg->nb.rb = 6;
		arg->nb.gb = 6;
		arg->nb.bb = 12;
	}
	refresh(arg);
}

void	color(t_a *arg, int key)
{
	arg->nb.rb = 0;
	arg->nb.gb = 0;
	arg->nb.bb = 0;
	if (key == arg->key.one)
	{
		arg->nb.rb = 8;
		arg->nb.bb = 8;
		arg->nb.gb = 0;
	}
	else if (key == arg->key.two)
	{
		arg->nb.rb = 16;
		arg->nb.gb = 0;
		arg->nb.bb = 0;
	}
	else if (key == arg->key.three)
	{
		arg->nb.rb = 8;
		arg->nb.gb = 8;
		arg->nb.bb = 16;
	}
	else
		psychedelic(arg, key);
	refresh(arg);
}

void	cross(t_a *arg)
{
	while (arg->nb.n++ < arg->nb.rs)
	{
		if (arg->nb.n == arg->nb.rs / 2)
		{
			arg->nb.y = 0;
			while (arg->nb.y++ <= arg->nb.rs)
				my_mlx_pixel_put(&arg->data, arg->nb.y, arg->nb.n,
					16777215);
		}
		my_mlx_pixel_put(&arg->data, arg->nb.rs / 2, arg->nb.n, 16777215);
	}
}
