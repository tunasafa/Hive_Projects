CC := cc
CFLAGS := -Wall -Wextra -Werror
NAME := minishell

LIBFT := libft/libft.a
INCL := -I headers/
RL_PATH := ~/.brew/opt/readline/lib

SRC :=			src/main.c \
				src/builtins/echo.c \
				src/builtins/export.c \
				src/builtins/unset.c \
				src/builtins/cd.c \
				src/builtins/env.c \
				src/builtins/exit.c \
				src/builtins/builtin_utils.c \
				src/builtins/builtins.c \
				src/builtins/shelllevel.c \
				src/builtins/pwd.c \
				src/builtins/var_utils.c \
				src/builtins/var_utils2.c \
				src/builtins/var_utils3.c \
				src/parsing/parser.c \
				src/parsing/syntax_check.c \
				src/parsing/syntax_check2.c \
				src/parsing/parser_utils.c \
				src/parsing/file_list_utils.c \
				src/parsing/parser_struct_utils.c \
				src/parsing/redirections.c \
				src/parsing/heredoc.c \
				src/parsing/heredoc_utils.c \
				src/parsing/command.c \
				src/parsing/arg_lst.c \
				src/utils/white_spaces.c \
				src/utils/errors.c \
				src/utils/errors2.c \
				src/utils/free_stuff.c \
				src/utils/init_c_env.c \
				src/execution/exe_cmds.c \
				src/execution/exe_cmds2.c \
				src/execution/exe_cmds3.c \
				src/execution/exe_cmds4.c \
				src/execution/execution_utils.c \
				src/execution/execution_utils2.c \
				src/ctrls/ctrld.c \
				src/ctrls/ctrl_utils.c \
				src/parsing/dolar_handling.c \
				src/parsing/dolar_handling1.c \
				src/parsing/dolar_handling2.c \
				src/parsing/dolar_handling3.c \
				src/parsing/dolar_handling4.c

OBJ := $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ $(INCL) -lreadline -L $(RL_PATH)

$(LIBFT):
	make -C ./libft

clean:
	rm -rf $(OBJ)
	make -C ./libft/ clean

fclean: clean
	make -C ./libft/ fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re		
