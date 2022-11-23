/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <danierod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:36:58 by danierod          #+#    #+#             */
/*   Updated: 2022/11/23 19:11:45 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	mainloop(t_a *arg)
{
	mlx_put_image_to_window(arg->mlx, arg->wdw, arg->data.img, 0, 0);
	cross(arg);
	return (0);
}

int	main(int ac, char **av)
{
	t_a arg;
	
	if (ac != 2)
		return (0);
	
	nb_starting(&arg);
	mlx_ignition(&arg);
		
    if (*av[1] == 'm')
	{
		arg.f = 'm';
		mandelbrot(&arg);
	}
	else if (*av[1] == 'j')
	{
		arg.f = 'j';	
		julia(&arg);
	}
    cross(&arg);
	
	mlx_loop_hook(arg.mlx, mainloop, &arg);
	mlx_hook(arg.wdw, 2, 1L << 0, key_press, &arg);
	mlx_hook(arg.wdw, 4, 1L << 2, mouse_press, &arg);
	mlx_hook(arg.wdw, 17, 0, leave, &arg);
	
	mlx_loop(arg.mlx);
	return (0);
}