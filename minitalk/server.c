#include "utils/utils.h"
#include <stdio.h>

// void	sig_handler(int sig)
// {
// 	static unsigned char c = 0x00;
// 	static int cnt = 0;

//     if (sig == SIGUSR1)
//         c |= 0x01 << cnt;
//     else
//         c |= 0x00 << cnt;
//     cnt++;
//     if (cnt == 7)
//     {
//         ft_putchar_fd(c,1);
//         ft_putchar_fd('\n',1);
//         cnt = 0;
//         c = 0x00;
//     }
// }

// int	main(void)
// {
// 	ft_putstr_fd("Server PID [", 1);
// 	ft_putnbr_fd(getpid(), 1);
// 	ft_putstr_fd("]\n", 1);
//     signal(SIGUSR1,sig_handler);
//     signal(SIGUSR2,sig_handler);
// 	while (1)
// 		pause();
// 	return (0);
// }

void	sig_handler(int sig, siginfo_t *siginfo, void *unused)
{
	static unsigned char	c = 0x00;
	static int				cnt = 0;
	static pid_t			client_pid = 0;

	(void)unused;
	if (!client_pid)
		client_pid = siginfo->si_pid;
	c |= (sig == SIGUSR1);
	if (++cnt == 8)
	{
		cnt = 0;
		ft_putchar_fd(c, 1);
		c = 0x00;
		kill(client_pid, SIGUSR1);
	}
	else
	{
		c <<= 1;
		kill(client_pid, SIGUSR2);
	}
    write(1,"a",1);
}

int	main(void)
{
	struct sigaction	e;

	ft_putstr_fd("Server PID [", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("]\n", 1);
	e.sa_flags = SA_SIGINFO;
	e.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &e, 0);
	sigaction(SIGUSR2, &e, 0);
	while (1)
		pause();
	return (0);
}