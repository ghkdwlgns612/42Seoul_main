/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 11:58:20 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/05/09 13:41:56 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr(int n, int fd)
{
	char	res;

	res = (n % 10) + '0';
	if ((n / 10) != 0)
		ft_putnbr(n / 10, fd);
	write(fd, &res, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n > 0)
		ft_putnbr(n, fd);
	else if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr(-n, fd);
	}
	else
		write(fd, "0", 1);
}
