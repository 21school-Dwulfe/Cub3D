/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wals_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:41:16 by dwulfe            #+#    #+#             */
/*   Updated: 2022/02/23 18:55:49 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

// texturing calculations
// side = 0 ray_dir_x < 0  position = start_position N
// side = 1 ray_dir_y < 0 position E or left from start
// side = 0 ray_dir_x > 0  position S
// side = 1 ray_dir_y > 0 position W
void	choose_textures_color(t_data *d)
{
	if (d->rc->side == 1 && d->rc->ray_dir_y < 0)
		d->rc->txtr_num = 3;
	else if (d->rc->side == 1 && d->rc->ray_dir_y >= 0)
		d->rc->txtr_num = 2;
	else if (d->rc->side == 0 && d->rc->ray_dir_x <= 0)
		d->rc->txtr_num = 0;
	else if (d->rc->side == 0 && d->rc->ray_dir_x > 0)
		d->rc->txtr_num = 1;
	else if (d->rc->map[d->rc->map_y][d->rc->map_x] == 'D')
		d->rc->txtr_num = 4;
	else
		d->rc->txtr_num = d->rc->map[d->rc->map_y][d->rc->map_x];
}

void	calculate_value_of_wall_x(t_data *d)
{
	if (d->rc->side == 0)
		d->rc->wall_x = d->rc->pos_y + d->rc->perp_wall_dist * d->rc->ray_dir_y;
	else
		d->rc->wall_x = d->rc->pos_x + d->rc->perp_wall_dist * d->rc->ray_dir_x;
	d->rc->wall_x -= floor(d->rc->wall_x);
	d->rc->txtr_x = (int)(d->rc->wall_x * (double)TXTR_W);
	if (d->rc->side == 0 && d->rc->ray_dir_x > 0)
		d->rc->txtr_x = TXTR_W - d->rc->txtr_x - 1;
	if (d->rc->side == 1 && d->rc->ray_dir_y < 0)
		d->rc->txtr_x = TXTR_W - d->rc->txtr_x - 1;
	d->rc->step = 1.0 * TXTR_H / d->rc->line_height;
	d->rc->txtr_pos = (d->rc->draw_start - WIN_Y / 2
			+ d->rc->line_height / 2) * d->rc->step;
}

void	draw_wall_textures(t_data *d, int x)
{
	int	y;

	y = d->rc->draw_start;
	while (y < d->rc->draw_end)
	{
		d->rc->txtr_y = (int)d->rc->txtr_pos & (TXTR_H - 1);
		d->rc->txtr_pos += d->rc->step;
		d->rc->color = d->textures[d->rc->txtr_num][TXTR_H * d->rc->txtr_y
			+ d->rc->txtr_x];
		if (d->rc->side == 1)
			d->rc->color = (d->rc->color >> 1) & 8355711;
		d->buff[y][x] = d->rc->color;
		y++;
	}
}
