/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <danierod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:36:58 by danierod          #+#    #+#             */
/*   Updated: 2022/11/22 11:40:23 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	main(int ac, char **av)
{
	t_a arg;
	
	if (ac != 2)
		return (0);
	
	mlx_ignition(&arg);
	mlx_put_image_to_window(arg.mlx, arg.wdw, arg.data.img, 0, 0);
		
    if (*av[1] == 'm')
		mandelbrot(&arg);
	else if (*av[1] == 'j')
		julia(&arg);
	else if (*av[1] == 'c')
		circle(&arg);
	else if (*av[1] == 't')
		pseudo_main();
    cross(&arg);
	
	
	get_key(&arg);
	mlx_hook(arg.wdw, 2, 1L << 0, key_press, &arg);
	mlx_hook(arg.wdw, 3, 1L << 1, key_release, &arg);
	
	mlx_loop(arg.mlx);
	return (0);
}