/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 14:19:09 by yassine           #+#    #+#             */
/*   Updated: 2023/03/06 15:19:59 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*ptrr;

	i = 0;
	ptr = (unsigned char *)s1;
	ptrr = (unsigned char *)s2;
	if (!n)
		return (0);
	while (i < n - 1 && ptr[i] == ptrr[i])
		i++;
	return (ptr[i] - ptrr[i]);
}
