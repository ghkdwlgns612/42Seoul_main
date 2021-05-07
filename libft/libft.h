/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 18:19:28 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/05/05 18:19:28 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>

int ft_atoi(const char *str);
void ft_bzero(void *ptr, size_t size);
void *ft_calloc(size_t count, size_t size);
int ft_isalnum(int c);
int ft_isalpha(int c);
int ft_isascii(int c);
int ft_isdigit(int c);
int ft_isprint(int c);
void *ft_memccpy(void *dest, const void *src, int val, size_t size);
void *ft_memcpy(void *dest, const void *src, size_t num);
void *ft_memmove(void *dest, const void *src, size_t num);
void *ft_memset(void *ptr, int value, size_t num);
char *ft_strchr(const char *str, int c);
char *ft_strdup(const char *str);
size_t ft_strlcat(char *dest, const char *src, size_t size);
size_t ft_strlcpy(char *dest, const char *src, size_t size);
int ft_strncmp(const char *str1, const char *str2, size_t num);
char *ft_strnstr(const char *big, const char *little, size_t len);
char *ft_strrchr(const char *s, int ch);
int ft_tolower(int c);
int ft_toupper(int c);
char *ft_substr(char const *s, unsigned int start, size_t len);

#endif