/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:40:45 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/12/19 13:40:49 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_map(int i, int j, char **file, t_data *data)
{
	char	**map;
	int		size;
	int		len;
	int		max_len;

	size = 0;
	while (file[++i])
		++size;
	map = malloc(sizeof(char *) * (size + 1));
	i -= size + 1;
	max_len = (int)ft_strlen(file[i]);
	while (file[++i])
	{
		map[++j] = ft_strdup(file[i]);
		len = (int)ft_strlen(map[j]);
		if (len > max_len)
			max_len = len;
	}
	map[j + 1] = NULL;
	check_map(map, data, size, max_len);
	data->map = map;
}

int	find_map(int *i, char **file, t_data *data)
{
	t_params	*params;
	int			j;

	params = malloc(sizeof(t_params));
	init_params(&params);
	data->params = params;
	while (file[*i])
	{
		j = 0;
		while (file[*i][j])
		{
			if (file[*i][j] == '1')
			{
				get_map((*i - 1), -1, file, data);
				return (1);
			}
			else if (file[*i][j] == ' ' || (file[*i][j] == '\t'))
				j++;
			else
				ft_error(FILE_ERROR);
		}
		(*i)++;
	}
	return (0);
}

void	parse_file(t_data *data, char **f, int *i, int *j)
{
	while (f[++(*i)])
	{
		*j = 0;
		while (f[*i][*j] && collect_all(data))
		{
			if_space(f[*i], j);
			if (f[*i][*j] == 'N' && f[*i][(*j) + 1] == 'O' && !data->txs->no)
				get_texts(j, f[*i], data, "NO");
			else if (f[*i][*j] == 'S' && f[*i][*j + 1] == 'O' && !data->txs->so)
				get_texts(j, f[*i], data, "SO");
			else if (f[*i][*j] == 'E' && f[*i][*j + 1] == 'A' && !data->txs->ea)
				get_texts(j, f[*i], data, "EA");
			else if (f[*i][*j] == 'W' && f[*i][*j + 1] == 'E' && !data->txs->we)
				get_texts(j, f[*i], data, "WE");
			else if (f[*i][*j] == 'F' && !data->colors->floor)
				get_colors(j, f[*i], data, 'F');
			else if (f[*i][*j] == 'C' && !data->colors->cell)
				get_colors(j, f[*i], data, 'C');
			else if (f[*i][*j] == '1')
				find_map(i, f, data);
			else
				ft_error(FILE_ERROR);
		}
	}
}
