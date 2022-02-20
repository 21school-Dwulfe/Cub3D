/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 19:11:39 by dwulfe            #+#    #+#             */
/*   Updated: 2022/02/17 22:15:47 by dwulfe           ###   ########.fr       */
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

void	move_straight(t_data *d)
{
	int	next_x;
	int	next_y;

	next_x = (int)(d->rc->pos_x + d->rc->dir_x * d->rc->move_speed);
	next_y = (int)(d->rc->pos_y + d->rc->dir_y * d->rc->move_speed);
	if (!d->rc->map[next_x][next_y])
	{
		d->rc->pos_x += d->rc->dir_x * d->rc->move_speed;
		d->rc->pos_y += d->rc->dir_y * d->rc->move_speed;
	}
}

void	move_back(t_data *d)
{
	int	next_x;
	int	next_y;

	next_x = (int)(d->rc->pos_x - d->rc->dir_x * d->rc->move_speed);
	next_y = (int)(d->rc->pos_y - d->rc->dir_y * d->rc->move_speed);
	if (!d->rc->map[next_x][next_y])
	{
		d->rc->pos_x -= d->rc->dir_x * d->rc->move_speed;
		d->rc->pos_y -= d->rc->dir_y * d->rc->move_speed;
	}
}

void	move_to_right(t_data *d)
{
	int	next_x;
	int	next_y;

	next_x = (int)(d->rc->pos_x + d->rc->plane_x * d->rc->move_speed);
	next_y = (int)(d->rc->pos_y + d->rc->plane_y * d->rc->move_speed);
	if (!d->rc->map[next_x][next_y])
	{
		d->rc->pos_x += d->rc->plane_x * d->rc->move_speed;
		d->rc->pos_y += d->rc->plane_y * d->rc->move_speed;
	}
}

void	move_to_left(t_data *d)
{
	int	next_x;
	int	next_y;

	next_x = (int)(d->rc->pos_x - d->rc->plane_x * d->rc->move_speed);
	next_y = (int)(d->rc->pos_y - d->rc->plane_y * d->rc->move_speed);
	if (!d->rc->map[next_x][next_y])
	{
		d->rc->pos_x -= d->rc->plane_x * d->rc->move_speed;
		d->rc->pos_y -= d->rc->plane_y * d->rc->move_speed;
	}
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
		move_straight(d);
	if (d->key[S])
		move_back(d);
	if (d->key[D])
		move_to_right(d);
	if (d->key[A])
		move_to_left(d);
	if (d->key_r)
		rotate_screen_to_right(d);
	if (d->key_l)
		rotate_screen_to_left(d);
	if (d->rc->dir_x != old_dir_x || d->rc->dir_y != old_dir_y || d->rc->plane_x != old_plane_x
		|| d->rc->plane_y  != old_plane_y || old_pos_x != d->rc->pos_x || old_pos_y != d->rc->pos_y)
	printf("plane_X = %g plane_Y = %g dir_x %g dir_y %g pos_x %g pos_y %g  side %d ray_dir_y %g ray_dir_x %g \n",
		d->rc->plane_x, d->rc->plane_y, d->rc->dir_y, d->rc->dir_x, d->rc->pos_x, d->rc->pos_y, d->rc->side, d->rc->ray_dir_y, d->rc->ray_dir_x);
}
// side = 0, plane_x = 0 plane_y = 0.66 ray_dir_y = 0.65 ray_dir_x < 0  position = start_position N
// side = 1 ray_dir_y < 0 position E or left from start
// side = 0 ray_dir_x >0  position 
// side = 1 ray_dir_y > 0