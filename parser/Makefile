
SRCS		= $(shell ls *.c)

OBJS		= $(SRCS:.c=.o)

LIBDIR		= ../libs/Libft
LIBFT_LIB	= $(LIBDIR)/libft.a
LIB			= -L$(LIBDIR) -lft
MLXDIR		= ../libs/minilibx_mms
MLX			= $(MLXDIR)/libmlx.dylib
MLX_START	= -L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit
NAME		= cub3D_parsing.a
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra #-I
RM			= rm -f

%.o: %.c	Makefile cub3D.h
			$(CC) $(CFLAGS) -g -c $< -o $@

$(NAME):	$(OBJS)
			ar rcs $(NAME) $?

all:		$(NAME)

$(LIBFT_LIB): 
	cd $(LIBDIR) && $(MAKE) && $(MAKE) bonus

$(MLX) :
	cd $(MLXDIR) && $(MAKE)

clean:
		$(RM) $(OBJS) $(BOBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

# debug : $(LIBFT_LIB) $(MLX)  $(OBJS)   
# 		$(CC) $(CFLAGS) $(MLX_START) $(LIB) $(OBJS) -g -o parser 
print :
	echo $(SRCS)
debug : $(LIBFT_LIB) $(MLX) $(OBJS)
		$(CC) $(MLX_START) $(CFLAGS) -g -fsanitize=address $(LIB) $(OBJS) -o parser 

.PHONY:		all clean fclean re tools tools2 debug print
