/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:07:03 by dwulfe            #+#    #+#             */
/*   Updated: 2022/02/17 22:19:26 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/main.h"

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
		render_init(&data);
		parse(&parser, argv[1]);
		render(&data);
	}
	else
		ft_error(COMMON_ERROR);
	return (0);
}
