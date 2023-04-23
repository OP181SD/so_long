/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  map closed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 22:10:04 by yasaidi           #+#    #+#             */
/*   Updated: 2023/03/14 14:26:00 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_map_closed(char **map, t_game *map_c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map_c->x)
	{
		if (map[i][0] != '1' || map[i][map_c->y - 1] != '1')
			return (0);
		i++;
	}
	while (j < map_c->y)
	{
		if (map[0][j] != '1' || map[map_c->x - 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	is_exit_next_to_z(char **map, int i, int j)
{
	if (map[i + 1][j] == 'Z' || map[i - 1][j] == 'Z' || map[i][j + 1] == 'Z'
		|| map[i][j - 1] == 'Z')
		return (1);
	return (0);
}

int	check_exit(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		i++;
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				return (is_exit_next_to_z(map, i, j));
			j++;
		}
	}
	return (0);
}
