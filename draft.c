
#include "../render.h"

// mlx_put_image_to_window(data->mlx, data->mlx_win, data->coin, x, y);
void	drawing_minimap(t_data *data, int x, int y)
{
	int			i;
	int			j;
	int			k;
	int			l;
	int			xy[2];
	//static int	xy_s[2];

	l = -20;
	k = -20;
	i = -1;
	//y = data->params->x;//* -10;
	y = 0;
	while (data->map[++i])
	{
	//	x = data->params->y; // * -10;
		x = 0;
		j = -1;
		while (data->map[i][++j])
		{
			printf("%d %d\n", data->params->x, data->params->y);
			if (data->map[i][j] == '1')// && x < 300 && y < 200)
				mlx_put_image_to_window(data->mlx, data->mlx_win, \
										data->mlx_image, x, y);
			if ((data->map[i][j] == 'N' || data->map[i][j] == 'W'
				|| data->map[i][j] == 'S' || data->map[i][j] == 'E'))
					//&& x < 300 && y < 200)
			{
				printf("%d %d\n", data->params->x, data->params->y);
				xy[0] = data->params->x;
				xy[1] = data->params->y;
				// if (first)
				// 	clear_player_minicard(data->mlx, data->mlx_win, xy_s, 6);
				draw_player_minicard(data->mlx, data->mlx_win, xy, 6);
				// xy_s[0] = xy[0];
				// xy_s[1] = xy[1];
			}
			if (data->map[i][j] == 'C') // && x < 300 && y < 200)
				mlx_put_image_to_window(data->mlx, data->mlx_win, \
										data->coin, x, y);
			x += 20;
		}
		y += 20;
	}
	// while (k < 300) //borders
	// {
	// 	mlx_put_image_to_window(data->mlx, data->mlx_win, \
	// 							data->mlx_image, k += 20, 200);
	// }
	// while (l < 200) //borders
	// {
	// 	mlx_put_image_to_window(data->mlx, data->mlx_win, \
	// 							data->mlx_image, 300, l += 20);
	// }
}



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movies.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:40:45 by ebalgruu          #+#    #+#             */
/*   Updated: 2022/02/05 19:00:24 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

void	ft_move_up(t_data *data)
{
	if (data->map[data->params->x - 1][data->params->y] != '1')
	{
		if (data->map[data->params->x - 1][data->params->y] == '0'
			|| data->map[data->params->x - 1][data->params->y] == 'C')
		{
			data->map[data->params->x][data->params->y] = '0';
			data->map[data->params->x - 1][data->params->y] = 'N';
		}
	}
}

void	ft_move_down(t_data *data)
{
	if (data->map[data->params->x + 1][data->params->y] != '1')
	{
		if (data->map[data->params->x + 1][data->params->y] == '0'
			|| data->map[data->params->x + 1][data->params->y] == 'C')
		{
			data->map[data->params->x][data->params->y] = '0';
			data->map[data->params->x + 1][data->params->y] = 'S';
		}
	}
}

void	ft_move_left(t_data *data)
{
	if (data->map[data->params->x][data->params->y - 1] != '1')
	{
		if (data->map[data->params->x][data->params->y - 1] == '0'
			|| data->map[data->params->x][data->params->y - 1] == 'C')
		{
			data->map[data->params->x][data->params->y] = '0';
			data->map[data->params->x][data->params->y - 1] = 'W';
		}
	}
}

void	ft_move_right(t_data *data)
{
	if (data->map[data->params->x][data->params->y + 1] != '1')
	{
		if ((data->map[data->params->x][data->params->y + 1] == '0'
			|| data->map[data->params->x][data->params->y + 1] == 'C'))
		{
			data->map[data->params->x][data->params->y] = '0';
			data->map[data->params->x][data->params->y + 1] = 'E';
		}
	}
}

void	player_move_draw(t_data *data)
{
	int		i;
	int		j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'W'
				|| data->map[i][j] == 'E' || data->map[i][j] == 'S')
			{
				data->params->x = i;
				data->params->y = j;
			}
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:40:45 by ebalgruu          #+#    #+#             */
/*   Updated: 2022/02/03 20:55:54 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

static void	ft_coins(t_data *data, int h, int w)
{
	char	*path;

	path = ft_strjoin(PWD, "/images/coin.xpm");
	data->coin = mlx_xpm_file_to_image(data->mlx, path, &h, &w);
	free(path);
}

static void	ft_coins1(t_data *data, int h, int w)
{
	char	*path;

	path = ft_strjoin(PWD, "/images/coin1.xpm");
	data->coin = mlx_xpm_file_to_image(data->mlx, path, &h, &w);
	free(path);
}

static void	ft_coins2(t_data *data, int h, int w)
{
	char	*path;

	path = ft_strjoin(PWD, "/images/coin2.xpm");
	data->coin = mlx_xpm_file_to_image(data->mlx, path, &h, &w);
	free(path);
}

static void	ft_coins3(t_data *data, int h, int w)
{
	char	*path;

	path = ft_strjoin(PWD, "/images/coin3.xpm");
	data->coin = mlx_xpm_file_to_image(data->mlx, path, &h, &w);
	free(path);
}

void	coin_animations(t_data *data)
{
	int		h;
	int		w;

	h = 0;
	w = 0;
	if (data->loop_counter == 0)
		ft_coins(data, h, w);
	else if (data->loop_counter == 10)
		ft_coins1(data, h, w);
	else if (data->loop_counter == 20)
		ft_coins2(data, h, w);
	else if (data->loop_counter == 30)
		ft_coins3(data, h, w);
	else if (data->loop_counter == 40)
		ft_coins2(data, h, w);
	else if (data->loop_counter == 50)
		ft_coins1(data, h, w);
}



void	get_move_from_key(t_data *data)
{
	player_move_draw(data);
	if (data->move == D)
		ft_move_right(data);
	else if (data->move == A)
		ft_move_left(data);
	else if (data->move == W)
		ft_move_up(data);
	else if (data->move == S)
		ft_move_down(data);
	else if (data->move == 123)
		ft_rotate_left(data);
	else if (data->move == 124)
		ft_rotate_right(data);
	data->move = 999;
}



void	vert_line(t_data *info, int x, int *y2, int color)
{
	int	y;

	y = y2[0];
	while (y <= y2[1])
	{
		mlx_pixel_put(info->mlx, info->mlx_win, x, y, color);
		y++;
	}
}

void	matrix_vert_line(t_data *data, int *y2, t_rgb *c)
{
	int	i;
	int	j;

	i = y2[0];
	j = y2[1] * WIN_X;
	while (i < WIN_Y * WIN_X && i <= j)
	{
		if (data->matrix[i] <= j)
		{
			data->matrix[i] = create_trgb(c->r, c->g, c->b);
		}
		i += WIN_X;
	}
}

