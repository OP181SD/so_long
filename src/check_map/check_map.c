/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 02:21:04 by yasaidi           #+#    #+#             */
/*   Updated: 2023/03/28 01:47:09 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verify_map(t_mlx *params)
{
	int		count;
	int		fd;
	char	*buff;

	map_check_data_init(&(params->data));
	fd = get_map_fd(params->filename);
	if (fd < 0)
		return (-1);
	buff = malloc(sizeof(count_lines(params->filename)));
	if (!buff)
		return (0);
	count = read(fd, buff, 1);
	while (count != 0)
	{
		process_char(buff[0], params);
		if (params->data.rows == 0)
			params->data.cols++;
		count = read(fd, buff, 1);
	}
	params->data.rows++;
	free(buff);
	close(fd);
	return (check_map_value(&(params->data)));
}

// int	main(void)
// {
// 	int closed;
// 	char **map;
// 	t_game map_c;

// 	map = get_map(&map_c);
// 	closed = verify_map(map, &map_c);
// 	if (!(closed == 1))
// 	{
// 		ft_printf("map valide");
// 	}
// 	free_map(map);
// }