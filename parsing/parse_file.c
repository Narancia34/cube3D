/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 09:41:01 by fbicane           #+#    #+#             */
/*   Updated: 2025/08/12 19:38:11 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parse_file(char **av, t_cub3d *game)
{
	int	cub_file;

	if (!av[1])
		parse_error(6, game);
	cub_file = open(av[1], O_RDONLY);
	if (-1 == cub_file)
		parse_error(5, NULL);
	parse_elements(cub_file, game);
	close(cub_file);
	printf(GREEN"Parsing done correctlly\n"RESET);
}
