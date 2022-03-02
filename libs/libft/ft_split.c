/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 11:44:54 by dwulfe            #+#    #+#             */
/*   Updated: 2022/03/02 11:44:55 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words_count(char const *s, char c, int count)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			j = 1;
		if (s[i] != c && j == 1)
		{
			j = 0;
			count++;
		}
		i++;
	}
	return (count);
}

static int	words_len(char const *s, char c)
{
	int	len;

	len = 0;
	if (s)
	{
		while (s[len] && s[len] != c)
			len++;
	}
	return (len);
}

static void	*mem_cleaner(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static char	*make_str(const char *s, char c, int *i)
{
	int		j;
	char	*res;
	int		len;

	j = 0;
	while (s[*i] && s[*i] == c)
		*i = *i + 1;
	len = words_len(s + *i, c);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (s[*i] != '\0' && s[*i] != c)
	{
		res[j] = s[*i];
		j++;
		*i = *i + 1;
	}
	res[j] = '\0';
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		count;
	int		i;
	int		j;

	i = 0;
	if (!s)
		return (NULL);
	count = words_count(s, c, 0);
	arr = (char **)malloc((count + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	j = 0;
	while (i < count)
	{
		arr[i] = make_str(s, c, &j);
		if (!arr[i])
			return (mem_cleaner(arr));
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
