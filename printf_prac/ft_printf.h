#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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
    int dot;
    int dot_num;
    int cnt;
    int result_cnt;
}   inform_list;

void    ft_write(char *str);
int     ft_strlen(char *str);
char	*ft_strdup(const char *str);
char    *ft_forward(char *str);
int     ft_int_length(int num);
void    ft_init(inform_list *inform);
void    ft_type(inform_list *inform, char *buf);
void    ft_length(inform_list *inform, char *buf, va_list ap);
void    ft_flag(inform_list *inform, char *buf);
void    ft_width(inform_list *inform, char *buf, va_list ap);
int    ft_res_strlen(inform_list *inform, char *str);
int    ft_int_setting_printf(inform_list *inform, char *str);
void    ft_int_flag_arr(inform_list *inform, int temp, int len, char *str);
void    ft_int_put_value(inform_list *inform, int temp, int len, char *str);
int    ft_int_print(inform_list *inform, char *str);
int     ft_printf(const char *str, ...);
void    ft_int_zero(inform_list *inform, char *str);
int    ft_minus(inform_list *inform, char *res);
int    ft_minus_int_print(inform_list *inform, char *str);
int    ft_minus_int_setting_printf(inform_list *inform, char *str);
void    ft_minus_int_flag_arr(inform_list *inform, int temp, int len, char *str);
void    ft_dot(inform_list *inform, char *buf);
void    ft_inform(inform_list *inform, char *buf ,va_list ap);
void    ft_dot_flag(inform_list *inform);
void    ft_dot(inform_list *inform, char *buf);

#endif
