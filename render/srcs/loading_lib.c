/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_lib.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:30:18 by dwulfe            #+#    #+#             */
/*   Updated: 2022/03/02 15:31:24 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

void	load_image(t_img *img, void *mlx_ptr, char *path)
{
	img->img = mlx_xpm_file_to_image(mlx_ptr, path,
			&img->img_width, &img->img_height);
	if (!img->img)
	{
		error_message("Error : ");
		error_message(path);
		error_message(" : No such image or format error\n");
		exit(EXIT_FAILURE);
	}
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->size_l, &img->endian);
}

void	save_image(t_data *data, int **text, char *path, t_img *img)
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
		while (x < img->img_width)
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
	ft_bzero(weapon->img, sizeof(t_img) * (i + 1));
	weapon->num_img = 0;
	while (weapon->num_img < i)
	{
		load_image(&weapon->img[weapon->num_img], mlx_ptr, path[l]);
		l++;
		weapon->num_img++;
	}
}

void	load_array_images_simple(t_img *img, void *mlx_ptr, char **path, int i)
{
	int	l;

	l = 0;
	img = malloc(sizeof(t_img) * (i + 1));
	ft_bzero(img, sizeof(t_img) * (i + 1));
	while (l < i)
	{
		load_image(&img[l], mlx_ptr, path[l]);
		l++;
	}
}
