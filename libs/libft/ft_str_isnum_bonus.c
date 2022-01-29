/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isnum_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:34:06 by dwulfe            #+#    #+#             */
/*   Updated: 2022/01/29 15:03:48 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_is_num(char *str)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (str[len])
		len++;
	while (str[i])
	{
		if ((str[i] < 48 || str[i] > 57) || (str[0] != '-'))
			break ;
		i++;
	}
	if (i == len)
		return (1);
	else
		return (0);
}
