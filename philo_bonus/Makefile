NAME = philo_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS =  srcs/main.c srcs/utils.c \
		srcs/parse.c srcs/routine.c \
		srcs/checkaction.c srcs/time.c
OBJS = ${SRCS:.c=.o}

UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
	CFLAGS += -pthread
endif

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -I includes ${OBJS} -o ${NAME}

fclean: clean
	rm -f ${NAME}

clean:
	rm -f ${OBJS}

re: fclean clean all