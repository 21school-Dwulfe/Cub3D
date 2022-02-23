/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _render_.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 23:16:32 by dwulfe            #+#    #+#             */
/*   Updated: 2022/02/23 19:57:13 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

void	sides(t_data *d)
{
	if (d->parser->pos == 'W')
	{
		d->rc->plane_x = -0.66;
		d->rc->plane_y = 0;
		d->rc->dir_x = 0;
		d->rc->dir_y = -1;
	}
	if (d->parser->pos == 'E')
	{
		d->rc->plane_x = 0.66;
		d->rc->plane_y = 0;
		d->rc->dir_x = 0;
		d->rc->dir_y = 1;
	}
}

void	define_player_position(t_data *d)
{
	d->rc->pos_x = (double)d->parser->pos_y + 0.5;
	d->rc->pos_y = (double)d->parser->pos_x + 0.5;
	if (d->parser->pos == 'N')
	{
		d->rc->plane_x = 0.0;
		d->rc->plane_y = 0.66;
		d->rc->dir_x = -1.0;
		d->rc->dir_y = 0.0;
	}
	if (d->parser->pos == 'S')
	{
		d->rc->plane_x = 0;
		d->rc->plane_y = -0.66;
		d->rc->dir_x = 1.0;
		d->rc->dir_y = 0.0;
	}
	sides(d);
}

void	raycasting_init(t_data *d, t_raycaster *rc)
{
	d->rc = rc;
	d->rc->mouse_counter = 0;
	d->rc->loop_counter = 0;
	d->rc->move_speed = 0.06;
	d->rc->rot_speed = 0.02;
	d->rc->map = malloc(sizeof(int *) * 24);
	d->rc->mouse_x = WIN_X / 2;
	d->rc->mouse_y = WIN_Y / 2;
	find_count_enemies(d);
	map_convertation(d);
	ft_bzero(d->key, sizeof(512));
}

int	action(t_data *data)
{
	data->curr_time++;
	if (data->curr_time == LONG_MAX)
		data->curr_time = 0;
	floor_ceiling(data);
	walls(data);
	textures(data);
	if (BONUS)
	{
		draw_minicard_field(data);
		draw_weapon_animation(data);
		stop_mouse_rotation(data);
	}
	key_update(data);
	draw_buff(data);
	return (0);
}

int	render(t_data *data)
{
	t_raycaster	rc;

	rc = (t_raycaster){};
	raycasting_init(data, &rc);
	define_player_position(data);
	mlx_mouse_hide(data->mlx, data->mlx_win);
	load_textures_mandatory(data);
	if (BONUS)
	{	
		load_weapons(data);
		load_textures_additional(data);
		set_start_ammunition(data);
		mlx_hook(data->mlx_win, 6, (1L << 6), mouse_rotation, data);
		mlx_hook(data->mlx_win, 4, (1L << 2), mouse_buttons_down, data);
		mlx_hook(data->mlx_win, 5, (1L << 2), mouse_buttons_up, data);
	}
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, button_pressed, data);
	mlx_key_hook(data->mlx_win, button_release, data);
	mlx_hook(data->mlx_win, DestroyNotify, KeyPressMask, ft_close, data);
	mlx_loop_hook(data->mlx, action, data);
	mlx_loop(data->mlx);
	exit(0);
	return (0);
}
