APP 			= Cub3d

SYSTEM 			:= $(shell uname)
SRCDIR 			:= ./render/srcs/
OBJDIR 			:= ./objs/
HEADERDIR		:= includes
PWD				:= $(shell pwd)

SRCS 			:= $(shell find $(SRCDIR) -name '*.c')
OBJS			:= ${addprefix $(OBJDIR), $(notdir $(SRCS:.c=.o))}
HEADERS			:= ${shell find ./libs -name '*.h'}
SYSTEM			=  $(shell uname)

CFLAGS			= -Wall -Wextra -Werror
DEBUG			= -g -fsanitize=address
OPTIM			= -O2
INCLUDES		= -I./includes
CC				= gcc
# ifeq ($(SYSTEM), Linux)
# MLXLIB			= -L./libs/minilibx_linux -lmlx_Linux -lXext -lX11 -lm -lz
# MLXDIR			= ./libs/minilibx_linux/
# else ifeq ($(SYSTEM), Darwin)
MLXLIB			= -L./libs/minilibx_opengl -lmlx -framework OpenGL -framework AppKit
MLXDIR			= ./libs/minilibx_opengl/
#endif
LIB				= -L./libs/libft -lft
PARSERLIB		= -L./parser/ -lparser -I./parser
MAIN			= ./objs/main.o

$(OBJDIR)%.o : $(SRCDIR)%.c
		$(CC) $(CFLAGS)  -g -DPWD="\"$(shell pwd)\"" -DBONUS=0 -c $< -o $@

${APP} 	: Makefile buildrepo $(LIB)  $(MLXLIB) $(PARSERLIB) $(MAIN) $(OBJS)
		$(CC) $(CFLAGS) $(DEBUG)  $(MAIN) $(OBJS) -o $(APP) $(PARSERLIB) $(MLXLIB) $(LIB)
# gcc main.c render/srcs/*.c -DBONUS=0 -DPWD="\"$(pwd)\"" -L./parser -lparser -L./libs/minilibx_linux -lmlx_Linux -lXext -lX11 -lm -lz -L./libs/libft -lft
all : $(APP)

print : 
	echo $(MLXLIB)

buildrepo :
		mkdir -p  $(OBJDIR)

$(MLXLIB) :
	cd $(MLXDIR) && $(MAKE)

$(PARSERLIB):
	$(MAKE) lib -C ./parser

$(LIB) :
	$(MAKE) -C ./libs/libft

$(MAIN) :
	$(CC) $(CFLAGS) -g -c main.c -o $(MAIN)
	
# clean:
# 			$(MAKE) clean -C $(LIBDIR) $(MLXDIR)
# 			$(RM) $(OBJS) $(BOBJS)

# fclean:		clean
# 			make fclean -C $(LIBDIR).PHONY: all clean fclean re bonus buildrepo
# 			$(RM) $(NAME) $(MLX)

re:			fclean all

# create 	: 
# $(MAKE) lib -C  ./parser
# $(MAKE) -C  ./libs/minilibx_mms
# $(MAKE) -C  ./libs/libft
clean	:
	$(MAKE) clean -C  ./parser
	$(MAKE) clean -C  ./libs/libft
	$(MAKE) clean -C  $(MLXDIR)

fclean	:
		rm -rf $(APP)
		rm -rf $(OBJDIR)
		$(MAKE) fclean -C  ./parser
		$(MAKE) fclean -C  ./libs/libft
		$(MAKE) clean -C  $(MLXDIR)

.PHONY	: all clean fclean re bonus buildrepo print create
	