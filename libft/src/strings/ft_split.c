/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:52:00 by yasaidi           #+#    #+#             */
/*   Updated: 2023/03/06 15:21:03 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	count_word(char *str, char c)
{
	int		i_str;
	int		i_word;

	i_str = 0;
	i_word = 0;
	while (str && str[i_str])
	{
		if (str[i_str] != c && str[i_str])
		{
			i_word++;
			while (str[i_str] != c && str[i_str])
				i_str++;
		}
		else
			i_str++;
	}
	return (i_word);
}

static	int	strlen_letter(const char *str, char c)
{
	int	i_letter_word;

	i_letter_word = 0;
	while (str && str[i_letter_word]
		&& (str[i_letter_word] != c && str[i_letter_word]))
		i_letter_word++;
	return (i_letter_word);
}

static	char	*ft_strword(const char *s, char c)
{
	int		i;
	int		letter_word;
	char	*word;

	i = 0;
	letter_word = strlen_letter(s, c);
	word = (char *)malloc((letter_word + 1) * sizeof(char));
	if (!word)
		return (0);
	while (i < letter_word)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_free_split(char **split, int i_str)
{
	while (i_str >= 0)
	{
		free(split[i_str]);
		i_str--;
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i_str;
	int		j_col;
	int		col_final;

	i_str = 0;
	j_col = 0;
	col_final = count_word((char *)s, c);
	split = (char **)malloc((col_final + 1) * sizeof(char *));
	if (!split)
		return (ft_free_split(split, i_str));
	while (s && s[i_str] && j_col < col_final)
	{
		if (s[i_str] != c && s[i_str])
		{
			split[j_col] = ft_strword(&s[i_str], c);
			i_str = i_str + strlen_letter(&s[i_str], c);
			j_col++;
			if (!s[i_str])
				break ;
		}
		i_str++;
	}
	split[j_col] = NULL;
	return (split);
}
