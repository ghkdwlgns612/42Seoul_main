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
        ft_length(inform,buf,ap);
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
    int len;
    va_start(ap,str);

    i = 0;
    res_len = 0;
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
        {
            write(1,&buf[i++],1);
        }
        free(res);
        free(my_inform);
        res_len += len;
    }
    free(buf);
    return (res_len);
}

int main()
{
    int num1;
    int num2;

    num1 = ft_printf("%20d  %010d %d\n",2147483647,12345,-123);
    num2 = printf("%20d  %010d %d\n",2147483647,12345,-123);
    printf("%d\n",num1);
    printf("%d\n",num2);
    num1 = ft_printf("%20d\n",2147483647);
    num2 = printf("%20d\n",2147483647);
    printf("%d\n",num1);
    printf("%d\n",num2);
    num1 = ft_printf("%-20d\n",2147483647);
    num2 = printf("%-20d\n",2147483647);
    printf("%d\n",num1);
    printf("%d\n",num2);
    num1 = ft_printf("%020d\n",2147483647);
    num2 =printf("%020d\n",2147483647);
    printf("%d\n",num1);
    printf("%d\n",num2);
    num1 = ft_printf("%0-20d\n",2147483647);
    num2 = printf("%0-20d\n",2147483647);
    printf("%d\n",num1);
    printf("%d\n",num2);
    num1 = ft_printf("%-020d\n",2147483647);
    num2 = printf("%-020d\n",2147483647);
    printf("%d\n",num1);
    printf("%d\n",num2);
    num1 = ft_printf("%20d\n",0);
    num2 = printf("%20d\n",0);
    printf("%d\n",num1);
    printf("%d\n",num2);
    num1 = ft_printf("%20d\n",0);
    num2 = printf("%20d\n",0);
    printf("%d\n",num1);
    printf("%d\n",num2);
    num1 = ft_printf("%-20d\n",0);
    num2 = printf("%-20d\n",0);
    printf("%d\n",num1);
    printf("%d\n",num2);
    num1 = ft_printf("%020d\n",0);
    num2 =printf("%020d\n",0);
    printf("%d\n",num1);
    printf("%d\n",num2);
    num1 = ft_printf("%0-20d\n",0);
    num2 = printf("%0-20d\n",0);
    printf("%d\n",num1);
    printf("%d\n",num2);
    num1 = ft_printf("%-020d\n",0);
    num2 = printf("%-020d\n",0);
    printf("%d\n",num1);
    printf("%d\n",num2);
    num1 = ft_printf("%20d\n",-123456);
    num2 = printf("%20d\n",-123456);
    printf("%d\n",num1);
    printf("%d\n",num2);
    num1 = ft_printf("%20d\n",-123456);
    num2 = printf("%20d\n",-123456);
    printf("%d\n",num1);
    printf("%d\n",num2);
    num1 = ft_printf("%-20d\n",-123456);
    num2 = printf("%-20d\n",-123456);
    printf("%d\n",num1);
    printf("%d\n",num2);
    num1 = ft_printf("%020d\n",-123456);
    num2 =printf("%020d\n",-123456);
    printf("%d\n",num1);
    printf("%d\n",num2);
    num1 = ft_printf("%0-20d\n",-123456);
    num2 = printf("%0-20d\n",-123456);
    printf("%d\n",num1);
    printf("%d\n",num2);
    num1 = ft_printf("%-020d\n",-123456);
    num2 = printf("%-020d\n",-123456);
    printf("%d\n",num1);
    printf("%d\n",num2);
    num1 = ft_printf("%.3d\n",123456);
    num2 = printf("%.3d\n",123456);
    printf("%d\n",num1);
    printf("%d\n",num2);
    num1 = ft_printf("%.9d\n",123456);
    num2 = printf("%.9d\n",123456);
    printf("%d\n",num1);
    printf("%d\n",num2);
    num1 = ft_printf("%.3d\n",0);
    num2 = printf("%.3d\n",0);
    printf("%d\n",num1);
    printf("%d\n",num2);
    num1 = ft_printf("%.9d\n",0);
    num2 = printf("%.9d\n",0);
    printf("%d\n",num1);
    printf("%d\n",num2);
    num1 = ft_printf("%.3d\n",-123456);
    num2 = printf("%.3d\n",-123456);
    printf("%d\n",num1);
    printf("%d\n",num2);
    num1 = ft_printf("%.9d\n",-123456);
    num2 = printf("%.9d\n",-123456);
    printf("%d\n",num1);
    printf("%d\n",num2);
    return 0;
}

