/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:08:07 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/05/09 12:08:57 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*ret;
	size_t	size;

	ret = (char *)malloc(sizeof(char) * (len + 1));
	size = ft_strlen(str);
	if (ret == 0 || str == 0)
		return (0);
	if (start >= size)
	{
		ret[0] = '\0';
		return (ret);
	}
	ft_strlcpy(ret, str + start, len + 1);
	return (ret);
}
