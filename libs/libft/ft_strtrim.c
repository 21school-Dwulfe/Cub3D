/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:46:00 by dwulfe            #+#    #+#             */
/*   Updated: 2022/03/02 11:46:00 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*res;

	if (s1 == 0 || set == 0)
		return (0);
	while (*s1 && ft_strchr(set, *s1) != 0)
		s1++;
	i = ft_strlen(s1);
	while (i > 0 && ft_strchr(set, s1[i]) != 0)
		i--;
	res = ft_substr((char *)s1, 0, i + 1);
	return (res);
}
