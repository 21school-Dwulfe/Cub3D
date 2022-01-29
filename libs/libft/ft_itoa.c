/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 20:05:43 by dwulfe            #+#    #+#             */
/*   Updated: 2021/04/23 20:05:43 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_getstr(int *length, int *tmp, int *n, char **str)
{
	int	i;

	if (*n < 0)
	{
		str[0][0] = '-';
		*n = -(*n);
		i = 1;
	}
	else
		i = 0;
	while (*length)
	{
		*tmp = *n / *length;
		str[0][i] = '0' + *tmp;
		*n %= *length;
		*length /= 10;
		i++;
	}
	str[0][i] = '\0';
}		

char	*ft_itoa(int n)
{
	char	*str;
	int		length;
	int		tmp;
	int		j;

	j = 1;
	tmp = n / 10;
	length = 1;
	if (n < 0)
		j = 2;
	while (tmp)
	{
		j++;
		length *= 10;
		tmp /= 10;
	}
	if ((long)n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *)malloc(sizeof(char) * j + 1);
	if (!str)
		return (NULL);
	ft_getstr(&length, &tmp, &n, &str);
	return (str);
}
