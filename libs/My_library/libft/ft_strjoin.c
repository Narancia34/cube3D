/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:25:38 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/29 15:34:35 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../my_library.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*s1_s2;

	if (!s1 || !s2)
		return (0);
	s1_s2 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s1_s2)
		return (0);
	i = 0;
	while (s1[i] != 0)
	{
		s1_s2[i] = s1[i];
		i++;
	}
	while (s2[i - ft_strlen(s1)])
	{
		s1_s2[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	s1_s2[i] = 0;
	return (s1_s2);
}
