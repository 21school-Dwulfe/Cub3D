/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdel_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:05:24 by dwulfe            #+#    #+#             */
/*   Updated: 2022/01/18 19:19:14 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrstr_del(char **dst, int s_counter)
{
	if (!dst || !s_counter)
		return (NULL);
	while (s_counter > 0)
	{
		s_counter--;
		free((void *)dst[s_counter]);
	}
	free(dst);
	dst = NULL;
	return (NULL);
}
