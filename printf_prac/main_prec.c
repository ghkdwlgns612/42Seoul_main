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
                num = ft_star(ap);
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
            num = -1;
        i++;
    }
    return(num);
}

int     ft_num(va_list ap)
{
    return (va_arg(ap,int));
}

void    ft_num_len_value(char *res,inform_list *inform)
{
    int temp;
    int len;
  
    temp = inform->num;
    len = inform->num_len;
    res[len--] = '\0';
    if (temp < 0)
        temp *= -1;
    while (temp)
    {
        res[len--] = (temp % 10) + '0';
        temp /= 10;
    }
    if (len == 0 && inform->num < 0)
        res[0] = '-';
}

void    ft_put_value_plus(char *res, inform_list *inform, int r_len, int flag)
{
    int temp;
    int len;
    int index;

    temp = inform->num;
    len = r_len;
    index = inform->precision - inform->num_len + 1;
    if (temp < 0)
        temp *= -1;
    if (flag == 1)
    {
        res[len--] = '\0';        
        while (temp)
        {
            res[len--] = (temp % 10) + '0';
            temp /= 10;
        }
        while (index--)
            res[len--] = '0';
        while (len > -1)
            res[len--] = ' ';
    }
    else
    {
        while (temp)
        {
            res[len--] = (temp % 10) + '0';
            temp /= 10;
        }
        while (index--)
            res[len--] = '0';
        len = r_len;
        while (len > -1)
            res[len++] = ' ';
    }
}

void    ft_put_value_minus(char *res, inform_list *inform, int r_len, int flag)
{
    
}

void    ft_right_nopre_value(char *res, inform_list *inform)
{
    if (inform->num < 0)
    {
        if (inform->precision >= inform->num_len)
            ft_put_value_minus(res, inform, inform->width, 1);
        else
            ft_put_value_minus(res, inform, inform->width, 1);
    }
    else
    {
        if (inform->precision >= inform->num_len)
            ft_put_value_plus(res, inform, inform->width, 1);
        else
            ft_put_value_plus(res, inform, inform->width, 1);     
    }
}

void    ft_left_nopre_value(char *res, inform_list *inform)
{
    if (inform->num < 0)
    {
        if (inform->precision >= inform->num_len)
            ft_put_value_minus(res, inform, inform->num_len, 0);
        else
            ft_put_value_minus(res, inform, inform->num_len, 0);
    }
    else
    {
        if (inform->precision >= inform->num_len)
            ft_put_value_plus(res, inform, inform->num_len, 0);
        else
            ft_put_value_plus(res, inform, inform->num_len, 0);     
    }
}

void    ft_ignore_zero(char **res,inform_list *inform)
{
    if (inform->minus_flag == 1 && inform->width > inform->num_len)
    {
        *res = (char *)malloc(sizeof(char) * (inform->width + 1));
        ft_left_nopre_value(*res, inform);
    }
    else if (inform->minus_flag == 0 && inform->width > inform->num_len)
    {
        *res = (char *)malloc(sizeof(char) * (inform->width + 1));
        ft_right_nopre_value(*res, inform);
    }
    else
    {
        *res = (char *)malloc(sizeof(char) * (inform->num_len + 1));
        ft_num_len_value(*res, inform);
    }
}

void    ft_zero_minus(char **res,inform_list *inform)
{

}

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
        inform->width = ft_width(&buf[i], ap);
        inform->precision = ft_precision(&buf[i], ap, inform);
        inform->num = ft_num(ap);
        inform->num_len = ft_int_length(inform->num);
        // printf("width : %d\n", inform->width);
        // printf("preci : %d\n", inform->precision);
        // printf("num : %d\n", inform->num);
        // printf("length : %d\n", inform->num_len);
        if (inform->precision < 0)
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

int main()
{
    printf(">%-4.d<\n",-135);
    ft_printf(">%-4.d<\n",-135);
    printf(">%-4.*d<\n",6,-135);
    ft_printf(">%-4.*d<\n",6,-135);
    printf(">%-4.1d<\n",-135);
    ft_printf(">%-4.1d<\n",-135);
    printf(">%-4.2d<\n",-135);
    ft_printf(">%-4.2d<\n",-135);
    printf(">%-4.3d<\n",-135);
    ft_printf(">%-4.3d<\n",-135);
    printf(">%-4.4d<\n",-135);
    ft_printf(">%-4.4d<\n",-135);
    printf(">%-4d<\n",-135);
    ft_printf(">%-4d<\n",-135);
    printf(">%-3.d<\n",-135);
    ft_printf(">%-3.d<\n",-135);
    printf(">%-3.*d<\n",6,-135);
    ft_printf(">%-3.*d<\n",6,-135);
    printf(">%-3.1d<\n",-135);
    ft_printf(">%-3.1d<\n",-135);
    printf(">%-3.2d<\n",-135);
    ft_printf(">%-3.2d<\n",-135);
    printf(">%-3.3d<\n",-135);
    ft_printf(">%-3.3d<\n",-135);
    printf(">%-3.4d<\n",-135);
    ft_printf(">%-3.4d<\n",-135);
    printf(">%-3d<\n",-135);
    ft_printf(">%-3d<\n",-135);
    printf(">%-2.d<\n",-135);
    ft_printf(">%-2.d<\n",-135);
    printf(">%-2.*d<\n",6,-135);
    ft_printf(">%-2.*d<\n",6,-135);
    printf(">%-2.1d<\n",-135);
    ft_printf(">%-2.1d<\n",-135);
    printf(">%-2.2d<\n",-135);
    ft_printf(">%-2.2d<\n",-135);
    printf(">%-2.3d<\n",-135);
    ft_printf(">%-2.3d<\n",-135);
    printf(">%-2.4d<\n",-135);
    ft_printf(">%-2.4d<\n",-135);
    printf(">%-2d<\n",-135);
    ft_printf(">%-2d<\n",-135);
    printf(">%-1.d<\n",-135);
    ft_printf(">%-1.d<\n",-135);
    printf(">%-1.*d<\n",6,-135);
    ft_printf(">%-1.*d<\n",6,-135);
    printf(">%-1.1d<\n",-135);
    ft_printf(">%-1.1d<\n",-135);
    printf(">%-1.2d<\n",-135);
    ft_printf(">%-1.2d<\n",-135);
    printf(">%-1.3d<\n",-135);
    ft_printf(">%-1.3d<\n",-135);
    printf(">%-1.4d<\n",-135);
    ft_printf(">%-1.4d<\n",-135);
    printf(">%-1d<\n",-135);
    ft_printf(">%-1d<\n",-135);
    printf(">%.d<\n",-135);
    ft_printf(">%.d<\n",-135);
    printf(">%.*d<\n",6,-135);
    ft_printf(">%.*d<\n",6,-135);
    printf(">%.1d<\n",-135);
    ft_printf(">%.1d<\n",-135);
    printf(">%.2d<\n",-135);
    ft_printf(">%.2d<\n",-135);
    printf(">%.3d<\n",-135);
    ft_printf(">%.3d<\n",-135);
    printf(">%.4d<\n",-135);
    ft_printf(">%.4d<\n",-135);
    printf(">%.0d<\n",-135);
    ft_printf(">%.0d<\n",-135);
    printf(">%*.d<\n", 10,-135);
    ft_printf(">%*.d<\n", 10,-135);
    printf(">%*.*d<\n",6, 10,-135);
    ft_printf(">%*.*d<\n",6, 10,-135);
    printf(">%*.1d<\n", 10,-135);
    ft_printf(">%*.1d<\n", 10,-135);
    printf(">%*.2d<\n", 10,-135);
    ft_printf(">%*.2d<\n", 10,-135);
    printf(">%*.3d<\n", 10,-135);
    ft_printf(">%*.3d<\n", 10,-135);
    printf(">%*.4d<\n", 10,-135);
    ft_printf(">%*.4d<\n", 10,-135);
    printf(">%*.0d<\n", 10,-135);
    ft_printf(">%*.0d<\n", 10,-135);
    printf(">%0.d<\n", -135);
    ft_printf(">%0.d<\n", -135);
    printf(">%0.*d<\n",6, -135);
    ft_printf(">%0.*d<\n",6, -135);
    printf(">%0.1d<\n", -135);
    ft_printf(">%0.1d<\n", -135);
    printf(">%0.2d<\n", -135);
    ft_printf(">%0.2d<\n", -135);
    printf(">%0.3d<\n", -135);
    ft_printf(">%0.3d<\n", -135);
    printf(">%0.4d<\n", -135);
    ft_printf(">%0.4d<\n", -135);
    printf(">%0.0d<\n", -135);
    ft_printf(">%0.0d<\n", -135);
    printf(">%1.d<\n", -135);
    ft_printf(">%1.d<\n", -135);
    printf(">%1.*d<\n",6, -135);
    ft_printf(">%1.*d<\n",6, -135);
    printf(">%1.1d<\n", -135);
    ft_printf(">%1.1d<\n", -135);
    printf(">%1.2d<\n", -135);
    ft_printf(">%1.2d<\n", -135);
    printf(">%1.3d<\n", -135);
    ft_printf(">%1.3d<\n", -135);
    printf(">%1.4d<\n", -135);
    ft_printf(">%1.4d<\n", -135);
    printf(">%1.0d<\n", -135);
    ft_printf(">%1.0d<\n", -135);
    printf(">%2.d<\n", -135);
    ft_printf(">%2.d<\n", -135);
    printf(">%2.*d<\n",6, -135);
    ft_printf(">%2.*d<\n",6, -135);
    printf(">%2.1d<\n", -135);
    ft_printf(">%2.1d<\n", -135);
    printf(">%2.2d<\n", -135);
    ft_printf(">%2.2d<\n", -135);
    printf(">%2.3d<\n", -135);
    ft_printf(">%2.3d<\n", -135);
    printf(">%2.4d<\n", -135);
    ft_printf(">%2.4d<\n", -135);
    printf(">%2.2d<\n", -135);
    ft_printf(">%2.2d<\n", -135);
    printf(">%3.d<\n", -135);
    ft_printf(">%3.d<\n", -135);
    printf(">%3.*d<\n",6, -135);
    ft_printf(">%3.*d<\n",6, -135);
    printf(">%3.1d<\n", -135);
    ft_printf(">%3.1d<\n", -135);
    printf(">%3.2d<\n", -135);
    ft_printf(">%3.2d<\n", -135);
    printf(">%3.3d<\n", -135);
    ft_printf(">%3.3d<\n", -135);
    printf(">%3.4d<\n", -135);
    ft_printf(">%3.4d<\n", -135);
    printf(">%3.2d<\n", -135);
    ft_printf(">%3.2d<\n", -135);
	printf(">%4.d<\n", -135);
    ft_printf(">%4.d<\n", -135);
    printf(">%4.*d<\n",6, -135);
    ft_printf(">%4.*d<\n",6, -135);
    printf(">%4.1d<\n", -135);
    ft_printf(">%4.1d<\n", -135);
    printf(">%4.2d<\n", -135);
    ft_printf(">%4.2d<\n", -135);
    printf(">%4.3d<\n", -135);
    ft_printf(">%4.3d<\n", -135);
    printf(">%4.4d<\n", -135);
    ft_printf(">%4.4d<\n", -135);
    printf(">%4.0d<\n", -135);
    ft_printf(">%4.0d<\n", -135);
    printf(">%0*.d<\n",10,-135);
    ft_printf(">%0*.d<\n",10,-135);
	printf(">%0*.*d<\n",10,6,-135);
    ft_printf(">%0*.*d<\n",10,6,-135);
	printf(">%0*.0d<\n",10,-135);
    ft_printf(">%0*.0d<\n",10,-135);
	printf(">%0*.1d<\n",10,-135);
    ft_printf(">%0*.1d<\n",10,-135);
	printf(">%0*.2d<\n",10,-135);
    ft_printf(">%0*.2d<\n",10,-135);
	printf(">%0*.3d<\n",10,-135);
    ft_printf(">%0*.3d<\n",10,-135);
	printf(">%0*.4d<\n",10,-135);
    ft_printf(">%0*.4d<\n",10,-135);
	printf(">%0*d<\n",10,-135);
    ft_printf(">%0*d<\n",10,-135);
    printf(">%00.d<\n",-135);
    ft_printf(">%00.d<\n",-135);
	printf(">%00.*d<\n",6,-135);
    ft_printf(">%00.*d<\n",6,-135);
	printf(">%00.0d<\n",-135);
    ft_printf(">%00.0d<\n",-135);
	printf(">%00.1d<\n",-135);
    ft_printf(">%00.1d<\n",-135);
	printf(">%00.2d<\n",-135);
    ft_printf(">%00.2d<\n",-135);
	printf(">%00.3d<\n",-135);
    ft_printf(">%00.3d<\n",-135);
	printf(">%00.4d<\n",-135);
    ft_printf(">%00.4d<\n",-135);
	printf(">%00d<\n",-135);
    ft_printf(">%00d<\n",-135);
    printf(">%01.d<\n",-135);
    ft_printf(">%01.d<\n",-135);
	printf(">%01.*d<\n",6,-135);
    ft_printf(">%01.*d<\n",6,-135);
	printf(">%01.0d<\n",-135);
    ft_printf(">%01.0d<\n",-135);
	printf(">%01.1d<\n",-135);
    ft_printf(">%01.1d<\n",-135);
	printf(">%01.2d<\n",-135);
    ft_printf(">%01.2d<\n",-135);
	printf(">%01.3d<\n",-135);
    ft_printf(">%01.3d<\n",-135);
	printf(">%01.4d<\n",-135);
    ft_printf(">%01.4d<\n",-135);
	printf(">%01d<\n",-135);
    ft_printf(">%01d<\n",-135);
    printf(">%02.d<\n",-135);
    ft_printf(">%02.d<\n",-135);
	printf(">%02.*d<\n",6,-135);
    ft_printf(">%02.*d<\n",6,-135);
	printf(">%02.0d<\n",-135);
    ft_printf(">%02.0d<\n",-135);
	printf(">%02.1d<\n",-135);
    ft_printf(">%02.1d<\n",-135);
	printf(">%02.2d<\n",-135);
    ft_printf(">%02.2d<\n",-135);
	printf(">%02.3d<\n",-135);
    ft_printf(">%02.3d<\n",-135);
	printf(">%02.4d<\n",-135);
    ft_printf(">%02.4d<\n",-135);
	printf(">%02d<\n",-135);
    ft_printf(">%02d<\n",-135);
    printf(">%03.d<\n",-135);
    ft_printf(">%03.d<\n",-135);
	printf(">%03.*d<\n",6,-135);
    ft_printf(">%03.*d<\n",6,-135);
	printf(">%03.0d<\n",-135);
    ft_printf(">%03.0d<\n",-135);
	printf(">%03.1d<\n",-135);
    ft_printf(">%03.1d<\n",-135);
	printf(">%03.2d<\n",-135);
    ft_printf(">%03.2d<\n",-135);
	printf(">%03.3d<\n",-135);
    ft_printf(">%03.3d<\n",-135);
	printf(">%03.4d<\n",-135);
    ft_printf(">%03.4d<\n",-135);
	printf(">%03d<\n",-135);
    ft_printf(">%03d<\n",-135);
    printf(">%04.d<\n",-135);
    ft_printf(">%04.d<\n",-135);
	printf(">%04.*d<\n",6,-135);
    ft_printf(">%04.*d<\n",6,-135);
	printf(">%04.0d<\n",-135);
    ft_printf(">%04.0d<\n",-135);
	printf(">%04.1d<\n",-135);
    ft_printf(">%04.1d<\n",-135);
	printf(">%04.2d<\n",-135);
    ft_printf(">%04.2d<\n",-135);
	printf(">%04.3d<\n",-135);
    ft_printf(">%04.3d<\n",-135);
	printf(">%04.4d<\n",-135);
    ft_printf(">%04.4d<\n",-135);
	printf(">%04d<\n",-135);
    ft_printf(">%04d<\n",-135);
    printf(">%--4.d<\n",-135);
    ft_printf(">%--4.d<\n",-135);
	printf(">%--4.*d<\n",6,-135);
    ft_printf(">%--4.*d<\n",6,-135);
	printf(">%--4.0d<\n",-135);
    ft_printf(">%--4.0d<\n",-135);
	printf(">%--4.1d<\n",-135);
    ft_printf(">%--4.1d<\n",-135);
	printf(">%--4.2d<\n",-135);
    ft_printf(">%--4.2d<\n",-135);
	printf(">%--4.3d<\n",-135);
    ft_printf(">%--4.3d<\n",-135);
	printf(">%--4.4d<\n",-135);
    ft_printf(">%--4.4d<\n",-135);
	printf(">%--4d<\n",-135);
    ft_printf(">%--4d<\n",-135);
    printf(">%--3.d<\n",-135);
    ft_printf(">%--3.d<\n",-135);
	printf(">%--3.*d<\n",6,-135);
    ft_printf(">%--3.*d<\n",6,-135);
	printf(">%--3.0d<\n",-135);
    ft_printf(">%--3.0d<\n",-135);
	printf(">%--3.1d<\n",-135);
    ft_printf(">%--3.1d<\n",-135);
	printf(">%--3.2d<\n",-135);
    ft_printf(">%--3.2d<\n",-135);
	printf(">%--3.3d<\n",-135);
    ft_printf(">%--3.3d<\n",-135);
	printf(">%--3.4d<\n",-135);
    ft_printf(">%--3.4d<\n",-135);
	printf(">%--3d<\n",-135);
    ft_printf(">%--3d<\n",-135);
    printf(">%--2.d<\n",-135);
    ft_printf(">%--2.d<\n",-135);
	printf(">%--2.*d<\n",6,-135);
    ft_printf(">%--2.*d<\n",6,-135);
	printf(">%--2.0d<\n",-135);
    ft_printf(">%--2.0d<\n",-135);
	printf(">%--2.1d<\n",-135);
    ft_printf(">%--2.1d<\n",-135);
	printf(">%--2.2d<\n",-135);
    ft_printf(">%--2.2d<\n",-135);
	printf(">%--2.3d<\n",-135);
    ft_printf(">%--2.3d<\n",-135);
	printf(">%--2.4d<\n",-135);
    ft_printf(">%--2.4d<\n",-135);
	printf(">%--2d<\n",-135);
    ft_printf(">%--2d<\n",-135);
    printf(">%--1.d<\n",-135);
    ft_printf(">%--1.d<\n",-135);
	printf(">%--1.*d<\n",6,-135);
    ft_printf(">%--1.*d<\n",6,-135);
	printf(">%--1.0d<\n",-135);
    ft_printf(">%--1.0d<\n",-135);
	printf(">%--1.1d<\n",-135);
    ft_printf(">%--1.1d<\n",-135);
	printf(">%--1.2d<\n",-135);
    ft_printf(">%--1.2d<\n",-135);
	printf(">%--1.3d<\n",-135);
    ft_printf(">%--1.3d<\n",-135);
	printf(">%--1.4d<\n",-135);
    ft_printf(">%--1.4d<\n",-135);
	printf(">%--1d<\n",-135);
    ft_printf(">%--1d<\n",-135);
    printf(">%-.d<\n",-135);
    ft_printf(">%-.d<\n",-135);
	printf(">%-.*d<\n",6,-135);
    ft_printf(">%-.*d<\n",6,-135);
	printf(">%-.0d<\n",-135);
    ft_printf(">%-.0d<\n",-135);
	printf(">%-.1d<\n",-135);
    ft_printf(">%-.1d<\n",-135);
	printf(">%-.2d<\n",-135);
    ft_printf(">%-.2d<\n",-135);
	printf(">%-.3d<\n",-135);
    ft_printf(">%-.3d<\n",-135);
	printf(">%-.4d<\n",-135);
    ft_printf(">%-.4d<\n",-135);
	printf(">%-d<\n",-135);
    ft_printf(">%-d<\n",-135);
    printf(">%-*.d<\n",10,-135);
    ft_printf(">%-*.d<\n",10,-135);
	printf(">%-*.*d<\n",6,10,-135);
    ft_printf(">%-*.*d<\n",6,10,-135);
	printf(">%-*.0d<\n",10,-135);
    ft_printf(">%-*.0d<\n",10,-135);
	printf(">%-*.1d<\n",10,-135);
    ft_printf(">%-*.1d<\n",10,-135);
	printf(">%-*.2d<\n",10,-135);
    ft_printf(">%-*.2d<\n",10,-135);
	printf(">%-*.3d<\n",10,-135);
    ft_printf(">%-*.3d<\n",10,-135);
	printf(">%-*.4d<\n",10,-135); // error(-)
    ft_printf(">%-*.4d<\n",10,-135);
    printf(">%-*d<\n",10,-135);
    ft_printf(">%-*d<\n",10,-135);
    printf(">%-1.d<\n",-135);
    ft_printf(">%-1.d<\n",-135);
	printf(">%-1.*d<\n",6,-135);
    ft_printf(">%-1.*d<\n",6,-135);
	printf(">%-1.0d<\n",-135);
    ft_printf(">%-1.0d<\n",-135);
	printf(">%-1.1d<\n",-135);
    ft_printf(">%-1.1d<\n",-135);
	printf(">%-1.2d<\n",-135);
    ft_printf(">%-1.2d<\n",-135);
	printf(">%-1.3d<\n",-135);
    ft_printf(">%-1.3d<\n",-135);
	printf(">%-1.4d<\n",-135);
    ft_printf(">%-1.4d<\n",-135);
	printf(">%-1d<\n",-135);
    ft_printf(">%-1d<\n",-135);
    printf(">%-2.d<\n",-135);
    ft_printf(">%-2.d<\n",-135);
	printf(">%-2.*d<\n",6,-135);
    ft_printf(">%-2.*d<\n",6,-135);
	printf(">%-2.0d<\n",-135);
    ft_printf(">%-2.0d<\n",-135);
	printf(">%-2.1d<\n",-135);
    ft_printf(">%-2.1d<\n",-135);
	printf(">%-2.2d<\n",-135);
    ft_printf(">%-2.2d<\n",-135);
	printf(">%-2.3d<\n",-135);
    ft_printf(">%-2.3d<\n",-135);
	printf(">%-2.4d<\n",-135);
    ft_printf(">%-2.4d<\n",-135);
	printf(">%-2d<\n",-135);
    ft_printf(">%-2d<\n",-135);
    printf(">%-3.d<\n",-135);
    ft_printf(">%-3.d<\n",-135);
	printf(">%-3.*d<\n",6,-135);
    ft_printf(">%-3.*d<\n",6,-135);
	printf(">%-3.0d<\n",-135);
    ft_printf(">%-3.0d<\n",-135);
	printf(">%-3.1d<\n",-135);
    ft_printf(">%-3.1d<\n",-135);
	printf(">%-3.2d<\n",-135);
    ft_printf(">%-3.2d<\n",-135);
	printf(">%-3.3d<\n",-135);
    ft_printf(">%-3.3d<\n",-135);
	printf(">%-3.4d<\n",-135);
    ft_printf(">%-3.4d<\n",-135);
	printf(">%-3d<\n",-135);
    ft_printf(">%-3d<\n",-135);
    printf(">%-4.d<\n",-135);
    ft_printf(">%-4.d<\n",-135);
	printf(">%-4.*d<\n",6,-135);
    ft_printf(">%-4.*d<\n",6,-135);
	printf(">%-4.0d<\n",-135);
    ft_printf(">%-4.0d<\n",-135);
	printf(">%-4.1d<\n",-135);
    ft_printf(">%-4.1d<\n",-135);
	printf(">%-4.2d<\n",-135);
    ft_printf(">%-4.2d<\n",-135);
	printf(">%-4.3d<\n",-135);
    ft_printf(">%-4.3d<\n",-135);
	printf(">%-4.4d<\n",-135);
    ft_printf(">%-4.4d<\n",-135);
	printf(">%-4d<\n",-135);
    ft_printf(">%-4d<\n",-135);
    return (0);
}
