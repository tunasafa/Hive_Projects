#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 11:59:48 by stuna             #+#    #+#              #
#    Updated: 2023/11/24 16:53:44 by stuna            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES = ft_printf.c \
	  print_adrs.c \
	  print_hex_b.c \
	  print_num.c \
	  print_str.c \
	  print_hex_s.c \
	  print_prcnt.c \
	  print_unsgnd.c \
	  putchar_printf.c \

HDR_FILES = ft_printf.h

OBJ_FILES = $(SRC_FILES:.c=.o)

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar -rcs $(NAME) $(OBJ_FILES)

%.o: %.c $(HDR_FILES)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean all clean

