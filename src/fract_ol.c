/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <danierod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:36:58 by danierod          #+#    #+#             */
/*   Updated: 2022/11/17 19:44:06 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	main_loop(t_a *arg)
{
	//mlx_hook(arg->mlx, 2, 1L << 0, &key_press, &arg);
	mlx_put_image_to_window(arg->mlx, arg->wdw, arg->data.img, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_a arg;
	
	if (ac != 2)
		return (0);
	mlx_ignition(&arg);
    
    if (*av[1] == 'm')
		mandelbrot(&arg);
	else if (*av[1] == 'c')
		circle(&arg);
	//else if (*av[1] == 't')
		//test(&arg);
	//else if (*av[1] == 'o')
        //old_mandela(&arg);
    cross(&arg);
    
	mlx_put_image_to_window(arg.mlx, arg.wdw, arg.data.img, 0, 0);
	mlx_loop_hook(arg.mlx, &main_loop, &arg);
	get_key(&arg);
	mlx_loop(arg.mlx);
	return (0);
}