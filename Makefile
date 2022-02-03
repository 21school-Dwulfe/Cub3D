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
MLXLIB			= -lmlx -framework OpenGL -framework AppKit
LIB				= -L./libs/Libft -lft
PARSERLIB		= -L./parser/ -lparser
MAIN			= ./objs/main.o

$(OBJDIR)%.o : $(SRCDIR)%.c
		$(CC) $(CFLAGS) -g -DPWD="\"$(shell pwd)\"" -c $< -o $@

${APP} 	: Makefile buildrepo $(LIB) $(MLX) $(PARSERLIB) $(MAIN) $(OBJS)
		$(CC) $(CFLAGS) $(DEBUG) $(PARSERLIB) $(MLXLIB) $(LIB) $(MAIN) $(OBJS) -o $(APP)

all : $(APP)

print : 
	echo $(OBJS)

buildrepo :
		mkdir -p  $(OBJDIR)

$(MLX) :
	cd $(MLXDIR) && $(MAKE)

$(PARSERLIB):
	$(MAKE) lib -C ./parser

$(LIB) :
	$(MAKE) -C ./libs/Libft

$(MAIN) :
	$(CC) $(CFLAGS) -c main.c -o $(MAIN)
	
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
	$(MAKE) clean -C  ./libs/Libft
	$(MAKE) clean -C  ./libs/minilibx_mms

fclean	:
		rm -rf $(APP)
		rm -rf $(OBJDIR)
		$(MAKE) fclean -C  ./parser
		$(MAKE) fclean -C  ./libs/Libft

.PHONY	: all clean fclean re bonus buildrepo print create
	