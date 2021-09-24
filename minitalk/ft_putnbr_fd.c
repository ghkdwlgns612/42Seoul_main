/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 17:34:59 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/08/04 17:35:13 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n < 0)
	{
		write(fd, "-", 1);
		if (n == -2147483648)
		{
			write(fd, "2147483648", 10);
			return ;
		}
		ft_putnbr_fd(-n, fd);
		return ;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + 48, fd);
}
