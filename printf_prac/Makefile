CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
SRCS =  ft_int_arr.c ft_int_put_value.c ft_int_setting.c ft_int_zero.c ft_printf.c\
		ft_utils1.c ft_utils2.c ft_int.c ft_char.c
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
