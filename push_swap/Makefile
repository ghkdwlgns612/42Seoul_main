NAME = push_swap
BONUS_NAME = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror
#CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

RFLAGS = rm -f

SRCS_DIR = ./src	\
			./src/algoritm	\
			./src/check_init	\
			./src/functions		\
			./src/utils			\

BONUS_DIR = ./bonus_checker	\
			./bonus_checker/check_init \
			./bonus_checker/functions_bonus \
			./bonus_checker/gnl	\
			./bonus_checker/util_bonus \

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

BONUS = ./bonus_checker/check_init/check_bonus.c	\
		./bonus_checker/check_init/init_bonus.c	\
		./bonus_checker/functions_bonus/push_bonus.c	\
		./bonus_checker/functions_bonus/reverse_rotate_bonus.c	\
		./bonus_checker/functions_bonus/rotate_bonus.c	\
		./bonus_checker/functions_bonus/swap_bonus.c	\
		./bonus_checker/gnl/get_next_line_utils_bonus.c	\
		./bonus_checker/gnl/get_next_line_bonus.c	\
		./bonus_checker/bonus_main.c	\
		./bonus_checker/checker.c	\
		./bonus_checker/util_bonus/ft_split_bonus.c 	\
		./bonus_checker/util_bonus/utils_bonus.c	\

OBJS = $(notdir $(SRCS:.c=.o))
vpath %.c $(SRCS_DIR)

BONUS_OBJS = $(notdir $(BONUS:.c=.o))
vpath %.c $(BONUS_DIR)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $^

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

bonus : $(BONUS_NAME)

$(BONUS_NAME) : $(BONUS_OBJS)
		$(CC) $(CFLAGS) -o $@ $^

clean :
	$(RFLAGS) -r $(OBJS) $(BONUS_OBJS)

fclean : clean
	$(RFLAGS) $(NAME) $(BONUS_NAME)

re : fclean all



