/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:54:47 by yassine           #+#    #+#             */
/*   Updated: 2023/03/06 15:12:16 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memchr(const void *mb, int c, size_t size)
{
	char		*str;
	size_t		i;

	str = (char *)mb;
	i = 0;
	while (i < size)
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	return (NULL);
}
