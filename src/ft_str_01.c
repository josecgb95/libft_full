/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-car <jose-car@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 09:29:31 by jose-car          #+#    #+#             */
/*   Updated: 2025/11/29 09:35:12 by jose-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

// returns a pointer to the first occurrence of the char c in the str s
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

// Returns a pointer to the last occurrence of the character c in the string s.
char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)&s[i]);
	while (i > 0)
	{
		if (s[i - 1] == (char)c)
			return ((char *)&s[i - 1]);
		i--;
	}
	return (NULL);
}

/*Returns a new string that is a substring of the original,
starting at a given index and up to a specified length.*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_strdup(""));
	if (len > len_s - start)
		len = len_s - start;
	sub_s = malloc(sizeof(char) * (len + 1));
	if (!sub_s)
		return (NULL);
	ft_memcpy(sub_s, s + start, len);
	sub_s[len] = '\0';
	return (sub_s);
}

/*	
	Searches for the first occurrence of the string 'little' within the
	string 'big', but only within the first 'len' characters of 'big'.
	Returns a pointer to the beginning of the match, or NULL if not found.
*/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	if (!big && len == 0)
		return (0);
	little_len = ft_strlen(little);
	while (big[i] && (i + little_len <= len))
	{
		if (ft_strncmp(&big[i], little, little_len) == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (0);
}
