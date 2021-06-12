#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct inform {
    int type; //1 정수 2 char 3문자열
    int precision;
    int width;
    int zero_flag;
    int minus_flag;
    int num;
    int num_len;
    int is_dot;
    int res_len;
}   inform_list;

void    ft_left_zero_value(char *res, inform_list *inform);
void    ft_right_zero_value(char *res, inform_list *inform);
void    ft_precision_zero_value(char *res, inform_list *inform);
void    ft_zero_printf(char **res, inform_list *inform);
void    ft_zero_value(char *res, inform_list *inform);
void    ft_zero_except_print(inform_list *inform, char *res);
void    ft_left_precision_value_apt(char *res, inform_list *inform, int r_len);
void    ft_left_precision_value(char *res, inform_list *inform, int r_len);
void    ft_right_precision_value_apt(char *res, inform_list *inform, int gap);
void    ft_right_precision_value(char *res, inform_list *inform, int r_len);
int     ft_num(va_list ap);
char	*ft_strdup(const char *str);
int		ft_atoi(const char *str);
int     ft_int_length(int num);
int     ft_strlen(const char *str);
void    ft_write(char *str);
void    ft_init(inform_list *inform);
int    ft_forward(char *str,int i);
int     ft_width(char *str, va_list ap, inform_list *inform);
int     ft_precision(char *str, va_list ap, inform_list *inform);
int     ft_flag(int i, char *str,inform_list *inform);
int     ft_star_width(va_list ap,inform_list *inform);
int     ft_star_precision(va_list ap, inform_list *inform);
void    ft_zero_minus(char **res,inform_list *inform);
void    ft_zero_value(char *res, inform_list *inform);
void    ft_ignore_zero(char **res,inform_list *inform);
void    ft_precision_value(char *res,inform_list *inform);
void    ft_num_value(char *res,inform_list *inform);

#endif
