/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:06:30 by dwulfe            #+#    #+#             */
/*   Updated: 2021/11/30 18:06:30 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_str_quantity(char const *s1, char c)
{
	int	quant;
	int	flag;

	quant = 0;
	flag = 0;
	if (*s1 == '\0')
		return (0);
	while (*s1 != '\0')
	{
		if (*s1 == c)
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			quant++;
		}
		s1++;
	}
	return (quant);
}

static int	ft_ch_q(char const *s2, char c, int start_i)
{
	int	lenght;

	lenght = 0;
	while (s2[start_i] != c && s2[start_i] != '\0')
	{
		lenght++;
		start_i++;
	}
	return (lenght);
}

static char	**ft_get(char const *s, char **dst, char c, int length)
{
	int	i;
	int	s_counter;
	int	char_i;

	i = 0;
	s_counter = 0;
	while (s[i] != '\0' && s_counter < length)
	{
		char_i = 0;
		while (s[i] == c)
			i++;
		dst[s_counter] = (char *)malloc(sizeof(char) * ft_ch_q(s, c, i) + 1);
		if (!dst[s_counter])
			return (ft_arrstr_del((char **)dst, s_counter));
		while (s[i] != '\0' && s[i] != c)
			dst[s_counter][char_i++] = s[i++];
		dst[s_counter][char_i] = '\0';
		s_counter++;
	}
	dst[s_counter] = (void *)0;
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	int		length;

	if (!s)
		return (NULL);
	length = ft_str_quantity(s, c);
	dst = (char **)malloc(sizeof(char *) * (length + 1));
	if (!dst)
		return (NULL);
	return (ft_get(s, dst, c, length));
}
