/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <danierod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:36:58 by danierod          #+#    #+#             */
/*   Updated: 2022/11/23 20:13:12 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	leave(t_a *arg)
{
	mlx_destroy_image(arg->mlx, arg->data.img);
	mlx_destroy_window(arg->mlx, arg->wdw);
	mlx_destroy_display(arg->mlx);
	free(arg->mlx);
	exit (0);
}

void	refresh(t_a *arg)
{
	mlx_destroy_image(arg->mlx, arg->data.img);
    arg->data.img = mlx_new_image(arg->mlx, arg->nb.rs, arg->nb.rs);
    arg->data.addr = mlx_get_data_addr(arg->data.img, &arg->data.bits_per_pixel, &arg->data.line_length, &arg->data.endian);
	if (arg->f == 'm')
		mandelbrot(arg);
	else if (arg->f == 'j')
		julia(arg);
}

void    julia_coord(t_a *arg)
{
	arg->nb.real = (arg->nb.x - arg->nb.rs / 2 + arg->nb.xoffset) / (300 + arg->nb.zoom);
	arg->nb.img = ((arg->nb.rs / 2 - arg->nb.y) + arg->nb.yoffset) / (300 + arg->nb.zoom);
	arg->nb.zx = arg->nb.real;
	arg->nb.zy = arg->nb.img;
	arg->nb.ir = (arg->nb.x - arg->nb.rs / 2) / (200 + arg->nb.zoom);
	arg->nb.ii = (arg->nb.rs / 2 - arg->nb.y) / (200 + arg->nb.zoom);
}

void    mandel_coord(t_a *arg)
{
	arg->nb.real = (arg->nb.x - arg->nb.rs / 2 - 175 + arg->nb.xoffset) / (350 + arg->nb.zoom);
	arg->nb.img = ((arg->nb.rs / 2 - arg->nb.y) + arg->nb.yoffset) / (350 + arg->nb.zoom);
	arg->nb.zx = arg->nb.real;
	arg->nb.zy = arg->nb.img;
	arg->nb.ir = (arg->nb.x - arg->nb.rs / 2 ) / (200 + arg->nb.zoom);
	arg->nb.ii = (arg->nb.rs / 2 - arg->nb.y) / (200 + arg->nb.zoom);
}

void    cross(t_a *arg)
{
    arg->nb.x = arg->nb.rs / 2;

    for (arg->nb.n = 0; arg->nb.n < arg->nb.rs; arg->nb.n++)
    {
            if (arg->nb.n == arg->nb.rs / 2)
            {
                    for (arg->nb.y = 0; arg->nb.y <= arg->nb.rs; arg->nb.y++)
                            my_mlx_pixel_put(&arg->data, arg->nb.y, arg->nb.n, 16777215);
            }
            my_mlx_pixel_put(&arg->data, arg->nb.x, arg->nb.n, 16777215);
    }
}