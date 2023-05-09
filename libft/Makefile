NAME = libft.a

SRC = ft_atoi.c \
		ft_split.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_bzero.c \
		get_next_line_utils.c \
		get_next_line.c

OBJ = ${SRC:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror -c

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

all : ${NAME}

${NAME}: ${OBJ}
	${CC} ${CFLAGS} ${SRC}
	ar rc ${NAME} ${OBJ}
	ranlib ${NAME}

clean :
	rm -f ${OBJ}

fclean : clean
		rm -f ${NAME} *.a

re : fclean all

.PHONY: re fclean clean all