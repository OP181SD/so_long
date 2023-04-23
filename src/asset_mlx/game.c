/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 22:35:19 by yasaidi           #+#    #+#             */
/*   Updated: 2023/03/28 15:53:33 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_params(t_mlx *params)
{
	params->mlx = mlx_init();
	if (!params->mlx)
	{
		ft_putstr("Error\n");
		free_map(params->pars.pars);
		exit(0);
	}
	params->win = mlx_new_window(params->mlx, params->map.y * 32, params->map.x
			* 32, "Men in Bitcoin");
	if (!params->win)
	{
		ft_putstr("Error\n");
		free_map(params->pars.pars);
		exit(0);
	}
}

void	put_img(t_mlx *params, int y, int x, char *filename)
{
	params->img_width = PIXEL;
	params->img_height = PIXEL;
	params->img = mlx_xpm_file_to_image(params->mlx, filename,
			&params->img_width, &params->img_height);
	if (!params->img)
	{
		ft_putstr("Error\n");
		exit(0);
	}
	mlx_put_image_to_window(params->mlx, params->win, params->img, x * 32, y
		* 32);
	mlx_destroy_image(params->mlx, params->img);
}

static int	process_env(t_mlx *params)
{
	int	y;
	int	x;

	y = 0;
	while (y < params->y)
	{
		x = 0;
		while (x < params->x)
		{
			if (params->get[y][x] == '1')
				put_img(params, y, x, WALL_XMP);
			else if (params->get[y][x] == 'P')
				put_img(params, y, x, PLAYER_XMP);
			else if (params->get[y][x] == '0')
				put_img(params, y, x, FLOOR_XMP);
			else if (params->get[y][x] == 'E')
				put_img(params, y, x, EXIT_XMP);
			else if (params->get[y][x] == 'C')
				put_img(params, y, x, COIN_XMP);
			x++;
		}
		y++;
	}
	return (0);
}

void	init_game(t_mlx *params)
{
	params->y = 0;
	while (params->get[params->y])
	{
		params->x = 0;
		while (params->get[params->y][params->x])
			params->x++;
		params->y++;
	}
	mlx_loop_hook(params->mlx, process_env, params);
}
