/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-car <jose-car@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:40:16 by jose-car          #+#    #+#             */
/*   Updated: 2025/11/28 20:02:10 by jose-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_print_condition(va_list ap, char c)
{
	int	print;

	print = 0;
	if (c == 'c')
		print += ft_putchar((unsigned char)va_arg(ap, int));
	else if (c == 's')
		print += ft_putstr((char *)va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		print += ft_putnbr((int)va_arg(ap, int));
	else if (c == 'u')
		print += ft_putunbr((unsigned int)va_arg(ap, unsigned int));
	else if (c == 'p')
		print += ft_putptr((void *)va_arg(ap, void *));
	else if (c == 'X')
		print += ft_puthex((unsigned int)va_arg(ap, unsigned int), 0);
	else if (c == 'x')
		print += ft_puthex((unsigned int)va_arg(ap, unsigned int), 1);
	else if (c == '%')
		print += ft_putchar('%');
	else
		print += ft_putchar(c);
	return (print);
}

int	ft_printf(char const *str, ...)
{
	va_list	ap;
	int		print;

	if (!str)
		return (-1);
	print = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			print += ft_print_condition(ap, *str);
		}
		else
			print += ft_putchar(*str);
		str++;
	}
	va_end(ap);
	return (print);
}
