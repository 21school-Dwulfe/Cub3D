/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 13:02:03 by dwulfe            #+#    #+#             */
/*   Updated: 2022/02/23 19:12:23 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

void	draw_weapon_x(t_data *d, t_img *weapon, int *offsets, int *vars)
{
	int	x;

	x = 0;
	while (x < weapon->img_width)
	{
		if (weapon->addr[vars[3] * weapon->img_width + x] != 0xFFFFFF
			&& weapon->addr[vars[3] * weapon->img_width + x] >= 0)
		{
			vars[0] = 1;
			while (vars[0] <= vars[2])
			{
				vars[1] = 1;
				while (vars[1] <= vars[2])
				{
					d->buff[vars[3] + offsets[1] + vars[0] + vars[3]]
					[x + offsets[0] + vars[1] + x]
						= weapon->addr[vars[3] * weapon->img_width + x];
					vars[1]++;
				}
				vars[0]++;
			}
		}
		x++;
	}
}

void	draw_weapon(t_data *d, t_img *weapon, int partial)
{
	int	y;
	int	offsets[2];
	int	increase[4];

	y = 0;
	ft_bzero(increase, sizeof(int) * 4);
	increase[2] = 2;
	offsets[0] = WIN_X / 2;
	offsets[1] = WIN_Y - 1 - ((weapon->img_height - partial) * increase[2]);
	while (y < weapon->img_height - partial)
	{	
		increase[3] = y;
		draw_weapon_x(d, weapon, offsets, increase);
		y++;
	}
}

int	calc_change_weapon(t_data *d)
{
	static int	partial;
	static int	result;

	if (d->act_w->changing)
	{
		if (d->curr_time - d->act_w->changing <= 1)
		{
			partial = d->act_w->img->img_height / 24;
			result = d->act_w->img->img_height - partial;
		}
		else if (d->curr_time - d->act_w->changing < 24)
		{
			result -= partial ;
		}
		if (d->curr_time - d->act_w->changing == 24)
		{
			partial = 0;
			result = 0;
			d->act_w->changing = 0;
			return (0);
		}
	}
	return (result);
}

void	draw_weapon_animation(t_data *d)
{
	if (!d->mouse_left)
		draw_weapon(d, d->act_w->img + d->act_w->active, calc_change_weapon(d));
	if (d->mouse_left && !d->act_w->changing && !d->act_w->realoding)
	{
		if (d->act_w->active == 0)
		{
			if (!d->act_w->start)
				d->act_w->start = d->curr_time;
		}
		if (d->act_w->start)
		{
			if ((d->act_w->start - d->curr_time) % 3 == 0)
			{
				d->act_w->active = d->act_w->active + 1;
			}
		}
		if (d->act_w->active == d->act_w->num_img)
		{
			d->act_w->start = 0;
			d->mouse_left = 0;
			d->act_w->active = 0;
		}
		draw_weapon(d, &d->act_w->img[d->act_w->active], 0);
	}
}
