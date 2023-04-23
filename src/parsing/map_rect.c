/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:11:47 by yasaidi           #+#    #+#             */
/*   Updated: 2023/03/22 19:24:59 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_rectangular(char **map, t_game *map_c)
{
	int	i;
	int	frist_line;
	int	line_next;
	int	x;

	x = map_c->x;
	frist_line = ft_strlen(map[0]);
	i = 0;
	while (i < x)
	{
		line_next = (int)ft_strlen(map[i]);
		if (frist_line != line_next)
			return (1);
		i++;
	}
	return (0);
}
