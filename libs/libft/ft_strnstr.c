/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:37:20 by dwulfe            #+#    #+#             */
/*   Updated: 2021/04/28 18:24:08 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*h;

	i = 0;
	h = (char *)haystack;
	if (needle[0] == '\0' || haystack == needle)
		return ((char *)haystack);
	while (i < len)
	{
		j = 0;
		while (haystack[i + j] != '\0' && i + j < len
			&& (haystack[i + j] - needle[j]) == 0)
		{
			if (needle[j + 1] == '\0')
				return (&h[i]);
			j++;
		}
		i++;
	}
	return ((void *)0);
}
