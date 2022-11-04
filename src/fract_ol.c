/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <danierod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:36:58 by danierod          #+#    #+#             */
/*   Updated: 2022/11/04 17:00:26 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	main(int ac, char **av)
{
	t_a arg;

	mlx_ignition(&arg);
    
    if (*av[1] == 'a')
        mandelbrot(&arg);

    cross(&arg);
    
	mlx_put_image_to_window(arg.mlx, arg.wdw, arg.data.img, 0, 0);
	mlx_loop(arg.mlx);
	return (0);
}