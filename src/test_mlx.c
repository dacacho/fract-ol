/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <danierod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:36:58 by danierod          #+#    #+#             */
/*   Updated: 2022/11/04 17:21:17 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}	t_data;

typedef struct t_arg
{
	t_data	data;
	void	*wdw;
	void	*mlx;
}t_a;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

//int	main(int ac, char **av)
{
	t_a arg;

	arg.mlx = mlx_init();
	arg.wdw = mlx_new_window(arg.mlx, 2000, 2000, "PLASMA_ULTRA_HD");
	arg.data.img = mlx_new_image(arg.mlx, 2000, 2000);
	arg.data.addr = mlx_get_data_addr(arg.data.img, &arg.data.bits_per_pixel, &arg.data.line_length, &arg.data.endian);
	
///////////////////////////////////////////// circle //////////////////////////////////////	
	
	if (*av[1] == 'a')
	{	
		int	xc = 1000, yc = 1000, r = 500, xx, yy;

		for (int y = 0; y <= 2000; y++)
		{
			for (int x = 0; x <= 2000; x++)
			{
				if ((x - 1000) * (x - 1000) + (y - 1000) * (y - 1000) <= r * r)
				{
					my_mlx_pixel_put(&arg.data, x, y, (x * y * 9876543210));
				}
			}
		}
	}

/////////////////////////////////////// try /////////////////////////////////////////

	if (*av[1] == 'b')
	{
		double y = 0, x = 0, a = -2, b = 1, d = -1, e = 1, n = 0, c, z = 0;
		while (y++ <= 2000)
		{
			x = 0;
			while (x++ <= 2000)
			{
				c = (a + x * (b - a)) * ((d + y * (e - d)));
				z = n = 0;
				while (z <= 2 && n++ <= 80)
				{
					z = z * z + c;
					my_mlx_pixel_put(&arg.data, x, y, z * 255 / 80);
				}
			}
		}
	}

///////////////////////////////////////// mandelbrot ////////////////////////////////////

	else if (*av[1] == 'c')
	{
		float y = 0;
		for (float k = -1; k <= 0.3; k+=0.001)
		{
			float x = 0;
			for (float j = -2; j <= 0.3; j+=0.001)
			{
				float zy = j, zx = k;
				for (int n = 0; n <= 150; n++)
				{
					float zz = zy * zy - zx * zx;
					zx = zy * zx * 2;
					zy = zz;
					zy += j;
					zx += k;
				}
				if (zx * zx + zy * zy < 4)
					my_mlx_pixel_put(&arg.data, x - 1000, y + 800, ((zx * zx + zy * zy) * 16777215) / 150);
				x++;
			}
			y++;
		}
	}


////////////////////////////////////// Mandela //////////////////////////////////////////////


	else if (*av[1] == 'd')
	{
		double k = -1, y = 0, zz = 0;
		while (k <= 1)
		{
			double x = 0;
			double j = -2;
			while (j <= 1)
			{
				double zy = j;
				double zx = k;
				double n = 0;
				while (n++ <= 150)
				{
					zz = zy * zy - zx * zx;
					zx = zy * zx * 2;
					zy = zz;
					zy += j;
					zx += k;
					if (zx * zx + zy * zy < 4)
						my_mlx_pixel_put(&arg.data, x - 250, y + 190, (n * n * 255));
				}
				x++;
				j += 0.00123;
			}
			y++;
			k += 0.00123;
		}
	}


///////////////////////////////////////////// cross ///////////////////////////////////////

        int     tx = 1000;

        for (int n = 0; n < 2000; n++)
        {
                if (n == 1000)
                {
                        for (int ty = 0; ty <= 2000; ty++)
                        {
                                my_mlx_pixel_put(&arg.data, ty, n++, 100000);
                                my_mlx_pixel_put(&arg.data, ty, n, 100000);
                                my_mlx_pixel_put(&arg.data, ty, n--, 100000);
                        }
                }
                my_mlx_pixel_put(&arg.data, tx++, n , 100000);
                my_mlx_pixel_put(&arg.data, tx, n, 100000);
                my_mlx_pixel_put(&arg.data, tx--, n, 100000);
        }


	mlx_put_image_to_window(arg.mlx, arg.wdw, arg.data.img, 0, 0);
	mlx_loop(arg.mlx);
	return (0);
}
