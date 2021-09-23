NAME = so_long

CC = gcc

CFLAG = -Wall -Werror -Wextra

SRCS = main.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$.o : $.c
	$(CC) $(CFLAG) -lmlx -c  $< -o $@

$(NAME) : $(OBJS)
	$(CC) -L ./minilibx_mms_20200219 -lmlx -framework OpenGL -framework AppKit *.c
