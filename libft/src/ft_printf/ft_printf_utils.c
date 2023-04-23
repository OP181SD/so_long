/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 21:03:09 by yasaidi           #+#    #+#             */
/*   Updated: 2022/12/13 13:17:24 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	long	n;

	n = nb;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
	return ((int_len(nb)));
}

int	ft_put_u(unsigned int nb)
{
	long	n;

	n = nb;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
	return ((int_len(n)));
}

int	ft_printhex(unsigned int nb, char type)
{
	unsigned int	len;
	const char		*base_lx;
	const char		*base_ux;

	base_lx = "0123456789abcdef";
	base_ux = "0123456789ABCDEF";
	len = 0;
	if (nb > 15)
	{
		len += ft_printhex((nb / 16), type);
		len += ft_printhex((nb % 16), type);
	}
	else if (type == 'x')
len += ft_putchar(base_lx[nb % 16]);
	else if (type == 'X')
len += ft_putchar(base_ux[nb % 16]);
	return (len);
}

int	ft_printptr(long long unsigned nb)
{
	const char			*base;
	long long unsigned	len;

	base = "0123456789abcdef";
	len = 0;
	if (nb > 15)
	{
		len += ft_printptr(nb / 16);
		len += ft_printptr(nb % 16);
	}
	else
		len += ft_putchar(base[nb % 16]);
	return (len);
}

int	is_null(long long unsigned nb)
{
	int	len;

	len = 0;
	if (nb == 0)
	{
		len += write(1, "(nil)", 5);
		return (len);
	}
	else
	{
		len += ft_putstr("0x");
		len += ft_printptr(nb);
	}
	return (len);
}
