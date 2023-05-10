NAME = fdf

SRC_NAME = main.c \
		map.c \
		utils.c \
		render.c \
		display.c \
		rotation.c \
		keyboard.c \
		free.c \

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC_PATH 	= ./src
OBJ_PATH	= ./obj

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

CC = cc

DEBUG = -fsanitize=address,leak

CFLAGS = -Wall -Wextra -Werror -g -I./include -I./minilibx -I./libft

all : obj ${NAME}

obj :
	mkdir -p $(OBJ_PATH)

${NAME}: ${OBJ}
	make -C libft
	(cd minilibx && ./configure)
	$(CC) $(OBJ) -lX11 -lXext -I./minilibx -L./minilibx -lmlx -lm -o $(NAME) ./libft/libft.a

$(OBJ_PATH)/%.o:$(SRC_PATH)/%.c
	${CC} ${CFLAGS} -c $< -o $@

clean :
	rm -f ${OBJ_PATH}
	make -C libft clean

fclean : clean
		rm -f ${NAME} *.a
		make -C libft fclean

re : fclean all

.PHONY: re fclean clean all
