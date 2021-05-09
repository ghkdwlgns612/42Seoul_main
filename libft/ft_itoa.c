/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 12:08:16 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/05/08 12:08:16 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  str_len(int n)
{
    size_t  ret;

    ret = 0;
    if (n < 0)
        n *= -1;
    else if (n == 0)
        return (1);
    while (n > 0)
    {
        n /= 10;
        ret++;
    }
    return (ret);
}

void    allocate_arr(int num, char *str, int len)
{
    while (num > 0)
    {
        str[len--] = (num % 10) + 48;
        num /= 10;
    }
}

char *ft_itoa(int n)
{
    char    *str;
    size_t  len;
    int     tmp;

    len = str_len(n);
    tmp = n;
    if (n == 0)
    {
        str[len] = '0';
        return (str);
    }
    else if (n < 0)
    {
        tmp = n * -1;
        len++;
    }
    if (str = (char *)malloc(sizeof(char) * (len + 1)) == 0)
        return (0);
    str[len] = 0;
    if (n < 0)
        str[0] = '-';
    allocate_arr(tmp, str, len);
    return (str);
}