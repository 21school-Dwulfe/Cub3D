/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_chars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:41:20 by dwulfe            #+#    #+#             */
/*   Updated: 2022/02/05 15:53:29 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

unsigned char	get_t_ch(int trgb)
{
	return (((unsigned char *)&trgb)[3]);
}

unsigned char	get_r_ch(int trgb)
{
	return (((unsigned char *)&trgb)[2]);
}

unsigned char	get_g_ch(int trgb)
{
	return (((unsigned char *)&trgb)[1]);
}

unsigned char	get_b_ch(int trgb)
{
	return (((unsigned char *)&trgb)[0]);
}

int	create_trgb_uch(unsigned char t, unsigned char r,
	unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}
