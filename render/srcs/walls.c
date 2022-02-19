/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:43:52 by dwulfe            #+#    #+#             */
/*   Updated: 2022/02/16 22:30:01 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../render.h"

//Calculate height of line to draw on screen
//calculate lowest and highest pixel to fill in current stripe
void	calc_height_and_dist_of(t_data *d)
{
	//Calculate height of line to draw on screen
	d->rc->line_height = (int)(WIN_Y / d->rc->perp_wall_dist);
	//calculate lowest and highest pixel to fill in current stripe
	d->rc->draw_start = -d->rc->line_height / 2 + WIN_Y / 2;
	if (d->rc->draw_start < 0)
		d->rc->draw_start = 0;
	d->rc->draw_end = d->rc->line_height / 2 + WIN_Y / 2;
	if (d->rc->draw_end >= WIN_Y)
		d->rc->draw_end = WIN_Y - 1;
}

void	choose_pixel_of_wall(t_data *d)
{
	d->rc->txtr_x = (int)(d->rc->wall_x * (double)TXTR_W);
	if (d->rc->side == 0 && d->rc->ray_dir_x > 0)
		d->rc->txtr_x = TXTR_W - d->rc->txtr_x - 1;
	if (d->rc->side == 1 && d->rc->ray_dir_y < 0)
		d->rc->txtr_x = d->rc->txtr_x - 1;
	d->rc->step = 1.0 * TXTR_W / d->rc->line_height;
	d->rc->txtr_pos = (d->rc->draw_start - WIN_Y / 2
		+ d->rc->line_height / 2) * d->rc->step;
}

void	digital_differential_analyzer(t_data *d)
{
	while (d->rc->hit == 0)
	{
		//jump to next map square, OR in x-direction, OR in y-direction
		if (d->rc->side_dist_x < d->rc->side_dist_y)
		{
			d->rc->side_dist_x += d->rc->delta_dist_x;
			d->rc->map_x += d->rc->step_x;
			d->rc->side = 0;
		}
		else
		{
			d->rc->side_dist_y += d->rc->delta_dist_y;
			d->rc->map_y += d->rc->step_y;
			d->rc->side = 1;
		}
		if (d->rc->map[d->rc->map_y][d->rc->map_x] > 0)
			d->rc->hit = 1;
	}
	if (d->rc->side == 0)
		d->rc->perp_wall_dist = (d->rc->map_x - d->rc->pos_x + (1 - d->rc->step_x) / 2) / d->rc->ray_dir_x;
	else
		d->rc->perp_wall_dist = (d->rc->map_y - d->rc->pos_y + (1 - d->rc->step_y) / 2) / d->rc->ray_dir_y;
}

void	calc_step_and_dist(t_data *d)
{
	if (d->rc->ray_dir_x < 0)
	{
		d->rc->step_x = -1;
		d->rc->side_dist_x = (d->rc->pos_x - d->rc->map_x) * d->rc->delta_dist_x;
	}
	else
	{
		d->rc->step_x = 1;
		d->rc->side_dist_x = (d->rc->map_x + 1.0 - d->rc->pos_x) * d->rc->delta_dist_x;
	}
	if (d->rc->ray_dir_y < 0)
	{
		d->rc->step_y = -1;
		d->rc->side_dist_y = (d->rc->pos_y - d->rc->map_y) * d->rc->delta_dist_y;
	}
	else
	{
		d->rc->step_y = 1;
		d->rc->side_dist_y = (d->rc->map_y + 1.0 - d->rc->pos_y) * d->rc->delta_dist_y;
	}
}

void	calc_ray_position_direction(t_data *d, int x)
{
	d->rc->camera_x = 2 * x / (double)WIN_X - 1;
	d->rc->ray_dir_x = d->rc->dir_x + d->rc->plane_x * d->rc->camera_x;
	d->rc->ray_dir_y = d->rc->dir_y + d->rc->plane_y * d->rc->camera_x;
	d->rc->map_x = (int)d->rc->pos_x;
	d->rc->map_y = (int)d->rc->pos_y;
	d->rc->delta_dist_x = fabs(1 / d->rc->ray_dir_x);
	d->rc->delta_dist_y = fabs(1 / d->rc->ray_dir_y);
	d->rc->hit = 0;
}

void	textures_coordinate(t_data *d, int x)
{
	int y;

	y = d->rc->draw_start;
	(void)x;
	while (y < d->rc->draw_end)
	{
		d->rc->txtr_y = (int)d->rc->txtr_pos & (TXTR_H - 1);
		d->rc->txtr_pos += d->rc->step;
		d->rc->color = 8355711 ;//d->textures[d->rc->txtr_num].addr[TXTR_H * d->rc->txtr_y + d->rc->txtr_x];
		if (d->rc->side == 1)
			d->rc->color = (d->rc->color >> 1) & 8355711;
		d->buff[y][x] = d->rc->color;
		y++;
	} 
}

void	buff_vert_line( t_data *d, int x, int draw_start, int draw_end, int color)
{
	int	y;

	y = draw_start;
	while (y <= draw_end)
	{
		d->buff[y][x] = color;
		y++;
	}

}

void	verLine(t_data *info, int x, int y1, int y2, int color)
{
	int	y;

	y = y1;
	while (y <= y2)
	{
		mlx_pixel_put(info->mlx, info->mlx_win, x, y, color);
		y++;
	}
}

void	untextured_draw_line(t_data *d, int x)
{
	int	color;

	if (d->rc->map[d->rc->map_y][d->rc->map_x] == 1)
		color = 0xFF0000;
	else if (d->rc->map[d->rc->map_y][d->rc->map_x] == 2)
		color = 0x00FF00;
	else if (d->rc->map[d->rc->map_y][d->rc->map_x] == 3)
		color = 0x0000FF;
	else if (d->rc->map[d->rc->map_y][d->rc->map_x] == 4)
		color = 0xFFFFFF;
	else
		color = 0xFFFF00;
	if (d->rc->side == 1)
		color = color / 2;
	//	create_trgb(c->r, c->g, c->b);
	//	matrix_vert_line(d, d->rc->draw_start, d->rc->draw_end, color);
	//buff_vert_line(d, x, d->rc->draw_start, d->rc->draw_end, color);
	buff_vert_line(d, x, d->rc->draw_start, d->rc->draw_end, color);
	//verLine(d, x, d->rc->draw_start, d->rc->draw_end, color);
}

void	walls(t_data *d)
{
	int	x;

	(void)d;
	x = 0;
	while (x < WIN_X)
	{
		calc_ray_position_direction(d, x);
		// d->rc->camera_x = 2 * x / (double)WIN_X - 1;
		// d->rc->ray_dir_x = d->rc->dir_y + d->rc->plane_y * d->rc->camera_x;
		// d->rc->ray_dir_y = d->rc->dir_x + d->rc->plane_x * d->rc->camera_x;
		// d->rc->map_x = (int)d->rc->pos_x;
		// d->rc->map_y = (int)d->rc->pos_y;
		// d->rc->delta_dist_x = fabs(1 / d->rc->ray_dir_x);
		// d->rc->delta_dist_y = fabs(1 / d->rc->ray_dir_y);
		// d->rc->hit = 0;
		//length of ray from current position to next x or y-side
		// double sideDistX;
		// double sideDistY;
		
		 //length of ray from one x or y-side to next x or y-side
	
		//double perpWallDist;
		
		//what direction to step in x or y-direction (either +1 or -1)
		// int stepX;
		// int stepY;
		
		 //was there a wall hit?
		//int side; //was a NS or a EW wall hit?
	//	calc_step_and_dist(d);
		if (d->rc->ray_dir_x < 0)
		{
			d->rc->step_x = -1;
			d->rc->side_dist_x = (d->rc->pos_x - d->rc->map_x) * d->rc->delta_dist_x;
		}
		else
		{
			d->rc->step_x = 1;
			d->rc->side_dist_x = (d->rc->map_x + 1.0 - d->rc->pos_x) * d->rc->delta_dist_x;
		}
		if (d->rc->ray_dir_y < 0)
		{
			d->rc->step_y = -1;
			d->rc->side_dist_y = (d->rc->pos_y - d->rc->map_y) * d->rc->delta_dist_y;
		}
		else
		{
			d->rc->step_y = 1;
			d->rc->side_dist_y = (d->rc->map_y + 1.0 - d->rc->pos_y) * d->rc->delta_dist_y;
		}
		//digital_differential_analyzer(d);
		while (d->rc->hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (d->rc->side_dist_x < d->rc->side_dist_y)
			{
				d->rc->side_dist_x += d->rc->delta_dist_x;
				d->rc->map_x += d->rc->step_x;
				d->rc->side = 0;
			}
			else
			{
				d->rc->side_dist_y += d->rc->delta_dist_y;
				d->rc->map_y += d->rc->step_y;
				d->rc->side = 1;
			}
			if (d->rc->map[d->rc->map_x][d->rc->map_y] > 0)
				d->rc->hit = 1;
		}
		if (d->rc->side == 0)
			d->rc->perp_wall_dist = (d->rc->map_x - d->rc->pos_x + (1 - d->rc->step_x) / 2) / d->rc->ray_dir_x;
		else
			d->rc->perp_wall_dist = (d->rc->map_y - d->rc->pos_y + (1 - d->rc->step_y) / 2) / d->rc->ray_dir_y;
	//	calc_height_and_dist_of(d);
		//Calculate height of line to draw on screen
		d->rc->line_height = (int)(WIN_Y / d->rc->perp_wall_dist);

		//calculate lowest and highest pixel to fill in current stripe
		d->rc->draw_start = -d->rc->line_height / 2 + WIN_Y / 2;
		if (d->rc->draw_start < 0)
			d->rc->draw_start = 0;
		d->rc->draw_end = d->rc->line_height / 2 + WIN_Y / 2;
		if (d->rc->draw_end >= WIN_Y)
			d->rc->draw_end = WIN_Y - 1;
		//untextured_draw_line(d, x);

		// texturing calculations
		// side = 0 ray_dir_x < 0  position = start_position N
		// side = 1 ray_dir_y < 0 position E or left from start
		// side = 0 ray_dir_x >0  position S
		// side = 1 ray_dir_y > 0 position W
		if (d->rc->side == 1 && d->rc->ray_dir_y < 0)
			d->rc->txtr_num = 3;
		else if (d->rc->side == 1 && d->rc->ray_dir_y >= 0)
			d->rc->txtr_num = 2;
		else if (d->rc->side == 0 && d->rc->ray_dir_x <= 0)
			d->rc->txtr_num = 0;
		else if (d->rc->side == 0 && d->rc->ray_dir_x > 0)
			d->rc->txtr_num = 1;
		//d->rc->txtr_num = d->rc->map[d->rc->map_y][d->rc->map_x];

		// calculate value of wallX
		if (d->rc->side == 0)
			d->rc->wall_x = d->rc->pos_y + d->rc->perp_wall_dist * d->rc->ray_dir_y;
		else
			d->rc->wall_x = d->rc->pos_x + d->rc->perp_wall_dist * d->rc->ray_dir_x;
		d->rc->wall_x -= floor(d->rc->wall_x);

		// x coordinate on the texture
		d->rc->txtr_x = (int)(d->rc->wall_x * (double)TXTR_W);
		if (d->rc->side == 0 && d->rc->ray_dir_x > 0)
			d->rc->txtr_x = TXTR_W - d->rc->txtr_x - 1;
		if (d->rc->side == 1 && d->rc->ray_dir_y < 0)
			d->rc->txtr_x = TXTR_W - d->rc->txtr_x - 1;

		// How much to increase the texture coordinate perscreen pixel
		d->rc->step = 1.0 * TXTR_H / d->rc->line_height;
		// Starting texture coordinate
		d->rc->txtr_pos = (d->rc->draw_start - WIN_Y / 2 + d->rc->line_height / 2) * d->rc->step;
		int y = d->rc->draw_start;
		while (y < d->rc->draw_end)
		{
			// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
			d->rc->txtr_y = (int)d->rc->txtr_pos & (TXTR_H - 1);
			d->rc->txtr_pos += d->rc->step;
			d->rc->color = d->textures[d->rc->txtr_num][TXTR_H * d->rc->txtr_y + d->rc->txtr_x];
			// make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
			if (d->rc->side == 1)
				d->rc->color = (d->rc->color >> 1) & 8355711;
			d->buff[y][x] = d->rc->color;
			y++;
		}
		x++;
	}
}
	// calc_ray_position_direction(d, x);
	// 	calc_step_and_dist(d);
	// 	digital_differential_analyzer(d);
	// 	calc_height_and_dist_of(&d->rc->line_height, &d->rc->draw_start, &d->rc->draw_end, d->rc->perp_wall_dist);
	// 	//choose_pixel_of_wall(d);



	// d->rc->camera_x = 2 * x / (double)WIN_X - 1;
	// 	d->rc->ray_dir_x = d->rc->dir_x + d->rc->plane_x * d->rc->camera_x;
	// 	d->rc->ray_dir_y = d->rc->dir_y + d->rc->plane_y * d->rc->camera_x;
		
	// 	d->rc->map_x = (int)d->rc->pos_x;
	// 	d->rc->map_y = (int)d->rc->pos_y;

	// 	//length of ray from current position to next x or y-side
	// 	// double sideDistX;
	// 	// double sideDistY;
		
	// 	 //length of ray from one x or y-side to next x or y-side
	// 	d->rc->delta_dist_x = fabs(1 / d->rc->ray_dir_x);
	// 	d->rc->delta_dist_y = fabs(1 / d->rc->ray_dir_y);
	// 	//double perpWallDist;
		
	// 	//what direction to step in x or y-direction (either +1 or -1)
	// 	// int stepX;
	// 	// int stepY;
		
	// 	d->rc->hit = 0; //was there a wall hit?
	// 	//int side; //was a NS or a EW wall hit?

	// 	if (d->rc->ray_dir_x < 0)
	// 	{
	// 		d->rc->step_x = -1;
	// 		d->rc->side_dist_x = (d->rc->pos_x - d->rc->map_x) * d->rc->delta_dist_x;
	// 	}
	// 	else
	// 	{
	// 		d->rc->step_x = 1;
	// 		d->rc->side_dist_x = (d->rc->map_x + 1.0 - d->rc->pos_x) * d->rc->delta_dist_x;
	// 	}
	// 	if (d->rc->ray_dir_y < 0)
	// 	{
	// 		d->rc->step_y = -1;
	// 		d->rc->side_dist_y = (d->rc->pos_y - d->rc->map_y) * d->rc->delta_dist_y;
	// 	}
	// 	else
	// 	{
	// 		d->rc->step_y = 1;
	// 		d->rc->side_dist_y = (d->rc->map_y + 1.0 - d->rc->pos_y) * d->rc->delta_dist_y;
	// 	}
	// 	while (d->rc->hit == 0)
	// 	{
	// 		//jump to next map square, OR in x-direction, OR in y-direction
	// 		if (d->rc->side_dist_x < d->rc->side_dist_y)
	// 		{
	// 			d->rc->side_dist_x += d->rc->delta_dist_x;
	// 			d->rc->map_x += d->rc->step_x;
	// 			d->rc->side = 0;
	// 		}
	// 		else
	// 		{
	// 			d->rc->side_dist_y += d->rc->delta_dist_y;
	// 			d->rc->map_y += d->rc->step_y;
	// 			d->rc->side = 1;
	// 		}
	// 		//Check if ray has hit a wall
	// 		printf("d->rc->map_x %d d->rc->map_y %d\n", d->rc->map_x, d->rc->map_y);
	// 		int g = 0;
	// 		while( d->parser->map[g])
	// 		{
	// 			printf("count =%d\n",printf("%s", d->parser->map[g]));
	// 			g++;
	// 		}
	// 		char *str = d->parser->map[d->rc->map_y];
	// 		(void)str;
	// 		if (d->parser->map[d->rc->map_y][d->rc->map_x] == '1')
	// 			d->rc->hit = 1;
	// 	}
	// 	if (d->rc->side == 0)
	// 		d->rc->perp_wall_dist = (d->rc->map_x - d->rc->pos_x + (1 - d->rc->step_x) / 2) / d->rc->ray_dir_x;
	// 	else
	// 		d->rc->perp_wall_dist = (d->rc->map_y - d->rc->pos_y + (1 - d->rc->step_y) / 2) / d->rc->ray_dir_y;

	// 	//Calculate height of line to draw on screen
	// 	d->rc->line_height = (int)(WIN_Y / d->rc->perp_wall_dist);

	// 	//calculate lowest and highest pixel to fill in current stripe
	// 	d->rc->draw_start = -d->rc->line_height / 2 + WIN_Y / 2;
	// 	if(d->rc->draw_start < 0)
	// 		d->rc->draw_start = 0;
	// 	d->rc->draw_end = d->rc->line_height / 2 + WIN_Y / 2;
	// 	if(d->rc->draw_end >= WIN_Y)
	// 		d->rc->draw_end = WIN_Y - 1;