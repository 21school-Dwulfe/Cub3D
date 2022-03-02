/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:41:19 by dwulfe            #+#    #+#             */
/*   Updated: 2022/03/02 11:41:25 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*res;
	size_t	i;

	i = 0;
	res = (void *) malloc(count * size);
	if (!res)
		return (NULL);
	while (i < (count * size))
	{
		res[i] = '\0';
		i++;
	}
	return (res);
}
