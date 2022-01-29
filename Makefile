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

${APP}	: Makefile $(HEADERS) $(LIB) $(OBJDIR)
		$(CC)  -o $(APP)

all	: $(APP)

clean	:
	$(MAKE) clean -C  ./parser
	$(MAKE) clean -C  ./render
	$(MAKE) clean -C  ./libs/Libft
	$(MAKE) clean -C  ./libs/dwulfe
	ifeq ($(SYSTEM), Linux)
		$(MAKE) clean -C  ./minilibx-linux

fclean	: clean
		rm -rf ($APP)

.PHONY	: all clean fclean re bonus buildrepo lib print

print	:
		echo $(HEADERS)
		#https://github.com/iamfantaser/libft.git
		#https://github.com/21school-Dwulfe/Cub3D.git