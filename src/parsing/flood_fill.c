/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:07:10 by yasaidi           #+#    #+#             */
/*   Updated: 2023/03/28 02:20:06 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_pos(t_mlx *params)
{
	char	**map;
	int		i;
	int		j;

	map = params->pars.pars;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				params->map.player_x = j;
				params->map.player_y = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

char	**cpy_map(char **map, int line_count)
{
	char	**cpy;
	int		i;

	cpy = malloc(sizeof(char *) * (line_count + 1));
	i = 0;
	while (i < line_count)
	{
		cpy[i] = ft_strdup(map[i]);
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}

void	process_fill(t_mlx *params, char **cpy)
{
	if (params->data.collect != 0)
	{
		write(2, "Error\n no paths to collectibles", 32);
		error_map(params->pars.pars, "");
		free_map(cpy);
		exit(0);
	}
	if (!check_exit(cpy))
	{
		write(2, "Error\nNo path to exit found", 28);
		error_map(params->pars.pars, "");
		free_map(cpy);
		exit(0);
	}
}

int	flood_fill(char **tab, t_game *map, t_mlx *params)
{
	if (tab[map->player_y][map->player_x] == '1'
		|| tab[map->player_y][map->player_x] == 'Z')
		return (1);
	if (tab[map->player_y][map->player_x] == 'C')
	{
		tab[map->player_y][map->player_x] = 'c';
		params->data.collect--;
	}
	if (tab[map->player_y][map->player_x] == 'E')
		return (1);
	if (tab[map->player_y][map->player_x] != 'E')
		tab[map->player_y][map->player_x] = 'Z';
	if (!flood_fill(tab, &(t_game){map->x, map->y, map->player_x + 1,
			map->player_y}, params))
		return (0);
	if (!flood_fill(tab, &(t_game){map->x, map->y, map->player_x - 1,
			map->player_y}, params))
		return (0);
	if (!flood_fill(tab, &(t_game){map->x, map->y, map->player_x, map->player_y
			+ 1}, params))
		return (0);
	if (!flood_fill(tab, &(t_game){map->x, map->y, map->player_x, map->player_y
			- 1}, params))
		return (0);
	return (1);
}
