/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-car <jose-car@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 23:17:33 by jose-car          #+#    #+#             */
/*   Updated: 2025/11/28 20:02:04 by jose-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

// ------ print character ----- //
int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

// ----- print string ------ //
int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[count])
	{
		write(1, &str[count], 1);
		count++;
	}
	return (count);
}
