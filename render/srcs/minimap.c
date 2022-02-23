/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:57:31 by dwulfe            #+#    #+#             */
/*   Updated: 2022/02/23 20:01:20 by dwulfe           ###   ########.fr       */
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

void	var_init(int *y, int *color)
{
	*y = 0;
	color[0] = create_trgb(119, 136, 153);
	color[1] = create_trgb(0, 255, 0);
}

void	draw_minicard_field(t_data *d)
{
	int	i_j[2];
	int	color[2];
	int	xy[2];
	int	xx;
	int	yy;

	var_init(&i_j[1], color);
	while (d->parser->map[i_j[1]])
	{
		i_j[0] = 0;
		while (d->parser->map[i_j[1]][i_j[0]])
		{
			xy[0] = i_j[0];
			xy[1] = i_j[1];
			if (d->parser->map[i_j[1]][i_j[0]] == '1')
				draw_square_minicard(d, xy, color[0], 10);
			xx = (int)d->rc->pos_y;
			yy = (int)d->rc->pos_x;
			if (i_j[0] == xx && i_j[1] == yy)
				draw_square_minicard(d, xy, color[1], 10);
			i_j[0]++;
		}
		i_j[1]++;
	}
}
