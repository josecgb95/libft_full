/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-car <jose-car@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 09:36:55 by jose-car          #+#    #+#             */
/*   Updated: 2025/11/29 09:38:52 by jose-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// concatenate str1 and str2
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	len;

	new_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_str)
		return (NULL);
	ft_strcpy(new_str, (char *)s1);
	len = ft_strlen(new_str);
	ft_strcpy(&new_str[len], (char *)s2);
	new_str[ft_strlen(new_str)] = '\0';
	return (new_str);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	l_src;
	size_t	l_dest;
	size_t	i;

	l_src = 0;
	l_dest = 0;
	while (src[l_src])
		l_src++;
	while (dest[l_dest] && l_dest < size)
		l_dest++;
	if (l_dest == size)
		return (l_src + size);
	i = 0;
	while ((l_dest + i < size - 1) && (src[i]))
	{
		dest[l_dest + i] = src[i];
		i++;
	}
	dest[l_dest + i] = '\0';
	return (l_dest + l_src);
}

// Copies up to size - 1 char from src to dst
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (size > 0)
	{
		while ((i < (size - 1)) && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len);
}

// Duplicates the string recieved as parameter using malloc(3).
char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*new_s;

	len = ft_strlen(s);
	new_s = (char *)malloc(sizeof(char) * (len + 1));
	if (new_s == NULL)
		return (NULL);
	ft_memcpy(new_s, s, len);
	new_s[len] = '\0';
	return (new_s);
}
