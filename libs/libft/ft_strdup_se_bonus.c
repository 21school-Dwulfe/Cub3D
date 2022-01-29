/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_se_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:07:10 by dwulfe            #+#    #+#             */
/*   Updated: 2021/11/30 18:07:12 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup_se(const char *s, size_t n, int c)
{
	char	*str;
	size_t	i;
	size_t	len;

	len = n;
	if (!n && !c)
		while (s[len])
			len++;
	else if (!n && c)
		while (s[len] && (s[len] - (unsigned char)c) != 0)
			len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && s[i] != '\0')
	{
		if (c)
			if (((unsigned char)s[i] - (unsigned char)c) == 0)
				break ;
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
