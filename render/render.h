/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:07:38 by dwulfe            #+#    #+#             */
/*   Updated: 2022/02/06 19:18:43 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "../libs/include.h"
# include "../parser/cub3D.h"
# include "../includes/structures.h"

void	render_init(t_data *data);
int		render(t_data *data);
int		create_trgb(int t, int r, int g, int b);
int		create_trgb_uch(unsigned char t, unsigned char r,
			unsigned char g, unsigned char b);
void	ft_rotate_left(t_data *data);
void	ft_rotate_right(t_data *data);
void	matrix_vert_line(t_data *data, int *y2, t_rgb *c);
void	clear_player_minicard(void *mlx, void *mlx_win, int *xy, int size);
void	draw_player_minicard(int *matrix, int *xy, int size);
int		ft_close(t_data *data);
int		button_pressed(int key, t_data *data);
int		action(t_data *data);
int		mouse_action(t_data *data);
void	drawing_minimap(t_data *data, int x, int y);
void	draw(t_data *data);
void	floor_ceiling(t_data *data);
void	walls(t_data *data);
void	doors(t_data *data);
void	load_textures(t_data *data);
void	textures(t_data *data);
void	key_update(t_data *data);


#endif