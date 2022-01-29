/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decorate_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:11:26 by dwulfe            #+#    #+#             */
/*   Updated: 2022/01/25 16:39:10 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_decorate(char *src, char *begining, char *end)
{
	char	*result;
	int		l[8];

	ft_bzero(l, sizeof(int) * 8);
	l[0] = ft_strlen(src) + ft_strlen(begining) + ft_strlen(end) + 1;
	result = ft_calloc(l[0], sizeof(char));
	l[1] = ft_strlen(begining);
	while (l[2] < l[1])
	{
		result[l[2]] = begining[l[2]];
		l[2]++;
	}
	l[3] = ft_strlen(src);
	while (l[4] < l[3])
	{
		result[l[2] + l[4]] = src[l[4]];
		l[4]++;
	}
	l[5] = ft_strlen(end);
	while (l[6] < l[5])
	{
		result[l[2] + l[4] + l[6]] = end[l[6]];
		l[6]++;
	}
	return (result);
}
