SERVER = server
CLIENT = client

CFLAGS = -Wall -Wextra -Werror
CC = gcc
LIBS = -L./libft -lft
LIBFT = libft.a

all: $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT):
	@make -C libft

$(SERVER): server.o
	@$(CC) server.o $(LIBS) -o $@

$(CLIENT): client.o
	@$(CC) client.o $(LIBS) -o $@

%.o: %.c
	@$(CC) $(CFLAGS) $< -c -I libft

clean:
	@make clean -C libft
	@rm -f *.o

fclean: clean
	@make fclean -C libft
	@rm -f $(SERVER) $(CLIENT)

re: fclean all