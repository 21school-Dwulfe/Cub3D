/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:40:45 by ebalgruu          #+#    #+#             */
/*   Updated: 2022/02/23 20:04:57 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_map(int i, int j, char **file, t_parser *data)
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
	max_len = (int)ft_strlen(file[0]);
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

int	find_map(int *i, char **file, t_parser *data)
{
	int			j;

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

void	parse_file(t_parser *d, char **f, int *i, int *j)
{
	while (f[++(*i)])
	{
		*j = 0;
		while (f[*i][*j] && collect_all(d))
		{
			if_space(f[*i], j);
			if (f[*i][*j] == 'N' && f[*i][(*j) + 1] == 'O' && !d->paths->no)
				get_texts(j, f[*i], d, "NO");
			else if (f[*i][*j] == 'S' && f[*i][*j + 1] == 'O' && !d->paths->so)
				get_texts(j, f[*i], d, "SO");
			else if (f[*i][*j] == 'E' && f[*i][*j + 1] == 'A' && !d->paths->ea)
				get_texts(j, f[*i], d, "EA");
			else if (f[*i][*j] == 'W' && f[*i][*j + 1] == 'E' && !d->paths->we)
				get_texts(j, f[*i], d, "WE");
			else if (f[*i][*j] == 'F' && !d->colors->floor)
				get_colors(j, f[*i], d, 'F');
			else if (f[*i][*j] == 'C' && !d->colors->cell)
				get_colors(j, f[*i], d, 'C');
			else if (f[*i][*j] == '1')
				find_map(i, f, d);
			else
				ft_error(FILE_ERROR);
		}
	}
}
