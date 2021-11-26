NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS =  srcs/main.c srcs/utils.c \
		srcs/parse.c srcs/routine.c
OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -I includes ${OBJS} -o ${NAME}

fclean: clean
	rm -f ${NAME}

clean:
	rm -f ${OBJS}

re: fclean clean all