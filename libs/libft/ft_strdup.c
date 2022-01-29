/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:07:16 by dwulfe            #+#    #+#             */
/*   Updated: 2021/11/30 18:07:16 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		l;
	char	*dest;

	l = ft_strlen(s);
	dest = (char *)malloc(sizeof(*s) * (l + 1));
	if (!dest)
		return ((void *)0);
	l = 0;
	while (s[l])
	{
		dest[l] = s[l];
		l++;
	}
	dest[l] = '\0';
	return (dest);
}
