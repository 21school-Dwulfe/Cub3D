/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:07:38 by dwulfe            #+#    #+#             */
/*   Updated: 2022/02/20 15:46:20 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "../libs/include.h"
# include "../parser/cub3D.h"
# include "../includes/structures.h"


void	render_init(t_data *data);
int		render(t_data *data);
void	load_textures_mandatory(t_data *data);
void	define_player_position(t_data *d);
int		create_trgb(int r, int g, int b);
int		create_trgb_uch(unsigned char t, unsigned char r,
			unsigned char g, unsigned char b);
void	ft_rotate_left(t_data *data);
void	ft_rotate_right(t_data *data);
void	clear_player_minicard(void *mlx, void *mlx_win, int *xy, int size);
void	draw_square_minicard(t_data *data, int *xy, int color, int size);
int		ft_close(int key, void *data);
int		button_pressed(int key, void *d);
int		action(t_data *data);
int		mouse_action(int x, int y, void *d);
void	drawing_minimap(t_data *data, int x, int y);
void	draw(t_data *data);
void	floor_ceiling(t_data *data);
void	walls(t_data *data);
void	doors(t_data *data);
void	textures(t_data *data);
void	key_update(t_data *data);
int		ft_close(int key, void *d);
int		button_release(int key, void *d);
void	rotate_screen_to_right(t_data *d);
void	rotate_screen_to_left(t_data *d);
void	draw_minicard_field(t_data *d);
int		mouse_rotation(int x,int y, void *p);
int		mouse_buttons_down(int	key, int x, int y, void *data);
int		mouse_buttons_up(int key, int x, int y, void *data);
void	draw_weapon(t_data *d, t_img *weapon, int partial);
void	error_message(char *message);
void	draw_weapon_animation(t_data *d);
void	load_weapons(t_data *d);
void    set_start_ammunition(t_data *d);
void	load_textures_additional(t_data *d);
void	save_image(t_data *data,int **text, char *path, t_img *img);
void	load_array_images(t_weapon *weapon, void *mlx_ptr, char **path, int i);

#endif
