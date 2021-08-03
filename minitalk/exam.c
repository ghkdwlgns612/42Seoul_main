#include "utils.h"
#include <stdio.h>
#include <signal.h>

void hand(int sig) {
    printf("hellog");    
}

int main(void) {

    int count=0;
    signal(SIGINT,hand);

}