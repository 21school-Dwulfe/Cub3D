/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:40:45 by ebalgruu          #+#    #+#             */
/*   Updated: 2022/02/03 20:56:13 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

void	get_move_from_key(t_data *data)
{
	player_move_draw(data);
	if (data->move == D)
	{
		ft_move_right(data);
		data->move = 999;
	}
	else if (data->move == A)
	{
		ft_move_left(data);
		data->move = 999;
	}
	else if (data->move == W)
	{
		ft_move_up(data);
		data->move = 999;
	}
	else if (data->move == S)
	{
		ft_move_down(data);
		data->move = 999;
	}
}
