/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:22:55 by btan              #+#    #+#             */
/*   Updated: 2024/01/02 17:54:13 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_printstr(int fd, char *str)
{
	if (!str)
		str = "(null)";
	return (write(fd, str, ft_strlen(str)));
}

static int	ft_printnbr(int fd, long nbr)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789";
	if (nbr < 0)
	{
		count += ft_printstr(fd, "-");
		nbr = -nbr;
	}
	if (nbr > 9)
		count += ft_printnbr(fd, nbr / 10);
	count += write(fd, &base[nbr % 10], 1);
	return (count);
}

static int	ft_printhex(int fd, unsigned long nbr, char fmt)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (fmt == 'X')
		base = "0123456789ABCDEF";
	if (fmt == 'p')
		if (nbr == 0)
			return (ft_printstr(fd, "(nil)"));
	if (nbr > 15)
		count += ft_printhex(fd, nbr / 16, fmt);
	if (count == 0 && fmt == 'p')
		count += ft_printstr(fd, "0x");
	count += write(fd, &base[nbr % 16], 1);
	return (count);
}

static int	ft_printfmt(int fd, int fmt, va_list lst)
{
	char	c;

	if (fmt == 'c')
	{
		c = va_arg(lst, int);
		return (write(fd, &c, 1));
	}
	if (fmt == 's')
		return (ft_printstr(fd, va_arg(lst, char *)));
	if (fmt == 'p')
		return (ft_printhex(fd, va_arg(lst, unsigned long), fmt));
	if (fmt == 'd' || fmt == 'i')
		return (ft_printnbr(fd, va_arg(lst, int)));
	if (fmt == 'u')
		return (ft_printnbr(fd, va_arg(lst, unsigned int)));
	if (fmt == 'x' || fmt == 'X')
		return (ft_printhex(fd, va_arg(lst, unsigned int), fmt));
	if (fmt == '%')
		return (write(fd, "%", 1));
	return (0);
}

int	ft_printf_fd(int fd, const char *str, ...)
{
	va_list	lst;
	int		count;

	va_start(lst, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			count += ft_printfmt(fd, *(++str), lst);
			str++;
		}
		else
			count += write(fd, &*(str++), 1);
	}
	va_end(lst);
	return (count);
}
