/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-car <jose-car@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:24:15 by jose-car          #+#    #+#             */
/*   Updated: 2025/11/28 20:05:23 by jose-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	c_r(unsigned char *dest, const unsigned char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
}

static void	c_l(unsigned char *dest, const unsigned char *src, size_t n)
{
	while (n > 0)
	{
		n--;
		dest[n] = src[n];
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*p_dest;
	const unsigned char	*p_src;

	p_dest = (unsigned char *)dest;
	p_src = (const unsigned char *)src;
	if (!dest && !src)
		return (0);
	if (dest == src)
		return (dest);
	if (dest < src)
		c_r(p_dest, p_src, n);
	else
		c_l(p_dest, p_src, n);
	return (dest);
}
