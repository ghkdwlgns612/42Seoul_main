#include "utils/utils.h"
#include <stdio.h>

void	sig_handler(int sig, siginfo_t *siginfo, void *unused)
{
	static int eight_bit = 0x00;
	static int cnt = 0;
	(void)unused;
	if (sig == SIGUSR1)
		eight_bit += 0x01 << (7 - cnt);
	cnt++;
	if (cnt == 8)
	{
		ft_putchar_fd(eight_bit, 1);
		cnt = 0;
		eight_bit = 0x00;
		kill(siginfo->si_pid,SIGUSR2);
	}
}

int	main(void)
{
	struct sigaction	action;

	ft_putstr_fd("Server PID [", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("]\n", 1);
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &action, 0);
	sigaction(SIGUSR2, &action, 0);
	while (1)
		pause();
	return (0);
}