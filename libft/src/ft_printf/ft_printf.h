/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:10:14 by yasaidi           #+#    #+#             */
/*   Updated: 2023/02/08 19:48:29 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
//int		ft_len(char *str);
int		ft_putstr(char *str);
int		ft_putnbr(int nb);
int		ft_put_u(unsigned int nb);
int		ft_printhex(unsigned int nb, char type);
int		ft_printptr(long long unsigned nb);
int		int_len(long nb_div);
int		is_null(long long unsigned nb);

#endif