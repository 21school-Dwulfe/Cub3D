/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:40:45 by ebalgruu          #+#    #+#             */
/*   Updated: 2022/02/03 17:29:42 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# include "../libs/include.h"

# define WIN_X 1024
# define WIN_Y 768

# define FILE_ERROR 100
# define MAP_ERROR 101
# define DATA_ERROR 102
# define MALLOC_ERROR 103
# define READ_ERROR 104
# define COMMON_ERROR 105

# define W 13
# define A 0
# define S 1
# define D 2
# define LEFT 123
# define RIGHT 124
# define ESC 53

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
}t_rgb;

typedef struct s_colors
{
	t_rgb	*floor;
	t_rgb	*cell;
}	t_colors;

typedef struct s_txs
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_txs;

typedef struct s_params
{
	int			pos;
	int			x;
	int			y;
	int			coin;
	int			coin_pos_x;
	int			coin_pos_y;
	int			enemy;
}t_params;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	void		*mlx_image;
	int			move;
	char		**map;
	int			loop_counter;
	void		*coin;
	t_txs		*txs;
	t_colors	*colors;
	t_params	*params;
}	t_data;

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
void	get_char(char c, t_data *data, int i, int j);

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
