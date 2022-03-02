/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:07:03 by dwulfe            #+#    #+#             */
/*   Updated: 2022/03/02 11:36:43 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	init(t_data *data, t_parser *parser, t_txs *txs, t_colors *colors)
{
	*data = (t_data){};
	*txs = (t_txs){};
	*parser = (t_parser){};
	*colors = (t_colors){};
	parser->paths = txs;
	parser->colors = colors;
	data->parser = parser;
}

void	render_init(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WIN_X, WIN_Y, "Cub3D");
	data->mlx_image = malloc(sizeof(t_img));
	data->mlx_image->img = mlx_new_image(data->mlx, WIN_X, WIN_Y);
	data->mlx_image->addr = (int *)mlx_get_data_addr(\
			data->mlx_image->img,
			&data->mlx_image->bits_per_pixel,
			&data->mlx_image->line_length,
			&data->mlx_image->endian);
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_parser	parser;
	t_colors	colors;
	t_txs		txs;

	init(&data, &parser, &txs, &colors);
	if (argc == 2)
	{
		if (check(argv[1]))
			ft_error(COMMON_ERROR);
		parse(&parser, argv[1]);
		render_init(&data);
		render(&data);
	}
	else
		ft_error(COMMON_ERROR);
	return (0);
}
