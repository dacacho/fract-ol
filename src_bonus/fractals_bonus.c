/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <danierod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:36:58 by danierod          #+#    #+#             */
/*   Updated: 2022/12/02 09:49:35 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol_bonus.h"

int	rec_jul(double real, double img, t_a *arg)
{
	arg->nb.ir = real;
	real = pow(real, 2.0) - pow(img, 2.0) + arg->nb.jx;
	img = 2.0 * arg->nb.ir * img + arg->nb.jy;
	if (pow(real, 2) + pow(img, 2) >= 4.0)
	{
		my_mlx_pixel_put(&arg->data, arg->nb.x, arg->nb.y,
			(arg->nb.n * arg->nb.rgb / arg->nb.mi) << arg->nb.rb
			| (arg->nb.n * arg->nb.rgb / arg->nb.mi) << arg->nb.gb
			| (arg->nb.n * arg->nb.rgb / arg->nb.mi) << arg->nb.bb);
		return (0);
	}
	if (arg->nb.n == arg->nb.mi)
	{
		my_mlx_pixel_put(&arg->data, arg->nb.x, arg->nb.y, 0);
		return (0);
	}
	arg->nb.n++;
	return (rec_jul(real, img, arg));
}

void	julia(t_a *arg)
{
	arg->nb.y = -1;
	while (++arg->nb.y < arg->nb.rs)
	{
		arg->nb.x = -1;
		while (++arg->nb.x < arg->nb.rs)
		{
			arg->nb.n = 0;
			coords(arg);
			rec_jul(arg->nb.real, arg->nb.img, arg);
		}
	}
}

int	rec_man(double real, double img, t_a *arg)
{
	arg->nb.ir = real;
	real = pow(real, 2.0) - pow(img, 2.0) + arg->nb.zx;
	img = 2.0 * arg->nb.ir * img + arg->nb.zy;
	if (pow(real, 2) + pow(img, 2) >= 4.0)
	{
		my_mlx_pixel_put(&arg->data, arg->nb.x, arg->nb.y,
			(arg->nb.n * arg->nb.rgb / arg->nb.mi) << arg->nb.rb
			| (arg->nb.n * arg->nb.rgb / arg->nb.mi) << arg->nb.gb
			| (arg->nb.n * arg->nb.rgb / arg->nb.mi) << arg->nb.bb);
		return (0);
	}
	if (arg->nb.n == arg->nb.mi)
	{
		my_mlx_pixel_put(&arg->data, arg->nb.x, arg->nb.y, 0);
		return (0);
	}
	arg->nb.n++;
	return (rec_man(real, img, arg));
}

void	mandelbrot(t_a *arg)
{
	arg->nb.y = -1;
	while (++arg->nb.y < arg->nb.rs)
	{
		arg->nb.x = -1;
		while (++arg->nb.x < arg->nb.rs)
		{
			arg->nb.n = 0;
			coords(arg);
			rec_man(arg->nb.real, arg->nb.img, arg);
		}
	}
}
