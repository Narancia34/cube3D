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

static void	check_file(char **av, t_cub3d *game)
{
	int	len;

	if (!av[1])
		parse_error(6, game);
	len = ft_strlen(av[1]);
	if (len < 5 && ft_strncmp(av[1] + (len - 4), ".cub", 4))
		parse_error(6, game);
	game->parse.cub_file = open(av[1], O_RDONLY);
	if (-1 == game->parse.cub_file)
		parse_error(5, NULL);
}

void	parse_file(char **av, t_cub3d *game)
{
	check_file(av, game);
	parse_elements(game);
	parse_map(game);
	close(game->parse.cub_file);
}
