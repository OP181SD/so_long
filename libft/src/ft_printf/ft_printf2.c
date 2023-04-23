/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:09:31 by yasaidi           #+#    #+#             */
/*   Updated: 2022/12/13 13:17:41 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_format(char fmt, va_list *def)
{
	int	len;

	len = 0;
	if (fmt == 'c')
		len += ft_putchar(va_arg(*def, int));
	else if (fmt == 's')
		len += ft_putstr(va_arg(*def, char *));
	else if (fmt == 'd' || fmt == 'i')
		len += ft_putnbr(va_arg(*def, int));
	else if (fmt == 'x' || fmt == 'X')
		len += ft_printhex(va_arg(*def, unsigned int), fmt);
	else if (fmt == 'u')
		len += ft_put_u(va_arg(*def, unsigned int));
	else if (fmt == 'p')
		len += is_null(va_arg(*def, long long unsigned));
	else if (fmt == '%')
		len += ft_putchar('%');
	else
		return (0);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	params;
	int		i;
	int		len;

	va_start(params, format);
	if (!format)
		return (0);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
			len += p_format(format[++i], &params);
		else
		{
			write(1, &format[i], 1);
			len++;
		}
		i++;
	}
	va_end(params);
	return (len);
}
