/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-car <jose-car@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 21:46:57 by jose-car          #+#    #+#             */
/*   Updated: 2025/12/03 21:50:15 by jose-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*p_s;

	i = 0;
	p_s = (const unsigned char *)s;
	while (i < n)
	{
		if (p_s[i] == (unsigned char)c)
			return ((void *)&p_s[i]);
		i++;
	}
	return (0);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*p_s1;
	unsigned char	*p_s2;

	i = 0;
	p_s1 = (unsigned char *) s1;
	p_s2 = (unsigned char *) s2;
	while (i < n)
	{
		if (p_s1[i] != p_s2[i])
		{
			return (p_s1[i] - p_s2[i]);
		}
		i++;
	}
	return (0);
}

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

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p_s;

	i = 0;
	p_s = (unsigned char *) s;
	while (i < n)
	{
		p_s[i] = (unsigned char)c;
		i++;
	}
	return (s);
}