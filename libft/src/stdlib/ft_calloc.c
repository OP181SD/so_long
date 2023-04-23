/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 14:21:06 by yassine           #+#    #+#             */
/*   Updated: 2023/01/10 08:06:45 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	if (size > 0 && nmemb * size / size != nmemb)
		return (NULL);
	tab = (char *) malloc(nmemb * size);
	if (!tab)
		return (0);
	ft_bzero (tab, size * nmemb);
	return (tab);
}
