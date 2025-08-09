/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:05:50 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/29 15:36:01 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../my_library.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*s_sub;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	i = 0;
	s_sub = (char *)malloc(len + 1);
	if (!s_sub)
		return (0);
	while (len != 0)
	{
		s_sub[i] = s[start];
		start++;
		i++;
		len--;
	}
	s_sub[i] = 0;
	return (s_sub);
}
