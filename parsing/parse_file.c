/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicane <fbicane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 09:41:01 by fbicane           #+#    #+#             */
/*   Updated: 2025/08/10 09:51:11 by fbicane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

void	parse_file(char **av, t_cub3d *game)
{
	int	cub_file;

	cub_file = open(av[1], O_RDONLY);
	if (-1 == cub_file)
		parse_error(5, NULL);
	parse_elements(cub_file, game);
	printf(GREEN"Parsing done correctlly\n"RESET);
}
