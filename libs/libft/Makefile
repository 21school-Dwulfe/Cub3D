SRCSDIR = ./

SRCS 			:= $(shell find . -name '*.c' ! -name '*_bonus.c')

SRCS_BONUS 		:= $(shell find . -name '*_bonus.c')

OBJS 			:= ${SRCS:.c=.o}

OBJS_BONUS 		:= ${SRCS_BONUS:.c=.o}

NAME 			:= libft.a 

HEADER 			:= libft.h

CC 				:= gcc

RM 				:= rm -rf

CFLAGS 			:= -Wall -Wextra -Werror 

%.o: %.c	libft.h
			${CC} ${CFLAGS} -I./ -c $<  -o ${<:.c=.o}

$(NAME) :	${OBJS} 
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

bonus: 	$(OBJS_BONUS)
		ar rc ${NAME} ${OBJS_BONUS}
		ranlib ${NAME}
			
all :		${NAME} 

clean :
			${RM} *.o

fclean :	clean 
			rm -rf libft.a

re :		fclean all

clean_bonus: 
			${RM} ${OBJS_BONUS}

fclean_bonus: clean_bonus 
			${RM} bonus

rebonus :  fclean_bonus bonus

.PHONY	:	bonus clean fclean all re  clean_bonus fclean_bonus rebonus


