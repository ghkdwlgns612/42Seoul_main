/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 19:29:01 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/05/08 19:29:01 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list  *ft_lstnew(void *content)
{
    t_list *res;

    if ((res = (t_list *)malloc(sizeof(t_list))) == 0)
        return (0);
    res->content = content;
    res->next = 0;
    return (res);
}