CC = gcc;

CFLAGS = -Wall -Wextra -Werror

RFLAGS = rm -f

NAME = push.a

SRCS = ./src/push_swap.c	\
		./src/utils/ft_split.c	\
		./src/utils/util1.c		\
		./src/check_init/*	\

OBJS = $(SRCS:.c:.o)

all : $(NAME)

%.o : %.c
			$(CC) $(CFLAGS)	-c $<

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

