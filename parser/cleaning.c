/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:40:45 by ebalgruu          #+#    #+#             */
/*   Updated: 2022/02/03 22:00:08 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_map(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_error(int key)
{
	write (1, "Error: ", 7);
	if (key == 100)
		write(1, "FILE_ERROR\n", 11);
	else if (key == 101)
		write (1, "MAP_ERROR\n", 10);
	else if (key == 102)
		write (1, "DATA_ERROR\n", 11);
	else if (key == 103)
		write (1, "MALLOC_ERROR\n", 13);
	else if (key == 104)
		write (1, "READ_ERROR\n", 11);
	else
		write (1, "COMMON_ERROR\n", 13);
	exit(0);
}

void	if_space(char *str, int *i)
{
	if (str[*i] == ' ')
	{
		while (str[*i] == ' ')
			(*i)++;
	}
}
