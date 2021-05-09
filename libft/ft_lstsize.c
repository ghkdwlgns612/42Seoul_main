/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 20:33:01 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/05/08 20:33:01 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstsize(t_list *lst)
{
    int num;

    num = 0;
    while (lst != NULL)
    {
        lst = lst->next;
        num++;
    }
    return (num);
}