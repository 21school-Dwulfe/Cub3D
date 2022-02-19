/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 13:02:03 by dwulfe            #+#    #+#             */
/*   Updated: 2022/02/19 17:23:14 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

void	draw_weapon(t_data *d, t_img *weapon)
{
	int	x;
	int y;
	int	x_offset;
	int	y_offset;
	int	increase[4];

	y = 0;
	ft_bzero(increase, sizeof(int) * 4);
	increase[2] = 2;
	x_offset = WIN_X / 2;
	y_offset =  WIN_Y - 1 - weapon->img_height * increase[2];
	while (y < weapon->img_height)
	{	
		x = 0;
		while (x < weapon->img_width)
		{
			if (weapon->addr[y * weapon->img_width + x] != 0xFFFFFF)
			{
				increase[0] = 1;
				while (increase[0] <= 3)
				{
					increase[1] = 1;
					while (increase[1] <= 3)
					{
						d->buff[y + y_offset + increase[0] + y][x + x_offset + increase[1] + x] = weapon->addr[y * weapon->img_width + x];
						increase[1]++;
					}
					increase[0]++;
				}
			}
			x++;
		}
		y++;
	}
}

// void	choose_weapon(t_data *data, t_weapon *weapon)
// {
	
// }

void	draw_weapon_animation(t_data *d)
{
	if (!d->mouse_left)
		draw_weapon(d, d->act_weapon->img + d->act_weapon->active);
	if (d->mouse_left)
    {
		if (d->act_weapon->active == 0)
		{
			if (!d->act_weapon->start)
				d->act_weapon->start =  d->curr_time;;
		}
		if (d->act_weapon->start)
		{
			if ((d->act_weapon->start - d->curr_time) % 3 == 0)
			{
				d->act_weapon->active = d->act_weapon->active + 1;
			}
		}
		if (d->act_weapon->active == d->act_weapon->num_img)
		{
			d->act_weapon->start = 0;
			d->mouse_left = 0;
			d->act_weapon->active = 0;
		}
		draw_weapon(d, &d->act_weapon->img[d->act_weapon->active]);
    }
}
