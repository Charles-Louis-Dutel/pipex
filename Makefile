NAME = pipex
NAME_BONUS = pipex_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror

############################Sources########################
SRCS_DIR = sources/
FILES = pipex.c \

SRCS = $(addprefix $(SRCS_DIR), $(FILES))

#BONUS_DIR = sources/bonus/
#FILES_BONUS = 

#SRCS_BONUS = $(addprefix $(BONUS_DIR), $(FILES_BONUS))

###########################Objects#########################
OBJS = ${SRCS:.c=.o}
#OBJS_BONUS = ${SRCS_BONUS:.c=.o}
#OBJS_ALL = ${OBJS} ${OBJS_BONUS}

##########################Libs#############################
LIBFT = ./libft/libft.a
FT_PRINTF = ./libft/ft_printf/libftprintf.a
GNL = ./libft/get_next_line/libgnl.a
ALL_LIB = ${LIBFT} ${FT_PRINTF} ${GNL}

##########################Rules############################
${NAME}: ${OBJS}
		@${MAKE} -C ./libft
		${CC} ${CFLAGS} ${OBJS} ${ALL_LIB} -o ${NAME}

all: ${NAME} bonus

#bonus: ${OBJS_BONUS}
#		@${MAKE} -C ./libft
#		${CC} ${CFLAGS} ${OBJS_BONUS} ${ALL_LIB} -o ${NAME_BONUS}

clean:
	@${MAKE} -C ./libft fclean
	rm -f ${OBJS}
#	rm -f ${OBJS_ALL}

fclean: clean
	rm -f ${NAME}
#	rm -f ${NAME_BONUS}

re: fclean all

.PHONY: all clean fclean re bonus