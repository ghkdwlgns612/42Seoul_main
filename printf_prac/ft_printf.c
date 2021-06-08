#include "ft_printf.h"

int    ft_res_strlen(inform_list *inform, char *str)
{
    if (inform->flag == 2)
        return (inform->width + 1);
    else
        return (ft_strlen(str) + 1);
}

int    ft_int_print(inform_list *inform, char *str)
{
    int temp = inform->num;
    int len;

    if (inform->flag == 3)
    {
        len = ft_int_setting_printf(inform,str);
        ft_int_put_value(inform,temp,len,str);
    }
    else if (inform->flag == 2)
    {
        len = ft_int_setting_printf(inform,str) + 1;
        ft_int_put_value(inform,temp,len,str);
    }
    else if (inform->flag == 1)
    {
        len = ft_int_setting_printf(inform,str);
        ft_int_put_value(inform,temp,len,str);
    }
    len = ft_res_strlen(inform, str);
    ft_write(str);
    return(len);
}

void    ft_inform(inform_list *inform, char *buf ,va_list ap)
{
        ft_init(inform);
        ft_type(inform, buf);
        ft_width(inform, buf,ap);
        ft_length(inform, ap);
        ft_flag(inform, buf);
        ft_dot(inform, buf);
}

int     ft_printf(const char *str, ...)
{
    va_list ap;
    inform_list *my_inform;
    char *buf = ft_strdup(str);
    char *res;
    int res_len;
    int i;
    int result_cnt;
    int len;
    va_start(ap,str);

    i = 0;
    res_len = 0;
    result_cnt = 0;
    while (buf[i])
    {
        my_inform = (inform_list *)malloc(sizeof(inform_list));
        ft_inform(my_inform,&buf[i],ap);
        while (buf[i] != '%' && buf[i] != '\0')
            write(1,&buf[i++],1);
        i++;
        if (my_inform->type == 1)
        {
            if (my_inform->num < 0)
            {
                if (my_inform->width == 0)
                    res = (char *)malloc(sizeof(char) * (my_inform->length + 1));
                else
                    res = (char *)malloc(sizeof(char) * (my_inform->width + 1));
                len = ft_minus_int_print(my_inform, res);
            }
            else
            {
                if (my_inform->width == 0)
                    res = (char *)malloc(sizeof(char) * (my_inform->length + 1));
                else
                    res = (char *)malloc(sizeof(char) * (my_inform->width + 1));
                len = ft_int_print(my_inform, res);
            }
        }
        while (buf[i] != '\0' && buf[i] != 'd' && buf[i] != 'c' && buf[i] != 's')
            i++;
        i++;
        while (buf[i] != '\0' && buf[i] != '%')
            write(1,&buf[i++],1);
        free(res);
        free(my_inform);
        result_cnt++;
        res_len += len;
        printf("type :%d\n",my_inform->type); // 1은 int형, 2는 char형, 3은 char *형
        printf("len :%d\n",my_inform->length); // 문자 및 숫자의 길이
        printf("width :%d\n",my_inform->width); // 중간 인자에 대한 것
        printf("flag :%d\n",my_inform->flag); // 1은 0채우기, 2는 왼쪽정렬, 3은 아무 플래그없음.
        printf("num : %d\n",my_inform->num);
        printf("dot : %d\n",my_inform->dot);
        printf("dot_num : %d\n", my_inform->dot_num);
    }
    if (result_cnt > 1)
        res_len++;
    free(buf);
    return (res_len);
}

int     main()
{
    // ft_printf("-->|%-4.d|<--\n", -135); //-->|-135|<--
    // ft_printf("-->|%-4.*d|<--\n", -4, -135); //-->|-135|<--
    // ft_printf("-->|%-4.*d|<--\n", -3, -135); //-->|-135|<--
    // ft_printf("-->|%-4.*d|<--\n", -2, -135); //-->|-135|<--
    // ft_printf("-->|%-4.*d|<--\n", -1, -135); //-->|-135|<--
    // ft_printf("-->|%-4.*d|<--\n", 0, -135); //-->|-135|<--
    // ft_printf("-->|%-4.*d|<--\n", 1, -135); //-->|-135|<--
    // ft_printf("-->|%-4.*d|<--\n", 2, -135); //-->|-135|<--
    // ft_printf("-->|%-4.*d|<--\n", 3, -135); //-->|-135|<--
    ft_printf("-->|%-4.*d|<--\n", 4, -135);	 //->|-0135|<--
    // ft_printf("-->|%-4.0d|<--\n", -135); //-->|-135|<--
    // ft_printf("-->|%-4.1d|<--\n", -135); //-->|-135|<--
    // ft_printf("-->|%-4.2d|<--\n", -135); //-->|-135|<--
    // ft_printf("-->|%-4.3d|<--\n", -135); //-->|-135|<--
     ft_printf("-->|%-4.4d|<--\n", -135);	 //->|-0135|<--
    // ft_printf("-->|%-4d|<--\n", -135); //-->|-135|<--
    // ft_printf("-->|%-3.d|<--\n", -135); //-->|-135|<--
    // ft_printf("-->|%-3.*d|<--\n", -4, -135); //-->|-135|<--
    // ft_printf("-->|%-3.*d|<--\n", -3, -135); //-->|-135|<--
    // ft_printf("-->|%-3.*d|<--\n", -2, -135); //-->|-135|<--
    // ft_printf("-->|%-3.*d|<--\n", -1, -135); //-->|-135|<--
    // ft_printf("-->|%-3.*d|<--\n", 0, -135); //-->|-135|<--
    // ft_printf("-->|%-3.*d|<--\n", 1, -135); //-->|-135|<--
    // ft_printf("-->|%-3.*d|<--\n", 2, -135); //-->|-135|<--
    // ft_printf("-->|%-3.*d|<--\n", 3, -135); //-->|-135|<--
    ft_printf("-->|%-3.*d|<--\n", 4, -135);	 //->|-0135|<--
    return 0;
}