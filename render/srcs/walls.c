/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:43:52 by dwulfe            #+#    #+#             */
/*   Updated: 2022/02/06 19:23:59 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../render.h"

//Calculate height of line to draw on screen
//calculate lowest and highest pixel to fill in current stripe
void	calucate_height_of_line(int *draw_start, int *draw_end,
	int perp_wall_dist)
{
	int	line_height;

	line_height = (int)(WIN_Y / perp_wall_dist);
	*draw_start = -line_height / 2 + WIN_Y / 2;
	if (*draw_start < 0)
		*draw_start = 0;
	*draw_end = line_height / 2 + WIN_Y / 2;
	if (*draw_end >= WIN_Y)
		*draw_end = WIN_Y - 1;
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

void	walls(t_data *data)
{
	(void)data;
	// int	x;

	// x = 0;
	// while (x < WIN_X)
	// {

	// 	x++;
	// }
}