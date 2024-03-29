SERVER_SRCS = server.c server_utils.c
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
SERVER_NAME = server

CLIENT_SRCS = client.c client_utils.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
CLIENT_NAME = client

NAME = minitalk
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = -I.

$(NAME):$(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME):$(SERVER_OBJS)
				$(CC) $(CFLAGS) $(SERVER_OBJS) $(INC) -o $(SERVER_NAME)

$(CLIENT_NAME):$(CLIENT_OBJS)
				$(CC) $(CFLAGS) $(CLIENT_OBJS) $(INC) -o $(CLIENT_NAME)

all: $(NAME)

clean:
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)

fclean:clean
		$(RM) $(SERVER_NAME) $(CLIENT_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
