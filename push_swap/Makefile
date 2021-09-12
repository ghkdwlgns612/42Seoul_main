NAME = push_swap
BONUS_NAME = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror
# CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

RFLAGS = rm -f

SRCS_DIR = ./src	\
			./src/algoritm	\
			./src/check_init	\
			./src/functions		\
			./src/utils			\

BONUS_DIR = ./bonus	\
			./bonus/check_init \
			./bonus/functions \
			./bonus/gnl	\

SRCS =	./src/push_swap.c	\
		./src/utils/ft_split.c	\
		./src/utils/utils.c	\
		./src/check_init/init.c	\
		./src/check_init/check_duplicate.c	\
		./src/functions/push.c	\
		./src/functions/reverse_rotate.c	\
		./src/functions/rotate.c	\
		./src/functions/swap.c	\
		./src/algoritm/a_to_b.c	\
		./src/algoritm/b_to_a.c	\
		./src/algoritm/algoritm.c	\
		./src/algoritm/five.c	\
		./src/algoritm/one_two_three.c	\
		./src/algoritm/three_a.c	\
		./src/algoritm/three_b.c	\

BONUS = ./bonus/check_init/check.c	\
		./bonus/check_init/init.c	\
		./bonus/functions/push.c	\
		./bonus/functions/reverse_rotate.c	\
		./bonus/functions/rotate.c	\
		./bonus/functions/swap.c	\
		./bonus/gnl/get_next_line_utils.c	\
		./bonus/gnl/get_next_line.c	\
		./bonus/bonus.c	\
		./bonus/checker.c	\
		./bonus/utils.c	\

OBJS = $(notdir $(SRCS:.c=.o))
vpath %.c $(SRCS_DIR)

BONUS_OBJS = $(notdir $(BONUS:.c=.o))
vpath %.c $(BONUS_DIR)

all : $(NAME)

bonus : $(BONUS_NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(BONUS_NAME) : $(BONUS_OBJS)
	$(CC) $(CFLAGS) -O $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $^

clean :
	$(RFLAGS) -r $(OBJS) $(BONUS_OBJS)

fclean : clean
	$(RFLAGS) $(NAME) $(BONUS_NAME)

re : fclean all



