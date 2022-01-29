/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_strs_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:32:10 by dwulfe            #+#    #+#             */
/*   Updated: 2022/01/29 15:06:12 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap_strs(void *p1, void *p2)
{
	void	*tmp;

	tmp = *(void **)p1;
	*(void **)p1 = *(void **)p2;
	*(void **)p2 = tmp;
}
