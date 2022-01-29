/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:40:45 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/12/19 13:40:49 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	check_texs(char *str, int i)
{
	if (!str[i])
		ft_error(DATA_ERROR);
	else
	{
		while (str[i])
		{
			if (str[i] == '.' && str[i + 1] == '/')
				break ;
			if (str[i] == ' ')
				i++;
			else
				ft_error(DATA_ERROR);
		}
	}
}

static char	*get_str_texs(char *str, int *i)
{
	int		j;
	int		len;
	char	*tmp;

	j = *i;
	len = (int)ft_strlen(str);
	while (str[++j])
	{
		if (!ft_isalnum(str[j]) && str[j] != '_'
			&& str[j] != '/' && str[j] != '.')
			ft_error(DATA_ERROR);
		else if (!ft_isalnum(str[len - 1]) && str[len - 1] != '/')
			ft_error(DATA_ERROR);
	}
	tmp = ft_substr(str, *i, len - (*i));
	*i = j;
	str = tmp;
	return (str);
}

void	get_texts(int *i, char *line, t_data *data, char *flag)
{
	int		j;

	(*i) += 2;
	j = *i;
	check_texs(line, *i);
	while (line[*i])
	{
		if (line[*i] == ' ')
			(*i)++;
		else if (line[*i] == '.' && line[(*i) + 1] == '/')
		{
			if (!ft_strcmp(flag, "NO") && !data->txs->no)
				data->txs->no = get_str_texs(line, i);
			else if (!ft_strcmp(flag, "SO") && !data->txs->so)
				data->txs->so = get_str_texs(line, i);
			else if (!ft_strcmp(flag, "WE") && !data->txs->we)
				data->txs->we = get_str_texs(line, i);
			else if (!ft_strcmp(flag, "EA") && !data->txs->ea)
				data->txs->ea = get_str_texs(line, i);
			break ;
		}
		else
			ft_error(DATA_ERROR);
	}
}
