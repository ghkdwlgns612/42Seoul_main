/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:08:07 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/05/11 11:27:10 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*res;
	size_t	new_len;

	if (str == 0)
		return (0);
	if ((unsigned int)ft_strlen(str) < start)
		return (ft_strdup(""));
	new_len = ft_strlen(str + start);
	if (new_len < len)
		len = new_len;
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strlcpy(res, str + start, len + 1);
	return (res);
}
