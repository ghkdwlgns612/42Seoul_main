#include "utils/utils.h"
#include <stdio.h>

void sig_handler() {
    printf("cntl + c 누르셨죠?\n");
}


int     main(void) {

	ft_putstr_fd("server pid:", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
    while(1) {
        printf("signal이 들어올 때까지 기다리겠습니다.\n");
        signal(SIGINT,sig_handler);
        pause();
        printf("시그널이 도착해서 종료\n");
    }
}