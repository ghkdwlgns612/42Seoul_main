/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 17:36:50 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/08/04 17:53:58 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	sig_handler(int sig, siginfo_t *siginfo, void *unused)
{
	static int	res;
	static int	cnt;

	(void)unused;
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
		if (kill(siginfo->si_pid, SIGUSR1) == -1)
			ft_putstr_fd("Server Signal Error\n", 1);
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_putstr_fd("PID = ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
