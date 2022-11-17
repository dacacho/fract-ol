/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <danierod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:36:58 by danierod          #+#    #+#             */
/*   Updated: 2022/11/17 19:23:47 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

/*void    old_mandela(t_a *arg)
{

    arg->nb.k = -1;
    arg->nb.y = 0;
    arg->nb.zz = 0;
    
    while (arg->nb.k <= 1 && arg->nb.y++ < RS)
    {
        arg->nb.x = 0;
        arg->nb.j = -2;
        while (arg->nb.j <= 1 && arg->nb.x++ < RS)
        {
            arg->nb.zy = arg->nb.j;
            arg->nb.zx = arg->nb.k;
            arg->nb.n = 0;
            while (arg->nb.n++ <= 200)
            {
                arg->nb.zz = pow(arg->nb.zy, 2) - pow(arg->nb.zx, 2);
                arg->nb.zx = (arg->nb.zy * arg->nb.zx) * 2;
                arg->nb.zy = arg->nb.zz;
                arg->nb.zy += arg->nb.j;
                arg->nb.zx += arg->nb.k;
                set_coord(arg);
                if (pow(arg->nb.zx, 2) + pow(arg->nb.zy, 2) <= 4)
                {
                    my_mlx_pixel_put(&arg->data, arg->nb.x, arg->nb.y, arg->nb.n * 100000000);
                }
            }
            arg->nb.j += 0.00123456789;
        }
        arg->nb.k += 0.00123456789;
    }
}*/

int    rec_man(double real, double img, t_a *arg)
{
    arg->nb.ir = real;
    real = pow(real, 2.0) - pow(img, 2.0) + arg->nb.zx;
	img = 2.0 * arg->nb.ir * img + arg->nb.zy; 
    if (pow(real, 2) + pow(img, 2) >= 4.0)
        my_mlx_pixel_put(&arg->data, arg->nb.x, arg->nb.y, arg->nb.n * 100000000);
    arg->nb.n++;
    if (arg->nb.n == 100)
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