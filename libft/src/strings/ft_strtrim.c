/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:26:25 by yasaidi           #+#    #+#             */
/*   Updated: 2023/03/06 15:11:30 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_iset(const char *str, const char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dest;

	dest = (char *)malloc(ft_strlen(s) + 1 * sizeof(char));
	if (!dest)
		return (0);
	i = 0;
	while (s[i])
	{
		((char *)dest)[i] = s[i];
		i++;
	}
	((char *)dest)[i] = '\0';
	return ((char *)dest);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (ft_iset(set, s1[i]))
		i++;
	if (i == (int)ft_strlen(s1))
		return (ft_strdup(""));
	j = ft_strlen(s1) - 1;
	while (ft_iset(set, s1[j]))
		j--;
	j++;
	str = malloc(sizeof(char) * j - i + 1);
	if (!str)
		return (NULL);
	ft_strncpy(str, &s1[i], j - i);
	str[j - i] = '\0';
	return (str);
}
