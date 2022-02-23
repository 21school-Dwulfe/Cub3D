/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:06:58 by dwulfe            #+#    #+#             */
/*   Updated: 2022/02/23 19:49:41 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

void	draw_buff(t_data *data)
{
	int	y;
	int	x;

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
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->mlx_image->img, 0, 0);
}

void	filter(t_data *d, int j, int k, int *curr)
{
	if (d->parser->map[j][k] >= '0' && d->parser->map[j][k] <= '9')
		*curr = d->parser->map[j][k] - '0';
	else if (d->parser->map[j][k] == 'N'
		|| d->parser->map[j][k] == 'S'
		|| d->parser->map[j][k] == 'W'
		|| d->parser->map[j][k] == 'E')
			*curr = 0;
	else if (d->parser->map[j][k] == 'X')
	{
		*curr = 'X';
		add_enemy(d, j, k);
	}	
	else if (d->parser->map[j][k] == 'D')
		*curr = 'D';
	else
		*curr = 1;
	d->rc->map[j][k] = *curr;
}

void	map_convertation(t_data *d)
{
	int	i;
	int	j;
	int	l;
	int	k;
	int	curr;

	i = 0;
	j = 0;
	curr = 0;
	while (d->parser->map[i])
		i++;
	d->rc->map = malloc(sizeof(int *) * i);
	while (j < i)
	{
		l = ft_strlen(d->parser->map[j]);
		d->rc->map[j] = malloc(sizeof(int) * (l));
		ft_bzero(d->rc->map[j], sizeof(int) * (l));
		k = -1;
		while (++k < l)
			filter(d, j, k, &curr);
		j++;
	}
}

void	find_count_enemies(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (d->parser->map[i])
	{
		j = 0;
		while (d->parser->map[j])
		{
			if (d->parser->map[i][j] == 'X')
				d->num_enemies++;
			j++;
		}
		i++;
	}
}

void	draw(t_data *data)
{
	int	y;
	int	x;

	(void)data;
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
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->mlx_image->img, 0, 0);
}
