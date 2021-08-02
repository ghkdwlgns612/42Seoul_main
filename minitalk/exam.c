#include "utils.h"

int main(void) {

    int count=0;

    /* SIGINT 시그널 받으면 무시하도록 설정 */
    signal(SIGINT, SIG_IGN);
    while (1) {
       printf("Hello World\n");
       sleep(1);
       if (++count == 5)   /* count가 5가 되면 */
          /* SIGINT 시그널 받으면 시스템에서 기본적으로 설정한 동작을 하도록 설정 */
        signal(SIGINT, SIG_DFL);
    }
}