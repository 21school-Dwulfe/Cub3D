/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:37:05 by dwulfe            #+#    #+#             */
/*   Updated: 2022/01/29 15:04:18 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_max(int *arr, int size)
{
	int	i;
	int	*max;

	i = 0;
	max = NULL;
	while (i < size)
	{
		if (max == NULL || arr[i] > *max)
			*max = arr[i];
		i++;
	}
	return (max);
}
