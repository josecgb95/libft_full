/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-car <jose-car@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 13:19:16 by jose-car          #+#    #+#             */
/*   Updated: 2025/11/28 20:05:41 by jose-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_count_words(char const *str, char c)
{
	size_t	i;
	size_t	count_word;

	i = 0;
	count_word = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
		{
			count_word++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count_word);
}

static char	*ft_copy_word(const char *s, size_t start, size_t end)
{
	size_t	i;
	char	*word;

	i = 0;
	word = malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static void	ft_free_all(char **array, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static int	ft_fill_split(char **result, const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			result[j] = ft_copy_word(s, start, i);
			if (!result[j])
				return (ft_free_all (result, j), 0);
			j++;
		}
	}
	result[j] = NULL;
	return (1);
}

// Splits a string into an array of words using a given delimiter.
char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!result)
		return (NULL);
	if (!ft_fill_split(result, s, c))
		return (NULL);
	return (result);
}
