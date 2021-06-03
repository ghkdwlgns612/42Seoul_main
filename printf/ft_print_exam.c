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

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}


char	*ft_strdup(const char *str)
{
	size_t	len;
	size_t	i;
	char	*ret;

	len = 0;
	while (str[len])
		len++;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char    *ft_forward(char *str)
{
    char *buf;
    
    buf = ft_strdup(str);
    while (*buf != '\0' && *buf != '%')
        buf++;
    return (buf);
}


int     ft_int_length(int num)
{
    int cnt = 0;
    while (num)
    {
        num /= 10;
        cnt++;
    }
    return (cnt);
}

void    ft_init(inform_list *inform)
{
    inform->type = 0;
    inform->length = 0;
    inform->flag = 0;
    inform->width = 0;
    inform->num = 0;
    inform->cnt = 0;
}

void    ft_type(inform_list *inform, char *buf)
{
    int i = 0;


    while (buf[i] && (buf[i] != 'c' || buf[i] != 's' || buf[i] != 'd'))
        i++;
    if (buf[i - 1] == 'd')
        inform->type = 1;
    else if (buf[i - 1] == 'c')
        inform->type = 2;
    else if (buf[i -1] == 's')
        inform->type = 3;
}

void    ft_length(inform_list *inform, char *buf, va_list ap)
{
    switch (inform->type)
    {
        case 1 :
            inform->num = va_arg(ap,int);
            if (inform->num < 0)
                inform->length = ft_int_length(-inform->num) + 1;
            else
                inform->length = ft_int_length(inform->num);
            break;
        // case 2 :
        //     inform->str = va_arg(ap,char *);
        //     inform->length = 1;
        //     break;
        // case 3 :
        //     inform->str = va_arg(ap,char *);
        //     inform->length = ft_strlen(inform->str);
        //     break;
        default:
            break;
    }
}

void    ft_flag(inform_list *inform, char *buf)
{
    int i = 0;
    while(buf[i] && buf[i] != '%')
        i++;
    i++;
    if (buf[i] == '0')
        inform->flag = 1; //0 채우기
    else if (buf[i] == '-' || (buf[i] == '-' && buf[i + 1] == '0') || (buf[i] == '0' && buf[i + 1] == '-'))
        inform->flag = 2; //- 채우기
    else
        inform->flag = 3; //아무 플래그 없음
}

void    ft_width(inform_list *inform, char *buf, va_list ap)
{
    int i = 0;
    while (buf[i])
    {
        if (buf[i] == '*')
        {
            inform->width = va_arg(ap,int);
            break ;
        }
        else if (buf[i] >= '1' && buf[i] <= '9')
        {
            while (buf[i] >= '0' && buf[i] <= '9')
            {
                inform->width *= 10;
                inform->width += buf[i++] - '0';
            }
            break ;
        }
        else
        {
        //    출력
        }
        i++;
    }
}

void    ft_int_print(inform_list *inform, char *str)
{
    int temp = inform->num;
    int len = inform->length;
    int i = -1;
    str[len--] = '\0';
    if (inform->flag == 3)
    {
        while (temp)
        {
            str[len--] = (temp % 10) + '0';
            temp /= 10;
        }
    }
    else if (inform->flag == 2)
    {
        while (i < len)
        {
            str[len--] = (temp % 10) + '0';
            temp /= 10;
            inform->cnt++;
            printf("%s\n",str);
        }
        inform->cnt++;
        while (inform->cnt < inform->width)
            str[inform->cnt++] = '0';
        str[inform->cnt++] = '\0';
    }
    while (*str)
        write(1,str++,1);
    write(1,"\n",1);
}

int     ft_printf(const char *str, ...)
{
    va_list ap;
    inform_list *my_inform;
    char *buf = ft_strdup(str);
    char *res;
    va_start(ap,str);
    
    printf("%s",buf);
    while (*buf)
    {
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
                ft_int_print(my_inform, res);
            }
            else
            {
                res = (char *)malloc(sizeof(char) * (my_inform->width + 1));
                ft_int_print(my_inform, res);
            }
            buf = ft_forward(buf);
        }
        buf++;
        free(res);
        break ;
    }
    // printf("%d\n",my_inform->type); // 1은 int형, 2는 char형, 3은 char *형
    // printf("%d\n",my_inform->length); // 문자 및 숫자의 길이
    // printf("%d\n",my_inform->width); // 중간 인자에 대한 것
    // printf("%d\n",my_inform->flag); // 1은 0채우기, 2는 왼쪽정렬, 3은 아무 플래그없음.
    // printf("%d\n",my_inform->num);

    return (1);
}

int main()
{
    ft_printf("%-6d",1234);
    return 0;
}
