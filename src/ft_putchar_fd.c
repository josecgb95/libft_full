/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-car <jose-car@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:17:55 by jose-car          #+#    #+#             */
/*   Updated: 2025/11/28 20:05:28 by jose-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*Sends the character 'c' to the specified file descriptor.*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
