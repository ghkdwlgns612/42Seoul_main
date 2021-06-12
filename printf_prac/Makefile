CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
SRCS =  main.c
OBJS = $(SRCS:.c=.o)
all : $(NAME)
$(NAME) : $(OBJS)
	ar cr $(NAME) $(OBJS)
%3.o : %3.c
	$(CC) $(CFLAGS) -c $^ -o $@
clean :
	rm -f $(OBJS)
	make clean -C ./libft
fclean :
	rm -f $(NAME) $(OBJS)
	make fclean -C ./libft
re :
	make fclean
	make all
