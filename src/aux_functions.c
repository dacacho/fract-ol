/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <danierod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:36:58 by danierod          #+#    #+#             */
/*   Updated: 2022/11/04 17:24:54 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void    cross(t_a *arg)
{
    arg->nb.x = 1000;

    for (arg->nb.n = 0; arg->nb.n < 2000; arg->nb.n++)
    {
            if (arg->nb.n == 1000)
            {
                    for (arg->nb.y = 0; arg->nb.y <= 2000; arg->nb.y++)
                    {
                            my_mlx_pixel_put(&arg->data, arg->nb.y, arg->nb.n++, 100000);
                            my_mlx_pixel_put(&arg->data, arg->nb.y, arg->nb.n, 100000);
                            my_mlx_pixel_put(&arg->data, arg->nb.y, arg->nb.n--, 100000);
                    }
            }
            my_mlx_pixel_put(&arg->data, arg->nb.x++, arg->nb.n , 100000);
            my_mlx_pixel_put(&arg->data, arg->nb.x, arg->nb.n, 100000);
            my_mlx_pixel_put(&arg->data, arg->nb.x--, arg->nb.n, 100000);
    }
}