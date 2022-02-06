/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 23:16:32 by dwulfe            #+#    #+#             */
/*   Updated: 2022/02/06 20:39:34 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

int	action(t_data *data)
{
	floor_ceiling(data);
	if (BONUS)
		doors(data);
	walls(data);
	textures(data);
	draw(data);
	key_update(data);
	return (0);
}

void	load_textures(t_data *data)
{
	int		h;
	int		w;
	char	*path[2];
	
	h = 0;
	w = 0;
	path[0] = ft_strjoin(PWD, "/images/wall.xpm");
	path[1] = ft_strjoin(PWD, "/images/coin.xpm");
	data->coin = mlx_xpm_file_to_image(data->mlx, path[1], &h, &w);
	free(path[0]);
	free(path[1]);
}

void	render_init(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WIN_X, WIN_Y, "Cub3D");
	data->mlx_image = mlx_new_image(data->mlx, WIN_X, WIN_Y);
	// mlx_xpm_file_to_image(data->mlx, path[0], &h, &w);
	data->addr = (int *)mlx_get_data_addr(data->mlx_image,
		&data->bits_per_pixel, 
		&data->line_length,
		&data->endian);
	
}

int	render(t_data *data)
{
	load_textures(data);
	mlx_loop_hook(data->mlx, action, data);
	mlx_hook(data->mlx_win, 17, 0, ft_close, data);
	if (BONUS)
		mlx_mouse_hook(data->mlx_win, mouse_action, data);
	mlx_hook(data->mlx_win, 02, (1L << 2), button_pressed, data);
	mlx_loop(data->mlx);
	exit(0);
	return (0);
}
