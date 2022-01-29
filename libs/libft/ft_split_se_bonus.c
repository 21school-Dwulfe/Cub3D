/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_se_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:34:40 by dwulfe            #+#    #+#             */
/*   Updated: 2022/01/29 15:05:29 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_strs(char	*str, int c)
{
	int	i;
	int	flag;
	int	count;

	i = -1;
	flag = 0;
	count = 0;
	while (str[++i])
	{
		if (str[i] == c)
			flag = 0;
		else if (flag == 0 && ++count)
			flag = 1;
	}
	return (count);
}

char	**ft_split_se(char *str, int c)
{
	int		i;
	int		j;
	int		start;
	char	**result;

	i = 0;
	j = 0;
	result = (char **)malloc(sizeof(char *) * (count_strs(str, c) + 1));
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		start = i;
		if (str[i] != c && str[i] != '\0')
		{
			while (str[i] && str[i] != c)
				i++;
			result[j] = ft_strndup(str + start, i - start);
			j++;
		}
		if (result[j - 1] == NULL)
			ft_arrstr_del(result, j);
	}
	result[j] = (void *)0;
	return (result);
}
