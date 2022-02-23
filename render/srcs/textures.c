/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:56:46 by dwulfe            #+#    #+#             */
/*   Updated: 2022/02/23 19:45:21 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

void	calc_transformation(t_data *d, int i)
{
	d->sp.sprite_x = d->sprite[d->spr_order[i]].x - d->rc->pos_x;
	d->sp.sprite_y = d->sprite[d->spr_order[i]].y - d->rc->pos_y;
	d->sp.inv_det = 1.0 / (d->rc->plane_x * d->rc->dir_y
			- d->rc->dir_x * d->rc->plane_y);
	d->sp.transform_x = d->sp.inv_det * (d->rc->dir_y * d->sp.sprite_x
			- d->rc->dir_x * d->sp.sprite_y);
	d->sp.transform_y = d->sp.inv_det * (-d->rc->plane_y
			* d->sp.sprite_x + d->rc->plane_x * d->sp.sprite_y);
	d->sp.sprite_screen_x = (int)(WIN_X / 2)
		*(1 + d->sp.transform_x / d->sp.transform_y);
	d->sp.v_move_screen = (int)(0.0 / d->sp.transform_y);
}

void	calc_draw_start_end(t_data *d)
{
	d->sp.sprite_height = (int)fabs((WIN_Y / d->sp.transform_y) / 1);
	d->sp.draw_start_y = -d->sp.sprite_height / 2
		+ WIN_Y / 2 + d->sp.v_move_screen;
	if (d->sp.draw_start_y < 0)
		d->sp.draw_start_y = 0;
	d->sp.draw_end_y = d->sp.sprite_height / 2
		+ WIN_Y / 2 + d->sp.v_move_screen;
	if (d->sp.draw_end_y >= WIN_Y)
		d->sp.draw_end_y = WIN_Y - 1;
	d->sp.spr_width = (int)fabs((WIN_Y / d->sp.transform_y) / 1);
	d->sp.draw_start_x = -d->sp.spr_width / 2 + d->sp.sprite_screen_x;
	if (d->sp.draw_start_x < 0)
		d->sp.draw_start_x = 0;
	d->sp.draw_end_x = d->sp.spr_width / 2 + d->sp.sprite_screen_x;
	if (d->sp.draw_end_x >= WIN_X)
		d->sp.draw_end_x = WIN_X - 1;
}

void	textures_y(t_data *d, int i)
{
	int	y;

	y = d->sp.draw_start_y;
	while (y < d->sp.draw_end_y)
	{
		d->sp.d = (y - d->sp.v_move_screen) * 256 - WIN_Y * 128
			+ d->sp.sprite_height * 128;
		d->sp.tex_y = ((d->sp.d * \
			d->txtr[d->sprite[d->spr_order[i]].texture].img_height)
				/ d->sp.sprite_height) / 256;
		d->sp.color = d->txtr[d->sprite[
			d->spr_order[i]].texture].addr
		[d->txtr[d->sprite[d->spr_order[i]].texture].img_width
			* d->sp.tex_y + d->sp.tex_x];
		if ((d->sp.color & 0x00FFFFFF) != 0 && d->sp.color > 0)
			d->buff[y][d->sp.stripe] = d->sp.color;
		y++;
	}
}

void	textures_con(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->num_sprites)
	{
		calc_transformation(d, i);
		calc_draw_start_end(d);
		d->sp.stripe = d->sp.draw_start_x;
		while (d->sp.stripe < d->sp.draw_end_x)
		{
			d->sp.tex_x = (int)((256 * (d->sp.stripe
							- (-d->sp.spr_width / 2 + d->sp.sprite_screen_x))
						* d->txtr[d->sprite[d->spr_order[i]].texture].img_width
						/ d->sp.spr_width) / 256);
			if (d->sp.transform_y > 0 && d->sp.stripe > 0
				&& d->sp.stripe < WIN_X && d->sp.transform_y
				< d->rc->z_buffer[d->sp.stripe])
				textures_y(d, i);
			d->sp.stripe++;
		}
		i++;
	}
}

void	textures(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->num_sprites)
	{
		d->spr_order[i] = i;
		d->sprite_distance[i] = ((d->rc->pos_x - d->sprite[i].x)
				* (d->rc->pos_x - d->sprite[i].x)
				+ (d->rc->pos_y - d->sprite[i].y)
				* (d->rc->pos_y - d->sprite[i].y));
		i++;
	}
	sort_sprites(d->spr_order, d->sprite_distance, d->num_enemies);
	textures_con(d);
}
