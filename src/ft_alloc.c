/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-car <jose-car@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:01:41 by jose-car          #+#    #+#             */
/*   Updated: 2025/12/04 15:01:55 by jose-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p_m;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	p_m = malloc(nmemb * size);
	if (!p_m)
		return (NULL);
	ft_bzero(p_m, nmemb * size);
	return (p_m);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*z;

	i = 0;
	z = (unsigned char *) s;
	while (i < n)
	{
		z[i] = 0;
		i++;
	}
}
