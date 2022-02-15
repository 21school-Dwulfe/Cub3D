/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwulfe <dwulfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:07:08 by dwulfe            #+#    #+#             */
/*   Updated: 2022/02/07 19:13:07 by dwulfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# define WIN_X 1024
# define WIN_Y 768

# define TXTR_H 64
# define TXTR_W 64

# define FILE_ERROR 100
# define MAP_ERROR 101
# define DATA_ERROR 102
# define MALLOC_ERROR 103
# define READ_ERROR 104
# define COMMON_ERROR 105

# ifdef __APPLE__
# define W 13
# define A 0
# define S 1
# define D 2
# define LEFT 123
# define RIGHT 124
# define ESC 53
# elif __linux__
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
}				t_rgb;

typedef struct s_colors
{
	t_rgb	*floor;
	t_rgb	*cell;
}	t_colors;

typedef struct s_txs
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
}				t_txs;
typedef struct s_raycaster
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		time;
	double		old_time;
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			loop_counter;
	int			txtr_num;
	double		wall_x;
	double		txtr_pos;
	int			txtr_x;
	int			txtr_y;
	double		step;
	int			color;
	int			**map;
	int			x;
	int			y;
	double		move_speed;
	double		rot_speed;
	double		plane_x;		
	double		plane_y;
}				t_raycaster;

typedef struct s_img
{
	void		*img;	
	int			*addr; 					// data array of colors in from matrix
	int			bits_per_pixel;
	int			size_l;
	int			line_length;
	int			endian;
	int			img_width;
	int			img_height;
}				t_img;

typedef struct s_parser
{
	int			pos;
	int			pos_x;
	int			pos_y;
	int			enemy;       	//
	char		**map;
	int			coin;
	int			coin_pos_x;
	int			coin_pos_y;
	t_txs		*paths;
	t_colors	*colors;
}				t_parser;

typedef struct s_data
{
	int				key[512];				// keys
	int				key_l;
	int				key_r;
//	int				matrix[WIN_X * WIN_Y];	// buffer matrix
	int				buff[WIN_Y][WIN_X];
	void			*mlx; 					// ptr mlx
	void			*mlx_win; 				// ptr win
	t_img			*mlx_image;				// 
	int				*textures[5];
	int				txt_count;
	t_raycaster		*rc;
	t_parser		*parser;
}					t_data;

#endif
