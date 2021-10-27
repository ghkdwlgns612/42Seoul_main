NAME = so_long

CC = gcc

CFLAG = -Wall -Werror -Wextrax

MLX_FLAGS =	-lmlx -framework OpenGL -framework AppKit -lm

SRCS =	main.c \
		get_next_line.c \
		check_input.c \
		check_norms.c \
		create_matrix.c \
		key_events.c \
		load_images.c \
		mlx_utils.c \
		put_images.c \
		win_lose.c \
		utils/ft_gnl_strchr.c \
		utils/ft_gnl_strjoin.c \
		utils/ft_gnl_strlen.c \
		utils/ft_itoa.c \
		utils/ft_putstr_fd.c \
		utils/ft_strjoin.c \
		utils/ft_strlen.c

OBJS = ${addprefix source/,$(SRCS:.c=.o)}

$.o : $.c
	${CC} ${CFLAG} -c  $< -o ${<:.c=.o}

${NAME} : ${OBJS}
	make -C mlx
	${CC} ${CFLAG} ${MLX_FLAGS} ${OBJS} -o ${NAME}

all : ${NAME}

clean :	
		make clean -C mlx
		@rm -rf ${OBJS}

fclean :	clean
			@rm -rf ${NAME}

re :	fclean all
