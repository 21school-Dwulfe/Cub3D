# include "../render.h"

void	define_player_position(t_data *d)
{
	d->rc->pos_x = (double)d->parser->pos_x + 0.5;
	d->rc->pos_y = (double)d->parser->pos_y + 0.5;
	if (d->parser->pos == 'N')
	{
		d->rc->plane_x = 0.0;
		d->rc->plane_y = 0.66;
		d->rc->dir_x = -1.0;
		d->rc->dir_y = 0.0;
	}
	if (d->parser->pos == 'S')
	{
		d->rc->plane_x = 0;
		d->rc->plane_y = -0.66;
		d->rc->dir_x = 1;
		d->rc->dir_y = 0;
		
	}
	if (d->parser->pos == 'W')
	{
		d->rc->plane_x = -0.66;
		d->rc->plane_y = 0;
		d->rc->dir_x = 0;
		d->rc->dir_y = -1;
	}
	if (d->parser->pos == 'E')
	{
		d->rc->plane_x = 0.66;
		d->rc->plane_y = 0;
		d->rc->dir_x = 0;
		d->rc->dir_y = 1;
	}
}

void	load_image(t_data *data,int **text, char *path, t_img *img)
{
	int		x;
	int		y;
	

	y = 0;
	x = 0;
	img->img = mlx_xpm_file_to_image(data->mlx, path, &img->img_width, &img->img_height);
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->size_l, &img->endian);
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

void	load_textures(t_data *data)
{
	t_img	img;

	// data->textures = malloc(sizeof(t_img) * 5);
	load_image(data, &data->textures[0], data->parser->paths->no, &img);
	load_image(data, &data->textures[1], data->parser->paths->so, &img);
	load_image(data, &data->textures[2], data->parser->paths->ea, &img);
	load_image(data, &data->textures[3], data->parser->paths->we, &img);
	load_image(data, &data->textures[4], "textures/door0.xpm", &img);
}

// void	load_textures_default(t_data *data)
// {
// 	//t_img	img;

// 	// data->textures[0].addr = load_image(data, "textures/eagle.xpm", &img);
// 	// data->textures[1].addr = load_image(data, "textures/redbrick.xpm", &img);
// 	// data->textures[2].addr = load_image(data, "textures/purplestone.xpm", &img);
// 	// data->textures[3].addr = load_image(data, "textures/greystone.xpm", &img);
// 	// data->textures[4].addr = load_image(data, "textures/bluestone.xpm", &img);
// 	// data->textures[5].addr = load_image(data, "textures/mossy.xpm", &img);
// 	// data->textures[6].addr = load_image(data, "textures/wood.xpm", &img);
// 	// data->textures[7].addr = load_image(data, "textures/colorstone.xpm", &img);
// 	// data->textures[8].addr = load_image(data, "textures/barrel.xpm", &img);
// 	// data->textures[9].addr = load_image(data, "textures/pillar.xpm", &img);
// 	// data->textures[10].addr = load_image(data, "textures/greenlight.xpm", &img);
// }