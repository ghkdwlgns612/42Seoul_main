#include "utils/utils.h"
#include <stdio.h>

void bit_converter(char eight_bit, int server_pid)
{
	int i = 0;
	while (i < 7)
	{
		if (eight_bit % 2 == 1)
			if(kill(server_pid,SIGUSR1) == -1)
			{
				ft_putstr_fd("ERROR SIGUSR1",1);
				exit(0);
			}
		else
			if(kill(server_pid,SIGUSR2) == -1)
			{
				ft_putstr_fd("ERROR SIGUSR2",1);
				exit(0);
			}
		i++;
		eight_bit /= 2;
	}
	sleep(1);
}


void send(char *str, int server_pid)
{
	int i = 0;

	while (str[i] != '\0')
	{
		bit_converter(str[i],server_pid);
		i++;
	}
}


void	signal_handler(int signum, siginfo_t *siginfo, void *unused)
{
	(void)unused;
	(void)siginfo;
	(void)signum;
	ft_putstr_fd("Signal received\n",1);
}

int	main(int argc, char **argv)
{
	struct sigaction	action;

	if (argc != 3 || !(100 <= ft_atoi(argv[1]) && ft_atoi(argv[1]) <= 99998))
	{
		ft_putstr_fd("Usage : ./client [99 < Server PID < 99999] [Message]", 1);
		return (1);
	}
	if (!ft_strlen(argv[2]))
		exit(0);
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &action, 0);
	sigaction(SIGUSR2, &action, 0);
	send(argv[2], ft_atoi(argv[1]));
	while (1)
		pause();
	return (0);
}