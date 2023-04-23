/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:45:35 by yasaidi           #+#    #+#             */
/*   Updated: 2023/03/28 02:08:12 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	trim_newline(char *line)
{
	size_t	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

char	**read_file_lines(int fd, int line_count)
{
	char	*line;
	int		i;
	char	**buf;

	buf = malloc(sizeof(char *) * (line_count + 1));
	if (!buf)
		return (NULL);
	i = 0;
	while (i < line_count)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		trim_newline(line);
		buf[i] = line;
		i++;
	}
	buf[i] = NULL;
	return (buf);
}

int	count_lines(char *filename)
{
	int		fd;
	char	*line;
	int		i;

	line = NULL;
	fd = get_map_fd(filename);
	if (fd == -1)
		return (-1);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		i++;
	}
	close(fd);
	return (i);
}

char	**get_map(t_game *map, char *filename)
{
	int		fd;
	int		line_count;
	char	**buf;

	fd = get_map_fd(filename);
	if (fd == -1)
		exit(0);
	line_count = count_lines(filename);
	if (line_count == 0)
	{
		close(fd);
		return (NULL);
	}
	map->x = line_count;
	buf = read_file_lines(fd, line_count);
	map->y = ft_strlen(buf[0]);
	close(fd);
	return (buf);
}
