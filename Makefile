CC = gcc
CFLAGS = -Wall -Werror -Wextra

CLIENT = client
SERVER = server

CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

NAME = $(CLIENT) $(SERVER)
LIBFT = Libft/libft.a

all: $(NAME)

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT): Minitalk/client.c $(LIBFT)
	$(CC) $(CFLAGS) Minitalk/client.c $(LIBFT) -o $(CLIENT)

$(SERVER): Minitalk/server.c $(LIBFT)
	$(CC) $(CFLAGS) Minitalk/server.c $(LIBFT) -o $(SERVER)

$(SERVER_BONUS): Minitalk_bonus/server_bonus.c $(LIBFT)
	$(CC) $(CFLAGS) Minitalk_bonus/server_bonus.c $(LIBFT) -o $(SERVER_BONUS)

$(CLIENT_BONUS): Minitalk_bonus/client_bonus.c $(LIBFT)
	$(CC) $(CFLAGS) Minitalk_bonus/client_bonus.c $(LIBFT) -o $(CLIENT_BONUS)

$(LIBFT): $(shell find Libft/ -name "*.c" -type f)
	$(MAKE) -C Libft 

clean:
	$(MAKE) -C Libft clean

fclean: clean
	$(MAKE) -C Libft fclean
	rm -rf $(NAME) $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all

.PHONY:		all clean fclean re