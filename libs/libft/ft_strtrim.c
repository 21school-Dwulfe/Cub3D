/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:07:49 by dwulfe            #+#    #+#             */
/*   Updated: 2021/11/30 18:07:49 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;

	if (!s1 || !set)
		return (NULL);
	while (*s1)
	{
		if (!(ft_strchr(set, *s1)))
			break ;
		s1++;
	}
	result = (char *)s1 + (ft_strlen(s1) - 1);
	while (result >= s1)
	{
		if (!(ft_strchr(set, *result)))
			break ;
		result--;
	}
	return (ft_strndup(s1, ++result - s1));
}
