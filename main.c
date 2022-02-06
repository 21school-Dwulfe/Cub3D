/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:07:03 by dwulfe            #+#    #+#             */
/*   Updated: 2022/02/06 20:07:50 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/main.h"

int	main(int argc, char **argv)
{
	t_colors	*colors;
	t_data		*data;
	t_txs		*txs;

	data = NULL;
	txs = NULL;
	colors = NULL;
	init(&data, &txs, &colors);
	if (argc == 2)
	{
		if (check(argv[1]))
			ft_error(COMMON_ERROR);
		render_init(data);
		parse(data, argv[1]);
		render(data);
	}
	else
		ft_error(COMMON_ERROR);
	return (0);
}
