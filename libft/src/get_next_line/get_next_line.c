/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:03:58 by yasaidi           #+#    #+#             */
/*   Updated: 2023/03/06 23:08:22 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_newline(char *save)
{
	int		i;

	i = 0;
	if (!save)
		return (0);
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	return (i);
}

char	*ft_gnl_read(int fd, char *stash)
{
	char	*buf;
	ssize_t	read_result;
	char	*tmp;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	read_result = 1;
	while (read_result > 0 && !ft_strchr(stash))
	{
		read_result = read(fd, buf, BUFFER_SIZE);
		if (read_result < 0)
			return (free(buf), NULL);
		buf[read_result] = '\0';
		tmp = stash;
		stash = ft_strjoin(tmp, buf);
		free(tmp);
	}
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;
	char		*tmp;

	if (fd < 0 || fd >= 1023 || BUFFER_SIZE <= 0)
	tmp = NULL;
	line = NULL;
	if (BUFFER_SIZE < 1 || fd < 0 || fd > 1024)
		return (NULL);
	stash[fd] = ft_gnl_read(fd, stash[fd]);
	line = ft_substr(stash[fd], 0, ft_newline(stash[fd]) + 1);
	tmp = stash[fd];
	stash[fd] = ft_substr(tmp, (ft_newline(stash[fd]) + 1), \
	(ft_strlen(stash[fd]) - (ft_newline(stash[fd]) + 1)));
	free(tmp);
	return (line);
}
