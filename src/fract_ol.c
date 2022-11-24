/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <danierod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:36:58 by danierod          #+#    #+#             */
/*   Updated: 2022/11/24 21:04:11 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void	warning(int opt)
{
	if (opt == 1)
	{
		write(1, "Wrong number of arguments.\n", 27);
		write(1, "__________________________\n", 27);
	}
	if (opt == 2)
	{
		write(1, "Invalid fractal name.\n", 22);
		write(1, "_____________________\n", 22);
		write(1, "\nOptions:\n[1]mandelbrot\n[2]julia\n[3]newton_raphson\n[4]keymap\n", 61);
		
	}
	write(1, "\nPrototype: (1)./fract_ol (2)name of the fractal\n", 49);
	exit(0);
}

void	key_map(void)
{
	write(1, "-[KEY MAP]-\n\n", 13);
	write(1, "Move fast:\n[w]-up\n[s]-down\n[a]-left\n[d]-right\n", 46);
	write(1, "________________\n\n", 18);
	write(1, "Move slow:\n[up arrow]\n[down arrow]\n[left arrow]\n[right arrow]\n", 62);
	write(1, "________________\n\n", 18);
	write(1, "Mouse:\n[scroll up]-zoom in\n[scroll down]-zoom out\n[left click]-select coordinates(julia)\n", 89);
	write(1, "________________\n\n", 18);
	write(1, "Iteration:\n[plus sign]-increase iterations\n[minus sign]-decrease iterations\n", 76);
	write(1, "________________\n\n", 18);
	write(1, "Color:\n[1]-blue\n[2]-purple\n[3]-yellow\n[4]-red shades\n[5]-'reggae'\n", 66);
	write(1, "________________\n\n", 18);
	write(1, "Select fractal:\n[m]-mandelbrot\n[j]-julia\n\n", 42);
	exit(0);
}

int	check(char *s1, char *s2)
{
	int i;
	i = -1;
	while (s1[++i])
	{
		if (s1[i] != s2[i])
			return (0);
	}
	return (1);
}

double	ch_db(const char *str)
{
	double sign = 1, comma = 0.1, nb = 0;
	int i = 0;
	if (str[i] == '-' && ++i)
		sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + (str[i++] - 48);
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb +=  (comma * (str[i++] - 48));
		comma /= 10;
	}
	return (nb * sign);
}

int	main(int ac, char **av)
{
	static t_a arg;
	
	ch_db(av[1]);
	if (ac != 2)
		warning(1);
	nb_starting(&arg);
	mlx_ignition(&arg);
	
    if (check("mandelbrot", av[1]))
	{
		arg.f = 'm';
		mandelbrot(&arg);
	}
	else if (check("julia", av[1]))
	{
		arg.f = 'j';	
		julia(&arg);
	}
	else if (check("keymap", av[1]))	
		key_map();
	else
		warning(2);
    cross(&arg);
	mlx_hooks(&arg);
	return (0);
}