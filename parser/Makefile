
SRCS		= $(shell ls *.c)

OBJS		= $(SRCS:.c=.o)

LIBDIR		= ../libs/Libft
LIBFT_LIB	= $(LIBDIR)/libft.a
LIB			= -L$(LIBDIR) -lft
MLXDIR		= ../libs/minilibx_mms
MLX			= $(MLXDIR)/libmlx.dylib
MLX_START	= -lmlx -framework OpenGL -framework AppKit
NAME		= libparser.a
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f

%.o: %.c	Makefile cub3D.h
			$(CC) -DPWD="\"$(shell pwd)\"" -g -c $< -o $@
 
$(NAME):	$(LIBFT_LIB) $(MLX) $(OBJS)
		$(CC) $(CFLAGS) -g -fsanitize=address  $(MLX_START) $(LIB) $(OBJS) -o parser 

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

print :
	echo $(SRCS)
	
lib  :$(OBJS)
			ar rcs libparser.a $?

.PHONY:		all clean fclean re tools tools2 lib print
