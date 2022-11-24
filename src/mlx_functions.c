/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <danierod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:36:58 by danierod          #+#    #+#             */
/*   Updated: 2022/11/24 19:19:21 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	mainloop(t_a *arg)
{
	mlx_put_image_to_window(arg->mlx, arg->wdw, arg->data.img, 0, 0);
	cross(arg);
	return (0);
}

void	my_mlx_pixel_put(t_dt *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	leave(t_a *arg)
{
	write(1, "Exiting program.\n", 17);
	mlx_destroy_image(arg->mlx, arg->data.img);
	mlx_destroy_window(arg->mlx, arg->wdw);
	mlx_destroy_display(arg->mlx);
	free(arg->mlx);
	exit (0);
}

void	mlx_hooks(t_a *arg)
{
	mlx_loop_hook(arg->mlx, mainloop, arg);
	mlx_hook(arg->wdw, 2, 1L << 0, key_press, arg);
	mlx_hook(arg->wdw, 4, 1L << 2, mouse_press, arg);
	mlx_hook(arg->wdw, 17, 0, leave, arg);
	mlx_loop(arg->mlx);
}

void    mlx_ignition(t_a *arg)
{
    arg->mlx = mlx_init();
	arg->wdw = mlx_new_window(arg->mlx, arg->nb.rs, arg->nb.rs, "Fract_ol");
	arg->data.img = mlx_new_image(arg->mlx, arg->nb.rs, arg->nb.rs);
	arg->data.addr = mlx_get_data_addr(arg->data.img, &arg->data.bits_per_pixel, &arg->data.line_length, &arg->data.endian);
	mlx_put_image_to_window(arg->mlx, arg->wdw, arg->data.img, 0, 0);
}