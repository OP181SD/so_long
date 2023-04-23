/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 22:38:01 by yasaidi           #+#    #+#             */
/*   Updated: 2023/03/28 02:17:15 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strstr(char *str, char *to_find)
{
	int	search;
	int	find;

	if (to_find[0] == '\0')
		return (str);
	search = 0;
	while (str[search])
	{
		find = 0;
		while (str[search + find] == to_find[find])
		{
			if (to_find[find + 1] == '\0')
				return (str + search);
			find++;
		}
		search++;
	}
	return (NULL);
}

int	check_map(char *filename)
{
	if (!(ft_strstr(filename, ".ber")))
	{
		ft_putstr("extension invalide");
		exit(0);
	}
	return (1);
}

int	get_map_fd(char *filename)
{
	int	fd;
	int	check;

	check = check_map(filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("impossible de ouvrir le fichier");
		exit(1);
	}
	return (fd);
}
