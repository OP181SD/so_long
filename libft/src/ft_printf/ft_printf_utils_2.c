/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:12:42 by yasaidi           #+#    #+#             */
/*   Updated: 2023/03/06 15:26:47 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}
/*
int	ft_len(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
*/

int	int_len(long nb_div)
{
	int		len;

	if (nb_div == 0)
		return (1);
	len = 0;
	if (nb_div < 0)
	{
		nb_div *= -1;
		len++;
	}
	while (nb_div > 0)
	{
		nb_div = nb_div / 10;
		len++;
	}
	return (len);
}
