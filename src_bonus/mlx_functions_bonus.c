/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <danierod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:36:58 by danierod          #+#    #+#             */
/*   Updated: 2022/12/02 09:49:48 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol_bonus.h"

int	mainloop(t_a *arg)
{
	mlx_put_image_to_window(arg->mlx, arg->wdw, arg->data.img, 0, 0);
	if (arg->nb.str)
	{
		mlx_string_put(arg->mlx, arg->wdw, 100, 100, 16777215, "-[KEY MAP]-");
		mlx_string_put(arg->mlx, arg->wdw, 100, 125, 16777215,
			"Move fast: [w]-up [s]-down [a]-left [d]-right");
		mlx_string_put(arg->mlx, arg->wdw, 100, 145, 16777215,
			"Move slow: [up arrow] [down arrow] [left arrow] [right arrow]");
		mlx_string_put(arg->mlx, arg->wdw, 100, 165, 16777215,
			"Mouse: [scroll]-zoom in/zoom out [left click]-select coordinates");
		mlx_string_put(arg->mlx, arg->wdw, 100, 185, 16777215,
			"Iteration: [plus sign]-[minus sign]-change iterations");
		mlx_string_put(arg->mlx, arg->wdw, 100, 205, 16777215,
			"Color:[1]-blue [2]-purple [3]-yellow [4]-[5]-[6]");
		mlx_string_put(arg->mlx, arg->wdw, 100, 225, 16777215,
			"Select fractal:[m]-mandelbrot [j]-julia");
		mlx_string_put(arg->mlx, arg->wdw, 100, 245, 16777215,
			"Others:[x]-toggle cross [k]-toggle keymap");
	}
	return (0);
}

void	my_mlx_pixel_put(t_dt *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	leave(t_a *arg)
{
	write(1, "\nExiting program.\n\n", 19);
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

void	mlx_ignition(t_a *arg)
{
	arg->nb.rgb = 255;
	arg->nb.mi = 20;
	arg->nb.rs = 2000;
	key_starting(arg);
	arg->mlx = mlx_init();
	arg->wdw = mlx_new_window(arg->mlx, arg->nb.rs, arg->nb.rs, "Fract_ol");
	arg->data.img = mlx_new_image(arg->mlx, arg->nb.rs, arg->nb.rs);
	arg->data.addr = mlx_get_data_addr(arg->data.img, &arg->data.bits_per_pixel,
			&arg->data.line_length, &arg->data.endian);
	mlx_put_image_to_window(arg->mlx, arg->wdw, arg->data.img, 0, 0);
}
