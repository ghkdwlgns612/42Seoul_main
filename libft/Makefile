# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihuhwan <jihuhwan@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/07 14:38:44 by jihuhwan          #+#    #+#              #
#    Updated: 2021/05/11 11:55:48 by jihuhwan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RFLAGS = rm -f

NAME = libft.a

SRCS = ft_atoi.c ft_isalpha.c ft_memccpy.c ft_memmove.c ft_strlcat.c ft_strnstr.c \
	   ft_bzero.c ft_isascii.c ft_memchr.c ft_memset.c ft_strlcpy.c ft_strrchr.c \
	   ft_isdigit.c ft_memcmp.c ft_strchr.c ft_strlen.c ft_tolower.c ft_substr.c\
	   ft_strjoin.c ft_isalnum.c ft_isprint.c ft_memcpy.c ft_strncmp.c ft_toupper.c\
	   ft_strdup.c ft_calloc.c ft_split.c ft_strtrim.c ft_itoa.c ft_strmapi.c\
	   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BON = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c\
		ft_lstadd_back.c ft_lstlast.c ft_lstdelone.c\
		ft_lstclear.c ft_lstiter.c ft_lstmap.c


OBJS = $(SRCS:.c=.o)
BON_OB = $(BON:.c=.o)

all : $(NAME)

%.o : %.c
			$(CC) $(CFLAGS)	-c $<

$(NAME) : $(OBJS)
		ar cr $(NAME) $(OBJS)

bonus : $(BON_OB)
		ar cr $(NAME) $(BON_OB)

clean :
		$(RFLAGS) $(OBJS) $(BON_OB)

fclean : clean
		$(RFLAGS) $(NAME)

re : fclean $(NAME)
