# Makefile
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++11

# Exercise 00
EX00_NAME = convert
EX00_SRCS = ScalarConverter.cpp main.cpp
EX00_OBJS = $(EX00_SRCS:.cpp=.o)

all: $(EX00_NAME)

$(EX00_NAME): $(EX00_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EX00_OBJS) $(EX01_OBJS) $(EX02_OBJS)

fclean: clean
	rm -f $(EX00_NAME) $(EX01_NAME) $(EX02_NAME)

re: fclean all

.PHONY: all clean fclean re
