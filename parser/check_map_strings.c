/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_strings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:40:45 by ebalgruu          #+#    #+#             */
/*   Updated: 2022/02/05 18:02:06 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_string(char *str, int y, t_data *data)
{
	int	x;

	x = 0;
	while (str[x])
	{
		if (str[x] == '1' || str[x] == '0' || str[x] == 'N' || str[x] == 'S'
			|| str[x] == 'E' || str[x] == 'W' || str[x] == 'C' || str[x] == 'X')
			get_char(str[x], data, x, y);
		x++;
	}
	return (0);
}

static int	check_left(char *str, int i)
{
	while (--i)
	{
		if (str[i] == ' ')
		{
			while (str[i] == ' ')
				i--;
			if (str[i] == '1' && i >= 0)
				break ;
			else
				return (1);
		}
	}
	return (0);
}

static int	check_right(char *str, int i, int len)
{
	while (str[i])
	{
		if (str[i] == ' ')
		{
			while (str[i] == ' ')
				i++;
			if (str[i] == '1' && i <= len)
				break ;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

static void	check_holes(char *str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			j = 0;
			while (str[i] == ' ')
			{
				j++;
				i++;
			}
			if (check_left(str, i)
				|| check_right(str, i - j, (int)ft_strlen(str)))
				ft_error(MAP_ERROR);
		}
		i++;
	}
}

int	check_walls(char *str, int i)
{
	int		len;
	char	*tmp;

	len = (int)ft_strlen(str);
	if (str[len - 1] == ' ')
		while (str[len - 1] == ' ')
			len--;
	if (str[i] == ' ')
	{
		while (str[i] == ' ')
			i++;
	}
	tmp = ft_substr(str, i, len - i);
	if (!tmp)
		ft_error(MALLOC_ERROR);
	check_holes(tmp);
	free(tmp);
	if (str[len - 1] != '1' || str[i] != '1')
		ft_error(MAP_ERROR);
	return (0);
}
