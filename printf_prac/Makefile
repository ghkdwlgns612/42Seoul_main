CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
SRCS =  ft_printf.c	ft_int_minus.c ft_int_precision.c ft_int.c ft_utils.c ft_inform.c
OBJS = $(SRCS:.c=.o)
all : $(NAME)
$(NAME) : $(OBJS)
	ar cr $(NAME) $(OBJS)
%.o : %.c
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
