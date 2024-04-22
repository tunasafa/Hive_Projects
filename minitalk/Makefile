# NAMES #
CLIENT = client
SERVER = server

# SOURCES #
SRC_CLIENT = client.c
SRC_SERVER = server.c
SRC_UTILS = utils.c
HEADER = minitalk.h

# COMPILE VARS #
CC     = gcc
CFLAGS = -Wall -Wextra -Werror
RM     = rm -f

# MESSAGE COLORS #
GREEN   = \033[32;1m
RED     = \033[31;49;1m
YELLOW  = \033[33;49;1m
RESET   = \033[0m

all: $(SERVER) $(CLIENT)

# BUILD #
$(SERVER): $(SRC_SERVER) $(HEADER)
	@ $(CC) $(CFLAGS) $(SRC_UTILS) $(SRC_SERVER) -o $(SERVER)
	@echo "\n	$(GREEN) SERVER IS BUILT $(RESET)"
$(CLIENT): $(SRC_CLIENT) $(HEADER)
	@ $(CC) $(CFLAGS) $(SRC_UTILS) $(SRC_CLIENT) -o $(CLIENT)
	@echo "\n	$(GREEN) CLIENT IS BUILT $(RESET)\n"

# CLEANS #
clean:
	@ $(RM) $(CLIENT) $(SERVER)
	@echo "\n	$(YELLOW) SERVER IS CLEANED $(RESET)"
	@echo "\n	$(YELLOW) CLIENT IS CLEANED $(RESET)\n"
fclean:
	@ $(RM) $(CLIENT) $(SERVER)
	@echo "\n	$(YELLOW) SERVER IS FCLEANED $(RESET)"
	@echo "\n	$(YELLOW) CLIENT IS FCLEANED $(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
