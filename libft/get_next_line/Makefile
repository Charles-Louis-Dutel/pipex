NAME = libgnl.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

###########################Sources#############################
SRCS = get_next_line.c get_next_line_utils.c

###########################Objects#############################
OBJS = ${SRCS:.c=.o}

%.o:%.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS} $?

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
