# Makefile
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++11

# Exercise 02
EX02_NAME = identify
EX02_SRCS = Base.cpp identify.cpp main.cpp
EX02_OBJS = $(EX02_SRCS:.cpp=.o)

all: $(EX02_NAME)

$(EX02_NAME): $(EX02_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EX00_OBJS) $(EX01_OBJS) $(EX02_OBJS)

fclean: clean
	rm -f $(EX00_NAME) $(EX01_NAME) $(EX02_NAME)

re: fclean all

.PHONY: all clean fclean re
