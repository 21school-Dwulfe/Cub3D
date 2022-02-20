/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenario.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:11:17 by dwulfe            #+#    #+#             */
/*   Updated: 2022/02/20 17:50:58 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

void    set_start_ammunition(t_data *d)
{
    d->weapon[0].inFOV = 1;
    d->weapon[1].inFOV = 1;
    d->weapon[2].inFOV = 1;
    d->weapon[3].inFOV = 0;
    d->available_weapon[0] = 1;
    d->available_weapon[1] = 2;
    d->available_weapon[2] = 3;
    d->available_weapon[3] = 4;
    d->act_weapon = &d->weapon[0];
}
