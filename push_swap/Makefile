NAME = push_swap 

SRC_FILES = check.c \
			init_stack.c \
			operation.c \
			push.c \
			revrot.c \
			swaps.c \
			utils_error.c \
			algo.c \
			error.c \
			main.c \
			rot.c \
			utilz.c \
			utils_stack.c \

OBJ_FILES = $(SRC_FILES:.c=.o)
LIBFT = libft/libft.a
HDR_FILES = push_swap.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft/

$(NAME): $(OBJ_FILES)
	${CC} ${CFLAGS} ${OBJ_FILES} ${LIBFT} -o ${NAME} -lft -Llibft

%.o: %.c
	$(CC) $(CFLAGS) -c ${SRC_FILES} -I ${HDR_FILES}

clean:
	make clean -C ./libft
	rm -f $(OBJ_FILES)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: fclean all clean
