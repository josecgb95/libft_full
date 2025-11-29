/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-car <jose-car@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:20:42 by jose-car          #+#    #+#             */
/*   Updated: 2025/11/28 20:01:39 by jose-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

// ---------- print number ------- //
int	ft_putnbr(int nbr)
{
	long	ln;
	int		count;

	count = 0;
	ln = nbr;
	if (ln < 0)
	{
		count += ft_putchar('-');
		ln = -ln;
	}
	if (ln >= 10)
		count += ft_putnbr(ln / 10);
	count += ft_putchar((ln % 10) + '0');
	return (count);
}

// ------ print unsigned number ------- //
int	ft_putunbr(unsigned int nbr)
{
	int		count;

	count = 0;
	if (nbr >= 10)
		count += ft_putunbr(nbr / 10);
	count += ft_putchar((nbr % 10) + '0');
	return (count);
}

// ------ print hexadecimal -------- //
int	ft_puthex(unsigned long nbr, int lowercase)
{
	const char	*base;
	int			count;

	count = 0;
	if (lowercase)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nbr >= 16)
		count += ft_puthex(nbr / 16, lowercase);
	count += ft_putchar(base[nbr % 16]);
	return (count);
}

// -------- print pointer ------ //
int	ft_putptr(void *ptr)
{
	unsigned long	p;
	int				count;

	count = 0;
	p = (unsigned long)ptr;
	if (!ptr)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	count += ft_puthex(p, 1);
	return (count);
}
