/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:40:45 by ebalgruu          #+#    #+#             */
/*   Updated: 2022/02/03 22:00:23 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

int	ft_close(t_data *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit (0);
}

void	ft_send_key(int key, t_data *data)
{
	if (key == W)
		data->move = W;
	else if (key == S)
		data->move = S;
	else if (key == A)
		data->move = A;
	else if (key == D)
		data->move = D;
	else if (key == ESC)
		ft_close(data);
}

void	drawing_map(t_data *data, int x, int y)
{
	int		i;
	int		j;

	i = -1;
	y = data->params->x * -15;
	while (data->map[++i])
	{
		x = data->params->y * -15;
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win, \
										data->mlx_image, x, y);
			if (data->map[i][j] == 'N' || data->map[i][j] == 'W'
				|| data->map[i][j] == 'S' || data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->mlx_win, \
										data->coin, x, y);
			if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->mlx_win, \
										data->coin, x, y);
			x += 20;
		}
		y += 20;
	}
}

//int	mouse_action(t_data *data)
//{
//	//(*f)(int button, int x, int y, void *param);
//
//	int	i = 0;
//	int	j = 0;
//	int *x;
//	int *y;
//
//	i = 1024;
//	j = 768;
//	x = &i;
//	y = &j;
////	int     mlx_mouse_hide(void);
////	mlx_mouse_show(void);
//	mlx_mouse_move(data->mlx_win, i, j);
//	mlx_mouse_get_pos(data->mlx_win, x, y);
//	return (0);
//}

int	action(t_data *data)
{
	data->loop_counter++;
	mlx_clear_window(data->mlx, data->mlx_win);
	drawing_map(data, 0, 0);
	get_move_from_key(data);
	coin_animations(data);
	return (0);
}

int	button_pressed(int key, t_data *data)
{
	ft_send_key(key, data);
	printf("%d\n", key);
	return (key);
}

void	run(t_data *data)
{
	mlx_loop_hook(data->mlx, action, data);
	mlx_hook(data->mlx_win, 17, 0, ft_close, data);
//	mlx_mouse_hook(data->mlx_win, mlx_mouse_show, data);
//	mlx_mouse_hook(data->mlx_win, mouse_action, data);
	mlx_hook(data->mlx_win, 02, (1L << 2), button_pressed, data);
	mlx_loop(data->mlx);
	exit(0);
}
