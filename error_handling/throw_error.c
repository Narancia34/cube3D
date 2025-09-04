/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 21:00:43 by fbicane           #+#    #+#             */
/*   Updated: 2025/09/04 22:29:19 by fbicane          ###   ########.fr       */
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
		printf(RED"Error:\nMissing a .cub file.\n"RESET);
	else if (7 == error_code)
		printf(RED"Error:\nMore than one starting position.\n"RESET);
	else if (8 == error_code)
		printf(RED"Error:\nMore than one starting position.\n"RESET);
	else if (9 == error_code)
		printf(RED"Error:\nNo starting position.\n"RESET);
	destroy_parsing(game);
}
