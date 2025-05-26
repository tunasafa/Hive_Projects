# Makefile
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++11

# Exercise 01
EX01_NAME = serializer
EX01_SRCS = Serializer.cpp main.cpp
EX01_OBJS = $(EX01_SRCS:.cpp=.o)


all: $(EX01_NAME)


$(EX01_NAME): $(EX01_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EX00_OBJS) $(EX01_OBJS) $(EX02_OBJS)

fclean: clean
	rm -f $(EX00_NAME) $(EX01_NAME) $(EX02_NAME)

re: fclean all

.PHONY: all clean fclean re
