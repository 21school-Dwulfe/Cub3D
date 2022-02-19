/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:57:31 by dwulfe            #+#    #+#             */
/*   Updated: 2022/02/17 20:39:01 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

void	draw_square_minicard(t_data *data, int *xy, int color, int size)
{
	int	xa;
	int	ya;

	xa = xy[0] * size;
	ya = xy[1] * size;
	while (ya < (xy[1] * size) + size)
	{
		xa = xy[0] * size;
		while (xa < (xy[0] * size) + size)
		{
			data->buff[ya][xa] = color;
			xa += 1;
		}
		ya += 1;
	}
}

void	draw_minicard_field(t_data *d)
{
	int	x;
	int	y;
	int	color[2];
	int xy[2];
	int	xx;
	int yy;
	
	y = 0;
	color[0] = create_trgb(119, 136, 153);
	color[1] = create_trgb(0, 255, 0);
	while (d->parser->map[y])
	{
		x = 0;
		while (d->parser->map[y][x])
		{
			xy[0] = x;
			xy[1] = y;
			if (d->parser->map[y][x] == '1')
				draw_square_minicard(d, xy, color[0], 10);
			xx =  (int)d->rc->pos_y;
			yy = (int)d->rc->pos_x;
			if (x ==  xx && y == yy)
				draw_square_minicard(d, xy, color[1], 10);
			x++;
		}
		y++;
	}
}
