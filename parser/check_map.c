/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:40:45 by ebalgruu          #+#    #+#             */
/*   Updated: 2022/02/03 20:52:05 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_char(char c, t_data *data, int i, int j)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W' )
		data->params->pos += c;
	else if (c == 'C')
		data->params->coin++;
	else if (c == 'X')
		data->params->enemy++;
	else if (c == '1' || c == '0')
		return ;
	if (data->params->pos)
	{
		data->params->x = i;
		data->params->y = j;
	}
	else if (data->params->coin)
	{
		data->params->coin_pos_x = i;
		data->params->coin_pos_y = j;
	}
}

char	*add_space(char *str, int max_len)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = malloc(sizeof(char) * (max_len + 1));
	while (i < (int)ft_strlen(str))
	{
		tmp[i] = str[i];
		i++;
	}
	while (i < max_len)
	{
		tmp[i] = ' ';
		i++;
	}
	tmp[i] = '\0';
	free (str);
	str = ft_strdup(tmp);
	free(tmp);
	return (str);
}

void	rot_map(char **map, int len, int size)
{
	char	**r_map;
	int		i;
	int		j;
	int		x;

	i = 0;
	j = len + 1;
	r_map = malloc(sizeof(char *) * (size));
	while (i < size)
	{
		if (map[--j])
		{
			x = 0;
			r_map[i] = malloc(sizeof(char) * (len));
			while (j >= 0)
				r_map[i][x++] = map[j--][i];
			r_map[i][x] = '\0';
			check_walls(r_map[i], 0);
			free(r_map[i]);
			j = len + 1;
			i++;
		}
	}
	free(r_map);
}

void	check_corners(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
			{
				if (map[i - 1][j - 1] == ' ' || map[i - 1][j + 1] == ' '
					|| map[i + 1][j + 1] == ' ' || map[i + 1][j - 1] == ' ')
					ft_error(MAP_ERROR);
			}
			j++;
		}
		i++;
	}
}

char	**check_map(char **map, t_data *data, int size, int len)
{
	int		i;

	i = -1;
	while (map[++i])
	{
		check_walls(map[i], 0);
		if ((int)ft_strlen(map[i]) < len)
			map[i] = add_space(map[i], len);
		check_string(map[i], i, data);
	}
	rot_map(map, size, len);
	check_corners(map);
	return (map);
}
