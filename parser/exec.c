/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:15:01 by dwulfe            #+#    #+#             */
/*   Updated: 2022/02/15 14:18:53 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	file_size(int out, char *argv)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_error(READ_ERROR);
	while (out)
	{
		out = get_next_line(fd, &line, 0);
		if (out < 0)
			ft_error(READ_ERROR);
		free(line);
		i++;
	}
	line = NULL;
	close(fd);
	return (i);
}

void	parse(t_parser *data, char *argv)
{
	int		i;
	int		fd;
	int		out;
	int		size;
	char	**file;

	i = 0;
	out = 1;
	size = file_size(out, argv);
	file = (char **)malloc(sizeof(char *) * (size + 1));
	if (!file)
		ft_error(MALLOC_ERROR);
	fd = open(argv, O_RDONLY);
	while (out)
	{
		out = get_next_line(fd, &file[i], 0);
		if (out < 0)
			ft_error(READ_ERROR);
		i++;
	}
	file[i] = NULL;
	check_params(data, file);
	free_map(file);
	close(fd);
}

// int	main(int argc, char **argv)
// {
// 	t_colors	*colors;
// 	t_data		*data;
// 	t_txs		*txs;

// 	data = NULL;
// 	txs = NULL;
// 	colors = NULL;
// 	init(&data, &txs, &colors);
// 	if (argc == 2)
// 	{
// 		if (check(argv[1]))
// 			ft_error(COMMON_ERROR);
// 		parse(data, argv[1]);
// 		run(data);
// 	}
// 	else
// 		ft_error(COMMON_ERROR);
// 	return (0);
// }
