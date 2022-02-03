/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:40:45 by ebalgruu          #+#    #+#             */
/*   Updated: 2022/02/03 20:55:54 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

static void	ft_coins(t_data *data, int h, int w)
{
	char	*path;

	path = ft_strjoin(PWD, "/images/coin.xpm");
	data->coin = mlx_xpm_file_to_image(data->mlx, path, &h, &w);
	free(path);
}

static void	ft_coins1(t_data *data, int h, int w)
{
	char	*path;

	path = ft_strjoin(PWD, "/images/coin1.xpm");
	data->coin = mlx_xpm_file_to_image(data->mlx, path, &h, &w);
	free(path);
}

static void	ft_coins2(t_data *data, int h, int w)
{
	char	*path;

	path = ft_strjoin(PWD, "/images/coin2.xpm");
	data->coin = mlx_xpm_file_to_image(data->mlx, path, &h, &w);
	free(path);
}

static void	ft_coins3(t_data *data, int h, int w)
{
	char	*path;

	path = ft_strjoin(PWD, "/images/coin3.xpm");
	data->coin = mlx_xpm_file_to_image(data->mlx, path, &h, &w);
	free(path);
}

void	coin_animations(t_data *data)
{
	int		h;
	int		w;

	h = 0;
	w = 0;
	if (data->loop_counter == 0)
		ft_coins(data, h, w);
	else if (data->loop_counter == 10)
		ft_coins1(data, h, w);
	else if (data->loop_counter == 20)
		ft_coins2(data, h, w);
	else if (data->loop_counter == 30)
		ft_coins3(data, h, w);
	else if (data->loop_counter == 40)
		ft_coins2(data, h, w);
	else if (data->loop_counter == 50)
		ft_coins1(data, h, w);
}
