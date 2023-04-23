/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:58:49 by yasaidi           #+#    #+#             */
/*   Updated: 2023/03/06 15:02:27 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// bool.h
int		ft_isalpha(char c);
int		ft_isdigit(char c);
int		ft_isascii(int c);
int		ft_isalnum(char c);
int		ft_isspace(char c);
// strings.h
size_t	ft_strlen(const char *str);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
char	*ft_strnstr(const char *str, const char *little, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
void	*ft_memchr(const void *mb, int c, size_t size);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *mb, int c, size_t size);
int		ft_memcmp(const void *s1, const void *s2, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strtrim(const char *s1, const char *set);
// ctypes.h
int		ft_toupper(int c);
int		ft_tolower(int c);
// stdlib.h
int		ft_atoi(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
void	ft_swap(int *a, int *b);

// typedef struct s_list
// {
// void 	*content;
// struct	s_list *next;

// } t_list;

// //lst
// t_list	*ft_lstnew(void *content);
// void	ft_lstadd_front(t_list **lst, t_list *new);
// void	ft_lstadd_back(t_list **lst, t_list *new);
// t_list	*ft_lstlast(t_list *lst);
// int		ft_lstsize(t_list *lst);
// void	ft_lstdelone(t_list *lst, void (*del)(void*));
// t_list	*ft_lstpre_last(t_list *lst);

#endif