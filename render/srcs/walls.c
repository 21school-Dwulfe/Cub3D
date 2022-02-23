/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:43:52 by dwulfe            #+#    #+#             */
/*   Updated: 2022/02/23 18:55:41 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

void	calc_ray_position_direction(t_data *d, int x)
{
	d->rc->camera_x = 2 * x / (double)WIN_X - 1;
	d->rc->ray_dir_x = d->rc->dir_x + d->rc->plane_x * d->rc->camera_x;
	d->rc->ray_dir_y = d->rc->dir_y + d->rc->plane_y * d->rc->camera_x;
	d->rc->map_x = (int)d->rc->pos_x;
	d->rc->map_y = (int)d->rc->pos_y;
	d->rc->delta_dist_x = fabs(1 / d->rc->ray_dir_x);
	d->rc->delta_dist_y = fabs(1 / d->rc->ray_dir_y);
	d->rc->hit = 0;
}

void	calc_height_and_dist_of(t_data *d)
{
	d->rc->line_height = (int)(WIN_Y / d->rc->perp_wall_dist);
	d->rc->draw_start = -d->rc->line_height / 2 + WIN_Y / 2;
	if (d->rc->draw_start < 0)
		d->rc->draw_start = 0;
	d->rc->draw_end = d->rc->line_height / 2 + WIN_Y / 2;
	if (d->rc->draw_end >= WIN_Y)
		d->rc->draw_end = WIN_Y - 1;
}

void	digital_differential_analyzer(t_data *d)
{
	while (d->rc->hit == 0)
	{
		if (d->rc->side_dist_x < d->rc->side_dist_y)
		{
			d->rc->side_dist_x += d->rc->delta_dist_x;
			d->rc->map_x += d->rc->step_x;
			d->rc->side = 0;
		}
		else
		{
			d->rc->side_dist_y += d->rc->delta_dist_y;
			d->rc->map_y += d->rc->step_y;
			d->rc->side = 1;
		}
		if (d->rc->map[d->rc->map_x][d->rc->map_y] == 1)
			d->rc->hit = 1;
	}
	if (d->rc->side == 0)
		d->rc->perp_wall_dist = (d->rc->map_x - d->rc->pos_x
				+ (1 - d->rc->step_x) / 2) / d->rc->ray_dir_x;
	else
		d->rc->perp_wall_dist = (d->rc->map_y - d->rc->pos_y
				+ (1 - d->rc->step_y) / 2) / d->rc->ray_dir_y;
}

void	calc_step_and_dist(t_data *d)
{
	if (d->rc->ray_dir_x < 0)
	{
		d->rc->step_x = -1;
		d->rc->side_dist_x = (d->rc->pos_x - d->rc->map_x)
			* d->rc->delta_dist_x;
	}
	else
	{
		d->rc->step_x = 1;
		d->rc->side_dist_x = (d->rc->map_x + 1.0 - d->rc->pos_x)
			* d->rc->delta_dist_x;
	}
	if (d->rc->ray_dir_y < 0)
	{
		d->rc->step_y = -1;
		d->rc->side_dist_y = (d->rc->pos_y - d->rc->map_y)
			* d->rc->delta_dist_y;
	}
	else
	{
		d->rc->step_y = 1;
		d->rc->side_dist_y = (d->rc->map_y + 1.0 - d->rc->pos_y)
			* d->rc->delta_dist_y;
	}
}

void	walls(t_data *d)
{
	int	x;

	(void)d;
	x = 0;
	while (x < WIN_X)
	{
		calc_ray_position_direction(d, x);
		calc_step_and_dist(d);
		digital_differential_analyzer(d);
		calc_height_and_dist_of(d);
		choose_textures_color(d);
		calculate_value_of_wall_x(d);
		draw_wall_textures(d, x);
		d->rc->z_buffer[x] = d->rc->perp_wall_dist;
		x++;
	}
}
