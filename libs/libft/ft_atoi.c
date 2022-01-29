/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 10:31:57 by dwulfe            #+#    #+#             */
/*   Updated: 2021/04/26 21:18:02 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_neg(const char *nptr, size_t *i, int *is_neg)
{
	if (nptr[*i] == '-')
	{
		*is_neg *= -1;
		*i = *i + 1;
	}
	else if (nptr[*i] == '+')
		*i = *i + 1;
}

int	ft_atoi(const char *nptr)
{
	size_t		i;
	int			is_neg;
	int			res;

	i = 0;
	is_neg = 1;
	res = 0;
	while (ft_isspace(nptr[i]))
		i++;
	ft_neg(nptr, &i, &is_neg);
	while (ft_isdigit(nptr[i]))
	{
		if (res > INT_MAX / 10)
			return (-1);
		else if (res < INT_MIN / 10)
			return (0);
		res = res * 10 + is_neg * (nptr[i] - '0');
		i++;
	}
	return (res);
}
