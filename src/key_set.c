/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <danierod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:36:58 by danierod          #+#    #+#             */
/*   Updated: 2022/11/22 11:38:11 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void	get_key(t_a *arg)
{
	arg->key.w = 119;
	arg->key.s = 115;
	arg->key.a = 97;
	arg->key.d = 100;
	arg->key.esc = 65307;
}

int	leave(t_a *arg)
{
	mlx_destroy_image(arg->mlx, arg->data.img);
	mlx_destroy_window(arg->mlx, arg->wdw);
	mlx_destroy_display(arg->mlx);
	free(arg->mlx);
	exit (0);
}

int     key_press(int key, t_a *arg)
{
	if (key == arg->key.esc)
		leave(arg);
	if (key == arg->key.w)
		key_up(arg, 1);
	else if (key == arg->key.s)
		key_down(arg, 1);
	else if (key == arg->key.a)
		key_left(arg, 1);
	else if (key == arg->key.d)
		key_right(arg, 1);
	return (0);
}

int		key_release(int key, t_a *arg)
{
	if (key == arg->key.w)
		key_up(arg, 0);
	else if (key == arg->key.s)
		key_down(arg, 0);
	else if (key == arg->key.a)
		key_left(arg, 0);
	else if (key == arg->key.d)
		key_right(arg, 0);
	return (0);
}