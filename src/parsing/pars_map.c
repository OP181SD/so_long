/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:55:17 by yasaidi           #+#    #+#             */
/*   Updated: 2023/03/28 15:56:52 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_pars(t_pars *pars)
{
	pars->pars = NULL;
	pars->closed = 0;
	pars->rect = 0;
	pars->all = 0;
}

static void	init_map(t_mlx *params)
{
	int	i;

	params->pars.pars = get_map(&(params->map), params->filename);
	if (params->pars.pars == 0)
		return ;
	params->pars.closed = is_map_closed(params->pars.pars, &(params->map));
	params->pars.rect = check_map_rectangular(params->pars.pars,
			&(params->map));
	params->pars.all = verify_map(params);
	params->collect_curr = 0;
	if (params->pars.all == 1)
	{
		i = 0;
		while (i < params->map.x)
		{
			free(params->pars.pars[i]);
			i++;
		}
		free(params->pars.pars);
		exit(0);
	}
}

void	process_map(t_pars *pars)
{
	if (pars->pars == NULL)
	{
		write(2, "Error\nThe map is not here", 25);
		error_map(pars->pars, "");
		exit(0);
	}
	if (pars->closed == 1)
		;
	else
	{
		write(2, "Error\nThe map is open", 22);
		error_map(pars->pars, "");
		exit(0);
	}
	if (pars->rect == 1)
	{
		write(2, "Error\nThe map is not rectangular", 33);
		error_map(pars->pars, "");
		exit(0);
	}
	else if (pars->all == 1)
		exit(0);
}

void	pars_map(t_mlx *params)
{
	char	**cpy;
	int		collectibles_count;

	init_pars(&(params->pars));
	init_map(params);
	process_map(&(params->pars));
	get_player_pos(params);
	cpy = cpy_map(params->pars.pars, params->map.x);
	collectibles_count = params->data.collect;
	flood_fill(cpy, &params->map, params);
	process_fill(params, cpy);
	params->data.collect = collectibles_count;
	free_map(cpy);
}
