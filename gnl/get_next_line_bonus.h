/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 13:46:56 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/05/18 15:30:13 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stdlib.h>

char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlen(const char *str);
int			ft_newline(char *str);
int			get_next_line(int fd, char **line);
char		*ft_strdup(char *str);
int			ft_return(char **static_str, char **line);
int			ft_split_line(char **line, char **static_str, int flag);

#endif
