/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-car <jose-car@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:31:04 by jose              #+#    #+#             */
/*   Updated: 2025/11/28 20:05:17 by jose-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// Copies from pointer src to dest taking n as maximum length of src.
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*p_dest;
	const unsigned char	*p_src;

	i = 0;
	p_dest = (unsigned char *)dest;
	p_src = (const unsigned char *)src;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
		p_dest[i] = p_src[i];
		i++;
	}
	return (dest);
}
