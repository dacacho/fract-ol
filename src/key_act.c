/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_act.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <danierod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:36:58 by danierod          #+#    #+#             */
/*   Updated: 2022/11/22 11:41:35 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

void    key_up(t_a *arg, int dir)
{
    if (dir == 1)
        printf("key up(press): %i\n", arg->key.w);
    else
        printf("key up(release): %i\n", arg->key.w);
}

void    key_down(t_a *arg, int dir)
{
    if (dir == 1)
        printf("key up(press): %i\n", arg->key.s);
    else
        printf("key up(release): %i\n", arg->key.s);
}

void    key_left(t_a *arg, int dir)
{
    if (dir == 1)
        printf("key up(press): %i\n", arg->key.a);
    else
        printf("key up(release): %i\n", arg->key.a);
}

void    key_right(t_a *arg, int dir)
{
    if (dir == 1)
        printf("key up(press): %i\n", arg->key.d);
    else
        printf("key up(release): %i\n", arg->key.d);
}