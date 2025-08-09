/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:56:56 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/29 15:34:00 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../my_library.h"

static void	ft_free(char **arr_s)
{
	int	i;

	i = 0;
	if (!arr_s)
		return ;
	while (arr_s[i] != 0)
	{
		free(arr_s[i]);
		i++;
	}
	free (arr_s);
}

static int	ft_count_words(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != 0)
	{
		if ((i == 0 && s[i] != c) || (i > 0 && s[i - 1] == c && s[i] != c))
			count++;
		i++;
	}
	return (count);
}

static char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

static char	**arr_str_all(char const *s, char **arr_s, char c, int words)
{
	int		len;
	int		i;

	i = 0;
	while (i < words)
	{
		len = 0;
		while (*s == c)
			s++;
		while (*s != c && *s != 0)
		{
			len++;
			s++;
		}
		arr_s[i] = malloc(len + 1);
		if (!arr_s[i])
		{
			ft_free(arr_s);
			return (0);
		}
		ft_strncpy(arr_s[i], s - len, len);
		i++;
	}
	arr_s[i] = 0;
	return (arr_s);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**arr_s;

	if (!s)
		return (0);
	words = ft_count_words(s, c);
	if (words == 0)
	{
		arr_s = malloc (sizeof(char *));
		if (!arr_s)
			return (0);
		arr_s[0] = 0;
		return (arr_s);
	}
	arr_s = malloc((words + 1) * sizeof(char *));
	if (!arr_s)
		return (0);
	arr_s = arr_str_all(s, arr_s, c, words);
	return (arr_s);
}
