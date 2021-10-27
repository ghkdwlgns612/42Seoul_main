/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_strchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:46:13 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/10/27 16:46:19 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char *ft_gnl_strchr(char *s, int c)
{
    if (c == '\0')
        return (&((char *)s)[ft_gnl_strlen(s)]);
    while (*s)
    {
        if (*s == c)
            return ((char *)s);
        s++;
    }
    return (NULL);
}
