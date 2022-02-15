/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 23:16:32 by dwulfe            #+#    #+#             */
/*   Updated: 2022/02/15 14:40:18 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"
	int map[24][24] = {
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,0,0,0,4,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
						};

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


int	action(t_data *data)
{
	floor_ceiling(data);
	
	walls(data);
//	textures(data);
	//draw(data);
	if (BONUS)
		doors(data);
	draw_buff(data);
	key_update(data);
	return (0);
}

// void	map_convertation(t_data *d)
// {
// 	int i;
// 	int	j;
// 	int	l;
// 	// int	k;
// 	// int curr;

// 	i = 0;
// 	j = 0;
// 	while (d->parser->map[i])
// 		i++;
// 	d->rc->map = malloc(sizeof(int*) * i);
// 	while (j < i)
// 	{
// 		l = ft_strlen(d->parser->map[j]);
// 		// d->rc->map[j] = malloc(sizeof(int) * (l));
// 		// ft_bzero(d->rc->map[j], sizeof(int) * (l));
// 		//k = 0;
// 		// while (k < l)
// 		// {
// 			// if (d->parser->map[j][k] >= '0' && d->parser->map[j][k] <= '9')
// 			// 	curr = d->parser->map[j][k] - '0';
// 			// else if (d->parser->map[j][k] == 'N'
// 			// 	|| d->parser->map[j][k] == 'S'
// 			// 	|| d->parser->map[j][k] == 'W'
// 			// 	|| d->parser->map[j][k] == 'E')
// 			// 	curr = d->parser->map[j][k];
// 			// else
// 			// 	curr = 1;
// 		// 	d->rc->map[j][k] = curr;
// 		// 	k++;
// 		// }
// 		// for (int h = 0; h < l; h++)
// 		// {
// 		// 	printf("%c",d->parser->map[j][h]);
// 		// }
// 		// printf("\n");
// 		j++;
// 	}
// 	// for (int i = 0; i < 24; i++)
// 	// {

// 	// 	d->rc->map[i] = map[i];
// 	// }
// }

void	raycasting_init(t_data *d, t_raycaster *rc)
{
	d->rc = rc;
	d->rc->pos_x = 12; //(double)d->parser->pos_x;
	d->rc->pos_y = 5; //(double)d->parser->pos_y;
	d->rc->dir_x = -1.0;
	d->rc->dir_y = 0.0;
	d->rc->plane_x = 0.0;
	d->rc->plane_y = 0.66;
	d->rc->move_speed =0.06; //MOVE_SPEED;// ;
	d->rc->rot_speed = 0.04;//RATATION_SPEED; //
	d->rc->map = malloc(sizeof(int *) * 24);
	
	for (int i = 0; i < 24; i++)
	{
		d->rc->map[i] = map[i]; 
	}
	//map_convertation(d);

	ft_bzero(d->key, sizeof(512));
}

void	render_init(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WIN_X, WIN_Y, "Cub3D");
	data->mlx_image = malloc(sizeof(t_img));
	data->mlx_image->img = mlx_new_image(data->mlx, WIN_X, WIN_Y);
	// mlx_xpm_file_to_image(data->mlx, path[0], &h, &w);
	data->mlx_image->addr = (int *)mlx_get_data_addr( \
		data->mlx_image->img,
		&data->mlx_image->bits_per_pixel, 
		&data->mlx_image->line_length,
		&data->mlx_image->endian);
	//data->textures = malloc(sizeof(t_img) * 6);
}

int	mouse_win3(int key, int x,int y, void *p)
{
	(void)p;
	(void)key;
	printf("Mouse moving in Win3, at %dx%d.\n",x,y);
	return (0);
}


//mlx_key_hook(data->mlx_win,button_pressed,0);
//	mlx_hook(data->mlx_win, MotionNotify, PointerMotionMask, mouse_win3, data);
//mlx_hook(data->mlx_win, 02, (1L << 2), button_pressed, data);
int	render(t_data *data)
{
	t_raycaster	rc;

	rc = (t_raycaster){};
	raycasting_init(data, &rc);
//	define_player_position(data);
	load_textures(data);
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, button_pressed, data);
	mlx_hook(data->mlx_win, DestroyNotify, KeyPressMask, ft_close, data);
	mlx_key_hook(data->mlx_win, button_release, data);
	if (BONUS)
	 	mlx_mouse_hook(data->mlx_win, mouse_action, data);
	mlx_loop_hook(data->mlx, action, data);
	mlx_loop(data->mlx);
	exit(0);
	return (0);
}
