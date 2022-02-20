/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prerender.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:19:33 by dwulfe            #+#    #+#             */
/*   Updated: 2022/02/19 17:04:49 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../render.h"

void	load_image(t_img *img, void *mlx_ptr, char *path)
{
	img->img = mlx_xpm_file_to_image(mlx_ptr, path, &img->img_width, &img->img_height);
	if (!img->img)
	{
		error_message("Error : ");
		error_message(path);
		error_message(" : No such image\n");
		exit(EXIT_FAILURE);
	}
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->size_l, &img->endian);
}

void	save_image(t_data *data,int **text, char *path, t_img *img)
{
	int		x;
	int		y;
	

	y = 0;
	x = 0;
	load_image(img, data->mlx, path);
	*text = malloc(sizeof(int) * TXTR_H * TXTR_W);
	while (y < img->img_height)
	{
		x = 0;
		while(x < img->img_width)
		{
			(*text)[img->img_width * y + x] = img->addr[img->img_width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, img->img);
}

void	load_array_images(t_weapon *weapon, void *mlx_ptr, char **path, int i)
{
	int	l;

	l = 0;
	weapon->img = malloc(sizeof(t_img) * (i + 1));
	weapon->num_img = 0;
	while (weapon->num_img < i)
	{
		load_image(&weapon->img[weapon->num_img], mlx_ptr, path[l]);
		l++;
		weapon->num_img++;
	}
}

void	load_weapons(t_data *d)
{
	char *array[8];
	
	array[0] = "textures/weapon/pistol_1.xpm";
	array[1] = "textures/weapon/pistol_2.xpm";
	array[2] = "textures/weapon/pistol_3.xpm";
	array[3] = "textures/weapon/leg_1.xpm";
	array[4] = "textures/weapon/leg_2.xpm";
	array[5] = "textures/weapon/give_money.xpm";
	array[6] = "textures/weapon/give_money_2.xpm";
	load_array_images(&d->weapon[0], d->mlx, array, 3);
	load_array_images(&d->weapon[1], d->mlx, array + 3, 2);
	load_array_images(&d->weapon[2], d->mlx, array + 5, 2);
}

void	load_textures_mandatory(t_data *d)
{
	t_img	img;

	save_image(d, &d->textures[0], d->parser->paths->no, &img);
	save_image(d, &d->textures[1], d->parser->paths->so, &img);
	save_image(d, &d->textures[2], d->parser->paths->ea, &img);
	save_image(d, &d->textures[3], d->parser->paths->we, &img);
	save_image(d, &d->textures[4], "textures/wolfenstein/door0.xpm", &img);
	load_weapons(d);
}
