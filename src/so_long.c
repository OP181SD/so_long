/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:28:28 by yasaidi           #+#    #+#             */
/*   Updated: 2023/03/28 16:03:31 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv, char **env)
{
	t_mlx	params;

	if (argc != 2 || !*env)
		exit(1);
	params.key_hook = 0;
	params.filename = argv[1];
	pars_map(&params);
	init_params(&params);
	control_command(&params);
	init_player(&params);
	init_game(&params);
	mlx_loop(params.mlx);
	free_all(&params);
}
