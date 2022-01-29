/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movies.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:40:45 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/12/19 13:40:49 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_move_up(t_data *data)
{
	if (data->map[data->params->x - 1][data->params->y] != '1')
	{
		if (data->map[data->params->x - 1][data->params->y] == '0'
			|| data->map[data->params->x - 1][data->params->y] == 'C')
		{
			data->map[data->params->x][data->params->y] = '0';
			data->map[data->params->x - 1][data->params->y] = 'N';
		}
	}
}

void	ft_move_down(t_data *data)
{
	if (data->map[data->params->x + 1][data->params->y] != '1')
	{
		if (data->map[data->params->x + 1][data->params->y] == '0'
			|| data->map[data->params->x + 1][data->params->y] == 'C')
		{
			data->map[data->params->x][data->params->y] = '0';
			data->map[data->params->x + 1][data->params->y] = 'S';
		}
	}
}

void	ft_move_left(t_data *data)
{
	if (data->map[data->params->x][data->params->y - 1] != '1')
	{
		if (data->map[data->params->x][data->params->y - 1] == '0'
			|| data->map[data->params->x][data->params->y - 1] == 'C')
		{
			data->map[data->params->x][data->params->y] = '0';
			data->map[data->params->x][data->params->y - 1] = 'W';
		}
	}
}

void	ft_move_right(t_data *data)
{
	if (data->map[data->params->x][data->params->y + 1] != '1')
	{
		if ((data->map[data->params->x][data->params->y + 1] == '0'
			 || data->map[data->params->x][data->params->y + 1] == 'C'))
		{
			data->map[data->params->x][data->params->y] = '0';
			data->map[data->params->x][data->params->y + 1] = 'E';
		}
	}
}

void	player_move_draw(t_data *data)
{
	int		i;
	int		j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'W'
				|| data->map[i][j] == 'E' || data->map[i][j] == 'S')
			{
				data->params->x = i;
				data->params->y = j;
			}
		}
	}
}
