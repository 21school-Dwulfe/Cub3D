/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:30:28 by dwulfe            #+#    #+#             */
/*   Updated: 2022/02/23 18:48:19 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

void	load_textures_additional(t_data *d)
{
	char	*array[4];

	array[0] = "textures/enemies/guard/attack_1.png";
	load_image(&d->txtr[0], d->mlx, array[0]);
	d->num_sprites = 2;
}

void	load_textures_mandatory(t_data *d)
{
	t_img	img;

	save_image(d, &d->textures[0], d->parser->paths->no, &img);
	save_image(d, &d->textures[1], d->parser->paths->so, &img);
	save_image(d, &d->textures[2], d->parser->paths->ea, &img);
	save_image(d, &d->textures[3], d->parser->paths->we, &img);
	save_image(d, &d->textures[4], "textures/wolfenstein/door0.xpm", &img);
	save_image(d, &d->textures[5], "textures/wolfenstein/door1.xpm", &img);
}

void	load_weapons(t_data *d)
{
	char	*array[14];

	array[0] = "textures/weapon/pistol_1.xpm";
	array[1] = "textures/weapon/pistol_2.xpm";
	array[2] = "textures/weapon/pistol_3.xpm";
	array[3] = "textures/weapon/shotgun_1.xpm";
	array[4] = "textures/weapon/shotgun_2.xpm";
	array[5] = "textures/weapon/shotgun_3.xpm";
	array[6] = "textures/weapon/shotgun_4.xpm";
	array[7] = "textures/weapon/shotgun_5.xpm";
	array[8] = "textures/weapon/shotgun_6.xpm";
	array[9] = "textures/weapon/shotgun_7.xpm";
	array[10] = "textures/weapon/give_money.xpm";
	array[11] = "textures/weapon/give_money_2.xpm";
	array[12] = "textures/weapon/leg_1.xpm";
	array[13] = "textures/weapon/leg_2.xpm";
	load_array_images(&d->weapon[0], d->mlx, array, 3);
	load_array_images(&d->weapon[1], d->mlx, array + 3, 7);
	load_array_images(&d->weapon[2], d->mlx, array + 10, 2);
	load_array_images(&d->weapon[3], d->mlx, array + 12, 2);
}
