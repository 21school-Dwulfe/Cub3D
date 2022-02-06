/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:40:45 by ebalgruu          #+#    #+#             */
/*   Updated: 2022/02/05 20:25:31 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/include.h"
# include "../includes/structures.h"

int		get_next_line(int fd, char **line, int ret);
int		ft_atoi_rgb(char *str);
void	ft_error(int key);

void	init(t_data **data, t_txs **txs, t_colors **colors);
void	mlx_data_init(t_data *data);
void	rgb_init(t_rgb **rgb);
void	init_params(t_params **params);

int		check_params(t_data *data, char **file);
int		collect_all(t_data *data);

void	parse(t_data *data, char *argv);
void	parse_file(t_data *data, char **file, int *i, int *j);
int		find_map(int *i, char **file, t_data *data);
void	check_r_map(char **map, int size, int len);
char	**check_map(char **map, t_data *data, int size, int len);
int		check(char *filename);
int		check_walls(char *str, int i);
int		check_string(char *str, int j, t_data *data);
void	get_char(char c, t_data *data, int x, int y);

void	get_texts(int *i, char *line, t_data *data, char *flag);
t_rgb	*make_colors(char **arr);

int		ft_close(t_data *data);
void	free_map(char **map);
void	ft_error(int key);
void	if_space(char *str, int *i);

void	run(t_data *data);

void	player_move_draw(t_data *data);
void	ft_move_up(t_data *data);
void	ft_move_down(t_data *data);
void	ft_move_left(t_data *data);
void	ft_move_right(t_data *data);
void	get_colors(int *i, char *line, t_data *data, char flag);

void	get_move_from_key(t_data *data);
void	coin_animations(t_data *data);

#endif
