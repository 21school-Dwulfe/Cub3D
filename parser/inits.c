/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:40:45 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/12/19 13:40:49 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_params(t_params **params)
{
	if (!params || !*params)
		ft_error(MALLOC_ERROR);
	(*params)->coin = 0;
	(*params)->pos = 0;
	(*params)->enemy = 0;
	(*params)->x = 0;
	(*params)->y = 0;
	(*params)->coin_pos_x = 0;
	(*params)->coin_pos_y = 0;
}

void	rgb_init(t_rgb **rgb)
{
	*rgb = malloc(sizeof(t_rgb));
	if (!rgb)
		ft_error(MALLOC_ERROR);
	(*rgb)->r = -1;
	(*rgb)->g = -1;
	(*rgb)->b = -1;
}

void	mlx_data_init(t_data *data)
{
	int		h;
	int		w;

	h = 0;
	w = 0;
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WIN_X, WIN_Y, "Cub3D");
	data->mlx_image = mlx_xpm_file_to_image(data->mlx, "/Users/ebalgruu/Desktop/21/cub3D/cub3D/images/wall.xpm", &h, &w);
	data->coin = mlx_xpm_file_to_image(data->mlx, "/Users/ebalgruu/Desktop/21/cub3D/cub3D/images/coin.xpm", &h, &w);
}

void	init(t_data **data, t_txs **txs, t_colors **colors)
{
	t_params	*params;

	params = NULL;
	*data = malloc(sizeof(t_data));
	*txs = malloc(sizeof(t_txs));
	*colors = malloc(sizeof(t_colors));
	if (!data || !txs || !colors)
		ft_error(MALLOC_ERROR);
	(*data)->params = params;
	(*data)->map = NULL;
	(*data)->move = 0;
	(*txs)->ea = NULL;
	(*txs)->no = NULL;
	(*txs)->so = NULL;
	(*txs)->we = NULL;
	(*data)->txs = *txs;
	(*colors)->cell = NULL;
	(*colors)->floor = NULL;
	(*data)->colors = *colors;
	(*data)->loop_counter = 0;
	(*data)->coin = NULL;
}
