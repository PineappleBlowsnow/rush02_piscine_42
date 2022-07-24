SRCS		= ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c main.c ft_errorhandle.c ft_displayfile.c
CFLAGS		= -Wall -Wextra -Werror
CC			= gcc
INC			= -I./includes
SRC_DIRS 	= ./srcs
BUILD_DIR   = ./builds
RM= rm -rf
OBJS =${SRCS:.c=.o}
NAME = ft_cat

${BUILD_DIR}/%.o:${SRC_DIRS}/%.c
	mkdir -p ${BUILD_DIR}
	${CC} ${CFLAGS}  -c $< -o $@ ${INC}

all: ${NAME}

${NAME}: ${OBJS:%=${BUILD_DIR}/%}
		${CC} ${CFLAGS} -o $@ ${OBJS:%=${BUILD_DIR}/%}
clean: 
	${RM} ${OBJS:%=${BUILD_DIR}/%}
fclean: clean
	${RM} ${NAME}
re: fclean all
