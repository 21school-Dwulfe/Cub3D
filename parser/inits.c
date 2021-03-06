/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:40:45 by ebalgruu          #+#    #+#             */
/*   Updated: 2022/02/23 20:03:33 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rgb_init(t_rgb **rgb)
{
	*rgb = (t_rgb *)malloc(sizeof(t_rgb));
	if (!rgb)
		ft_error(MALLOC_ERROR);
	(*rgb)->r = -1;
	(*rgb)->g = -1;
	(*rgb)->b = -1;
}
