/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 12:34:09 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/05/08 12:34:09 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char    *str;
    size_t  len;
    size_t  i;

    i = 0;
    len = ft_strlen(s);
    if (s == 0) //입력 문자열이 0일 때
        return (0);
    if ((str = (char *)malloc(sizeof(char) * (len + 1))) == 0)//할당이 안됬을 때
        return (0);
    while (i < len)
    {
        str[i] = f(i, s[i]);
        i++;
    }
    str[i] = '\0';
    return (str);
}