/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:40:45 by ebalgruu          #+#    #+#             */
/*   Updated: 2022/02/03 20:51:30 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check(char *filename)
{
	int	len;

	len = (int)ft_strlen(filename);
	if ((filename[len - 4] != '.') || (filename[len - 3] != 'c')
		|| (filename[len - 2] != 'u') || (filename[len - 1] != 'b'))
		return (1);
	return (0);
}

int	check_params(t_parser *parser, char **file)
{
	int		i;
	int		j;

	j = 0;
	i = -1;
	parse_file(parser, file, &i, &j);
	if (parser->pos != 'N' && parser->pos != 'S'
		&& parser->pos != 'W' && parser->pos != 'E')
		ft_error(DATA_ERROR);
	return (0);
}

int	collect_all(t_parser *parser)
{
	if (parser->colors->floor && parser->colors->cell
		&& parser->paths->no
		&& parser->paths->ea && parser->paths->so
		&& parser->paths->we && parser->map)
		return (0);
	else if (parser->map)
		ft_error(FILE_ERROR);
	return (1);
}
