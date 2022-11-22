/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <danierod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:36:58 by danierod          #+#    #+#             */
/*   Updated: 2022/11/22 08:18:08 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"


int    rec_jul(double real, double img, t_a *arg)
{
    arg->nb.ir = real;
    real = pow(real, 2.0) - pow(img, 2.0) + arg->nb.zx;
	img = 2.0 * arg->nb.ir * img + arg->nb.zy; 
    if (pow(real, 2) + pow(img, 2) >= 4.0)
        my_mlx_pixel_put(&arg->data, arg->nb.x, arg->nb.y, ((int)arg->nb.n * 255 / MI) << 8 | ((int)arg->nb.n * 255 / MI) << 0 | ((int)arg->nb.n * 255 / MI) << 8);
    arg->nb.n++;
    if (arg->nb.n == MI)
        return (0);
    return (rec_jul(real, img, arg));
}

void    julia(t_a *arg)
{
    arg->nb.y = -1;
    while (++arg->nb.y < RS)
    {
        arg->nb.x = -1;
        while (++arg->nb.x < RS)
        {
            arg->nb.n = 0;
            julia_coord(arg);
            rec_jul(arg->nb.real, arg->nb.img, arg);
        }
    }
}

int    rec_man(double real, double img, t_a *arg)
{
    arg->nb.ir = real;
    real = pow(real, 2.0) - pow(img, 2.0) + arg->nb.zx;
	img = 2.0 * arg->nb.ir * img + arg->nb.zy; 
    if (pow(real, 2) + pow(img, 2) >= 4.0)
        my_mlx_pixel_put(&arg->data, arg->nb.x, arg->nb.y, ((int)arg->nb.n * 255 / MI) << 8 | ((int)arg->nb.n * 255 / MI) << 0 | ((int)arg->nb.n * 255 / MI) << 8);
    arg->nb.n++;
    if (arg->nb.n == MI)
        return (0);
    return (rec_man(real, img, arg));
}

void    mandelbrot(t_a *arg)
{
    arg->nb.y = -1;
    while (++arg->nb.y < RS)
    {
        arg->nb.x = -1;
        while (++arg->nb.x < RS)
        {
            arg->nb.n = 0;
            mandel_coord(arg);
            rec_man(arg->nb.real, arg->nb.img, arg);
        }
    }
}