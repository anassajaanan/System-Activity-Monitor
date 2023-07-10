NAME = system_monitor

SRC =	cpu.c disk.c main.c memory.c utils.c \
		./helpers/ft_atoi.c ./helpers/ft_isnumeric.c ./helpers/ft_split.c ./helpers/ft_strjoin.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror

${NAME}: ${SRC}
	${CC} ${CFLAGS} ${SRC} -o ${NAME}

all: ${NAME}

clean:
	rm -f ${NAME}

.PHONY: all clean
