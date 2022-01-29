/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:36:50 by dwulfe            #+#    #+#             */
/*   Updated: 2022/01/29 15:04:06 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_min(int *arr, int size)
{
	int	i;
	int	*min;

	i = 0;
	min = NULL;
	while (i < size)
	{
		if (min == NULL || arr[i] < *min)
			*min = arr[i];
		i++;
	}
	return (min);
}
