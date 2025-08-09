/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:46:10 by fbicane           #+#    #+#             */
/*   Updated: 2025/01/29 15:28:57 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../my_library.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*row_mm;

	if (!count && !size && (count > SIZE_MAX / size))
		return (0);
	row_mm = (unsigned char *)malloc(count * size);
	if (!row_mm)
		return (0);
	ft_bzero(row_mm, (count * size));
	return (row_mm);
}
