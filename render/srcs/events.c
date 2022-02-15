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
int mouse_action(int key, int x,int y, void *p)
{
	t_data	*data;

	data = (t_data *)p;
	(void)key;
	(void)data;
	(void)y;
	(void)x;
	//if (x < WIN_X / 2)
	return (0);
}

int button_pressed(int key, void *d) // t_data *data)
{
	t_data *data;
	
	data = (t_data *)d;
	if (key == ESC)
		exit(0);
	if (key == W || key == S || key == A || key == D || key == LEFT || key == RIGHT)
	{
		if (key == LEFT)
			data->key_l = 1;
		else if (key == RIGHT)
		 	data->key_r = 1;
		else
			data->key[key] = 1;
	}
	printf("pressed =%d\n", key);
	return (key);
}

int button_release(int key, void *d)
{
	t_data *data;

	data = (t_data *)d;
	if (key == ESC)
		exit(0);
	if (key == W || key == S || key == A || key == D || key == LEFT || key == RIGHT)
	{
		if (key == LEFT)
			data->key_l = 0;
		else if (key == RIGHT)
		 	data->key_r = 0;
		else
			data->key[key] = 0;
	}
	printf("release =%d\n", key);
	return (key);
}

int ft_close(int key, void *d)
{
	(void)d;
	(void)key;
	exit(0);
	return (0);
}
