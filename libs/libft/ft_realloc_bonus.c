/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:04:37 by dwulfe            #+#    #+#             */
/*   Updated: 2022/01/29 15:05:02 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *memory, size_t size)
{
	void	*result;

	result = malloc(size);
	if (result)
	{
		ft_bzero(result, size);
		result = ft_memmove(result, memory, size);
		ft_delptr(&memory);
		return (result);
	}
	return (NULL);
}
