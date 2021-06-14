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
    char alpha;
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
char	*ft_strdup(const char *str);
int		ft_atoi(const char *str);
int     ft_int_length(int num);
int     ft_strlen(const char *str,inform_list *inform);
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
void    ft_int_setting(inform_list *inform, va_list ap, char *buf);
int    ft_int_main(va_list ap, inform_list *inform, char *str);
int    ft_int_main(va_list ap, inform_list *inform, char *str);
void    ft_type(inform_list *inform, char *str);
int    ft_select(inform_list *inform, va_list ap, char *str);
int     ft_printf(const char *str, ...);
int    ft_char_main(va_list ap, inform_list *inform, char *buf);
int    ft_side_write(char *str,int i,inform_list *inform);
void    ft_char_input(char *res, inform_list *inform);
void    ft_char_setting(inform_list *inform, va_list ap, char *buf);
void    ft_write2(char *str, size_t size);
void    ft_percent_setting(inform_list *inform, va_list ap, char *buf);
void    ft_write1_percent(char *res, inform_list *inform);
void    ft_write_percent(char **res, inform_list *inform);
int     ft_percent_main(va_list ap,inform_list *inform, char *str);
void    ft_type_inner(inform_list *inform, char alpha);


#endif
