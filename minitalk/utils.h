/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 17:35:38 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/08/04 17:40:43 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <signal.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);

#endif
