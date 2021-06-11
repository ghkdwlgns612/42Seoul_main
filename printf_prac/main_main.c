/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student2seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:49:18 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/06/09 21:17:53 by jihuhwan         ###   ########.fr       */
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
    int is_dot;
}   inform_list;

void    ft_init(inform_list *inform)
{
    inform->precision = 0;
    inform->width = 0;
    inform->zero_flag = 0;
    inform->minus_flag = 0;
    inform->is_dot = 0;
}

int     ft_star_precision(va_list ap)
{
    int num;

    num = va_arg(ap,int);
    if (num < 0)
        return (0);
    else 
        return (num);
}

int     ft_star_width(va_list ap,inform_list *inform)
{
    int num;

    num = va_arg(ap,int);
    if (num < 0)
    {
        inform->minus_flag = 1;
        return (-num);
    }
    else 
        return (num);
}

int				ft_minus(char c)
{
	if (c == '+' || c == '-')
	{
		if (c == '-')
			return (0);
	}
	return (1);
}

int     ft_int_length(int num)
{
    int cnt;

    cnt = 0;
    while (num)
    {
        num /= 10;
        cnt++;
    }
    return (cnt);
}

int     ft_strlen(const char *str)
{
	int     i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

void    ft_write(char *str)
{
    int i;

    i = 0;
    while (str[i])
        write(1,&str[i++],1);
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

int     ft_precision(char *str, va_list ap, inform_list *inform)
{
    int i;
    int num;
    
    num = 0;
    i = 0;
    while (str[i] != '\0' && str[i] != '%')
    {
        if (str[i] == '.')
        {
            inform->is_dot = 1;
            i++;
            if (str[i] == '*')
            {
                num = ft_star_precision(ap);
                break ;
            }
            else if (str[i] == '-' || (str[i] > '0' && str[i] < '9'))
            {
                num = ft_atoi(&str[i]);
                break ;
            }
            else
                num = -1;
        }
        i++;
    }
    return (num);
}

int     ft_width(char *str, va_list ap, inform_list *inform)
{
    int i;
    int num;

    i = 0;
    num = 0;
    while (str[i] != '\0' && str[i] != '%' && str[i] != '.')
    {
        if (str[i] == '*')
        {
            num = ft_star_width(ap,inform);
            break ;
        }
        else if (str[i] == '-' || (str[i] > '0' && str[i] < '9'))
        {
            num = ft_atoi(&str[i]);
            break ;
        }
        else
            num = -1;
        i++;
    }
    return(num);
}

int     ft_num(va_list ap)
{
    return (va_arg(ap,int));
}

void    ft_num_value(char *res,inform_list *inform)
{
    int temp;
    int len;
  
    temp = inform->num;
    len = inform->num_len;
    if (temp < 0)
    {
        temp *= -1;
        len++;
    }
    res[len--] = '\0';
    while (temp)
    {
        res[len--] = (temp % 10) + '0';
        temp /= 10;
    }
    if (len == 0 && inform->num < 0)
        res[0] = '-';
}

void    ft_left_precision_value_apt(char *res, inform_list *inform, int r_len)
{
    int temp;
    int len;

    len = r_len - 1;
    temp = inform->num;
    if (temp < 0)
        temp *= -1;
    while (temp)
    {
        res[len--] = (temp % 10) + '0';
        temp /= 10;
    }
    while (len > -1)
    {
        if (len == 0 && inform->num < 0)
            res[len--] = '-';
        else
            res[len--] = '0';
    }
    len = r_len;
    while (len < inform->width)
        res[len++] = ' ';
    res[len] = '\0';
}

void    ft_left_precision_value(char *res, inform_list *inform, int r_len)
{
    int temp;
    int len;
    int gap;

    gap = inform->precision - inform->num_len;
    len = r_len;
    temp = inform->num;
    if (temp < 0)
        temp *= -1;
    if (inform->precision > inform->num_len) //오른쪽 정렬인데 pre존재. 양음 확인필요.
        ft_left_precision_value_apt(res, inform, len + gap); //len + gap부터 숫자 넣기. >001234    <
    else //오른쪽 정렬인데 pre 존재 x. 양음 확인.
    {
        len--;
        while (temp)
        {
            res[len--] = (temp % 10) + '0';
            temp /= 10;
        }
        if (inform->num < 0)
            res[len--] = '-';
        len = r_len;
        if (inform->num < 0)
            while (len < inform->width)
                res[len++] = ' ';
        else
            while (len < inform->width)
                res[len++] = ' ';   
        res[len] = '\0';        
    }
}

void    ft_right_precision_value_apt(char *res, inform_list *inform, int gap)
{
    int temp;
    int len;
    int zero;

    zero = gap;
    len = inform->width - 1;
    temp = inform->num;
    if (temp < 0)
        temp *= -1;
    while (temp)
    {
        res[len--] = (temp % 10) + '0';
        temp /= 10;
    }
    while (zero--)
        res[len--] = '0';
    if (inform->num < 0)
        res[len--] = '-';
    while (len > -1)
        res[len--] = ' ';   
}

void    ft_right_precision_value(char *res, inform_list *inform, int r_len)
{
    int temp;
    int len;
    int gap;

    gap = inform->precision - inform->num_len;
    len = r_len;
    temp = inform->num;
    if (temp < 0)
        temp *= -1;
    res[len--] = '\0';
    if (inform->precision > inform->num_len) //오른쪽 정렬인데 pre존재. 양음 확인필요.
        ft_right_precision_value_apt(res, inform, gap);//inform->width에서 시작해서 gap만큼 '0'넣고 ' '넣기.
    else //오른쪽 정렬인데 pre 존재 x. 양음 확인.
    {
        while (temp)
        {
            res[len--] = (temp % 10) + '0';
            temp /= 10;
        }
        if (inform->num < 0)
            res[len--] = '-';
        while (len > -1)
            res[len--] = ' ';        
    }
}

void    ft_precision_value(char *res,inform_list *inform)
{
    int temp;
    int gap;
    int len;

    gap = inform->precision - inform->num_len; 
    if (inform->num < 0)
    {
        temp = inform->num * (-1);
        len = inform->precision + 1;
        res[0] = '-';
    }
    else
    {
        temp = inform->num;
        len = inform->precision;
    }
    res[len--] = '\0';
    while (temp)
    {
        res[len--] = (temp % 10) + '0';
        temp /= 10;        
    }
    while (gap--)
        res[len--] = '0';
}

void    ft_ignore_zero(char **res,inform_list *inform)
{
    if ((inform->width > inform->precision && inform->precision > inform->num_len) || (inform->width > inform->precision && inform->width > inform->num_len)) //width할당, -플래그 확인, pre적용 후, 양음확인 or width할당, -플래그 확인, pre미적용, 양음확인
    {
        *res = (char *)malloc(inform->width + 1);
        if (inform->minus_flag == 1)
        {
            if (inform->num < 0)
                ft_left_precision_value(*res, inform, inform->num_len + 1);
            else
                ft_left_precision_value(*res, inform, inform->num_len);    
        }
        else
            ft_right_precision_value(*res, inform, inform->width);
    }
    else if (inform->precision > inform->num_len && inform->precision >= inform->width) //pre할당 후 양음 확인 바로 값넣기.
    {
        if (inform->num < 0)
            *res = (char *)malloc(inform->precision + 2);
        else
            *res = (char *)malloc(inform->precision + 1);   
        ft_precision_value(*res, inform);    
    }
    else //num_len 할당 후 양음 확인 후 바로 값 넣기.
    {
        if (inform->num >= 0)
            *res = (char *)malloc(inform->num_len + 1);
        else
            *res = (char *)malloc(inform->num_len + 2);
        ft_num_value(*res, inform);
    }
}

void    ft_zero_value(char *res, inform_list *inform)
{
    int len;
    int temp;

    temp = inform->num;
    len = inform->width;
    if (inform->num < 0)
        temp *= -1;
    res[len--] = '\0';
    while (temp)
    {
        res[len--] = (temp % 10) + '0';
        temp /= 10;        
    }
    while (len)
        res[len--] = '0';
    if (inform->num < 0)
        res[len] = '-';
    else
        res[len] = '0';
}

void    ft_zero_minus(char **res,inform_list *inform)
{
    if (inform->width > inform->num_len)
    {
        *res = (char *)malloc(inform->width + 1);
        if (inform->minus_flag == 1)
        {
            if (inform->num < 0)
                ft_left_precision_value(*res, inform, inform->num_len + 1);
            else
                ft_left_precision_value(*res, inform, inform->num_len); 
        }
        else if (inform->zero_flag == 1)
            ft_zero_value(*res,inform);
        else
            ft_right_precision_value(*res, inform, inform->width);
    }
    else
    {
        if (inform->num >= 0)
            *res = (char *)malloc(inform->num_len + 1);
        else
            *res = (char *)malloc(inform->num_len + 2);
        ft_num_value(*res, inform);
    }
}

// void    ft_zero_printf(char **res, inform_list *inform)
// {
    
// }

int    ft_forward(char *str,int i)
{
    while (str[i] != 'd')
        i++;
    i++;
    return (i);
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
    res_len = 0;
    while (buf[i])
    {
        inform = (inform_list *)(malloc)(sizeof(inform_list));
        ft_init(inform);
        while (buf[i] != '%' && buf[i] != '\0')
            write(1,&buf[i++],1);
        i++;
        i = ft_flag(i, buf, inform);
        inform->width = ft_width(&buf[i], ap, inform);
        inform->precision = ft_precision(&buf[i], ap, inform);
        inform->num = ft_num(ap);
        inform->num_len = ft_int_length(inform->num);
        // printf("width : %d\n", inform->width);
        // printf("preci : %d\n", inform->precision);
        // printf("num : %d\n", inform->num);
        // printf("length : %d\n", inform->num_len);
        // printf("dot : %d\n", inform->is_dot);
        // printf("zero : %d\n", inform->zero_flag);
        // printf("minus : %d\n", inform->minus_flag);
        if (inform->width < 0)
            inform->width *= -1;
        // if (inform->num == 0)
        //     ft_zero_printf(res,inform);
        if (inform->is_dot == 1)
            ft_ignore_zero(&res,inform);
        else
            ft_zero_minus(&res,inform);
        res_len += ft_strlen(res);
        ft_write(res);
        i = ft_forward(buf, i);
        free(inform);
        free(res);
        while (buf[i] != '%' && buf[i] != '\0')
            write(1,&buf[i++],1);
    } 
    free(buf);
    return (res_len);
}

// int main()
// {
    //  printf(">%-4.d<\n",135);
    // ft_printf(">%-4.d<\n",135);
    // printf(">%-4.*d<\n",6,135);
    // ft_printf(">%-4.*d<\n",6,135);
    // printf(">%-4.1d<\n",135);
    // ft_printf(">%-4.1d<\n",135);
    // printf(">%-4.2d<\n",135);
    // ft_printf(">%-4.2d<\n",135);
    // printf(">%-4.3d<\n",135);
    // ft_printf(">%-4.3d<\n",135);
    // printf(">%-4.4d<\n",135);
    // ft_printf(">%-4.4d<\n",135);
    // printf(">%-4d<\n",135);
    // ft_printf(">%-4d<\n",135);
    // printf(">%-3.d<\n",135);
    // ft_printf(">%-3.d<\n",135);
    // printf(">%-3.*d<\n",6,135);
    // ft_printf(">%-3.*d<\n",6,135);
    // printf(">%-3.1d<\n",135);
    // ft_printf(">%-3.1d<\n",135);
    // printf(">%-3.2d<\n",135);
    // ft_printf(">%-3.2d<\n",135);
    // printf(">%-3.3d<\n",135);
    // ft_printf(">%-3.3d<\n",135);
    // printf(">%-3.4d<\n",135);
    // ft_printf(">%-3.4d<\n",135);
    // printf(">%-3d<\n",135);
    // ft_printf(">%-3d<\n",135);
    // printf(">%-2.d<\n",135);
    // ft_printf(">%-2.d<\n",135);
    // printf(">%-2.*d<\n",6,135);
    // ft_printf(">%-2.*d<\n",6,135);
    // printf(">%-2.1d<\n",135);
    // ft_printf(">%-2.1d<\n",135);
    // printf(">%-2.2d<\n",135);
    // ft_printf(">%-2.2d<\n",135);
    // printf(">%-2.3d<\n",135);
    // ft_printf(">%-2.3d<\n",135);
    // printf(">%-2.4d<\n",135);
    // ft_printf(">%-2.4d<\n",135);
    // printf(">%-2d<\n",135);
    // ft_printf(">%-2d<\n",135);
    // printf(">%-1.d<\n",135);
    // ft_printf(">%-1.d<\n",135);
    // printf(">%-1.*d<\n",6,135);
    // ft_printf(">%-1.*d<\n",6,135);
    // printf(">%-1.1d<\n",135);
    // ft_printf(">%-1.1d<\n",135);
    // printf(">%-1.2d<\n",135);
    // ft_printf(">%-1.2d<\n",135);
    // printf(">%-1.3d<\n",135);
    // ft_printf(">%-1.3d<\n",135);
    // printf(">%-1.4d<\n",135);
    // ft_printf(">%-1.4d<\n",135);
    // printf(">%-1d<\n",135);
    // ft_printf(">%-1d<\n",135);
    // printf(">%.d<\n",135);
    // ft_printf(">%.d<\n",135);
    // printf(">%.*d<\n",6,135);
    // ft_printf(">%.*d<\n",6,135);
    // printf(">%.1d<\n",135);
    // ft_printf(">%.1d<\n",135);
    // printf(">%.2d<\n",135);
    // ft_printf(">%.2d<\n",135);
    // printf(">%.3d<\n",135);
    // ft_printf(">%.3d<\n",135);
    // printf(">%.4d<\n",135);
    // ft_printf(">%.4d<\n",135);
    // printf(">%.0d<\n",135);
    // ft_printf(">%.0d<\n",135);
    // printf(">%*.d<\n", 10,135);
    // ft_printf(">%*.d<\n", 10,135);
    // printf(">%*.*d<\n",6, 10,135);
    // ft_printf(">%*.*d<\n",6, 10,135);
    // printf(">%*.1d<\n", 10,135);
    // ft_printf(">%*.1d<\n", 10,135);
    // printf(">%*.2d<\n", 10,135);
    // ft_printf(">%*.2d<\n", 10,135);
    // printf(">%*.3d<\n", 10,135);
    // ft_printf(">%*.3d<\n", 10,135);
    // printf(">%*.4d<\n", 10,135);
    // ft_printf(">%*.4d<\n", 10,135);
    // printf(">%*.0d<\n", 10,135);
    // ft_printf(">%*.0d<\n", 10,135);
    // printf(">%0.d<\n", 135);
    // ft_printf(">%0.d<\n", 135);
    // printf(">%0.*d<\n",6, 135);
    // ft_printf(">%0.*d<\n",6, 135);
    // printf(">%0.1d<\n", 135);
    // ft_printf(">%0.1d<\n", 135);
    // printf(">%0.2d<\n", 135);
    // ft_printf(">%0.2d<\n", 135);
    // printf(">%0.3d<\n", 135);
    // ft_printf(">%0.3d<\n", 135);
    // printf(">%0.4d<\n", 135);
    // ft_printf(">%0.4d<\n", 135);
    // printf(">%0.0d<\n", 135);
    // ft_printf(">%0.0d<\n", 135);
    // printf(">%1.d<\n", 135);
    // ft_printf(">%1.d<\n", 135);
    // printf(">%1.*d<\n",6, 135);
    // ft_printf(">%1.*d<\n",6, 135);
    // printf(">%1.1d<\n", 135);
    // ft_printf(">%1.1d<\n", 135);
    // printf(">%1.2d<\n", 135);
    // ft_printf(">%1.2d<\n", 135);
    // printf(">%1.3d<\n", 135);
    // ft_printf(">%1.3d<\n", 135);
    // printf(">%1.4d<\n", 135);
    // ft_printf(">%1.4d<\n", 135);
    // printf(">%1.0d<\n", 135);
    // ft_printf(">%1.0d<\n", 135);
    // printf(">%2.d<\n", 135);
    // ft_printf(">%2.d<\n", 135);
    // printf(">%2.*d<\n",6, 135);
    // ft_printf(">%2.*d<\n",6, 135);
    // printf(">%2.1d<\n", 135);
    // ft_printf(">%2.1d<\n", 135);
    // printf(">%2.2d<\n", 135);
    // ft_printf(">%2.2d<\n", 135);
    // printf(">%2.3d<\n", 135);
    // ft_printf(">%2.3d<\n", 135);
    // printf(">%2.4d<\n", 135);
    // ft_printf(">%2.4d<\n", 135);
    // printf(">%2.2d<\n", 135);
    // ft_printf(">%2.2d<\n", 135);
    // printf(">%3.d<\n", 135);
    // ft_printf(">%3.d<\n", 135);
    // printf(">%3.*d<\n",6, 135);
    // ft_printf(">%3.*d<\n",6, 135);
    // printf(">%3.1d<\n", 135);
    // ft_printf(">%3.1d<\n", 135);
    // printf(">%3.2d<\n", 135);
    // ft_printf(">%3.2d<\n", 135);
    // printf(">%3.3d<\n", 135);
    // ft_printf(">%3.3d<\n", 135);
    // printf(">%3.4d<\n", 135);
    // ft_printf(">%3.4d<\n", 135);
    // printf(">%3.2d<\n", 135);
    // ft_printf(">%3.2d<\n", 135);
	// printf(">%4.d<\n", 135);
    // ft_printf(">%4.d<\n", 135);
    // printf(">%4.*d<\n",6, 135);
    // ft_printf(">%4.*d<\n",6, 135);
    // printf(">%4.1d<\n", 135);
    // ft_printf(">%4.1d<\n", 135);
    // printf(">%4.2d<\n", 135);
    // ft_printf(">%4.2d<\n", 135);
    // printf(">%4.3d<\n", 135);
    // ft_printf(">%4.3d<\n", 135);
    // printf(">%4.4d<\n", 135);
    // ft_printf(">%4.4d<\n", 135);
    // printf(">%4.0d<\n", 135);
    // ft_printf(">%4.0d<\n", 135);
    // printf(">%0*.d<\n",10,135);
    // ft_printf(">%0*.d<\n",10,135);
	// printf(">%0*.*d<\n",10,6,135);
    // ft_printf(">%0*.*d<\n",10,6,135);
	// printf(">%0*.0d<\n",10,135);
    // ft_printf(">%0*.0d<\n",10,135);
	// printf(">%0*.1d<\n",10,135);
    // ft_printf(">%0*.1d<\n",10,135);
	// printf(">%0*.2d<\n",10,135);
    // ft_printf(">%0*.2d<\n",10,135);
	// printf(">%0*.3d<\n",10,135);
    // ft_printf(">%0*.3d<\n",10,135);
	// printf(">%0*.4d<\n",10,135);
    // ft_printf(">%0*.4d<\n",10,135);
	// printf(">%0*d<\n",10,135);
    // ft_printf(">%0*d<\n",10,135);
    // printf(">%00.d<\n",135);
    // ft_printf(">%00.d<\n",135);
	// printf(">%00.*d<\n",6,135);
    // ft_printf(">%00.*d<\n",6,135);
	// printf(">%00.0d<\n",135);
    // ft_printf(">%00.0d<\n",135);
	// printf(">%00.1d<\n",135);
    // ft_printf(">%00.1d<\n",135);
	// printf(">%00.2d<\n",135);
    // ft_printf(">%00.2d<\n",135);
	// printf(">%00.3d<\n",135);
    // ft_printf(">%00.3d<\n",135);
	// printf(">%00.4d<\n",135);
    // ft_printf(">%00.4d<\n",135);
	// printf(">%00d<\n",135);
    // ft_printf(">%00d<\n",135);
    // printf(">%01.d<\n",135);
    // ft_printf(">%01.d<\n",135);
	// printf(">%01.*d<\n",6,135);
    // ft_printf(">%01.*d<\n",6,135);
	// printf(">%01.0d<\n",135);
    // ft_printf(">%01.0d<\n",135);
	// printf(">%01.1d<\n",135);
    // ft_printf(">%01.1d<\n",135);
	// printf(">%01.2d<\n",135);
    // ft_printf(">%01.2d<\n",135);
	// printf(">%01.3d<\n",135);
    // ft_printf(">%01.3d<\n",135);
	// printf(">%01.4d<\n",135);
    // ft_printf(">%01.4d<\n",135);
	// printf(">%01d<\n",135);
    // ft_printf(">%01d<\n",135);
    // printf(">%02.d<\n",135);
    // ft_printf(">%02.d<\n",135);
	// printf(">%02.*d<\n",6,135);
    // ft_printf(">%02.*d<\n",6,135);
	// printf(">%02.0d<\n",135);
    // ft_printf(">%02.0d<\n",135);
	// printf(">%02.1d<\n",135);
    // ft_printf(">%02.1d<\n",135);
	// printf(">%02.2d<\n",135);
    // ft_printf(">%02.2d<\n",135);
	// printf(">%02.3d<\n",135);
    // ft_printf(">%02.3d<\n",135);
	// printf(">%02.4d<\n",135);
    // ft_printf(">%02.4d<\n",135);
	// printf(">%02d<\n",135);
    // ft_printf(">%02d<\n",135);
    // printf(">%03.d<\n",135);
    // ft_printf(">%03.d<\n",135);
	// printf(">%03.*d<\n",6,135);
    // ft_printf(">%03.*d<\n",6,135);
	// printf(">%03.0d<\n",135);
    // ft_printf(">%03.0d<\n",135);
	// printf(">%03.1d<\n",135);
    // ft_printf(">%03.1d<\n",135);
	// printf(">%03.2d<\n",135);
    // ft_printf(">%03.2d<\n",135);
	// printf(">%03.3d<\n",135);
    // ft_printf(">%03.3d<\n",135);
	// printf(">%03.4d<\n",135);
    // ft_printf(">%03.4d<\n",135);
	// printf(">%03d<\n",135);
    // ft_printf(">%03d<\n",135);
    // printf(">%04.d<\n",135);
    // ft_printf(">%04.d<\n",135);
	// printf(">%04.*d<\n",6,135);
    // ft_printf(">%04.*d<\n",6,135);
	// printf(">%04.0d<\n",135);
    // ft_printf(">%04.0d<\n",135);
	// printf(">%04.1d<\n",135);
    // ft_printf(">%04.1d<\n",135);
	// printf(">%04.2d<\n",135);
    // ft_printf(">%04.2d<\n",135);
	// printf(">%04.3d<\n",135);
    // ft_printf(">%04.3d<\n",135);
	// printf(">%04.4d<\n",135);
    // ft_printf(">%04.4d<\n",135);
	// printf(">%04d<\n",135);
    // ft_printf(">%04d<\n",135);
    // printf(">%--4.d<\n",135);
    // ft_printf(">%--4.d<\n",135);
	// printf(">%--4.*d<\n",6,135);
    // ft_printf(">%--4.*d<\n",6,135);
	// printf(">%--4.0d<\n",135);
    // ft_printf(">%--4.0d<\n",135);
	// printf(">%--4.1d<\n",135);
    // ft_printf(">%--4.1d<\n",135);
	// printf(">%--4.2d<\n",135);
    // ft_printf(">%--4.2d<\n",135);
	// printf(">%--4.3d<\n",135);
    // ft_printf(">%--4.3d<\n",135);
	// printf(">%--4.4d<\n",135);
    // ft_printf(">%--4.4d<\n",135);
	// printf(">%--4d<\n",135);
    // ft_printf(">%--4d<\n",135);
    // printf(">%--3.d<\n",135);
    // ft_printf(">%--3.d<\n",135);
	// printf(">%--3.*d<\n",6,135);
    // ft_printf(">%--3.*d<\n",6,135);
	// printf(">%--3.0d<\n",135);
    // ft_printf(">%--3.0d<\n",135);
	// printf(">%--3.1d<\n",135);
    // ft_printf(">%--3.1d<\n",135);
	// printf(">%--3.2d<\n",135);
    // ft_printf(">%--3.2d<\n",135);
	// printf(">%--3.3d<\n",135);
    // ft_printf(">%--3.3d<\n",135);
	// printf(">%--3.4d<\n",135);
    // ft_printf(">%--3.4d<\n",135);
	// printf(">%--3d<\n",135);
    // ft_printf(">%--3d<\n",135);
    // printf(">%--2.d<\n",135);
    // ft_printf(">%--2.d<\n",135);
	// printf(">%--2.*d<\n",6,135);
    // ft_printf(">%--2.*d<\n",6,135);
	// printf(">%--2.0d<\n",135);
    // ft_printf(">%--2.0d<\n",135);
	// printf(">%--2.1d<\n",135);
    // ft_printf(">%--2.1d<\n",135);
	// printf(">%--2.2d<\n",135);
    // ft_printf(">%--2.2d<\n",135);
	// printf(">%--2.3d<\n",135);
    // ft_printf(">%--2.3d<\n",135);
	// printf(">%--2.4d<\n",135);
    // ft_printf(">%--2.4d<\n",135);
	// printf(">%--2d<\n",135);
    // ft_printf(">%--2d<\n",135);
    // printf(">%--1.d<\n",135);
    // ft_printf(">%--1.d<\n",135);
	// printf(">%--1.*d<\n",6,135);
    // ft_printf(">%--1.*d<\n",6,135);
	// printf(">%--1.0d<\n",135);
    // ft_printf(">%--1.0d<\n",135);
	// printf(">%--1.1d<\n",135);
    // ft_printf(">%--1.1d<\n",135);
	// printf(">%--1.2d<\n",135);
    // ft_printf(">%--1.2d<\n",135);
	// printf(">%--1.3d<\n",135);
    // ft_printf(">%--1.3d<\n",135);
	// printf(">%--1.4d<\n",135);
    // ft_printf(">%--1.4d<\n",135);
	// printf(">%--1d<\n",135);
    // ft_printf(">%--1d<\n",135);
    // printf(">%-.d<\n",135);
    // ft_printf(">%-.d<\n",135);
	// printf(">%-.*d<\n",6,135);
    // ft_printf(">%-.*d<\n",6,135);
	// printf(">%-.0d<\n",135);
    // ft_printf(">%-.0d<\n",135);
	// printf(">%-.1d<\n",135);
    // ft_printf(">%-.1d<\n",135);
	// printf(">%-.2d<\n",135);
    // ft_printf(">%-.2d<\n",135);
	// printf(">%-.3d<\n",135);
    // ft_printf(">%-.3d<\n",135);
	// printf(">%-.4d<\n",135);
    // ft_printf(">%-.4d<\n",135);
	// printf(">%-d<\n",135);
    // ft_printf(">%-d<\n",135);
    // printf(">%-*.d<\n",10,135);
    // ft_printf(">%-*.d<\n",10,135);
	// printf(">%-*.*d<\n",6,10,135);
    // ft_printf(">%-*.*d<\n",6,10,135);
	// printf(">%-*.0d<\n",10,135);
    // ft_printf(">%-*.0d<\n",10,135);
	// printf(">%-*.1d<\n",10,135);
    // ft_printf(">%-*.1d<\n",10,135);
	// printf(">%-*.2d<\n",10,135);
    // ft_printf(">%-*.2d<\n",10,135);
	// printf(">%-*.3d<\n",10,135);
    // ft_printf(">%-*.3d<\n",10,135);
	// printf(">%-*.4d<\n",10,135); // error(-)
    // ft_printf(">%-*.4d<\n",10,135);
    // printf(">%-*d<\n",10,135);
    // ft_printf(">%-*d<\n",10,135);
    // printf(">%-1.d<\n",135);
    // ft_printf(">%-1.d<\n",135);
	// printf(">%-1.*d<\n",6,135);
    // ft_printf(">%-1.*d<\n",6,135);
	// printf(">%-1.0d<\n",135);
    // ft_printf(">%-1.0d<\n",135);
	// printf(">%-1.1d<\n",135);
    // ft_printf(">%-1.1d<\n",135);
	// printf(">%-1.2d<\n",135);
    // ft_printf(">%-1.2d<\n",135);
	// printf(">%-1.3d<\n",135);
    // ft_printf(">%-1.3d<\n",135);
	// printf(">%-1.4d<\n",135);
    // ft_printf(">%-1.4d<\n",135);
	// printf(">%-1d<\n",135);
    // ft_printf(">%-1d<\n",135);
    // printf(">%-2.d<\n",135);
    // ft_printf(">%-2.d<\n",135);
	// printf(">%-2.*d<\n",6,135);
    // ft_printf(">%-2.*d<\n",6,135);
	// printf(">%-2.0d<\n",135);
    // ft_printf(">%-2.0d<\n",135);
	// printf(">%-2.1d<\n",135);
    // ft_printf(">%-2.1d<\n",135);
	// printf(">%-2.2d<\n",135);
    // ft_printf(">%-2.2d<\n",135);
	// printf(">%-2.3d<\n",135);
    // ft_printf(">%-2.3d<\n",135);
	// printf(">%-2.4d<\n",135);
    // ft_printf(">%-2.4d<\n",135);
	// printf(">%-2d<\n",135);
    // ft_printf(">%-2d<\n",135);
    // printf(">%-3.d<\n",135);
    // ft_printf(">%-3.d<\n",135);
	// printf(">%-3.*d<\n",6,135);
    // ft_printf(">%-3.*d<\n",6,135);
	// printf(">%-3.0d<\n",135);
    // ft_printf(">%-3.0d<\n",135);
	// printf(">%-3.1d<\n",135);
    // ft_printf(">%-3.1d<\n",135);
	// printf(">%-3.2d<\n",135);
    // ft_printf(">%-3.2d<\n",135);
	// printf(">%-3.3d<\n",135);
    // ft_printf(">%-3.3d<\n",135);
	// printf(">%-3.4d<\n",135);
    // ft_printf(">%-3.4d<\n",135);
	// printf(">%-3d<\n",135);
    // ft_printf(">%-3d<\n",135);
    // printf(">%-4.d<\n",135);
    // ft_printf(">%-4.d<\n",135);
	// printf(">%-4.*d<\n",6,135);
    // ft_printf(">%-4.*d<\n",6,135);
	// printf(">%-4.0d<\n",135);
    // ft_printf(">%-4.0d<\n",135);
	// printf(">%-4.1d<\n",135);
    // ft_printf(">%-4.1d<\n",135);
	// printf(">%-4.2d<\n",135);
    // ft_printf(">%-4.2d<\n",135);
	// printf(">%-4.3d<\n",135);
    // ft_printf(">%-4.3d<\n",135);
	// printf(">%-4.4d<\n",135);
    // ft_printf(">%-4.4d<\n",135);
	// printf(">%-4d<\n",135);
    // ft_printf(">%-4d<\n",135);
//}

// int     main()
// {
//     printf(">%-4.*d<\n",-4, -135);
//     ft_printf(">%-4.*d<\n",-4, -135);
// }
