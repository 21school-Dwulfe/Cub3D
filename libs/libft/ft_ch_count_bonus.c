/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ch_count_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:29:39 by dwulfe            #+#    #+#             */
/*   Updated: 2022/01/25 16:39:39 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ch_count(char *str, char ch)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		if ((unsigned char)str[i] - (unsigned char)ch == 0)
			result++;
		i++;
	}
	return (result);
}
