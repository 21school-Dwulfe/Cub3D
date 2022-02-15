/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:40:45 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/12/19 13:40:49 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_color(char *str, int *i)
{
	int	dot;

	dot = 0;
	while (str[++(*i)])
	{
		if (str[*i] == ' ' || ft_isdigit(str[*i]))
			continue ;
		else if (str[*i] == ',')
			dot++;
		else
			ft_error(DATA_ERROR);
	}
	if (dot != 2)
		ft_error(DATA_ERROR);
}

t_rgb	*make_colors(char **rgb_arr)
{
	int		i;
	t_rgb	*rgb;

	i = -1;
	rgb = NULL;
	rgb_init(&rgb);
	while (rgb_arr[++i])
	{
		if (ft_isdigit(*rgb_arr[i]))
		{
			if (rgb->r < 0)
				rgb->r = ft_atoi_rgb(rgb_arr[i]);
			else if (rgb->g < 0)
				rgb->g = ft_atoi_rgb(rgb_arr[i]);
			else if (rgb->b < 0)
				rgb->b = ft_atoi_rgb(rgb_arr[i]);
			else
				continue ;
		}
		else
			ft_error(DATA_ERROR);
	}
	if (i != 3 || (rgb->r < 0 || rgb->g < 0 || rgb->b < 0))
		ft_error(DATA_ERROR);
	return (rgb);
}

void	get_colors(int *i, char *line, t_parser *data, char flag)
{
	char	**rgb_arr;
	int		j;

	j = (*i);
	rgb_arr = NULL;
	check_color(line, i);
	while (line[++j])
	{
		if (line[j] == ' ')
			continue ;
		else if (ft_isdigit(line[j]))
		{
			line = ft_substr(line, j, ft_strlen(line) - j);
			rgb_arr = ft_split(line, ',');
			free(line);
			if (flag == 'F')
				data->colors->floor = make_colors(rgb_arr);
			else if (flag == 'C')
				data->colors->cell = make_colors(rgb_arr);
			free_map(rgb_arr);
			break ;
		}
		else
			ft_error(DATA_ERROR);
	}
}
