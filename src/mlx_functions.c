/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <danierod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:36:58 by danierod          #+#    #+#             */
/*   Updated: 2022/11/04 16:58:39 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    mlx_ignition(t_a *arg)
{
    arg->mlx = mlx_init();
	arg->wdw = mlx_new_window(arg->mlx, 2000, 2000, "PLASMA_ULTRA_HD");
	arg->data.img = mlx_new_image(arg->mlx, 2000, 2000);
	arg->data.addr = mlx_get_data_addr(arg->data.img, &arg->data.bits_per_pixel, &arg->data.line_length, &arg->data.endian);
}