/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 21:00:43 by fbicane           #+#    #+#             */
/*   Updated: 2025/08/10 21:18:25 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parce_error(int error_code, t_cub3d *game)
{
	if (1 == error_code)
	{
		printf(RED"Each element must contain type identifier followed by its specific information"RESET);
		destroy_parcing(game);
	}
	else if (2 == error_code)
	{
		printf(RED"Failed loading textures\n"RESET);
		destroy_parcing(game);
	}
}
