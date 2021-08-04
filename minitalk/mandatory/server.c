/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 17:36:14 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/08/04 17:45:03 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/utils.h"

void	ft_signal(int sig)
{
	static int	res;
	static int	cnt;

	if (cnt == 0)
		cnt = 128;
	if (sig == SIGUSR1)
		res += cnt;
	cnt /= 2;
	if (cnt == 0)
	{
		ft_putchar_fd((char)res, 1);
		cnt = 128;
		res = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr_fd("PID = ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, ft_signal);
	signal(SIGUSR2, ft_signal);
	while (1)
		pause();
	return (0);
}
