/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 23:16:32 by dwulfe            #+#    #+#             */
/*   Updated: 2022/02/19 13:58:58 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

void	draw_buff(t_data *data)
{
	int y;
	int x;

	x = 0;
	y = 0;
	while (y < WIN_Y)
	{
		x = 0;
		while (x < WIN_X)
		{
			data->mlx_image->addr[y * WIN_X + x] = data->buff[y][x]; 
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_image->img, 0, 0);
}

// 60 fps  1 framePerSeconds = 1000 / 60 = 16.66666 usec
void	stop_mouse_rotation(t_data *d)
{
	if (d->rc->mouse_counter && d->curr_time - d->last_mouse_rotation >= 3)
	{
		d->rc->mouse_counter = 0;
		d->rc->rot_speed = 0.03;
		write(1, "clean\n\n\n", 9);
		d->key_l = 0;
		d->key_r = 0;
	}
}

//1024 
// middle 512  need to save offset 
// 768 - 1 - 83
int	action(t_data *data)
{
	data->curr_time++;
	if (data->curr_time == LONG_MAX)
		data->curr_time = 0;
	floor_ceiling(data);
	walls(data);
	if (BONUS)
	{
		doors(data);
		draw_minicard_field(data);
		draw_weapon_animation(data);
		stop_mouse_rotation(data);
	}
	key_update(data);
	draw_buff(data);
	return (0);
}

void	map_convertation(t_data *d)
{
	int i;
	int	j;
	int	l;
	int	k;
	int curr;

	i = 0;
	j = 0;
	while (d->parser->map[i])
		i++;
	d->rc->map = malloc(sizeof(int*) * i);
	while (j < i)
	{
		l = ft_strlen(d->parser->map[j]);
		d->rc->map[j] = malloc(sizeof(int) * (l));
		ft_bzero(d->rc->map[j], sizeof(int) * (l));
		k = 0;
		while (k < l)
		{
			if (d->parser->map[j][k] >= '0' && d->parser->map[j][k] <= '9')
				curr = d->parser->map[j][k] - '0';
			else if (d->parser->map[j][k] == 'N'
				|| d->parser->map[j][k] == 'S'
				|| d->parser->map[j][k] == 'W'
				|| d->parser->map[j][k] == 'E')
					curr = 0;
			else
				curr = 1;
			d->rc->map[j][k] = curr;
			k++;
		}
		for (int h = 0; h < l; h++)
		{
			printf("%d",d->rc->map[j][h]);
		}
		printf("\n");
		j++;
	}
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
	map_convertation(d);
	ft_bzero(d->key, sizeof(512));
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
		d->rc->dir_x = 1;
		d->rc->dir_y = 0;
	}
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

void	render_init(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WIN_X, WIN_Y, "Cub3D");
	data->mlx_image = malloc(sizeof(t_img));
	data->mlx_image->img = mlx_new_image(data->mlx, WIN_X, WIN_Y);
	data->mlx_image->addr = (int *)mlx_get_data_addr( \
		data->mlx_image->img,
		&data->mlx_image->bits_per_pixel, 
		&data->mlx_image->line_length,
		&data->mlx_image->endian);
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
		//load_textures_additional();
		set_start_ammunition(data);
		mlx_hook(data->mlx_win, 6, (1L<<6), mouse_rotation, data);
		mlx_hook(data->mlx_win, 4, (1L<<2), mouse_buttons_down, data);
		mlx_hook(data->mlx_win, 5, (1L<<2), mouse_buttons_up, data);
	}
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, button_pressed, data);
	mlx_key_hook(data->mlx_win, button_release, data);
	mlx_hook(data->mlx_win, DestroyNotify, KeyPressMask, ft_close, data);
	mlx_loop_hook(data->mlx, action, data);
	mlx_loop(data->mlx);
	exit(0);
	return (0);
}
