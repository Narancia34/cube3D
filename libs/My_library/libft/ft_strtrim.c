/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:44:23 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/29 15:35:52 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../my_library.h"

static int	*hash_table(int *check_tab, const char *set)
{
	int	i;

	i = 0;
	if (!check_tab)
		return (0);
	ft_memset(check_tab, 0, 255);
	while (set[i] != 0)
	{
		check_tab[(unsigned char)set[i]] = 1;
		i++;
	}
	return (check_tab);
}

static char	*ft_set_str(int i, int j, const char *s1)
{
	char	*str;

	if (i > j)
	{
		str = (char *)malloc(1);
		if (!str)
			return (0);
		str[0] = 0;
		return (str);
	}
	str = (char *)malloc(j - i + 2);
	if (!str)
		return (0);
	ft_memcpy(str, s1 + i, j - i + 1);
	str[j - i + 1] = 0;
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		check_tab[255];
	int		i;
	int		j;
	char	*str;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup((const char *)s1));
	hash_table(check_tab, set);
	i = ft_strlen(s1) - 1;
	while (check_tab[(unsigned char)s1[i]] == 1)
		i--;
	j = i;
	i = 0;
	while (check_tab[(unsigned char)s1[i]] == 1)
		i++;
	str = ft_set_str(i, j, s1);
	return (str);
}
