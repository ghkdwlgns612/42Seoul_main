CC = gcc

CFLAGS = -Wall -Wextra -Werror

RFLAGS = rm -f

NAME = libftprintf.a

SRCS = ft_printf.c ft_check_info.c ft_initnode.c ft_make_d.c ft_make_nd.c ft_make_s.c \
       ft_output_c.c ft_output_d.c ft_output_p.c ft_output_s.c ft_output_u.c ft_output_x.c \
	   ft_start_printf.c ft_to_str.c ft_output_percent.c ft_output_c.c ft_make_c.c \
	   ft_maxsize.c ft_utils.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcu $(NAME) $(OBJS)

bonus : all

clean :
	$(RFLAGS) $(OBJS)

fclean : clean
	$(RFLAGS) $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re
