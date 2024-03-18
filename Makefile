NAME = pipex
NAME_BONUS = pipex_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

############################Sources########################
SRCS_DIR = sources/
FILES = pipex.c childs.c utils.c manage_error.c\

SRCS = $(addprefix $(SRCS_DIR), $(FILES))

BONUS_DIR = sources/bonus/
FILES_BONUS = pipex_bonus.c manage_error_bonus.c \
			  utils_bonus.c childs_bonus.c first_last_child.c \
			  here_doc.c without_here_doc.c \

SRCS_BONUS = $(addprefix $(BONUS_DIR), $(FILES_BONUS))

###########################Objects#########################
OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}
OBJS_ALL = ${OBJS} ${OBJS_BONUS}

##########################Libs#############################
LIBFT = ./libft/libft.a
FT_PRINTF = ./libft/ft_printf/libftprintf.a
GNL = ./libft/get_next_line/libgnl.a
GNL_NO_MALLOC = ./libft/gnl_no_malloc/libgnlnomalloc.a
ALL_LIB = ${LIBFT} ${FT_PRINTF} ${GNL} ${GNL_NO_MALLOC}

##########################Rules############################
${NAME}: ${OBJS}
		@${MAKE} -C ./libft
		${CC} ${CFLAGS} ${OBJS} ${ALL_LIB} -o ${NAME}

all: ${NAME} bonus

bonus: ${OBJS_BONUS}
		@${MAKE} -C ./libft
		${CC} ${CFLAGS} ${OBJS_BONUS} ${ALL_LIB} -o ${NAME_BONUS}

clean:
	@${MAKE} -C ./libft fclean
	rm -f ${OBJS}
	rm -f ${OBJS_BONUS}
	rm -f ${OBJS_ALL}

fclean: clean
	rm -f ${NAME}
	rm -f ${NAME_BONUS}

re: fclean all

.PHONY: all clean fclean re bonus
