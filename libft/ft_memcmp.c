/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:16:52 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/05/06 15:16:52 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp(const void *str1, const void *str2, size_t num)
{
    unsigned char *cmp1;
    unsigned char *cmp2;
    size_t i;

    if (num == 0)
        return (0);
    i = 0;
    cmp1 = (unsigned char *)str1;
    cmp2 = (unsigned char *)str2;
    while (i < num)
    {
        if (cmp1[i] != cmp2[i])
            return (cmp1[i] - cmp2[i]);
        i++;
    }
    return (0);
}