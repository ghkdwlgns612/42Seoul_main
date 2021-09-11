NAME = push_swap

CC = gcc;

CFLAGS = -Wall -Wextra -Werror
# CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

RFLAGS = rm -f

OBJS_DIR = ./obj

SRCS_DIR = ./src	\
			./src/algoritm	\
			./src/check_init	\
			./src/functions		\
			./src/utils			\

# SRCS =	./src/push_swap.c	\
# 		./src/utils/ft_split.c	\
# 		./src/utils/util1.c	\
# 		./src/check_init/init.c	\
# 		./src/check_init/check_duplicate.c	\
# 		./src/functions/push.c	\
# 		./src/functions/reverse_rotate.c	\
# 		./src/functions/rotate.c	\
# 		./src/functions/swap.c	\
# 		./src/algoritm/a_to_b.c	\
# 		./src/algoritm/b_to_a.c	\
# 		./src/algoritm/algoritm.c	\
# 		./src/algoritm/five.c	\
# 		./src/algoritm/one_two_three.c	\
# 		./src/algoritm/three_a.c	\
# 		./src/algoritm/three_b.c	\

SRCS = main.c

OBJS = $(SRCS:.c=.o)
# vpath %.c $(SRCS_DIR)
# OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJS_DIR) :
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean : 
	$(RFLAGS) $(OBJS)






