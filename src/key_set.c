/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <danierod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:36:58 by danierod          #+#    #+#             */
/*   Updated: 2022/11/24 16:27:11 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void    nb_starting(t_a *arg)
{
	arg->key.one = 49;
	arg->key.two = 50;
	arg->key.three = 51;
	arg->key.four = 52;
	arg->key.five = 53;
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
	arg->key.m = 109;
	arg->key.n = 110;
	arg->key.esc = 65307;
    arg->key.up = 65362;
	arg->key.down = 65364;
	arg->key.left = 65361;
	arg->key.right = 65363;
	arg->nb.mi = 20;
	arg->nb.rs = 2000;
}

void    pos_n_iter(t_a *arg, char dir, int vel, int opt)
{
	int add = 5;
	if (vel)
		add += 15;
	if (opt == 0)
	{
		if (dir == 'w')
			arg->nb.yoffset += add;
		else if (dir == 's')
			arg->nb.yoffset -= add;
		else if (dir == 'a')
			arg->nb.xoffset -= add;
		else if (dir == 'd')
			arg->nb.xoffset += add;
	}
	else if (opt == 1)
	{
		if (dir == '+')
			arg->nb.mi += 5;
		else if (dir == '-' && arg->nb.mi > 6)
			arg->nb.mi -= 5;
	}
	refresh(arg);
}

int		mouse_press(int key,int x, int y, t_a *arg)
{
	(void)x;
	(void)y;
	if (key == arg->key.m_left)
	{
		mlx_mouse_get_pos(arg->mlx, arg->wdw, &x, &y);
		arg->nb.jx = (x - arg->nb.rs / 2.0 + arg->nb.xoffset) / (300.0 + arg->nb.zoom);
		arg->nb.jy = (arg->nb.rs / 2.0 - y + arg->nb.yoffset) / (300.0 + arg->nb.zoom);
	}
	else if (key == arg->key.m_up)
	{
		arg->nb.zoom += 100;
		arg->nb.xoffset += (x - arg->nb.rs/2);
		arg->nb.yoffset -= (y - arg->nb.rs/2);
	}
	else if (key == arg->key.m_down && arg->nb.zoom > 100)
	{
		arg->nb.zoom -= 100;
		arg->nb.xoffset += (x - arg->nb.rs/2);
		arg->nb.yoffset -= (y - arg->nb.rs/2);
	}
	refresh(arg);
	return (0);
}

int     key_press(int key, t_a *arg)
{
	if (key == arg->key.esc)
		leave(arg);
	else if (key == arg->key.up)
		pos_n_iter(arg, 'w', 0, 0);
	else if (key == arg->key.down)
		pos_n_iter(arg, 's', 0, 0);
	else if (key == arg->key.left)
		pos_n_iter(arg, 'a', 0, 0);
	else if (key == arg->key.right)
		pos_n_iter(arg, 'd', 0, 0);
	else if (key == arg->key.w)
		pos_n_iter(arg, 'w', 1, 0);
	else if (key == arg->key.s)
		pos_n_iter(arg, 's', 1, 0);
	else if (key == arg->key.a)
		pos_n_iter(arg, 'a', 1, 0);
	else if (key == arg->key.d)
		pos_n_iter(arg, 'd', 1, 0);
	else if (key == arg->key.plus)
		pos_n_iter(arg, '+', 0, 1);
	else if (key == arg->key.minus)
		pos_n_iter(arg, '-', 0, 1);
	else if (key == arg->key.one || key == arg->key.two || key == arg->key.three || key == arg->key.four || key == arg->key.five)
		color(arg, key);
	else if (key == arg->key.m)
	{
		arg->f = 'm';
		refresh(arg);
	}
	else if (key == arg->key.j)
	{
		arg->f = 'j';
		refresh(arg);
	}
	else if (key == arg->key.n)
	{
		arg->f = 'n';
		refresh(arg);
	}
	return (0);
}
