/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:40:45 by ebalgruu          #+#    #+#             */
/*   Updated: 2022/02/07 19:13:09 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// void	init_params(t_params **params)
// {
// 	if (!params || !*params)
// 		ft_error(MALLOC_ERROR);
// 	(*params)->coin = 0;
// 	(*params)->pos = 0;
// 	(*params)->enemy = 0;
// 	(*params)->pos_x = 0;
// 	(*params)->pos_y = 0;
// 	(*params)->coin_pos_x = 0;
// 	(*params)->coin_pos_y = 0;
// }

void	rgb_init(t_rgb **rgb)
{
	*rgb = (t_rgb *)malloc(sizeof(t_rgb));
	if (!rgb)
		ft_error(MALLOC_ERROR);
	(*rgb)->r = -1;
	(*rgb)->g = -1;
	(*rgb)->b = -1;
}

