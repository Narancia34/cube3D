/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:30:41 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/29 15:32:18 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../my_library.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_tc;
	size_t			i;

	i = 0;
	s_tc = ((unsigned char *)(s));
	while (i < n)
	{
		if (s_tc[i] == (unsigned char)c)
			return (&s_tc[i]);
		i++;
	}
	return (0);
}
