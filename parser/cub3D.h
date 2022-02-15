/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:16:04 by dwulfe            #+#    #+#             */
/*   Updated: 2022/02/15 14:25:51 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/include.h"
# include "../includes/structures.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int		get_next_line(int fd, char **line, int ret);
int		ft_atoi_rgb(char *str);
void	ft_error(int key);

// void	init(t_parser **data, t_parser **parser, t_txs **txs, t_colors **colors);
// void	mlx_data_init(t_parser *data);
void	rgb_init(t_rgb **rgb);
// void	init_params(t_params **params);

int		check_params(t_parser *data, char **file);
int		collect_all(t_parser *data);

void	parse(t_parser *data, char *argv);
void	parse_file(t_parser *data, char **file, int *i, int *j);
int		find_map(int *i, char **file, t_parser *data);
void	check_r_map(char **map, int size, int len);
char	**check_map(char **map, t_parser *data, int size, int len);
int		check(char *filename);
int		check_walls(char *str, int i);
int		check_string(char *str, int j, t_parser *data);
void	get_char(char c, t_parser *data, int x, int y);

void	get_texts(int *i, char *line, t_parser *data, char *flag);
t_rgb	*make_colors(char **arr);

void	free_map(char **map);
void	ft_error(int key);
void	if_space(char *str, int *i);

void	run(t_parser *data);

void	player_move_draw(t_parser *data);
void	ft_move_up(t_parser *data);
void	ft_move_down(t_parser *data);
void	ft_move_left(t_parser *data);
void	ft_move_right(t_parser *data);
void	get_colors(int *i, char *line, t_parser *data, char flag);

void	get_move_from_key(t_parser *data);
void	coin_animations(t_parser *data);

#endif
