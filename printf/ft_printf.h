#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct inform {
    int type;
    int length;
    int flag;
    int width;
    int num;
    int cnt;
    int result_cnt;
}   inform_list;
