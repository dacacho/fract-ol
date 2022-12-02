/* ************************************************************************** */
/*	                                                                          */
/*                                                        :::      ::::::::   */
/*   key_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <danierod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:36:58 by danierod          #+#    #+#             */
/*   Updated: 2022/11/29 19:30:24 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol_bonus.h"

void	key_starting(t_a *arg)
{
	arg->key.one = 49;
	arg->key.two = 50;
	arg->key.three = 51;
	arg->key.four = 52;
	arg->key.five = 53;
	arg->key.six = 54;
	arg->key.plus = 61;
	arg->key.minus = 45;
	arg->key.m_left = 1;
	arg->key.m_up = 4;
	arg->key.m_down = 5;
	arg->key.w = 119;
	arg->key.s = 115;
	arg->key.a = 97;
	arg->key.d = 100;
	arg->key.j = 106;
	arg->key.k = 107;
	arg->key.m = 109;
	arg->key.x = 120;
	arg->key.esc = 65307;
	arg->key.up = 65362;
	arg->key.down = 65364;
	arg->key.left = 65361;
	arg->key.right = 65363;
}

int	mouse_press(int key, int x, int y, t_a *arg)
{
	(void)x;
	(void)y;
	if (key == arg->key.m_left)
	{
		mlx_mouse_get_pos(arg->mlx, arg->wdw, &x, &y);
		arg->nb.jx = (x - arg->nb.rs / 2.0 + arg->nb.xoffset)
			/ (300.0 + arg->nb.zoom);
		arg->nb.jy = (arg->nb.rs / 2.0 - y + arg->nb.yoffset)
			/ (300.0 + arg->nb.zoom);
	}
	else if (key == arg->key.m_up)
	{
		arg->nb.zoom += 100;
		arg->nb.xoffset += (x - arg->nb.rs / 2);
		arg->nb.yoffset -= (y - arg->nb.rs / 2);
	}
	else if (key == arg->key.m_down && arg->nb.zoom > 100)
	{
		arg->nb.zoom -= 100;
		arg->nb.xoffset += (x - arg->nb.rs / 2);
		arg->nb.yoffset -= (y - arg->nb.rs / 2);
	}
	refresh(arg);
	return (0);
}

void	pos_n_iter(t_a *arg, int key, int vel, int opt)
{
	int	add;

	add = 5;
	if (vel)
		add += 15;
	if (opt == 0)
	{
		if (key == 119)
			arg->nb.yoffset += add;
		else if (key == 115)
			arg->nb.yoffset -= add;
		else if (key == 97)
			arg->nb.xoffset -= add;
		else if (key == 100)
			arg->nb.xoffset += add;
	}
	else if (opt == 1)
	{
		if (key == 61)
			arg->nb.mi += 5;
		else if (key == 45 && arg->nb.mi > 6)
			arg->nb.mi -= 5;
	}
	refresh(arg);
}

void	toggle(t_a *arg, int key)
{
	if (key == arg->key.k)
	{
		if (arg->nb.str)
			arg->nb.str--;
		else
			arg->nb.str++;
	}
	else if (key == arg->key.x)
	{
		if (arg->nb.oo)
			arg->nb.oo--;
		else
			arg->nb.oo++;
	}
	else if (key == arg->key.m)
			arg->f = 'm';
	else if (key == arg->key.j)
			arg->f = 'j';
	refresh(arg);
}

int	key_press(int key, t_a *arg)
{
	if (key == arg->key.esc)
		leave(arg);
	else if (key == arg->key.x || key == arg->key.k
		|| key == arg->key.m || key == arg->key.j)
		toggle(arg, key);
	else if (key == arg->key.up || key == arg->key.down
		|| key == arg->key.left || key == arg->key.right)
		pos_n_iter(arg, key, 0, 0);
	else if (key == arg->key.w || key == arg->key.s
		|| key == arg->key.a || key == arg->key.d)
		pos_n_iter(arg, key, 1, 0);
	else if (key == arg->key.plus || key == arg->key.minus)
		pos_n_iter(arg, key, 0, 1);
	else if (key == arg->key.one || key == arg->key.two || key == arg->key.three
		|| key == arg->key.four || key == arg->key.five || key == arg->key.six)
		color(arg, key);
	return (0);
}
