/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_str_arr_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:35:23 by dwulfe            #+#    #+#             */
/*   Updated: 2022/01/29 15:05:13 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_params(int length, char *str_arr[])
{
	int			i;
	int			j;
	char		*temp;
	size_t		min[3];

	i = -1;
	while (++i < length)
	{
		j = -1;
		while (++j < length - i - 1)
		{
			min[0] = ft_strlen(str_arr[j]);
			min[1] = ft_strlen(str_arr[j + 1]);
			if (min[0] < min[1])
				min[2] = min[0];
			else
				min[2] = min[1];
			if (ft_strncmp(str_arr[j], str_arr[j + 1], min[2] + 1) > 0)
			{
				temp = str_arr[j];
				str_arr[j] = str_arr[j + 1];
				str_arr[j + 1] = temp;
			}
		}
	}
}
