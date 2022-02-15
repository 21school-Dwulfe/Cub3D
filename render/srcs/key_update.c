/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 19:11:39 by dwulfe            #+#    #+#             */
/*   Updated: 2022/02/06 19:17:33 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

void	rotate_screen_to_right(t_data *d)
{
	double old_dir_x;
	double old_plane_x;
	
	old_plane_x = d->rc->plane_x;
	old_dir_x = d->rc->dir_x;
	d->rc->dir_x = d->rc->dir_x * cos(-d->rc->rot_speed)
		- d->rc->dir_y * sin(-d->rc->rot_speed);
	d->rc->dir_y = old_dir_x * sin(-d->rc->rot_speed)
		+ d->rc->dir_y * cos(-d->rc->rot_speed);
	d->rc->plane_x = d->rc->plane_x * cos(-d->rc->rot_speed)
		- d->rc->plane_y * sin(-d->rc->rot_speed);
	d->rc->plane_y = old_plane_x * sin(-d->rc->rot_speed)
		+ d->rc->plane_y * cos(-d->rc->rot_speed);
}

void	rotate_screen_to_left(t_data *d)
{
	double old_dir_x;
	double old_plane_x;
	
	old_plane_x = d->rc->plane_x;
	old_dir_x = d->rc->dir_x;
	d->rc->dir_x = d->rc->dir_x * cos(d->rc->rot_speed)
		- d->rc->dir_y * sin(d->rc->rot_speed);
	d->rc->dir_y = old_dir_x * sin(d->rc->rot_speed)
		+ d->rc->dir_y * cos(d->rc->rot_speed);
	d->rc->plane_x = d->rc->plane_x * cos(d->rc->rot_speed)
		- d->rc->plane_y * sin(d->rc->rot_speed);
	d->rc->plane_y = old_plane_x * sin(d->rc->rot_speed)
		+ d->rc->plane_y * cos(d->rc->rot_speed);
}

void	key_update(t_data *d)
{
	double old_dir_x = d->rc->dir_x;
	double old_dir_y = d->rc->dir_y;
	double old_plane_x = d->rc->plane_x;
	double old_plane_y = d->rc->plane_y;
	double old_pos_x = d->rc->pos_x;
	double old_pos_y = d->rc->pos_y;
	
	if (d->key[W])
	{
		if (!d->rc->map[(int)(d->rc->pos_x + d->rc->dir_x \
			* d->rc->move_speed)][(int)(d->rc->pos_y)])
			d->rc->pos_x += d->rc->dir_x * d->rc->move_speed;
		if (!d->rc->map[(int)(d->rc->pos_x)][(int)(d->rc->pos_y \
			+ d->rc->dir_y * d->rc->move_speed)])
		d->rc->pos_y += d->rc->dir_y * d->rc->move_speed;
	}
	if (d->key[S])
	{
		if (!d->rc->map[(int)(d->rc->pos_x - d->rc->dir_x \
			* d->rc->move_speed)][(int)(d->rc->pos_y)])
			d->rc->pos_x -= d->rc->dir_x * d->rc->move_speed;
		if (!d->rc->map[(int)(d->rc->pos_x)][(int)(d->rc->pos_y \
			- d->rc->dir_y * d->rc->move_speed)])
		d->rc->pos_y -= d->rc->dir_y * d->rc->move_speed;
	}
	if (d->key[D])
	{
		if (!d->rc->map[(int)(d->rc->pos_x - d->rc->dir_x \
			* d->rc->move_speed)][(int)(d->rc->pos_y)])
			d->rc->pos_x += d->rc->plane_x * d->rc->move_speed;
		if (!d->rc->map[(int)(d->rc->pos_x)][(int)(d->rc->pos_y \
			- d->rc->dir_y * d->rc->move_speed)])
		d->rc->pos_y += d->rc->plane_y * d->rc->move_speed;
	}
	if (d->key[A])
	{
		if (!d->rc->map[(int)(d->rc->pos_x - d->rc->dir_x \
			* d->rc->move_speed)][(int)(d->rc->pos_y)])
			d->rc->pos_x -= d->rc->plane_x * d->rc->move_speed;
		if (!d->rc->map[(int)(d->rc->pos_x)][(int)(d->rc->pos_y \
			- d->rc->dir_y * d->rc->move_speed)])
		d->rc->pos_y -= d->rc->plane_y * d->rc->move_speed;
	}
	if (d->key_r)
		rotate_screen_to_right(d);
	if (d->key_l)
		rotate_screen_to_left(d);
	if (d->rc->dir_x != old_dir_x || d->rc->dir_y != old_dir_y || d->rc->plane_x != old_plane_x || d->rc->plane_y  != old_plane_y || old_pos_x != d->rc->pos_x || old_pos_y != d->rc->pos_y)
		printf("plane_X = %g plane_Y = %g dir_x %g dir_y %g pos_x %g pos_y %g \n", d->rc->plane_x, d->rc->plane_y, d->rc->dir_y, d->rc->dir_x, d->rc->pos_x, d->rc->pos_y);
}
