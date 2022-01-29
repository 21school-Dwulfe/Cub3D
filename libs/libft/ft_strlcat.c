/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:49:29 by dwulfe            #+#    #+#             */
/*   Updated: 2021/04/25 15:36:14 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	length;

	i = 0;
	length = 0;
	while (dst[length] != '\0' && length < dstsize)
		length++;
	while (src[i] != '\0' && (length + i + 1) < dstsize)
	{
		dst[length + i] = src[i];
		i++;
	}
	if (length < dstsize)
		dst[length + i] = '\0';
	return ((length + ft_strlen(src)));
}
