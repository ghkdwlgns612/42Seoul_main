NAME = minitalk

SERVER = server
CLIENT = client

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SRC = ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strlen.c ft_atoi.c

CC = gcc
FLAGS = -Wall -Wextra -Werror
RF = rm -rf

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER):
	$(CC) -I $(FLAGS) $(SRC) server.c -o $(SERVER)

$(CLIENT):
	$(CC) -I $(FLAGS) $(SRC) client.c -o $(CLIENT)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS):
	$(CC) -I $(FLAGS) $(SRC) utils.h server_bonus.c -o $(SERVER_BONUS)

$(CLIENT_BONUS):
	$(CC) -I $(FLAGS) $(SRC) utils.h client_bonus.c -o $(CLIENT_BONUS)

clean:
	$(RF) *dSYM *.gch

fclean: clean
	$(RF) $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all