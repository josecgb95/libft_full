/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-car <jose-car@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:51:08 by jose-car          #+#    #+#             */
/*   Updated: 2025/11/28 20:04:16 by jose-car         ###   ########.fr       */
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
