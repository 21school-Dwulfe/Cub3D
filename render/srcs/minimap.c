/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:57:31 by dwulfe            #+#    #+#             */
/*   Updated: 2022/02/06 16:52:33 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

void	draw_player_minicard(int *matrix, int *xy, int size)
{
	int	xa;
	int	ya;

	xa = xy[0] * 20;
	ya = xy[1] * 20;
	while (ya < (xy[1] * 20) + size)
	{
		xa = xy[0] * 20;
		while (xa < (xy[0] * 20) + size )
		{
			matrix[ya * WIN_Y + xa] = 0x00FF00;
			xa += 1;
		}
		ya += 1;
	}
}
