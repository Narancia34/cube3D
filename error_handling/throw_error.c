/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 21:00:43 by fbicane           #+#    #+#             */
/*   Updated: 2025/08/12 19:37:57 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parse_error(int error_code, t_cub3d *game)
{
	if (1 == error_code)
	{
		printf(RED"Error:\nEach element must contain type identifier");
		printf(" followed by its specific information.\n"RESET);
	}
	else if (2 == error_code)
		printf(RED"Error:\nFailed loading textures.\n"RESET);
	else if (3 == error_code)
		printf(RED"Error:\nR,G,B colors in range [0,255].\n"RESET);
	else if (4 == error_code)
		printf(RED"Error:\nUnexpected element in the file.\n");
	else if (5 == error_code)
		printf(RED"Error:\nFile doesn't exist.\n"RESET);
	else if (6 == error_code)
		printf(RED"Error:\nMissing a .cub file"RESET);
	destroy_parcing(game);
}
