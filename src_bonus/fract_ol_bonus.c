/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <danierod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:36:58 by danierod          #+#    #+#             */
/*   Updated: 2022/12/02 09:49:27 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol_bonus.h"

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
		write(1, "\nOptions:\n[1]mandelbrot\n[2]julia\n[3]keymap\n", 43);
	}
	write(1, "\nPrototype: (1)./fract_ol (2)name of the fractal\n", 49);
	write(1, "_________________________________________________\n", 50);
	write(1, "\nPrototype(with coordinates for julia): ", 40);
	write(1, "(1)./fract_ol (2)julia (3)X coords (4)Y coords\n\n", 48);
	exit(0);
}

void	key_map(void)
{
	write(1, "-[KEY MAP]-\n\n", 13);
	write(1, "Move fast:\n[w]-up\n[s]-down\n[a]-left\n[d]-right\n", 46);
	write(1, "________________\n\n", 18);
	write(1, "Move slow:\n[up arrow]\n[down arrow]\n", 35);
	write(1, "[left arrow]\n[right arrow]\n", 27);
	write(1, "________________\n\n", 18);
	write(1, "Mouse:\n[scroll up]-zoom in\n[scroll down]-zoom out\n", 50);
	write(1, "[left click]-select coordinates(julia)\n", 39);
	write(1, "________________\n\n", 18);
	write(1, "Iteration:\n[plus sign]-increase iterations\n", 43);
	write(1, "[minus sign]-decrease iterations\n", 33);
	write(1, "________________\n\n", 18);
	write(1, "Color:\n[1]-blue\n[2]-purple\n[3]-yellow\n", 38);
	write(1, "[4]-red shades\n[5]-'reggae'\n[6]-green shades\n", 45);
	write(1, "________________\n\n", 18);
	write(1, "Select fractal:\n[m]-mandelbrot\n[j]-julia\n", 41);
	write(1, "________________\n\n", 18);
	write(1, "Others:\n[x]-toggle cross\n[k]-toggle keymap\n", 43);
	write(1, "________________\n\n", 18);
	write(1, "Julia suggestion coords:\n(1)[x] 0.0\t[y] 0.8\n", 44);
	write(1, "(2)[x] -0.9\t[y] 0.0\n(3)[x] 0.13\t[y] -0.7\n\n", 42);
	exit(0);
}

int	check(char *s1, char *s2)
{
	int	i;

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
	double	sign;
	double	comma;
	double	nb;
	int		i;

	sign = 1;
	comma = 0.1;
	nb = 0;
	i = 0;
	if (str[i] == '-' && ++i)
		sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + (str[i++] - 48);
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb += (comma * (str[i++] - 48));
		comma /= 10;
	}
	return (nb * sign);
}

int	main(int ac, char **av)
{
	static t_a	arg;

	if (ac != 2 && ac != 4)
		warning(1);
	mlx_ignition(&arg);
	if (check("mandelbrot", av[1]))
	{
		arg.f = 'm';
		mandelbrot(&arg);
	}
	else if (check("julia", av[1]) && ac == 4)
	{
		arg.f = 'j';
		arg.nb.jx = ch_db(av[2]);
		arg.nb.jy = ch_db(av[3]);
		julia(&arg);
	}
	else if (check("keymap", av[1]))
		key_map();
	else
		warning(2);
	mlx_hooks(&arg);
	return (0);
}
