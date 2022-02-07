/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:43:52 by dwulfe            #+#    #+#             */
/*   Updated: 2022/02/07 21:49:18 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../render.h"

//Calculate height of line to draw on screen
//calculate lowest and highest pixel to fill in current stripe
void	calc_height_and_dist_of(int *line_height, int *draw_start,
	int *draw_end, int perp_wall_dist)
{
	*line_height = (int)(WIN_Y / perp_wall_dist);
	*draw_start = -(*line_height) / 2 + WIN_Y / 2;
	if (*draw_start < 0)
		*draw_start = 0;
	*draw_end = *line_height / 2 + WIN_Y / 2;
	if (*draw_end >= WIN_Y)
		*draw_end = WIN_Y - 1;
}

void	choose_pixel_of_wall(t_data *d)
{
	d->rc->txtr_x = (int)(d->rc->wall_x * (double)64);
	if (d->rc->side == 0 && d->rc->ray_dir_x > 0)
		d->rc->txtr_x = 64 - d->rc->txtr_x - 1;
	if (d->rc->side == 1 && d->rc->ray_dir_y < 0)
		d->rc->txtr_x = d->rc->txtr_x - 1;
	d->rc->step = 1.0 * 64 / d->rc->line_height;
	//d->rc->txtr_pos = d->rc->draw_start -
}

void	vert_line(t_data *info, int x, int *y2, int color)
{
	int	y;

	y = y2[0];
	while (y <= y2[1])
	{
		mlx_pixel_put(info->mlx, info->mlx_win, x, y, color);
		y++;
	}
}

void	matrix_vert_line(t_data *data, int *y2, t_rgb *c)
{
	int	i;
	int	j;

	i = y2[0];
	j = y2[1] * WIN_X;
	while (i < WIN_Y * WIN_X && i <= j)
	{
		if (data->matrix[i] <= j)
		{
			data->matrix[i] = create_trgb(c->t, c->r, c->g, c->b);
		}
		i += WIN_X;
	}
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
		if (d->map[d->rc->map_x][d->rc->map_y] > 0)
			d->rc->hit = 1;
	}
	if (d->rc->side == 0)
		d->rc->perp_wall_dist = (d->rc->side_dist_x - d->rc->delta_dist_x);
	else
		d->rc->perp_wall_dist = (d->rc->side_dist_y - d->rc->delta_dist_y);
}

void	calc_step_and_dist(t_data *d)
{
	if (d->rc->ray_dir_x < 0)
	{
		d->rc->step_x = -1;
		d->rc->side_dist_x = (d->params->pos_x - d->rc->map_x) * d->rc->delta_dist_x;
	}
	else
	{
		d->rc->step_x = -1;
		d->rc->side_dist_x = (d->rc->map_x + 1 - d->params->pos_x);
	}
	if (d->rc->ray_dir_y < 0)
	{
		d->rc->step_y = -1;
		d->rc->side_dist_y = (d->params->pos_y - d->rc->map_y);
	}
	else
	{
		d->rc->step_y = -1;
		d->rc->side_dist_y = (d->rc->map_y + 1 - d->params->pos_y);
	}
}

void	calc_ray_position_direction(t_data *d, int x)
{
	d->rc->camera_x = 2 * x / (double)WIN_X - 1;
	d->rc->ray_dir_x = d->params->dir_x + d->params->plane_x * d->rc->camera_x;
	d->rc->ray_dir_y = d->params->dir_y + d->params->plane_y * d->rc->camera_x;
	d->rc->map_x = (int)d->params->pos_x;
	d->rc->map_y = (int)d->params->pos_y;
	d->rc->delta_dist_x = fabs(1 / d->rc->ray_dir_x);
	d->rc->delta_dist_y = fabs(1 / d->rc->ray_dir_y);
}

void	walls(t_data *d)
{
	int	x;

	x = 0;
	while (x < WIN_X)
	{
		calc_ray_position_direction(d, x);
		calc_step_and_dist(d);
		digital_differential_analyzer(d);
		calc_height_and_dist_of(d->rc->draw_start, d->rc->draw_end, d->rc->perp_wall_dist);
		choose_pixel_of_wall(d);
		pixels_in_matrix_buff(d);
		x++;
	}
}