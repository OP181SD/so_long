/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:06:25 by yasaidi           #+#    #+#             */
/*   Updated: 2023/03/27 20:05:10 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_check_data_init(t_map_check *data)
{
	data->exit = 0;
	data->player = 0;
	data->wall = 0;
	data->collect = 0;
	data->empty = 0;
	data->unvalid = 0;
	data->rows = 0;
	data->cols = 0;
}

void	process_char(char c, t_mlx *data)
{
	if (c == 'P')
		data->data.player++;
	else if (c == 'E')
		data->data.exit++;
	else if (c == 'C')
		data->data.collect++;
	else if (c == '0')
		data->data.empty++;
	else if (c == '1')
		data->data.wall++;
	else if (c != '\n')
		data->data.unvalid++;
}

int	check_map_value(t_map_check *data)
{
	if (data->player == 0 || data->player > 1)
	{
		ft_printf("Error\n not more than one player\n");
		return (1);
	}
	if (data->exit != 1)
	{
		ft_printf("Error\n you need one exit\n");
		return (1);
	}
	if (data->collect == 0)
	{
		ft_printf("Error\n you need at least one collectible\n");
		return (1);
	}
	if (data->unvalid > 0)
	{
		ft_printf("Error\n the map is invalid\n");
		return (1);
	}
	return (0);
}
