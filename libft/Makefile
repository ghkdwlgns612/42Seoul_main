# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihuhwan <jihuhwan@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/07 14:38:44 by jihuhwan          #+#    #+#              #
#    Updated: 2021/05/09 12:22:22 by jihuhwan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RFLAGS = rm -f

NAME = libft.a

SRCS = ft_isalpha.c	ft_memchr.c	ft_strchr.c	ft_strncmp.c\
		ft_atoi.c	ft_isascii.c	ft_memcmp.c	ft_strdup.c	ft_strnstr.c\
		ft_bzero.c	ft_isdigit.c	ft_memcpy.c	ft_strlcat.c	ft_strrchr.c\
		ft_calloc.c	ft_isprint.c	ft_memmove.c	ft_strlcpy.c	ft_tolower.c\
		ft_isalnum.c	ft_memccpy.c	ft_memset.c	ft_strlen.c	ft_toupper.c
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
