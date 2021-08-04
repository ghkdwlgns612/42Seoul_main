NAME	=	minitalk;

# CLIENT	=	client;
# CLIENT_SRC	=	utils/ft_atoi.c utils/ft_putchar_fd.c \
# 			 utils/ft_putnbr_fd.c utils/ft_putstr_fd.c \
# 			 mandatory/client.c utils/utils.h;
# CLIENT_BONUS = utils/ft_atoi.c utils/ft_putchar_fd.c \
# 			 utils/ft_putnbr_fd.c utils/ft_putstr_fd.c \
# 			 bonus/client_bonus.c utils/utils.h;

# SERVER = server;
# SERVER_SRC = utils/ft_atoi.c utils/ft_putchar_fd.c \
# 			 utils/ft_putnbr_fd.c utils/ft_putstr_fd.c \
# 			 mandatory/server.c utils/utils.h;
# SERVER_BONUS = utils/ft_atoi.c utils/ft_putchar_fd.c \
# 			 utils/ft_putnbr_fd.c utils/ft_putstr_fd.c \
# 			 bonus/server_bonus.c utils/utils.h;

CLIENT	=	client;
CLIENT_SRC	=	utils/*.*	mandatory/client.c
CLIENT_BONUS	=	utils/*.*	bonus/client_bonus.c

SERVER	=	server;
SERVER_SRC	=	utils/*.*	mandatory/server.c
SERVER_BONUS	=	utils/*.*	bonus/server_bonus.c

CC	=	gcc
FLAGS	=	-Wall -Wextra -Werror
RM	=	rm -rf

all	: $(CLIENT) $(SERVER)

	$(CLIENT) : $(CLIENT_SRC)
				$(CC)	$(FLAGS)	-I	$(CLIENT_SRC)	-o	$(CLIENT)

	$(SERVER)	:	$(SERVER_SRC)
				$(CC)	$(FLAGS)	-I	$(SERVER_SRC)	-o	$(SERVER)

bonus : CL_BONUS SR_BONUS

CL_BONUS : $(CLIENT_BONUS)
	$(CC) $(FLAGS) -I $(CLIENT_BONUS) -o $(CLIENT)

SR_BONUS : $(SERVER_BONUS)
	$(CC) $(FLAGS) -I $(SERVER_BONUS) -o $(SERVER)

cl: $(CL)

sv: $(SV)

clean:

fclean: clean
	@$(RM) $(SV) $(CL) $(SV_BONUS) $(CL_BONUS) 

re: fclean all