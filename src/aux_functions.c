/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <danierod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:36:58 by danierod          #+#    #+#             */
/*   Updated: 2022/11/17 19:42:09 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void    mandel_coord(t_a *arg)
{
	arg->nb.xzoom = 1;
	arg->nb.yzoom = 1;
	arg->nb.xoffset = 0;
	arg->nb.yoffset = 0;
	arg->nb.real = (arg->nb.x - RS / 2.0 - 175.0 + arg->nb.xoffset) / (350.0 + arg->nb.xzoom);
	arg->nb.img = ((RS / 2.0 - arg->nb.y) + arg->nb.yoffset) / (350.0 + arg->nb.yzoom);
	arg->nb.zx = arg->nb.real;
	arg->nb.zy = arg->nb.img;
	arg->nb.ir = (arg->nb.x - RS / 2.0) / (200.0 + arg->nb.xzoom);
	arg->nb.ii = (RS / 2.0 - arg->nb.y) / (200.0 + arg->nb.yzoom);
}

void	set_coord(t_a *arg)
{
	arg->nb.real = (arg->nb.x - RS / 2.0) / 37;
	arg->nb.img = (RS / 2.0 - arg->nb.y) / 37;
}

void	get_key(t_a *arg)
{
	arg->key.w = 119;
	arg->key.s = 115;
	arg->key.a = 97;
	arg->key.d = 100;
	arg->key.esc = 65307;
}

int     key_press(int key, t_a *arg)
{
        if (key == arg->key.esc)
        {
                printf("exiting.\n");
                mlx_destroy_window(arg->mlx, arg->mlx);
                exit(EXIT_SUCCESS);
        }        
        else if (key == arg->key.w)
                printf("up\n");
        else if (key == arg->key.s)
                printf("down\n");
        else if (key == arg->key.a)
                printf("left\n");
        else if (key == arg->key.d)
                printf("right\n");
        return (0);
}

void    cross(t_a *arg)
{
    arg->nb.x = RS / 2;

    for (arg->nb.n = 0; arg->nb.n < RS; arg->nb.n++)
    {
            if (arg->nb.n == RS / 2)
            {
                    for (arg->nb.y = 0; arg->nb.y <= RS; arg->nb.y++)
                    {
                            my_mlx_pixel_put(&arg->data, arg->nb.y, arg->nb.n++, 16777215);
                            my_mlx_pixel_put(&arg->data, arg->nb.y, arg->nb.n, 16777215);
                            my_mlx_pixel_put(&arg->data, arg->nb.y, arg->nb.n--, 16777215);
                    }
            }
            my_mlx_pixel_put(&arg->data, arg->nb.x++, arg->nb.n , 16777215);
            my_mlx_pixel_put(&arg->data, arg->nb.x, arg->nb.n, 16777215);
            my_mlx_pixel_put(&arg->data, arg->nb.x--, arg->nb.n, 16777215);
    }
}

void    circle(t_a *arg)
{
	arg->nb.y = -1;
	while (++arg->nb.y < RS)
	{
			arg->nb.x = -1;
			while (++arg->nb.x < RS)
			{
				set_coord(arg);
				if (sqrt(arg->nb.real * arg->nb.real + arg->nb.img * arg->nb.img) <= 15)
					my_mlx_pixel_put(&arg->data, arg->nb.x, arg->nb.y, (arg->nb.real * arg->nb.real + arg->nb.img * arg->nb.img) * 1000000); 
			}
	}
}

void	test(t_a *arg)
{
	arg->nb.y = -1;
	while (++arg->nb.y < RS)
	{
			arg->nb.x = -1;
			while (++arg->nb.x < RS)
			{
				my_mlx_pixel_put(&arg->data, arg->nb.x, arg->nb.y, arg->nb.y / arg->nb.x * 1000);
			}
	}
}