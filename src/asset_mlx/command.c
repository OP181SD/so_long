/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:52:46 by yasaidi           #+#    #+#             */
/*   Updated: 2023/03/27 14:39:22 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_all(t_mlx *params)
{
	mlx_destroy_window(params->mlx, params->win);
	mlx_destroy_display(params->mlx);
	free(params->mlx);
	free_map(params->pars.pars);
	free_map(params->get);
	exit(0);
}

int	close_mouse(t_mlx *params)
{
	mlx_loop_end(params->mlx);
	return (0);
}

int	echap_key(int keysym, t_mlx *params)
{
	if (keysym == XK_Escape)
		mlx_loop_end(params->mlx);
	return (0);
}

void	control_command(t_mlx *params)
{
	mlx_hook(params->win, 17, 0, &close_mouse, params);
	mlx_hook(params->win, KeyPress, KeyPressMask, &echap_key, params);
	mlx_key_hook(params->win, &key_maps, params);
}

void	init_player(t_mlx *params)
{
	params->get = get_map(&(params->map), params->filename);
	params->y = 0;
	while (params->get[params->y])
	{
		params->x = 0;
		while (params->get[params->y][params->x])
		{
			if (params->get[params->y][params->x] == 'P')
			{
				params->map.player_y = params->y;
				params->map.player_x = params->x;
			}
			params->x++;
		}
		params->y++;
	}
}
