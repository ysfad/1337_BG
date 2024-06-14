CFLAGS= -Wall -Wextra -Werror
SERVER= server
CLIENT= client
SERVER_C= server.c
CLIENT_C= client.c
SERVER_BONUS= server_bonus
CLIENT_BONUS= client_bonus
SERVER_BONUS_C= server_bonus.c
CLIENT_BONUS_C= client_bonus.c
LIBPRINT= ft_printf/libftprintf.a

all: server client

$(SERVER):$(SERVER_C)
	cc $(CFLAGS) -o $(SERVER) $(SERVER_C) $(LIBPRINT)

$(CLIENT):$(CLIENT_C)
	cc $(CFLAGS) -o $(CLIENT) $(CLIENT_C) $(LIBPRINT)

bonus: client_bonus server_bonus

$(SERVER_BONUS):$(SERVER_BONUS_C)
	cc $(CFLAGS) -o $(SERVER_BONUS) $(SERVER_BONUS_C) $(LIBPRINT)

$(CLIENT_BONUS):$(CLIENT_BONUS_C)
	cc $(CFLAGS) -o $(CLIENT_BONUS) $(CLIENT_BONUS_C) $(LIBPRINT)

clean:
	rm -rf $(SERVER)
	rm -rf $(CLIENT)
	rm -rf $(SERVER_BONUS)
	rm -rf $(CLIENT_BONUS)

fclean: clean

re: clean all