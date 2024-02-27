NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

###########################Sources#############################
SRCS = \
		ft_printf.c fonctions1.c fonctions2.c check_flags.c\
		fonctions_diese_bonus.c fonctions_plus_bonus.c \
		fonctions_space_bonus.c fonctions_moins_bonus.c \
		fonctions_moins2_bonus.c fonctions_point_bonus.c \
		fonctions_point2_bonus.c fonctions_number_space_bonus.c \
		fonctions_0_bonus.c fonctions_0_point_bonus.c \
		fonctions_0_point2_bonus.c \

###########################Objects#############################
OBJS = ${SRCS:.c=.o}

##########################Rules###############################

%.o : %.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS} $?

all: ${NAME}

bonus : all

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
