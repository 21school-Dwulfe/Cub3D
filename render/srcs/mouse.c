/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:09:54 by dwulfe            #+#    #+#             */
/*   Updated: 2022/02/19 12:23:54 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

int	mouse_rotation(int x,int y, void *p)
{
	t_data	*d;
	int		delta;

	d = (t_data *)p;
	delta = d->rc->x - x;
	d->rc->mouse_counter = 1;
	d->last_mouse_rotation = d->curr_time;	
	if (abs(delta) > 10 && d->rc->rot_speed < 0.06)
			d->rc->rot_speed += 0.03;
	if (delta < 0)
	{
		d->key_r++;
		d->key_l = 0;
	}
	else if (delta > 0)
	{
		d->key_r = 0;
		d->key_l++;
	}
	if (x < WIN_X * 0.3 || x > WIN_X * 0.7 || y < WIN_Y * 0.3 || y > WIN_Y * 0.7)
	{
		mlx_mouse_move(d->mlx_win, WIN_X / 2, WIN_Y / 2);
		d->rc->x = WIN_X / 2;
	}
	d->rc->x = x;
	printf("Mouse moving in Win3, at %dx%d.delta = %d middle = %d\n ", x, y, delta, WIN_X / 2);
	return (0);
}

int	mouse_buttons_down(int	key, int x, int y, void *data)
{
	t_data *d;

	d = (t_data *)data;
	(void)key;
	(void)x;
	(void)y;
	(void)d;
	if (key == 1)
		d->mouse_left = 1;
	if (key == 2)
		d->mouse_left = 2;
	printf("mouse keydown %d\n", key);
	return (0);
}

int	mouse_buttons_up(int key, int x, int y, void *data)
{
	t_data *d;

	d = (t_data *)data;
	(void)key;
	(void)x;
	(void)y;
	(void)d;
	// if (key == 1)
	// 	d->mouse_left = 0;
	// if (key == 2)
	// 	d->mouse_left = 0;
	printf("mouse keyup %d\n", key);
	return (0);
}
