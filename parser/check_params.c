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

int	check_params(t_data *data, char **file)
{
	int		i;
	int		j;

	j = 0;
	i = -1;
	parse_file(data, file, &i, &j);
	if (data->params->pos != 'N' && data->params->pos != 'S'
		&& data->params->pos != 'W' && data->params->pos != 'E')
		ft_error(DATA_ERROR);
	return (0);
}

int	collect_all(t_data *data)
{
	if (data->colors->floor && data->colors->cell && data->txs->no
		&& data->txs->ea && data->txs->so && data->txs->we && data->map)
		return (0);
	else if (data->map)
		ft_error(FILE_ERROR);
	return (1);
}
