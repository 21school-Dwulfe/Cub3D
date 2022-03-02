
#ifndef INCLUDE_H
# define INCLUDE_H

# include "./libft/libft.h"
# ifdef __APPLE__
#  include "./minilibx_opengl/mlx.h"
#  define KEY_PRESS 2
#  define DESTROYNOTIFY 17
# elif __linux__
#  include "./minilibx_linux/mlx.h"
#  include "/usr/include/X11/X.h"
# endif
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

#endif