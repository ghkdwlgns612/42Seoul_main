/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:49:18 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/06/09 16:57:02 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct inform {
    int precision;
    int width;
    int zero_flag;
    int minus_flag;
    int num;
    int num_len;
}   inform_list;

void    ft_init(inform_list *inform)
{
    inform->precision = 0;
    inform->width = 0;
    inform->zero_flag = 0;
    inform->minus_flag = 0;
}

int     ft_star(va_list ap)
{
    int num;

    num = va_arg(ap,int);
    if (num < 0)
        return (0);
    else 
        return (num);
}

int				ft_minus(char c)
{
	if (c == '+' || c == '-')
	{
		if (c == '-')
			return (-1);
	}
	return (1);
}

int     ft_int_length(int num)
{
    int cnt;

    if (num < 0)
    {
        cnt = 1;
        num *= -1;
    }
    else
        cnt = 0;
    while (num)
    {
        num /= 10;
        cnt++;
    }
    return (cnt);
}

int				ft_atoi(const char *str)
{
	int			i;
	int			minus;
	long long	res;

	i = 0;
	minus = 1;
	res = 0;
	while (str[i] && (str[i] == ' ' || (str[i] <= 13 && str[i] >= 9)))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (minus * res);
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

int     ft_flag(int i, char *str,inform_list *inform)
{
    if ((str[i] == '0' && str[i + 1] == '-') || (str[i] == '0' && str[i + 1] == '-'))
    {
        inform->zero_flag = 1;
        inform->minus_flag = 1;
        return (i + 2);
    }
    else if (str[i] == '0')
    {
        inform->zero_flag = 1;
        return (i + 1);
    }
    else if (str[i] == '-')
    {
        inform->minus_flag = 1;
        return (i + 1);
    }
    else
    {
        return (i);
    }    
}

int     ft_chk_precision(char *str, va_list ap)
{
    int i;
    int num;
    
    num = 0;
    i = 0;
    while (str[i] != '\0' && str[i] != '%')
    {
        if (str[i] == '.')
        {
            i++;
            if (str[i] == '*')
            {
                num = ft_star(ap);
                break ;
            }
            else if (str[i] == '-' || (str[i] > '0' && str[i] < '9'))
            {
                num = ft_atoi(&str[i]);
                break ;
            }
            else
                num = 0;
        }
        i++;
    }
    return (num);
}

int     ft_width(char *str, va_list ap)
{
    int i;
    int num;

    i = 0;
    num = 0;
    while (str[i] != '\0' && str[i] != '%' && str[i] != '.')
    {
        if (str[i] == '*')
        {
            num = ft_star(ap);
            break ;
        }
        else if (str[i] == '-' || (str[i] > '0' && str[i] < '9'))
        {
            num = ft_atoi(&str[i]);
            break ;
        }
        else
            num = 0;
        i++;
    }
    return(num);
}

int     ft_num(char *str, va_list ap)
{
    return (va_arg(ap,int));
}

void    ft_minus_allocate(char **res,inform_list *inform){
    if ((inform->precision < inform->num_len) && (inform->width <= inform->num_len))
    {
        *res = (char *)malloc(sizeof(char) * (inform->num_len + 1));
    }
    else if ((inform->precision < inform->num_len) && (inform->width > inform->num_len))
    {
        *res = (char *)malloc(sizeof(char) * (inform->width + 1));
    }
    else
    {
        *res = (char *)malloc(sizeof(char) * (inform->precision + 1));
    }
}

void    ft_left_alloc(char *res,inform_list *inform, int r_len)
{
    int temp;
    int len;

    len = r_len;
    temp = inform->num;
    if (temp < 0)
    {}
    else
    {
        while (temp)
        {
            res[len--] = (temp % 10) + '0';
            temp /= 10;
        }
        len = inform->num_len;
        while (len < inform->width)
            res[len++] = ' ';
        res[len] = '\0';
    }
}

void    ft_zero_alloc(char *res,inform_list *inform, int r_len)
{
    int temp;
    int len;

    len = r_len;
    temp = inform->num;
    if (temp < 0)
    {}
    else
    {
        res[len--] = '\0';
        while (temp)
        {
            res[len--] = (temp % 10) + '0';
            temp /= 10;
        }
        while (len > -1)
            res[len--] = '0';
    }
}

void    ft_right_alloc(char *res,inform_list *inform, int r_len)
{
    int temp;
    int len;

    len = r_len;
    temp = inform->num;
    if (temp < 0)
    {}
    else
    {
        res[len--] = '\0';
        while (temp)
        {
            res[len--] = (temp % 10) + '0';
            temp /= 10;
        }
        while (len > -1)
            res[len--] = ' ';
    }
}

char    *ft_width_plus_value(char *res,inform_list *inform)
{
    if (inform->minus_flag == 1 && inform->zero_flag == 1)
        ft_left_alloc(res, inform, inform->num - 1);//왼쪽정렬
    else if(inform->minus_flag == 1)
        ft_left_alloc(res, inform, inform->num - 1);//왼쪽정렬
    else if (inform->zero_flag == 1)
        ft_zero_alloc(res, inform, inform->width);//0채우기
    else
        ft_right_alloc(res, inform, inform->width);//오른쪽정렬
    return (res);
}

char    *ft_precision_plus_value(char *res,inform_list *inform)
{
    if (inform->minus_flag == 1 && inform->zero_flag == 1)
        ft_left_alloc(res, inform, inform->num - 1);//왼쪽정렬
    else if(inform->minus_flag == 1)
        ft_left_alloc(res, inform, inform->num - 1);//왼쪽정렬
    else if (inform->zero_flag == 1)
        ft_zero_alloc(res, inform, inform->precision);//0채우기
    else
        ft_right_alloc(res, inform, inform->precision);//오른쪽정렬
    return (res);
}

void    ft_plus_allocate(char **res,inform_list *inform){
    if ((inform->precision < inform->num_len) && (inform->width <= inform->num_len))
    {
        *res = (char *)malloc(sizeof(char) * (inform->num_len + 1));
    }
    else if ((inform->precision <= inform->num_len) && (inform->width > inform->num_len))
    {
        *res = (char *)malloc(sizeof(char) * (inform->width + 1));
        *res = ft_width_plus_value(*res, inform);
    }
    else
    {
        *res = (char *)malloc(sizeof(char) * (inform->precision + 1));
        inform->zero_flag = 1;
        inform->minus_flag = 0;
        *res = ft_precision_plus_value(*res, inform);
    }
}

int     ft_printf(const char *str, ...)
{
    va_list ap;
    inform_list *inform;
    char *buf;
    char *res;
    int i;
    int res_len;
    
    buf = ft_strdup(str);
    va_start(ap,str);
    i = 0;
    while (buf[i])
    {
        inform = (inform_list *)(malloc)(sizeof(inform_list));
        ft_init(inform);
        while (buf[i] != '%' && buf[i] != '\0')
            write(1,&buf[i++],1);
        i++;
        i = ft_flag(i, buf, inform);
        inform->width = ft_width(&buf[i], ap);
        inform->precision = ft_chk_precision(&buf[i], ap);
        inform->num = ft_num(&buf[i], ap);
        inform->num_len = ft_int_length(inform->num);
        if (inform->num < 0)
            ft_minus_allocate(&res,inform);
        else
            ft_plus_allocate(&res,inform);
        // printf("width : %d\n",inform->width);
        // printf("precis : %d\n",inform->precision);
        // printf("num : %d\n",inform->num);
        // printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
        printf("%s<\n",res);

        free(inform);
        free(res);
        break ;
    }
    free(buf);
    return (1);
}

int main()
{
    // ft_printf("%-*.d",15,-1234);
    // ft_printf("%-*.*d",10,15,-1234);
    // ft_printf("%-*.0d",15,-1234);
    // ft_printf("%-*.1d",15,-1234);
    // ft_printf("%-*.2d",15,-1234);
    // ft_printf("%-*.3d",15,-1234);
    // ft_printf("%-*.4d",15,-1234);
    // ft_printf("%-*d",15,-1234);
    // printf(">%3d<\n",1234); //width만
    // printf(">%4d<\n",1234); //width만
    // printf(">%-5d<\n",1234); //width만
    // printf(">%.3d<\n",1234); //precision만
    // printf(">%.4d<\n",1234); //precision만
    // printf(">%.5d<\n",1234); //precision만
    // printf(">%3.3d<\n",1234); //width,precision < length
    // printf(">%4.4d<\n",1234); //width,precision < length
    // printf(">%5.5d<\n",1234); //width,precision < length
    printf(">%5.3d<\n",1234); // prcision < length, width > length
    printf(">%5.4d<\n",1234); // prcision < length, width > length
    printf(">%5.5d<\n",1234); // prcision < length, width > length
    ft_printf(">%5.3d<\n",1234); // prcision < length, width > length
    ft_printf(">%5.4d<\n",1234); // prcision < length, width > length
    ft_printf(">%5.5d<\n",1234); // prcision < length, width > length

    return (0);
}