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
	int		t;
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

typedef struct s_raycaster
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;	
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		txtr_num;
	double	wall_x;
	double	txtr_pos;
	int		txtr_x;
	int		txtr_y;
	double	step;
	int		color;
	int		x;
	int		y;
}				t_raycaster;


typedef struct s_params
{
	int			pos;
	int			pos_x;
	int			pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		time;
	double		old_time;
	int			coin;
	int			coin_pos_x;
	int			coin_pos_y;
	int			enemy;
}				t_params;

typedef struct s_data
{
	void			*mlx; 					// ptr mlx
	void			*mlx_win; 				// ptr win
	void			*mlx_image;				// pointer image
	int				*addr; 					// data array of colors in from matrix
	int				matrix[WIN_X * WIN_Y];	// buffer matrix
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	t_raycaster		*rc;
	int				keys[512];				// keys
	char			**map;
	int				loop_counter;
	void			*coin;
	t_txs			*txs;
	t_colors		*colors;
	t_params		*params;
}					t_data;

#endif
