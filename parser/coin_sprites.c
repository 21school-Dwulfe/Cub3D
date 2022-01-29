/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:40:45 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/12/19 13:40:49 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_coins(t_data *data, void *coin, int h, int w)
{
	coin = "/Users/ebalgruu/Desktop/21/cub3D/cub3D/images/coin.xpm";
	data->coin = mlx_xpm_file_to_image(data->mlx, coin, &h, &w);
}

static void	ft_coins1(t_data *data, void *coin, int h, int w)
{
	coin = "/Users/ebalgruu/Desktop/21/cub3D/cub3D/images/coin1.xpm";
	data->coin = mlx_xpm_file_to_image(data->mlx, coin, &h, &w);
}

static void	ft_coins2(t_data *data, void *coin, int h, int w)
{
	coin = "/Users/ebalgruu/Desktop/21/cub3D/cub3D/images/coin2.xpm";
	data->coin = mlx_xpm_file_to_image(data->mlx, coin, &h, &w);
}

static void	ft_coins3(t_data *data, void *coin, int h, int w)
{
	coin = "/Users/ebalgruu/Desktop/21/cub3D/cub3D/images/coin3.xpm";
	data->coin = mlx_xpm_file_to_image(data->mlx, coin, &h, &w);
}

void	coin_animations(t_data *data)
{
	int		h;
	int		w;
	void	*friends;

	h = 0;
	w = 0;
	if (data->loop_counter == 0)
		ft_coins(data, &friends, h, w);
	else if (data->loop_counter == 10)
		ft_coins1(data, &friends, h, w);
	else if (data->loop_counter == 20)
		ft_coins2(data, &friends, h, w);
	else if (data->loop_counter == 30)
		ft_coins3(data, &friends, h, w);
	else if (data->loop_counter == 40)
		ft_coins2(data, &friends, h, w);
	else if (data->loop_counter == 50)
		ft_coins1(data, &friends, h, w);
}
