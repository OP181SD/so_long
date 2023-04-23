/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:57:46 by yasaidi           #+#    #+#             */
/*   Updated: 2023/03/28 03:43:13 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_movement(t_mlx *params, int new_y, int new_x)
{
	static int	nb_moves = 0;

	nb_moves++;
	ft_printf("\rNombre de mouvements : %d", nb_moves);
	if (params->get[new_y][new_x] == 'C')
		params->collect_curr++;
	if (params->get[new_y][new_x] == 'E'
		&& params->data.collect == params->collect_curr)
	{
		write(1, "\ngg", 3);
		mlx_loop_end(params->mlx);
	}
	else if (params->get[new_y][new_x] == '0'
			|| params->get[new_y][new_x] == 'C')
	{
		params->get[params->map.player_y][params->map.player_x] = '0';
		params->map.player_y = new_y;
		params->map.player_x = new_x;
		params->get[new_y][new_x] = 'P';
	}
}

int	key_maps(int key_hook, t_mlx *params)
{
	if (!params->get)
		return (0);
	if (params->map.y < 0 && params->map.x < 0)
		return (0);
	if (key_hook == W && params->map.player_y - 1 >= 0
		&& params->get[params->map.player_y - 1][params->map.player_x] != '1')
		handle_movement(params, params->map.player_y - 1, params->map.player_x);
	else if (key_hook == A && params->map.player_x - 1 >= 0
		&& params->get[params->map.player_y][params->map.player_x
		- 1] != '1')
		handle_movement(params, params->map.player_y, params->map.player_x - 1);
	else if (key_hook == S && params->map.player_y + 1 < params->y
		&& params->get[params->map.player_y
			+ 1][params->map.player_x] != '1')
		handle_movement(params, params->map.player_y + 1, params->map.player_x);
	else if (key_hook == D && params->map.player_x + 1 < params->x
		&& params->get[params->map.player_y][params->map.player_x
		+ 1] != '1')
		handle_movement(params, params->map.player_y, params->map.player_x + 1);
	return (0);
}
