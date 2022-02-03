/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 23:16:32 by dwulfe            #+#    #+#             */
/*   Updated: 2022/02/03 20:40:30 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

void	render_init(t_data *data)
{
	int		h;
	int		w;
	char	*path[2];

	h = 0;
	w = 0;
	path[0] = ft_strjoin(PWD, "/images/wall.xpm");
	path[1] = ft_strjoin(PWD, "/images/coin.xpm");
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WIN_X, WIN_Y, "Cub3D");
	data->mlx_image = mlx_xpm_file_to_image(data->mlx, path[0], &h, &w);
	data->coin = mlx_xpm_file_to_image(data->mlx, path[1], &h, &w);
	free(path[0]);
	free(path[1]);
}

int	render(t_data *data)
{
	run(data);
	return (0);
}
