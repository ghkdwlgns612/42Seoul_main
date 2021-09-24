/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 21:46:02 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/09/12 21:47:16 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../bonus.h"

void	ft_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(0);
}

int	ft_minus(char c)
{
	if (c == '+' || c == '-')
	{
		if (c == '-')
			return (-1);
	}
	return (1);
}

void	ft_putendl_fd(char *s, int fd)
{
	size_t	len;

	if (s == 0 || fd < 0)
		return ;
	len = ft_strlen(s);
	write(fd, s, len);
	write(fd, "\n", 1);
}

long long	ft_atoi(const char *str)
{
	int			i;
	int			minus;
	long long	res;

	i = 0;
	minus = 1;
	res = 0;
	while (str[i] && (str[i] == ' ' || (str[i] <= 13 && str[i] >= 9)))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (minus * res);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}
