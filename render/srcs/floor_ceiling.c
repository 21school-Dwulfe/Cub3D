/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:00:44 by dwulfe            #+#    #+#             */
/*   Updated: 2022/02/06 20:39:11 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

void	floor_ceiling(t_data *d)
{
	int	y;
	int	x;
	(void)d;
	// int	end;
	int	floor;
	int	ceiling;

	floor = create_trgb( 
		d->parser->colors->floor->r,
		d->parser->colors->floor->g,
		d->parser->colors->floor->b);
	ceiling = create_trgb( 
		d->parser->colors->cell->r,
		d->parser->colors->cell->g,
		d->parser->colors->cell->b);
	// end = WIN_Y * WIN_X;
	y = WIN_Y / 2 - 1;
	while (y < WIN_Y)
	{
		x = -1;
		while (++x < WIN_X)
		{
			// d->matrix[end - (y * WIN_X) - 1 + x] = ceiling;
			// d->matrix[y * WIN_X + x] = floor;
			d->buff[WIN_Y- y - 1][x] = ceiling;
			d->buff[y][x] = floor;
		}
		y++;
	}
}