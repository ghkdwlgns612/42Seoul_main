# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihuhwan <jihuhwan@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/07 14:38:44 by jihuhwan          #+#    #+#              #
#    Updated: 2021/05/10 12:40:02 by jihuhwan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RFLAGS = rm -f

NAME = libft.a

SRCS = ft_lstclear_bonus.c	ft_memset.c		ft_strmapi.c\
		ft_atoi.c	ft_lstdelone_bonus.c	ft_putchar_fd.c		ft_strncmp.c\
		ft_bzero.c	ft_lstiter_bonus.c	ft_putendl_fd.c		ft_strnstr.c\
		ft_calloc.c	ft_lstlast_bonus.c	ft_putnbr_fd.c		ft_strrchr.c\
		ft_isalnum.c	ft_lstmap_bonus.c	ft_putstr_fd.c		ft_strtrim.c\
		ft_isalpha.c	ft_lstnew_bonus.c	ft_split.c		ft_substr.c\
		ft_isascii.c	ft_lstsize_bonus.c	ft_strchr.c		ft_tolower.c\
		ft_isdigit.c	ft_memccpy.c		ft_strdup.c		ft_toupper.c\
		ft_isprint.c	ft_memchr.c		ft_strjoin.c\
		ft_itoa.c	ft_memcmp.c	ft_strlcat.c\
		ft_lstadd_back_bonus.c	ft_memcpy.c	ft_strlcpy.c\
		ft_lstadd_front_bonus.c	ft_memmove.c	ft_strlen.c

OBJS = $(SRCS:.c=.o)

all = $(NAME)

%.o : %.c
			$(CC) $(CFLAGS)	-c $<

$(NAME) : $(OBJS)
		ar cr $(NAME) $(OBJS)

clean :
		$(RFLAGS) $(OBJS) $(BON_O)

fclean : clean
		$(RFLAGS) $(NAME)

re : fclean $(NAME)
