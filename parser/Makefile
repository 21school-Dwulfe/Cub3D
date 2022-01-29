SRCS		= funcs.c gnl.c inits.c mlx.c \
			  cleaning.c check_map.c parse_textures.c check_params.c \
			  parse_colors.c parser.c exec.c \
#main.c 
#BSRCS		= ... //bonus part

OBJS		= $(SRCS:.c=.o)

#BOBJS		= $(BSRCS:.c=.o) //bonus part

LIBDIR		= Libft

LIBFT_LIB	= $(LIBDIR)/libft.a

LIB			= -L$(LIBDIR) -lft

MLXDIR		= minilibx_mms

MLX			= $(MLXDIR)/libmlx.dylib

MLX_START	= -lmlx -framework OpenGL -framework AppKit

NAME		= cub3D_parsing.a

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra -I

RM			= rm -f



%.o: %.c	Makefile cub3D.h
			$(CC) $(CFLAGS)  $(LIBDIR)  -c $< -o $@

debug :	$(LIBFT_LIB) $(OBJS) $(MLX)  main.c
		$(CC) $(CFLAGS) $(LIBDIR) main.c -o main.o
		$(CC) $(CFLAGS) $(LIBDIR) $(OBJS) \
		main.o -g -fsanitize=address -o $(NAME) $(LIB) $(MLX_START)

$(NAME):	$(OBJS) 
			ar x 
			ar rcs $(NAME) $?

all:		$(NAME)

$(LIBFT_LIB):	tools ;

tools:
			make -C $(LIBDIR)

$(MLX):		tools2 ;

tools2:
			$(MAKE) -C $(MLXDIR)

clean:
			$(MAKE) clean -C $(LIBDIR) 
			$(MAKE) clean -C $(MLXDIR)
			$(RM) $(OBJS) $(BOBJS)

fclean:		clean
			make fclean -C $(LIBDIR)
			$(RM) $(NAME) $(MLX)

re:			fclean all

.PHONY:		all clean fclean re tools tools2 debug

