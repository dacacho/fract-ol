/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <danierod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:36:58 by danierod          #+#    #+#             */
/*   Updated: 2022/11/09 21:26:51 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	main(int ac, char **av)
{
	t_a arg;

	if (ac != 2)
		return (0);
	mlx_ignition(&arg);
    
    if (*av[1] == 'm')
        mandelbrot(&arg);

    cross(&arg);
    
	mlx_put_image_to_window(arg.mlx, arg.wdw, arg.data.img, 0, 0);
	mlx_loop(arg.mlx);
	return (0);
}