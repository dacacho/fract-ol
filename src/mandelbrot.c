/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <danierod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:36:58 by danierod          #+#    #+#             */
/*   Updated: 2022/11/09 21:35:05 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void    mandelbrot(t_a *arg)
{
    arg->nb.k = -1;
    arg->nb.y = 0;
    arg->nb.zz = 0;
    while (arg->nb.k <= 1)
    {
        arg->nb.x = 0;
        arg->nb.j = -2;
        while (arg->nb.j <= 1)
        {
            arg->nb.zy = arg->nb.j;
            arg->nb.zx = arg->nb.k;
            arg->nb.n = 0;
            while (arg->nb.n++ <= 150)
            {
                arg->nb.zz = arg->nb.zy * arg->nb.zy - arg->nb.zx * arg->nb.zx;
                arg->nb.zx = arg->nb.zy * arg->nb.zx * 2;
                arg->nb.zy = arg->nb.zz;
                arg->nb.zy += arg->nb.j;
                arg->nb.zx += arg->nb.k;
                if (arg->nb.zx * arg->nb.zx + arg->nb.zy * arg->nb.zy < 4)
                    my_mlx_pixel_put(&arg->data, arg->nb.x - 250, arg->nb.y + 190, arg->nb.n * arg->nb.n * 100000);
            }
            arg->nb.x++;
            arg->nb.j += 0.00123;
        }
        arg->nb.y++;
        arg->nb.k += 0.00123;
    }
}