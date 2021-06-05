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

    if (inform->flag == 3) //아무것도 없을 경우.
    {
        len = ft_int_setting_printf(inform,str);
        ft_int_put_value(inform,temp,len,str);
    }
    else if (inform->flag == 2) //왼쪽정렬
    {
        len = ft_int_setting_printf(inform,str) + 1;
        ft_int_put_value(inform,temp,len,str);
    }
    else if (inform->flag == 1) //0채우기
    {
        len = ft_int_setting_printf(inform,str);
        ft_int_put_value(inform,temp,len,str);
    }
    len = ft_res_strlen(inform, str);
    ft_write(str);
    return(len);
}

int     ft_printf(const char *str, ...)
{
    va_list ap;
    inform_list *my_inform;
    char *buf = ft_strdup(str);
    char *res;
    int len;
    va_start(ap,str);
    
    while (1)
    {
        my_inform = (inform_list *)malloc(sizeof(inform_list));
        ft_init(my_inform);
        ft_type(my_inform, buf);
        ft_width(my_inform, buf,ap);
        ft_length(my_inform,buf,ap);
        ft_flag(my_inform, buf);


        if (my_inform->type == 1)
        {
            if (my_inform->width == 0)
            {
                res = (char *)malloc(sizeof(char) * (my_inform->length + 1));
                len = ft_int_print(my_inform, res);
            }
            else
            {
                res = (char *)malloc(sizeof(char) * (my_inform->width + 1));
                len = ft_int_print(my_inform, res);
            }
            buf = ft_forward(buf);
        }
        // printf("type :%d\n",my_inform->type); // 1은 int형, 2는 char형, 3은 char *형
        // printf("len :%d\n",my_inform->length); // 문자 및 숫자의 길이
        // printf("width :%d\n",my_inform->width); // 중간 인자에 대한 것
        // printf("flag :%d\n",my_inform->flag); // 1은 0채우기, 2는 왼쪽정렬, 3은 아무 플래그없음.
        // printf("%d\n",my_inform->num);

        free(res);
        free(my_inform);
        break ;
    }
    return (len);
}

int main()
{
    int num1;
    int num2;
    num1 = ft_printf("%d\n",1234);
    num2 = printf("%d\n",1234);
    printf("%d\n",num1);
    printf("%d\n",num2);
    num1 = ft_printf("%6d\n",1234);
    num2 = printf("%6d\n",1234);
    printf("%d\n",num1);
    printf("%d\n",num2);
    num1 = ft_printf("%-6d\n",1234);
    num2 = printf("%-6d\n",1234);
    printf("%d\n",num1);
    printf("%d\n",num2);
    num1 = ft_printf("%06d\n",1234);
    num2 =printf("%06d\n",1234);
    printf("%d\n",num1);
    printf("%d\n",num2);
    num1 = ft_printf("%0-6d\n",1234);
    num2 = printf("%0-6d\n",1234);
    printf("%d\n",num1);
    printf("%d\n",num2);
    num1 = ft_printf("%-06d\n",1234);
    num2 = printf("%-06d\n",1234);
    printf("%d\n",num1);
    printf("%d\n",num2);
    return 0;
}