/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:09:54 by dwulfe            #+#    #+#             */
/*   Updated: 2022/02/23 18:55:02 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

void	control_x_y(t_data *d, int x, int y)
{
	if (x < WIN_X * 0.3 || x > WIN_X * 0.7)
	{
		mlx_mouse_move(d->mlx_win, WIN_X / 2, y);
		d->rc->x = WIN_X / 2;
	}
	if (y < WIN_Y * 0.3 || y > WIN_Y * 0.7)
	{
		mlx_mouse_move(d->mlx_win, x, WIN_Y / 2);
		d->rc->y = WIN_X / 2;
	}
}

int	mouse_rotation(int x, int y, void *p)
{
	t_data	*d;
	int		delta;

	d = (t_data *)p;
	delta = d->rc->x - x;
	d->rc->mouse_counter = 1;
	d->last_mouse_rotation = d->curr_time;
	if (abs(delta) > 10 && d->rc->rot_speed < 0.045)
			d->rc->rot_speed += 0.015;
	if (abs(delta) > 25 && d->rc->rot_speed < 0.06)
		d->rc->rot_speed += 0.015;
	if (delta < -1)
	{
		d->key_r++;
		d->key_l = 0;
	}
	else if (delta > 1)
	{
		d->key_r = 0;
		d->key_l++;
	}
	d->rc->x = x;
	control_x_y(d, x, y);
	return (0);
}

int	mouse_buttons_down(int key, int x, int y, void *data)
{
	t_data	*d;

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
	t_data	*d;

	d = (t_data *)data;
	(void)key;
	(void)x;
	(void)y;
	(void)d;
	printf("mouse keyup %d\n", key);
	return (0);
}

void	stop_mouse_rotation(t_data *d)
{
	if (d->rc->mouse_counter && d->curr_time - d->last_mouse_rotation >= 3)
	{
		d->rc->mouse_counter = 0;
		d->rc->rot_speed = 0.03;
		write(1, "clean\n\n\n", 9);
		d->key_l = 0;
		d->key_r = 0;
	}
}
