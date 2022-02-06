/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 15:49:12 by dwulfe            #+#    #+#             */
/*   Updated: 2022/02/06 18:18:08 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

//(*f)(int button, int x, int y, void *param);
int	mouse_action(t_data *data)
{
	int	i;
	int	j;
	int	*x;
	int	*y;

	i = 1024;
	j = 768;
	x = &i;
	y = &j;
	mlx_mouse_move(data->mlx_win, i, j);
	mlx_mouse_get_pos(data->mlx_win, x, y);
	return (0);
}

int	button_pressed(int key, t_data *data)
{
	if (key == ESC)
		ft_close(data);
	if (key == W || key == S || key == A || key == D
        || key == LEFT || key == RIGHT)
		data->keys[key] = 1;
	printf("pressed =%d\n", key);
	return (key);
}

int button_release(int key, t_data *data)
{
	if (key == ESC)
		ft_close(data);
    if (key == W || key == S || key == A || key == D
        || key == LEFT || key == RIGHT)
		data->keys[key] = 0;
	printf("release =%d\n", key);
	return (key);
}

int	ft_close(t_data *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit (0);
}
