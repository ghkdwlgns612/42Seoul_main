/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 09:54:47 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/05/08 09:54:47 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  word_num(const char *str, char c)
{
    size_t  i;
    size_t  num;

    i = 0;
    num = 0;
    while (str[i] != 0)
    {
        if (str[i] != c)
        {
            num++;
            while (str[i] != c)
                i++;
        }
        else
            i++;
    }
    return (num);
}

void    ft_strcpy(char *dest, char const *src, int start, int last)
{
    int     i;

    i = 0;
    while (start < last)
    {
        dest[i] = src[start];
        i++;
        start++;
    }
    dest[i] ='\0';
}

void    *mem_free(char **fail_arr, size_t num)
{
    size_t  i;

    i = 0;
    while (i < num)
    {
        free(fail_arr[i]);
        i++;
    }
    free(fail_arr);
    return (NULL);
}

void    semi_spilt(const char *origin_str, char c, char **split_str)
{
    size_t  i;
    size_t  j;
    size_t  start;

    i = 0;
    j = 0;
    while (origin_str[i])
    {
        if (origin_str[i] != c)
        {
            start = i;
            while (origin_str[i] != c && origin_str[i] != '\0')
                i++;
            if ((split_str[j] = (char *)malloc(sizeof(char) * (i - start + 1))) == 0)
            {
                mem_free(split_str, j);
                return ;
            }
            ft_strcpy(split_str[j], origin_str, start, i);
            j++;
        }
        else
            i++;
    }
}

char **ft_split(char const *s, char c)
{
    char    **str;
    size_t  num;
    if (s == 0)
        return (0);
    num = word_num(s, c);
    str = (char **)malloc(sizeof(char *) * (num + 1));
    if (str == 0)
        return (0);
    if (num == 0)
        return (str);
    str[num] = '\0';
    semi_split(s, c, str);
    return (str);
}