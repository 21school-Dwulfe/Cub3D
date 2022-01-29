APP 			= Cub3d

SYSTEM 			:= $(shell uname)

ifeq ($(SYSTEM), Linux)
	MAKE		= make
endif

CFLAGS			= -Wall -Wextra -Werror
DEBUG			= -g
OPTIM			= -O2
INCLUDES		= -I./includes
CC				= gcc
LIBS			= -L./libs/libft -lft
#LIBS			+= -L./libst/minilibx-linux-master -l

%.o : %.c 
		$(CC) $(LIBS) $(DEBUG) $(OPTIM) $(INCLUDES) $(CFLAGS) -c $< -o $@

${APP}	: Makefile $(HEADERS) create main.c main.o
		$(CC) main.o  -o $(APP)

all		: $(APP)

#	$(MAKE) -C  ./render
create 	: 
		$(CC) -c main.c -o main.o
		$(MAKE) -C  ./parser
		$(MAKE) -C  ./libs/libft
# ifeq ($(SYSTEM), Linux)
# 	$(MAKE) -C  ./libs/minilibx-linux-master
# endif
# ifeq ($(SYSTEM), Darwin)
# 	$(MAKE) -C  ./libs/minilibx_mms
# endif

#	$(MAKE) clean -C  ./render
clean	:
		$(MAKE) clean -C  ./parser
		$(MAKE) clean -C  ./libs/Libft
		$(MAKE) clean -C  ./libs/dwulfe
# ifeq ($(SYSTEM), Linux)
# 	$(MAKE) clean -C  ./libs/minilibx-linux-master
# endif
# ifeq ($(SYSTEM), Darwin)
# 	$(MAKE) clean -C  ./libs/minilibx_mms
# endif

fclean	:
		rm -rf $(APP)
		$(MAKE) fclean -C  ./parser
		$(MAKE) fclean -C  ./render
		$(MAKE) fclean -C  ./libs/Libft
		$(MAKE) fclean -C  ./libs/dwulfe
		ifeq ($(SYSTEM), Linux)
			$(MAKE) fclean -C  ./libs/minilibx-linux-master
		endif
		ifeq ($(SYSTEM), Darwin)
			$(MAKE) fclean -C  ./libs/minilibx_mms
		endif

.PHONY	: all clean fclean re bonus buildrepo print create

print	:
		echo $(HEADERS)
	