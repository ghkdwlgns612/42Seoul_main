/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihuhwan <jihuhwan@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 06:37:04 by jihuhwan          #+#    #+#             */
/*   Updated: 2021/09/13 07:10:39 by jihuhwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	is_newline(char *save)
{
	int	i;

	if (!save)
		return (0);
	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_line(char *save)
{
	int		i;
	int		dest_len;
	char	*dest;

	dest_len = 0;
	while (save[dest_len] != '\n' && save[dest_len])
		dest_len++;
	dest = (char *)malloc(dest_len + 1);
	if (!(dest))
		return (NULL);
	i = -1;
	while (++i < dest_len)
		dest[i] = save[i];
	dest[i] = '\0';
	return (dest);
}

char	*get_save(char *save)
{
	int		i;
	int		j;
	int		save_len;
	char	*dest;

	save_len = ft_strlen_gnl(save);
	i = 0;
	while (save[i] != '\n' && save[i])
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	i++;
	dest = (char *)malloc(save_len - i + 1);
	if (!(dest))
		return (NULL);
	j = 0;
	while (save[i])
		dest[j++] = save[i++];
	dest[j] = '\0';
	free(save);
	return (dest);
}

int	get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*save[10200];
	int			read_len;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (fd < 0 || fd > 10200 || !line || BUFFER_SIZE <= 0 || !(buff))
		return (-1);
	read_len = 1;
	while (!is_newline(save[fd]) && read_len != 0)
	{
		read_len = read(fd, buff, BUFFER_SIZE);
		if ((read_len) < 0)
			return (-1);
		buff[read_len] = '\0';
		save[fd] = ft_strjoin_gnl(save[fd], buff);
		if (!(save[fd]))
			return (-1);
	}
	free(buff);
	*line = get_line(save[fd]);
	save[fd] = get_save(save[fd]);
	if (!save[fd])
		return (0);
	return (1);
}
