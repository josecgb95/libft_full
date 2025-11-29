/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-car <jose-car@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 17:28:57 by jose-car          #+#    #+#             */
/*   Updated: 2025/11/28 20:03:32 by jose-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*new_str;
	size_t	len_s1;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	if (!s1)
		len_s1 = 0;
	else
		len_s1 = ft_strlen_gnl(s1);
	new_str = (char *)malloc(sizeof(char) * (len_s1 + ft_strlen_gnl(s2) + 1));
	if (!new_str)
		return (NULL);
	while (s1 && s1[j])
		new_str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	if (s1)
		free(s1);
	return (new_str);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
