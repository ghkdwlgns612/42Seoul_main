CC = gcc;

CFLAGS = -Wall -Wextra -Werror

RFLAGS = rm -f

NAME = push.a

SRCS = src/push_swap.c

OBJS = $(SRCS:.c:.o)

all : $(NAME)

%.o : %.c
			$(CC) $(CFLAGS)	-c $<

$(NAME) : $(OBJS)
	ar cr $(NAME) $(OBJS)