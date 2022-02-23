/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenario.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:11:17 by dwulfe            #+#    #+#             */
/*   Updated: 2022/02/23 19:56:24 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

void	add_enemy(t_data *d, int y, int x)
{
	if (d->num_enemies < ENEMIES_COUNT)
	{
		d->sprite[d->num_enemies].x = (double)y + 0.5;
		d->sprite[d->num_enemies].y = (double)x + 0.5;
		d->sprite[d->num_enemies].texture = 0;
		d->num_enemies++;
	}
}

void	set_start_ammunition(t_data *d)
{
	d->weapon[0].in_fov = 1;
	d->weapon[1].in_fov = 1;
	d->weapon[2].in_fov = 1;
	d->weapon[3].in_fov = 0;
	d->available_weapon[0] = 1;
	d->available_weapon[1] = 2;
	d->available_weapon[2] = 3;
	d->available_weapon[3] = 4;
	d->act_w = &d->weapon[0];
}
