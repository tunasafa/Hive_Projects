# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/25 14:23:54 by stuna             #+#    #+#              #
#    Updated: 2025/02/11 16:44:12 by stuna            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CXX = c++ 

FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

GREEN = \033[0;32m
YELLOW = \033[0;33m
NC = \033[0m

all: $(NAME)

$(NAME):$(OBJS)
	@$(CXX) $(FLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)Build successful: $(NAME)$(NC)"

%.o: %.cpp
	@$(CXX) $(FLAGS) -c $<

clean:
	@rm -f $(OBJS)
	@echo "$(YELLOW)Clean successful: object files removed$(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW)Clean successful: $(NAME) removed.$(NC)"

re: fclean all

.PHONY: fclean all clean re

